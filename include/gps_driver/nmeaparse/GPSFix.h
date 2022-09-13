#ifndef GPSFIX_H_
#define GPSFIX_H_

#include <cstdint>
#include <ctime>
#include <string>
#include <chrono>
#include <vector>
#include <cmath>
#include <sstream>

namespace nmea {

	class GPSSatellite;
	class GPSAlmanac;
	class GPSFix;
	class GPSService;


	// =========================== GPS SATELLITE =====================================

	class GPSSatellite {
	public:
		GPSSatellite() :
			snr(0),
			prn(0),
			elevation(0),
			azimuth(0)
		{};

		//satellite data
		double snr;			// 0-99 dB
		uint32_t prn;		// id - 0-32
		double elevation;	// 0-90 deg
		double azimuth;		// 0-359 deg
		std::string toString();
		operator std::string();
	};


	// =========================== GPS TIMESTAMP =====================================

	// UTC time
	class GPSTimestamp {
	private:
		std::string monthName(uint32_t index);
	public:
		GPSTimestamp();

		int32_t hour;
		int32_t min;
		double sec;

		int32_t month;
		int32_t day;
		int32_t year;

		// Values collected directly from the GPS
		double rawTime;
		int32_t rawDate;

		// Set directly from the NMEA time stamp
		// hhmmss.sss
		void setTime(double raw_ts);

		std::string toString();
	};






	// =========================== GPS FIX =====================================

	class GPSFix {
		friend GPSService;

	private:

		bool haslock;
		bool setlock(bool b);		//returns true if lock status **changed***, false otherwise.


	public:

		GPSFix();
		virtual ~GPSFix();

		GPSTimestamp timestamp;

		char status;		// Status: A=active, V=void (not locked)
		double altitude;		// meters
		double latitude;		// degrees N
		double longitude;		// degrees E

		double stddev_altitude;
		double stddev_latitude;
		double stddev_longitude;

		double speed;			// km/h

		bool locked();
		
		std::chrono::seconds timeSinceLastUpdate();	// Returns seconds difference from last timestamp and right now.

		std::string toString();
		operator std::string();
	};

}

#endif /* GPSFIX_H_ */
