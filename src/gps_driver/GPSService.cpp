#include <iostream>
#include <cmath>
#include <fstream>

#include <gps_driver/nmeaparse/GPSService.h>
#include <gps_driver/nmeaparse/NumberConversion.h>

using namespace std;
using namespace std::chrono;

using namespace nmea;


// ------ Some helpers ----------
// Takes the NMEA lat/long format (dddmm.mmmm, [N/S,E/W]) and converts to degrees N,E only
double convertLatLongToDeg(string llstr, string dir){

	double pd = parseDouble(llstr);
	double deg = trunc(pd / 100);				//get ddd from dddmm.mmmm
	double mins = pd - deg * 100;

	deg = deg + mins / 60.0;

	char hdg = 'x';
	if (!dir.empty()){
		hdg = dir[0];
	}

	//everything should be N/E, so flip S,W
	if (hdg == 'S' || hdg == 'W'){
		deg *= -1.0;
	}

	return deg;
}
double convertKnotsToKilometersPerHour(double knots){
	return knots * 1.852;
}



// ------------- GPSSERVICE CLASS -------------


GPSService::GPSService(){

}

GPSService::GPSService(NMEAParser& parser) {
	attachToParser(parser);		// attach to parser in the GPS object
}

GPSService::~GPSService() {
	// TODO Auto-generated destructor stub
}

void GPSService::attachToParser(NMEAParser& _parser){

	// NMEA-0183 messages: Overview https://www.trimble.com/OEM_ReceiverHelp/V4.44/en/
	/* used sentences...
	$GNGNS		- lat, long, alt
	$GNGST		- standard deviation for lat, lon and alt
    $GNVTG		- course and speed information relative to the ground
	$GPZDA		- 1pps timing message
	*/

	_parser.setSentenceHandler("GNGST", [this](const NMEASentence& nmea) {
		this->read_GNGST(nmea);
	});
    _parser.setSentenceHandler("GNZDA", [this](const NMEASentence& nmea) {
        this->read_GNZDA(nmea);
    });
    _parser.setSentenceHandler("GNVTG", [this](const NMEASentence& nmea) {
        this->read_GNVTG(nmea);
    });
	_parser.setSentenceHandler("GNGNS", [this](const NMEASentence& nmea) {
        this->read_GNGNS(nmea);
	});

}


void GPSService::read_GNGNS(const NMEASentence& nmea){
	/* -- EXAMPLE --
	 *
	$GNGNS,103600.01,5114.51176,N,00012.29380,W,ANNN,07,1.18,111.5,45.6,,,V*00\r\n

	Where:
	GNS          GNSS fix data
	index:
	[0] 123519          UTC time
	[1-2] 4807.038,N    Latitude 48 deg 07.038' N
	[3-4] 1131.000,E    Longitude 11 deg 31.000' E
	[5] AAAA            posmode: Positioning mode. Four character (A/N): GPS, GLONASS, Galileo, BeiDou
	[6] 08              Number of satellites being tracked
	[7] 0.9             Horizontal dilution of position
	[8] 545.4,M         Altitude, Meters, above mean sea level
	[9] 46.9,M          Geoid separation: difference between ellipsoid and mean sea level
	[10]                Time in seconds since last DGPS update
	[11] (empty field)  DGPS station ID number
	[12]                Navigational status indicator: V (Equipment is not providing navigational status information, fixed field, only available in NMEA 4.10 and later)
	[13]  *47          the checksum data, always begins with *
	*/
	try
	{
		if (!nmea.checksumOK()){
			throw NMEAParseError("Checksum is invalid!");
        }

		if (nmea.parameters.size() < 13){
			throw NMEAParseError("GPS data is missing parameters.");
        }

		// TIMESTAMP
        this->fix.timestamp.setTime(parseDouble(nmea.parameters[0]));
		string sll;
		string dir;
		// LAT
		sll = nmea.parameters[1];
		dir = nmea.parameters[2];
		if (!sll.empty()){
			this->fix.latitude = convertLatLongToDeg(sll, dir);
		}

		// LONG
		sll = nmea.parameters[3];
		dir = nmea.parameters[4];
		if (!sll.empty()){
			this->fix.longitude = convertLatLongToDeg(sll, dir);
		}

		string posMode;

		posMode = nmea.parameters[5];

		// FIX QUALITY
		bool lockupdate = this->fix.setlock(true);

		// ALTITUDE
		if (!nmea.parameters[8].empty()){
			this->fix.altitude = parseDouble(nmea.parameters[8]);
		}
		else {
			// leave old value
		}

		//this->fix.status = nmea.parameters[12][0];
        if ((nmea.parameters[5][0] == 'A' or nmea.parameters[5][0] == 'D' or nmea.parameters[5][0] == 'F' or nmea.parameters[5][0] == 'R')
                and (nmea.parameters[5][1] == 'A' or nmea.parameters[5][1] == 'D' or nmea.parameters[5][1] == 'F' or nmea.parameters[5][1] == 'R')) {
            this->fix.status = 'A';
        }

        if (nmea.parameters[5][0] == 'D' and nmea.parameters[5][1] == 'D') {
            this->fix.status = 'D';
        }

        if (nmea.parameters[5][0] == 'F' and nmea.parameters[5][1] == 'F') {
            this->fix.status = 'F';
        }

        if (nmea.parameters[5][0] == 'R' and nmea.parameters[5][1] == 'R') {
            this->fix.status = 'R';
        }
		
		

		//calling handlers
		if (lockupdate){
			this->onLockStateChanged(this->fix.haslock);
		}
		this->onUpdate();
	}
	catch (NumberConversionError& ex)
	{
		NMEAParseError pe("GPS Number Bad Format [$GNGNS] :: " + ex.message, nmea);
		throw pe;
	}
	catch (NMEAParseError& ex)
	{
		NMEAParseError pe("GPS Data Bad Format [$GNGNS] :: " + ex.message, nmea);
		throw pe;
	}
}

