#ifndef PY_HAL_DROTEK_F9P
#define PY_HAL_DROTEK_F9P

#include <iostream>
#include <string>
#include <exception>

#include <math.h>
#include "HAL_Sirius_F9P_Rover.cc"

class PyHALDrotekF9P {
	private:
		SiriusF9P_Rover* hal_gps;
		bool connected;
	public:
		PyHALDrotekF9P(){}

	~PyHALDrotekF9P(){
		if (connected) hal_gps->disconnect();
	}

	// Call this first
	// port: the path to the device
	bool init(std::string port) {
		try {
			hal_gps = new SiriusF9P_Rover(port, 9600, READ_GNS | READ_GST);
			connected = hal_gps->isPortOpen();
			return connected;
		} catch(exception& e) {
			std::cout << "Exception: " << e.what() << std::endl;
			return false;
		}
	}

    std::string get_gnss_name() {
		return "Drotek-F9P";
	}

    bool shutdown() {
		hal_gps->disconnect();
		return true;
	}

    void get_gnss_info(double *gnss_status) {
        hal_gps->readPacket();
		double* res_gps = hal_gps->getStatus();

        gnss_status[0] = res_gps[0];
        gnss_status[1] = res_gps[1];
        gnss_status[2] = res_gps[2];
        gnss_status[3] = res_gps[3];
        gnss_status[4] = res_gps[4];
        gnss_status[5] = res_gps[5];
	}

    GPSTimestamp getTimestamp() {
        return hal_gps->getTimestamp();
    }

	bool has_fix() {
		hal_gps->readPacket();
        hal_gps->getStatus();
		return hal_gps->hasFix();
	}

	constexpr bool has_rtcm() const {
		return true;
	}

    void put_rtcm_msg(const char *rtcm_msg, int rtcm_size){
        hal_gps->writePacket(rtcm_msg, rtcm_size);
	}
};

#endif // PY_HAL_DROTEK_F9P
