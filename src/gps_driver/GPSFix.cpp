#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>

#include <gps_driver/nmeaparse/GPSFix.h>

using namespace std;
using namespace std::chrono;

using namespace nmea;

// ===========================================================
// ======================== GPS TIMESTAMP ====================
// ===========================================================


GPSTimestamp::GPSTimestamp(){
	hour = 0;
	min = 0;
	sec = 0;

	month = 1;
	day = 1;
	year = 1970;

	rawTime = 0;
	rawDate = 0;
}

// indexed from 1!
std::string GPSTimestamp::monthName(uint32_t index){
	if (index < 1 || index > 12){
		std::stringstream ss;
		ss << "[month:" << index << "]";
		return ss.str();
	}

	std::string names[] = {
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December"
	};
	return names[index - 1];
}

void GPSTimestamp::setTime(double raw_ts){
	rawTime = raw_ts;

	hour = (int32_t)trunc(raw_ts / 10000.0);
	min = (int32_t)trunc((raw_ts - hour * 10000) / 100.0);
	sec = raw_ts - min * 100 - hour * 10000;
}

std::string GPSTimestamp::toString(){
	std::stringstream ss;
	ss << hour << "h " << min << "m " << sec << "s" << "  " << monthName(month) << " " << day << " " << year;
	return ss.str();
}







// =====================================================
// ======================== GPS FIX ====================
// =====================================================

GPSFix::GPSFix() {

	status = 'V';	// Void

	haslock = 0;

	latitude = 0;	
	longitude = 0;	
	speed = 0;
	stddev_altitude = 0;
	stddev_longitude = 0;
	stddev_latitude = 0;
	altitude = 0;


}

GPSFix::~GPSFix() {
	// TODO Auto-generated destructor stub
}

// Returns the duration since the Host has received information
seconds GPSFix::timeSinceLastUpdate(){
	time_t now = time(NULL);
	struct tm stamp = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	stamp.tm_hour = timestamp.hour;
	stamp.tm_min = timestamp.min;
	stamp.tm_sec = (int)timestamp.sec;
	stamp.tm_year = timestamp.year-1900;
	stamp.tm_mon = timestamp.month-1;
	stamp.tm_mday = timestamp.day;

	time_t then = mktime(&stamp);
	uint64_t secs = (uint64_t)difftime(now,then);
	return seconds((uint64_t)secs);
}


bool GPSFix::setlock(bool locked){
	if (haslock != locked){
		haslock = locked;
		return true;
	}
	return false;
}

bool GPSFix::locked(){
	return haslock;
}


std::string fixStatusToString(char status){
	switch (status){
	case 'A':
		return "Active";
	case 'V':
		return "Void";
	default:
		return "Unknown";
	}
}

std::string GPSFix::toString(){
	stringstream ss;
	ios_base::fmtflags oldflags = ss.flags();

	ss << "========================== GPS FIX ================================" << endl
		<< " Status: \t\t" << ((haslock) ? "LOCK!" : "SEARCHING...") << endl
		<< " < Fix Details >" << endl
		<< "   Age:                " << timeSinceLastUpdate().count() << " s" << endl
		<< "   Timestamp:          " << timestamp.toString() << "   UTC   \n\t\t\t(raw: " << timestamp.rawTime << " time, " << timestamp.rawDate << " date)" << endl
		<< "   Raw Status:         " << status			<< "  (" << fixStatusToString(status) << ")" << endl
		<< "   Lat/Lon (N,E):      " << setprecision(6) << fixed << latitude << "' N, " << longitude << "' E" <<  endl;

	ss.flags(oldflags);  //reset

	ss << "   Altitude:           " << altitude << " m" << endl
		<< "   Speed:              " << speed << " km/h" << endl;

	return ss.str();
}
GPSFix::operator std::string(){
	return toString();
}