void GPSService::read_GNGST(const NMEASentence& nmea){
	/*  -- EXAMPLE --
	$GNGST,082356.00,1.8,,,,1.7,1.3,2.2*7E\r\n

	Where:
	GST      GNSS pseudorange error statistics
	[0] 123519          UTC time
	[1] 1.8             RangeRMS: RMS value of the standard deviation of the ranges
	[2] -               STDMajor: Standard deviation of semi-major axis
	[3] -               STDMinor: Standard deviation of semi-minor axis
	[4] -               Orient:   Orientation of semi-major axis
	[5] -               StdLat: Standard deviation of latitude error
	[6] -               StdLong: Standard deviation of longitude error
	[7] -               StdAlt: Standard deviation of altitude error
	[8]   *47          the checksum data, always begins with *
	*/

	try
	{
		if (!nmea.checksumOK()){
			throw NMEAParseError("Checksum is invalid!");
		}

		if (nmea.parameters.size() < 8){
			throw NMEAParseError("GST data is missing parameters.");
		}

        this->fix.stddev_latitude = parseDouble(nmea.parameters[5]);
        this->fix.stddev_longitude = parseDouble(nmea.parameters[6]);
        this->fix.stddev_altitude = parseDouble(nmea.parameters[7]);

		//calling handlers
        this->onUpdate();
	}
	catch (NumberConversionError& ex)
	{
		NMEAParseError pe("GPS Number Bad Format [$GNGST] :: " + ex.message, nmea);
		throw pe;
	}
	catch (NMEAParseError& ex)
	{
		NMEAParseError pe("GPS Data Bad Format [$GNGST] :: " + ex.message, nmea);
		throw pe;
	}
}

void GPSService::read_GNZDA(const NMEASentence& nmea){
	/*  -- EXAMPLE --
	$GPZDA,082710.00,16,09,2002,00,00*64\r\n

	Where:
	ZDA          Time and date
	index:
	[0] 123519          UTC time
	[1]                 UTC day
	[2]                 UTC month
	[3]                 UTC year
	[4]                 Local time zone hours
	[5]                 Local time zone minutes

	*/

	try
	{
		if (!nmea.checksumOK()){
			throw NMEAParseError("Checksum is invalid!");
		}

		//if(nmea.parameters.size() < 18){
		//	throw NMEAParseError("GPS data is missing parameters.");
		//}

		//cout << "ALMANAC FINISHED page " << this->fix.almanac.processedPages << " of " << this->fix.almanac.totalPages << endl;
		this->onUpdate();

	}
	catch (NumberConversionError& ex)
	{
		NMEAParseError pe("GPS Number Bad Format [$GPGSV] :: " + ex.message, nmea);
		throw pe;
	}
	catch (NMEAParseError& ex)
	{
		NMEAParseError pe("GPS Data Bad Format [$GPGSV] :: " + ex.message, nmea);
		throw pe;
	}
}

void GPSService::read_GNVTG(const NMEASentence& nmea){
	/*
	$GPVTG,77.52,T,,M,0.004,N,0.008,K,A*06\r\n

	where:
	VTG          Track made good and ground speed
	[0-1]	054.7,T      True track made good (degrees)
	[2-3]	034.4,M      Magnetic track made good
	[4-5]	005.5,N      Ground speed, knots
	[6-7]	010.2,K      Ground speed, Kilometers per hour
	[7]	                 posMode
	[8]	*48          Checksum
	*/

	cout << "nmea.parameters.size(): " << nmea.parameters.size() << endl;
	try
	{
		if (!nmea.checksumOK()){
			throw NMEAParseError("Checksum is invalid!");
		}

		if (nmea.parameters.size() < 9){
			throw NMEAParseError("GPS data is missing parameters.");
		}

		// SPEED
		// if empty, is converted to 0
		this->fix.speed = convertKnotsToKilometersPerHour(parseDouble(nmea.parameters[6]));		//km/h

		this->onUpdate();
	}
	catch (NumberConversionError& ex)
	{
		NMEAParseError pe("GPS Number Bad Format [$GNVTG] :: " + ex.message, nmea);
		throw pe;
	}
	catch (NMEAParseError& ex)
	{
		NMEAParseError pe("GPS Data Bad Format [$GNVTG] :: " + ex.message, nmea);
		throw pe;
	}
}

