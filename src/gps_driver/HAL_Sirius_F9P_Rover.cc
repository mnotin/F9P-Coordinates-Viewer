#ifndef MY_HAL_SIRIUS_FP9_ROVER
#define MY_HAL_SIRIUS_FP9_ROVER

#include <ctime>
#include <iostream>
#include <libserial/SerialPort.h>
#include <fstream>

#include <gps_driver/nmeaparse/nmea.h>

#define BUF_SIZE 200

#define READ_GNS 1
#define READ_GST 2
#define READ_ZDA 4
#define READ_VTG 8

using namespace LibSerial;
using namespace std;
using namespace nmea;

class KalmanLatLong {
private:
    float MinAccuracy = 1;

    float Q_metres_per_second;    
    long TimeStamp_milliseconds;

public:
    double lat;
    double lng;
    float variance; // P matrix.  Negative means object uninitialised.  NB: units irrelevant, as long as same units used throughout

    KalmanLatLong(float Q_metres_per_second) { this->Q_metres_per_second = Q_metres_per_second; variance = -1; }

    long get_TimeStamp() { return TimeStamp_milliseconds; }
    double get_lat() { return lat; }
    double get_lng() { return lng; }
    float get_accuracy() { return (float)sqrt(variance); }

    void SetState(double lat, double lng, float accuracy, long TimeStamp_milliseconds) {
        this->lat=lat; this->lng=lng; variance = accuracy * accuracy; this->TimeStamp_milliseconds=TimeStamp_milliseconds;
    }

    /// <summary>
    /// Kalman filter processing for lattitude and longitude
    /// </summary>
    /// <param name="lat_measurement_degrees">new measurement of lattidude</param>
    /// <param name="lng_measurement">new measurement of longitude</param>
    /// <param name="accuracy">measurement of 1 standard deviation error in metres</param>
    /// <param name="TimeStamp_milliseconds">time of measurement</param>
    /// <returns>new state</returns>
    void Process(double lat_measurement, double lng_measurement, float accuracy, long TimeStamp_milliseconds) {
        if (accuracy < MinAccuracy) accuracy = MinAccuracy;
        if (variance < 0) {
            // if variance < 0, object is unitialised, so initialise with current values
            this->TimeStamp_milliseconds = TimeStamp_milliseconds;
            lat=lat_measurement; lng = lng_measurement; variance = accuracy*accuracy; 
        } else {
            // else apply Kalman filter methodology

            long TimeInc_milliseconds = TimeStamp_milliseconds - this->TimeStamp_milliseconds;
            if (TimeInc_milliseconds > 0) {
                // time has moved on, so the uncertainty in the current position increases
                variance += TimeInc_milliseconds * Q_metres_per_second * Q_metres_per_second / 1000;
                this->TimeStamp_milliseconds = TimeStamp_milliseconds;
                // TO DO: USE VELOCITY INFORMATION HERE TO GET A BETTER ESTIMATE OF CURRENT POSITION
            }

            // Kalman gain matrix K = Covarariance * Inverse(Covariance + MeasurementVariance)
            // NB: because K is dimensionless, it doesn't matter that variance has different units to lat and lng
            float K = variance / (variance + accuracy * accuracy);
            // apply K
            lat += K * (lat_measurement - lat);
            lng += K * (lng_measurement - lng);
            // new Covarariance  matrix is (IdentityMatrix - K) * Covarariance 
            variance = (1 - K) * variance;
        }
    }
};

class SiriusF9P_Rover {

protected:
    NMEAParser parser;
    GPSService gps;
    SerialPort my_serial_port;
    char* buffer;
    int position;

    int count_packets;
    int packet_to_receive;

    double output_packet[6];

    KalmanLatLong* kalmanFilt;

    bool useGNS;
    bool useGST;
    bool useZDA;
    bool useVTG;

public:
    SiriusF9P_Rover(std::string port, unsigned int baudRate, unsigned int flags)
    {
        gps.attachToParser(parser);

        kalmanFilt = new KalmanLatLong(1.0);

        // Handle events when the lock state changes
        /*
        gps.onLockStateChanged += [](bool newlock){
            if (newlock){
                cout << "\t\t\tGPS acquired LOCK!" << endl;
            }
            else {
                cout << "\t\t\tGPS lost lock. Searching..." << endl;
            }
        };
        */

        useGNS = (flags >> 0) & 1;
        useGST = (flags >> 1) & 1;
        useZDA = (flags >> 2) & 1;
        useVTG = (flags >> 3) & 1;

        packet_to_receive = useGNS + useGST;

        // (optional) - Handle events when the parser receives each sentence
        //parser.onSentence += [](const NMEASentence& n){
        //    cout << "Received " << (n.checksumOK() ? "good" : "bad") << " GPS Data: " << n.name << endl;
        //};

        my_serial_port.Open(port);

        if(baudRate == 115200)
            my_serial_port.SetBaudRate(LibSerial::BaudRate::BAUD_115200);
        else if(baudRate == 9600)
            my_serial_port.SetBaudRate(LibSerial::BaudRate::BAUD_9600);

        position = 0;
        buffer = new char[BUF_SIZE];

        count_packets = 0;
    }

    void disconnect() {
        my_serial_port.Close();
    }

    bool isPortOpen() {
        return my_serial_port.IsOpen();
    }

    void readPacket() {
        count_packets = 0;

        for(int i = 0; i < packet_to_receive; i++)
            readSerial();
    }

    void writePacket(const char* data, int size){
	    my_serial_port.Write(std::string(data, size));
    }

    void readSerial() {
        do{
            my_serial_port.ReadByte(buffer[position], 0);

            if (buffer[position] == '$'){
                for (int i = 0; i < position; i++) 
                    buffer[i] = '\0';
                buffer[0] = '$';
                position = 1;
            } else {
                ++position;
            }
        } while(buffer[position - 1] != '\n');

        try {
            if (buffer[0] == '$') {
                parser.readLine(buffer);
            }
        } catch (NMEAParseError &e) {
            cout << "Error in parsing: " << e.what() << endl;
        }

        for (int i = 0; i < position; i++) 
		    buffer[i] = '\0';
        position = 0;
    }

    void printStatus() {
        cout << gps.fix.toString() << endl;
    }

    double* getStatus() {
        std::time_t timestamp = std::time(nullptr);
        kalmanFilt->Process(gps.fix.latitude, gps.fix.longitude, gps.fix.stddev_latitude, timestamp);
        output_packet[0] = gps.fix.latitude;
        output_packet[1] = gps.fix.longitude;
        output_packet[2] = gps.fix.altitude;
        output_packet[3] = gps.fix.stddev_latitude;
        output_packet[4] = gps.fix.stddev_longitude;
        output_packet[5] = gps.fix.stddev_altitude;

        return output_packet;
    }

    GPSTimestamp getTimestamp() {
        return gps.fix.timestamp;
    }

    bool hasFix() {
        ofstream myFile("/home/user/debug.txt");
		myFile << gps.fix.status;
		myFile.close();
		return gps.fix.status == 'A' or gps.fix.status == 'D' or gps.fix.status == 'F' or gps.fix.status == 'R';
    }
};

#endif //MY_HAL_SIRIUS_FP9_ROVER
