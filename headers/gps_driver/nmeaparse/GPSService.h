#ifndef GPSSERVICE_H_
#define GPSSERVICE_H_

#include <string>
#include <chrono>
#include <functional>
#include "GPSFix.h"
#include "NMEAParser.h"
#include "Event.h"

namespace nmea {

class GPSService {
private:

	void read_GNGNS	(const NMEASentence& nmea);
	void read_GNGST	(const NMEASentence& nmea);
	void read_GNVTG	(const NMEASentence& nmea);
    void read_GNZDA	(const NMEASentence& nmea);

public:
	GPSFix fix;

    GPSService();
	GPSService(NMEAParser& parser);
	virtual ~GPSService();

	Event<void(bool)> onLockStateChanged;		// user assignable handler, called whenever lock changes
	Event<void()> onUpdate;						// user assignable handler, called whenever fix changes

	void attachToParser(NMEAParser& parser);			// will attach to this parser's nmea sentence events
};


}

#endif /* GPSSERVICE_H_ */
