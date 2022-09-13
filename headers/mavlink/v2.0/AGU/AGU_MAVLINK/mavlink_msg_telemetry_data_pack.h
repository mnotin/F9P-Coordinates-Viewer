#pragma once
// MESSAGE TELEMETRY_DATA_PACK PACKING

#define MAVLINK_MSG_ID_TELEMETRY_DATA_PACK 13001


typedef struct __mavlink_telemetry_data_pack_t {
 uint64_t Log_Timestamp; /*< [ms] Log timestamp since 1.1.1970 UTC.*/
 uint64_t GNSS_Timestamp; /*< [ms] GNSS Timestamp since 1.1.1970 UTC.*/
 int32_t Latitude; /*< [deg] Latitude 10^7*/
 int32_t Longitude; /*< [deg] Longitude 10^7*/
 uint32_t GNSS_Altitude; /*< [m] GNSS altitude 10^3*/
 int32_t Altitude_Main_Altimeter; /*< [m] Altitude from main radar altimeter 10^2*/
 int32_t Altitude_Payload_Altimeter; /*< [m] Altitude from payload radar altimeter 10^2*/
 float ECEF_Position_X; /*< [m] ECEF vector position X*/
 float ECEF_Position_Y; /*< [m] ECEF vector position Y*/
 float ECEF_Position_Z; /*< [m] ECEF vector position Z*/
 float ECEF_Velocity_X; /*< [m/s] ECEF vector velocity X*/
 float ECEF_Velocity_Y; /*< [m/s] ECEF vector velocity Y*/
 float ECEF_Velocity_Z; /*< [m/s] ECEF vector velocity Z*/
 float Quaternion_0; /*<  Quaternion[0]*/
 float Quaternion_1; /*<  Quaternion[1]*/
 float Quaternion_2; /*<  Quaternion[2]*/
 float Quaternion_3; /*<  Quaternion[3] Scalar component*/
 uint32_t Telemetry_Status_Mask; /*<  Telemetry module status mask*/
 int16_t Air_Speed_U; /*< [m/s] Air speed U vector 10^2*/
 int16_t Air_Speed_V; /*< [m/s] Air speed V vector 10^2*/
 int16_t Air_Speed_W; /*< [m/s] Air speed W vector 10^2*/
 int16_t Air_Temperature; /*< [°C] Air temperature 10^2*/
 uint16_t Velocity_Horizontal; /*< [m/s] Linear velocity horizontal 10^2*/
 int16_t Velocity_Vertical; /*< [m/s] Linear velocity vertical 10^2*/
 uint16_t Position_Accuracy; /*< [m] GNSS position accuracy 10^2*/
 uint16_t Speed_Accuracy; /*< [m/s] GNSS speed accuracy 10^2*/
 int16_t Acceleration_X; /*< [m/s^2] Linear acceleration X 10^2*/
 int16_t Acceleration_Y; /*< [m/s^2] Linear acceleration Y 10^2*/
 int16_t Acceleration_Z; /*< [m/s^2] Linear acceleration Z 10^2*/
 int16_t Roll_Angle; /*< [deg] Roll angle 10^2*/
 int16_t Pitch_Angle; /*< [deg] Pitch angle 10^2*/
 int16_t Yaw_Angle; /*< [deg] Yaw angle 10^2*/
 int16_t Angular_Rate_Roll; /*< [deg/s] Roll angle 10^2*/
 int16_t Angular_Rate_Pitch; /*< [deg/s] Pitch angle 10^2*/
 int16_t Angular_Rate_Yaw; /*< [deg/s] Yaw angle 10^2*/
 uint8_t Satellite_Num; /*<  Number of GPS satellite in view*/
} mavlink_telemetry_data_pack_t;

#define MAVLINK_MSG_ID_TELEMETRY_DATA_PACK_LEN 115
#define MAVLINK_MSG_ID_TELEMETRY_DATA_PACK_MIN_LEN 115
#define MAVLINK_MSG_ID_13001_LEN 115
#define MAVLINK_MSG_ID_13001_MIN_LEN 115

#define MAVLINK_MSG_ID_TELEMETRY_DATA_PACK_CRC 84
#define MAVLINK_MSG_ID_13001_CRC 84



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TELEMETRY_DATA_PACK { \
    13001, \
    "TELEMETRY_DATA_PACK", \
    36, \
    {  { "Log_Timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_telemetry_data_pack_t, Log_Timestamp) }, \
         { "GNSS_Timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 8, offsetof(mavlink_telemetry_data_pack_t, GNSS_Timestamp) }, \
         { "Latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_telemetry_data_pack_t, Latitude) }, \
         { "Longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 20, offsetof(mavlink_telemetry_data_pack_t, Longitude) }, \
         { "GNSS_Altitude", NULL, MAVLINK_TYPE_UINT32_T, 0, 24, offsetof(mavlink_telemetry_data_pack_t, GNSS_Altitude) }, \
         { "Air_Speed_U", NULL, MAVLINK_TYPE_INT16_T, 0, 80, offsetof(mavlink_telemetry_data_pack_t, Air_Speed_U) }, \
         { "Air_Speed_V", NULL, MAVLINK_TYPE_INT16_T, 0, 82, offsetof(mavlink_telemetry_data_pack_t, Air_Speed_V) }, \
         { "Air_Speed_W", NULL, MAVLINK_TYPE_INT16_T, 0, 84, offsetof(mavlink_telemetry_data_pack_t, Air_Speed_W) }, \
         { "Air_Temperature", NULL, MAVLINK_TYPE_INT16_T, 0, 86, offsetof(mavlink_telemetry_data_pack_t, Air_Temperature) }, \
         { "Altitude_Main_Altimeter", NULL, MAVLINK_TYPE_INT32_T, 0, 28, offsetof(mavlink_telemetry_data_pack_t, Altitude_Main_Altimeter) }, \
         { "Altitude_Payload_Altimeter", NULL, MAVLINK_TYPE_INT32_T, 0, 32, offsetof(mavlink_telemetry_data_pack_t, Altitude_Payload_Altimeter) }, \
         { "Velocity_Horizontal", NULL, MAVLINK_TYPE_UINT16_T, 0, 88, offsetof(mavlink_telemetry_data_pack_t, Velocity_Horizontal) }, \
         { "Velocity_Vertical", NULL, MAVLINK_TYPE_INT16_T, 0, 90, offsetof(mavlink_telemetry_data_pack_t, Velocity_Vertical) }, \
         { "Position_Accuracy", NULL, MAVLINK_TYPE_UINT16_T, 0, 92, offsetof(mavlink_telemetry_data_pack_t, Position_Accuracy) }, \
         { "Speed_Accuracy", NULL, MAVLINK_TYPE_UINT16_T, 0, 94, offsetof(mavlink_telemetry_data_pack_t, Speed_Accuracy) }, \
         { "Acceleration_X", NULL, MAVLINK_TYPE_INT16_T, 0, 96, offsetof(mavlink_telemetry_data_pack_t, Acceleration_X) }, \
         { "Acceleration_Y", NULL, MAVLINK_TYPE_INT16_T, 0, 98, offsetof(mavlink_telemetry_data_pack_t, Acceleration_Y) }, \
         { "Acceleration_Z", NULL, MAVLINK_TYPE_INT16_T, 0, 100, offsetof(mavlink_telemetry_data_pack_t, Acceleration_Z) }, \
         { "ECEF_Position_X", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_telemetry_data_pack_t, ECEF_Position_X) }, \
         { "ECEF_Position_Y", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_telemetry_data_pack_t, ECEF_Position_Y) }, \
         { "ECEF_Position_Z", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_telemetry_data_pack_t, ECEF_Position_Z) }, \
         { "ECEF_Velocity_X", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_telemetry_data_pack_t, ECEF_Velocity_X) }, \
         { "ECEF_Velocity_Y", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_telemetry_data_pack_t, ECEF_Velocity_Y) }, \
         { "ECEF_Velocity_Z", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_telemetry_data_pack_t, ECEF_Velocity_Z) }, \
         { "Roll_Angle", NULL, MAVLINK_TYPE_INT16_T, 0, 102, offsetof(mavlink_telemetry_data_pack_t, Roll_Angle) }, \
         { "Pitch_Angle", NULL, MAVLINK_TYPE_INT16_T, 0, 104, offsetof(mavlink_telemetry_data_pack_t, Pitch_Angle) }, \
         { "Yaw_Angle", NULL, MAVLINK_TYPE_INT16_T, 0, 106, offsetof(mavlink_telemetry_data_pack_t, Yaw_Angle) }, \
         { "Angular_Rate_Roll", NULL, MAVLINK_TYPE_INT16_T, 0, 108, offsetof(mavlink_telemetry_data_pack_t, Angular_Rate_Roll) }, \
         { "Angular_Rate_Pitch", NULL, MAVLINK_TYPE_INT16_T, 0, 110, offsetof(mavlink_telemetry_data_pack_t, Angular_Rate_Pitch) }, \
         { "Angular_Rate_Yaw", NULL, MAVLINK_TYPE_INT16_T, 0, 112, offsetof(mavlink_telemetry_data_pack_t, Angular_Rate_Yaw) }, \
         { "Quaternion_0", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_telemetry_data_pack_t, Quaternion_0) }, \
         { "Quaternion_1", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_telemetry_data_pack_t, Quaternion_1) }, \
         { "Quaternion_2", NULL, MAVLINK_TYPE_FLOAT, 0, 68, offsetof(mavlink_telemetry_data_pack_t, Quaternion_2) }, \
         { "Quaternion_3", NULL, MAVLINK_TYPE_FLOAT, 0, 72, offsetof(mavlink_telemetry_data_pack_t, Quaternion_3) }, \
         { "Telemetry_Status_Mask", NULL, MAVLINK_TYPE_UINT32_T, 0, 76, offsetof(mavlink_telemetry_data_pack_t, Telemetry_Status_Mask) }, \
         { "Satellite_Num", NULL, MAVLINK_TYPE_UINT8_T, 0, 114, offsetof(mavlink_telemetry_data_pack_t, Satellite_Num) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TELEMETRY_DATA_PACK { \
    "TELEMETRY_DATA_PACK", \
    36, \
    {  { "Log_Timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_telemetry_data_pack_t, Log_Timestamp) }, \
         { "GNSS_Timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 8, offsetof(mavlink_telemetry_data_pack_t, GNSS_Timestamp) }, \
         { "Latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_telemetry_data_pack_t, Latitude) }, \
         { "Longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 20, offsetof(mavlink_telemetry_data_pack_t, Longitude) }, \
         { "GNSS_Altitude", NULL, MAVLINK_TYPE_UINT32_T, 0, 24, offsetof(mavlink_telemetry_data_pack_t, GNSS_Altitude) }, \
         { "Air_Speed_U", NULL, MAVLINK_TYPE_INT16_T, 0, 80, offsetof(mavlink_telemetry_data_pack_t, Air_Speed_U) }, \
         { "Air_Speed_V", NULL, MAVLINK_TYPE_INT16_T, 0, 82, offsetof(mavlink_telemetry_data_pack_t, Air_Speed_V) }, \
         { "Air_Speed_W", NULL, MAVLINK_TYPE_INT16_T, 0, 84, offsetof(mavlink_telemetry_data_pack_t, Air_Speed_W) }, \
         { "Air_Temperature", NULL, MAVLINK_TYPE_INT16_T, 0, 86, offsetof(mavlink_telemetry_data_pack_t, Air_Temperature) }, \
         { "Altitude_Main_Altimeter", NULL, MAVLINK_TYPE_INT32_T, 0, 28, offsetof(mavlink_telemetry_data_pack_t, Altitude_Main_Altimeter) }, \
         { "Altitude_Payload_Altimeter", NULL, MAVLINK_TYPE_INT32_T, 0, 32, offsetof(mavlink_telemetry_data_pack_t, Altitude_Payload_Altimeter) }, \
         { "Velocity_Horizontal", NULL, MAVLINK_TYPE_UINT16_T, 0, 88, offsetof(mavlink_telemetry_data_pack_t, Velocity_Horizontal) }, \
         { "Velocity_Vertical", NULL, MAVLINK_TYPE_INT16_T, 0, 90, offsetof(mavlink_telemetry_data_pack_t, Velocity_Vertical) }, \
         { "Position_Accuracy", NULL, MAVLINK_TYPE_UINT16_T, 0, 92, offsetof(mavlink_telemetry_data_pack_t, Position_Accuracy) }, \
         { "Speed_Accuracy", NULL, MAVLINK_TYPE_UINT16_T, 0, 94, offsetof(mavlink_telemetry_data_pack_t, Speed_Accuracy) }, \
         { "Acceleration_X", NULL, MAVLINK_TYPE_INT16_T, 0, 96, offsetof(mavlink_telemetry_data_pack_t, Acceleration_X) }, \
         { "Acceleration_Y", NULL, MAVLINK_TYPE_INT16_T, 0, 98, offsetof(mavlink_telemetry_data_pack_t, Acceleration_Y) }, \
         { "Acceleration_Z", NULL, MAVLINK_TYPE_INT16_T, 0, 100, offsetof(mavlink_telemetry_data_pack_t, Acceleration_Z) }, \
         { "ECEF_Position_X", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_telemetry_data_pack_t, ECEF_Position_X) }, \
         { "ECEF_Position_Y", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_telemetry_data_pack_t, ECEF_Position_Y) }, \
         { "ECEF_Position_Z", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_telemetry_data_pack_t, ECEF_Position_Z) }, \
         { "ECEF_Velocity_X", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_telemetry_data_pack_t, ECEF_Velocity_X) }, \
         { "ECEF_Velocity_Y", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_telemetry_data_pack_t, ECEF_Velocity_Y) }, \
         { "ECEF_Velocity_Z", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_telemetry_data_pack_t, ECEF_Velocity_Z) }, \
         { "Roll_Angle", NULL, MAVLINK_TYPE_INT16_T, 0, 102, offsetof(mavlink_telemetry_data_pack_t, Roll_Angle) }, \
         { "Pitch_Angle", NULL, MAVLINK_TYPE_INT16_T, 0, 104, offsetof(mavlink_telemetry_data_pack_t, Pitch_Angle) }, \
         { "Yaw_Angle", NULL, MAVLINK_TYPE_INT16_T, 0, 106, offsetof(mavlink_telemetry_data_pack_t, Yaw_Angle) }, \
         { "Angular_Rate_Roll", NULL, MAVLINK_TYPE_INT16_T, 0, 108, offsetof(mavlink_telemetry_data_pack_t, Angular_Rate_Roll) }, \
         { "Angular_Rate_Pitch", NULL, MAVLINK_TYPE_INT16_T, 0, 110, offsetof(mavlink_telemetry_data_pack_t, Angular_Rate_Pitch) }, \
         { "Angular_Rate_Yaw", NULL, MAVLINK_TYPE_INT16_T, 0, 112, offsetof(mavlink_telemetry_data_pack_t, Angular_Rate_Yaw) }, \
         { "Quaternion_0", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_telemetry_data_pack_t, Quaternion_0) }, \
         { "Quaternion_1", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_telemetry_data_pack_t, Quaternion_1) }, \
         { "Quaternion_2", NULL, MAVLINK_TYPE_FLOAT, 0, 68, offsetof(mavlink_telemetry_data_pack_t, Quaternion_2) }, \
         { "Quaternion_3", NULL, MAVLINK_TYPE_FLOAT, 0, 72, offsetof(mavlink_telemetry_data_pack_t, Quaternion_3) }, \
         { "Telemetry_Status_Mask", NULL, MAVLINK_TYPE_UINT32_T, 0, 76, offsetof(mavlink_telemetry_data_pack_t, Telemetry_Status_Mask) }, \
         { "Satellite_Num", NULL, MAVLINK_TYPE_UINT8_T, 0, 114, offsetof(mavlink_telemetry_data_pack_t, Satellite_Num) }, \
         } \
}
#endif

/**
 * @brief Pack a telemetry_data_pack message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param Log_Timestamp [ms] Log timestamp since 1.1.1970 UTC.
 * @param GNSS_Timestamp [ms] GNSS Timestamp since 1.1.1970 UTC.
 * @param Latitude [deg] Latitude 10^7
 * @param Longitude [deg] Longitude 10^7
 * @param GNSS_Altitude [m] GNSS altitude 10^3
 * @param Air_Speed_U [m/s] Air speed U vector 10^2
 * @param Air_Speed_V [m/s] Air speed V vector 10^2
 * @param Air_Speed_W [m/s] Air speed W vector 10^2
 * @param Air_Temperature [°C] Air temperature 10^2
 * @param Altitude_Main_Altimeter [m] Altitude from main radar altimeter 10^2
 * @param Altitude_Payload_Altimeter [m] Altitude from payload radar altimeter 10^2
 * @param Velocity_Horizontal [m/s] Linear velocity horizontal 10^2
 * @param Velocity_Vertical [m/s] Linear velocity vertical 10^2
 * @param Position_Accuracy [m] GNSS position accuracy 10^2
 * @param Speed_Accuracy [m/s] GNSS speed accuracy 10^2
 * @param Acceleration_X [m/s^2] Linear acceleration X 10^2
 * @param Acceleration_Y [m/s^2] Linear acceleration Y 10^2
 * @param Acceleration_Z [m/s^2] Linear acceleration Z 10^2
 * @param ECEF_Position_X [m] ECEF vector position X
 * @param ECEF_Position_Y [m] ECEF vector position Y
 * @param ECEF_Position_Z [m] ECEF vector position Z
 * @param ECEF_Velocity_X [m/s] ECEF vector velocity X
 * @param ECEF_Velocity_Y [m/s] ECEF vector velocity Y
 * @param ECEF_Velocity_Z [m/s] ECEF vector velocity Z
 * @param Roll_Angle [deg] Roll angle 10^2
 * @param Pitch_Angle [deg] Pitch angle 10^2
 * @param Yaw_Angle [deg] Yaw angle 10^2
 * @param Angular_Rate_Roll [deg/s] Roll angle 10^2
 * @param Angular_Rate_Pitch [deg/s] Pitch angle 10^2
 * @param Angular_Rate_Yaw [deg/s] Yaw angle 10^2
 * @param Quaternion_0  Quaternion[0]
 * @param Quaternion_1  Quaternion[1]
 * @param Quaternion_2  Quaternion[2]
 * @param Quaternion_3  Quaternion[3] Scalar component
 * @param Telemetry_Status_Mask  Telemetry module status mask
 * @param Satellite_Num  Number of GPS satellite in view
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_telemetry_data_pack_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t Log_Timestamp, uint64_t GNSS_Timestamp, int32_t Latitude, int32_t Longitude, uint32_t GNSS_Altitude, int16_t Air_Speed_U, int16_t Air_Speed_V, int16_t Air_Speed_W, int16_t Air_Temperature, int32_t Altitude_Main_Altimeter, int32_t Altitude_Payload_Altimeter, uint16_t Velocity_Horizontal, int16_t Velocity_Vertical, uint16_t Position_Accuracy, uint16_t Speed_Accuracy, int16_t Acceleration_X, int16_t Acceleration_Y, int16_t Acceleration_Z, float ECEF_Position_X, float ECEF_Position_Y, float ECEF_Position_Z, float ECEF_Velocity_X, float ECEF_Velocity_Y, float ECEF_Velocity_Z, int16_t Roll_Angle, int16_t Pitch_Angle, int16_t Yaw_Angle, int16_t Angular_Rate_Roll, int16_t Angular_Rate_Pitch, int16_t Angular_Rate_Yaw, float Quaternion_0, float Quaternion_1, float Quaternion_2, float Quaternion_3, uint32_t Telemetry_Status_Mask, uint8_t Satellite_Num)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TELEMETRY_DATA_PACK_LEN];
    _mav_put_uint64_t(buf, 0, Log_Timestamp);
    _mav_put_uint64_t(buf, 8, GNSS_Timestamp);
    _mav_put_int32_t(buf, 16, Latitude);
    _mav_put_int32_t(buf, 20, Longitude);
    _mav_put_uint32_t(buf, 24, GNSS_Altitude);
    _mav_put_int32_t(buf, 28, Altitude_Main_Altimeter);
    _mav_put_int32_t(buf, 32, Altitude_Payload_Altimeter);
    _mav_put_float(buf, 36, ECEF_Position_X);
    _mav_put_float(buf, 40, ECEF_Position_Y);
    _mav_put_float(buf, 44, ECEF_Position_Z);
    _mav_put_float(buf, 48, ECEF_Velocity_X);
    _mav_put_float(buf, 52, ECEF_Velocity_Y);
    _mav_put_float(buf, 56, ECEF_Velocity_Z);
    _mav_put_float(buf, 60, Quaternion_0);
    _mav_put_float(buf, 64, Quaternion_1);
    _mav_put_float(buf, 68, Quaternion_2);
    _mav_put_float(buf, 72, Quaternion_3);
    _mav_put_uint32_t(buf, 76, Telemetry_Status_Mask);
    _mav_put_int16_t(buf, 80, Air_Speed_U);
    _mav_put_int16_t(buf, 82, Air_Speed_V);
    _mav_put_int16_t(buf, 84, Air_Speed_W);
    _mav_put_int16_t(buf, 86, Air_Temperature);
    _mav_put_uint16_t(buf, 88, Velocity_Horizontal);
    _mav_put_int16_t(buf, 90, Velocity_Vertical);
    _mav_put_uint16_t(buf, 92, Position_Accuracy);
    _mav_put_uint16_t(buf, 94, Speed_Accuracy);
    _mav_put_int16_t(buf, 96, Acceleration_X);
    _mav_put_int16_t(buf, 98, Acceleration_Y);
    _mav_put_int16_t(buf, 100, Acceleration_Z);
    _mav_put_int16_t(buf, 102, Roll_Angle);
    _mav_put_int16_t(buf, 104, Pitch_Angle);
    _mav_put_int16_t(buf, 106, Yaw_Angle);
    _mav_put_int16_t(buf, 108, Angular_Rate_Roll);
    _mav_put_int16_t(buf, 110, Angular_Rate_Pitch);
    _mav_put_int16_t(buf, 112, Angular_Rate_Yaw);
    _mav_put_uint8_t(buf, 114, Satellite_Num);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TELEMETRY_DATA_PACK_LEN);
#else
    mavlink_telemetry_data_pack_t packet;
    packet.Log_Timestamp = Log_Timestamp;
    packet.GNSS_Timestamp = GNSS_Timestamp;
    packet.Latitude = Latitude;
    packet.Longitude = Longitude;
    packet.GNSS_Altitude = GNSS_Altitude;
    packet.Altitude_Main_Altimeter = Altitude_Main_Altimeter;
    packet.Altitude_Payload_Altimeter = Altitude_Payload_Altimeter;
    packet.ECEF_Position_X = ECEF_Position_X;
    packet.ECEF_Position_Y = ECEF_Position_Y;
    packet.ECEF_Position_Z = ECEF_Position_Z;
    packet.ECEF_Velocity_X = ECEF_Velocity_X;
    packet.ECEF_Velocity_Y = ECEF_Velocity_Y;
    packet.ECEF_Velocity_Z = ECEF_Velocity_Z;
    packet.Quaternion_0 = Quaternion_0;
    packet.Quaternion_1 = Quaternion_1;
    packet.Quaternion_2 = Quaternion_2;
    packet.Quaternion_3 = Quaternion_3;
    packet.Telemetry_Status_Mask = Telemetry_Status_Mask;
    packet.Air_Speed_U = Air_Speed_U;
    packet.Air_Speed_V = Air_Speed_V;
    packet.Air_Speed_W = Air_Speed_W;
    packet.Air_Temperature = Air_Temperature;
    packet.Velocity_Horizontal = Velocity_Horizontal;
    packet.Velocity_Vertical = Velocity_Vertical;
    packet.Position_Accuracy = Position_Accuracy;
    packet.Speed_Accuracy = Speed_Accuracy;
    packet.Acceleration_X = Acceleration_X;
    packet.Acceleration_Y = Acceleration_Y;
    packet.Acceleration_Z = Acceleration_Z;
    packet.Roll_Angle = Roll_Angle;
    packet.Pitch_Angle = Pitch_Angle;
    packet.Yaw_Angle = Yaw_Angle;
    packet.Angular_Rate_Roll = Angular_Rate_Roll;
    packet.Angular_Rate_Pitch = Angular_Rate_Pitch;
    packet.Angular_Rate_Yaw = Angular_Rate_Yaw;
    packet.Satellite_Num = Satellite_Num;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TELEMETRY_DATA_PACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TELEMETRY_DATA_PACK;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TELEMETRY_DATA_PACK_MIN_LEN, MAVLINK_MSG_ID_TELEMETRY_DATA_PACK_LEN, MAVLINK_MSG_ID_TELEMETRY_DATA_PACK_CRC);
}

/**
 * @brief Pack a telemetry_data_pack message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param Log_Timestamp [ms] Log timestamp since 1.1.1970 UTC.
 * @param GNSS_Timestamp [ms] GNSS Timestamp since 1.1.1970 UTC.
 * @param Latitude [deg] Latitude 10^7
 * @param Longitude [deg] Longitude 10^7
 * @param GNSS_Altitude [m] GNSS altitude 10^3
 * @param Air_Speed_U [m/s] Air speed U vector 10^2
 * @param Air_Speed_V [m/s] Air speed V vector 10^2
 * @param Air_Speed_W [m/s] Air speed W vector 10^2
 * @param Air_Temperature [°C] Air temperature 10^2
 * @param Altitude_Main_Altimeter [m] Altitude from main radar altimeter 10^2
 * @param Altitude_Payload_Altimeter [m] Altitude from payload radar altimeter 10^2
 * @param Velocity_Horizontal [m/s] Linear velocity horizontal 10^2
 * @param Velocity_Vertical [m/s] Linear velocity vertical 10^2
 * @param Position_Accuracy [m] GNSS position accuracy 10^2
 * @param Speed_Accuracy [m/s] GNSS speed accuracy 10^2
 * @param Acceleration_X [m/s^2] Linear acceleration X 10^2
 * @param Acceleration_Y [m/s^2] Linear acceleration Y 10^2
 * @param Acceleration_Z [m/s^2] Linear acceleration Z 10^2
 * @param ECEF_Position_X [m] ECEF vector position X
 * @param ECEF_Position_Y [m] ECEF vector position Y
 * @param ECEF_Position_Z [m] ECEF vector position Z
 * @param ECEF_Velocity_X [m/s] ECEF vector velocity X
 * @param ECEF_Velocity_Y [m/s] ECEF vector velocity Y
 * @param ECEF_Velocity_Z [m/s] ECEF vector velocity Z
 * @param Roll_Angle [deg] Roll angle 10^2
 * @param Pitch_Angle [deg] Pitch angle 10^2
 * @param Yaw_Angle [deg] Yaw angle 10^2
 * @param Angular_Rate_Roll [deg/s] Roll angle 10^2
 * @param Angular_Rate_Pitch [deg/s] Pitch angle 10^2
 * @param Angular_Rate_Yaw [deg/s] Yaw angle 10^2
 * @param Quaternion_0  Quaternion[0]
 * @param Quaternion_1  Quaternion[1]
 * @param Quaternion_2  Quaternion[2]
 * @param Quaternion_3  Quaternion[3] Scalar component
 * @param Telemetry_Status_Mask  Telemetry module status mask
 * @param Satellite_Num  Number of GPS satellite in view
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_telemetry_data_pack_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t Log_Timestamp,uint64_t GNSS_Timestamp,int32_t Latitude,int32_t Longitude,uint32_t GNSS_Altitude,int16_t Air_Speed_U,int16_t Air_Speed_V,int16_t Air_Speed_W,int16_t Air_Temperature,int32_t Altitude_Main_Altimeter,int32_t Altitude_Payload_Altimeter,uint16_t Velocity_Horizontal,int16_t Velocity_Vertical,uint16_t Position_Accuracy,uint16_t Speed_Accuracy,int16_t Acceleration_X,int16_t Acceleration_Y,int16_t Acceleration_Z,float ECEF_Position_X,float ECEF_Position_Y,float ECEF_Position_Z,float ECEF_Velocity_X,float ECEF_Velocity_Y,float ECEF_Velocity_Z,int16_t Roll_Angle,int16_t Pitch_Angle,int16_t Yaw_Angle,int16_t Angular_Rate_Roll,int16_t Angular_Rate_Pitch,int16_t Angular_Rate_Yaw,float Quaternion_0,float Quaternion_1,float Quaternion_2,float Quaternion_3,uint32_t Telemetry_Status_Mask,uint8_t Satellite_Num)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TELEMETRY_DATA_PACK_LEN];
    _mav_put_uint64_t(buf, 0, Log_Timestamp);
    _mav_put_uint64_t(buf, 8, GNSS_Timestamp);
    _mav_put_int32_t(buf, 16, Latitude);
    _mav_put_int32_t(buf, 20, Longitude);
    _mav_put_uint32_t(buf, 24, GNSS_Altitude);
    _mav_put_int32_t(buf, 28, Altitude_Main_Altimeter);
    _mav_put_int32_t(buf, 32, Altitude_Payload_Altimeter);
    _mav_put_float(buf, 36, ECEF_Position_X);
    _mav_put_float(buf, 40, ECEF_Position_Y);
    _mav_put_float(buf, 44, ECEF_Position_Z);
    _mav_put_float(buf, 48, ECEF_Velocity_X);
    _mav_put_float(buf, 52, ECEF_Velocity_Y);
    _mav_put_float(buf, 56, ECEF_Velocity_Z);
    _mav_put_float(buf, 60, Quaternion_0);
    _mav_put_float(buf, 64, Quaternion_1);
    _mav_put_float(buf, 68, Quaternion_2);
    _mav_put_float(buf, 72, Quaternion_3);
    _mav_put_uint32_t(buf, 76, Telemetry_Status_Mask);
    _mav_put_int16_t(buf, 80, Air_Speed_U);
    _mav_put_int16_t(buf, 82, Air_Speed_V);
    _mav_put_int16_t(buf, 84, Air_Speed_W);
    _mav_put_int16_t(buf, 86, Air_Temperature);
    _mav_put_uint16_t(buf, 88, Velocity_Horizontal);
    _mav_put_int16_t(buf, 90, Velocity_Vertical);
    _mav_put_uint16_t(buf, 92, Position_Accuracy);
    _mav_put_uint16_t(buf, 94, Speed_Accuracy);
    _mav_put_int16_t(buf, 96, Acceleration_X);
    _mav_put_int16_t(buf, 98, Acceleration_Y);
    _mav_put_int16_t(buf, 100, Acceleration_Z);
    _mav_put_int16_t(buf, 102, Roll_Angle);
    _mav_put_int16_t(buf, 104, Pitch_Angle);
    _mav_put_int16_t(buf, 106, Yaw_Angle);
    _mav_put_int16_t(buf, 108, Angular_Rate_Roll);
    _mav_put_int16_t(buf, 110, Angular_Rate_Pitch);
    _mav_put_int16_t(buf, 112, Angular_Rate_Yaw);
    _mav_put_uint8_t(buf, 114, Satellite_Num);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TELEMETRY_DATA_PACK_LEN);
#else
    mavlink_telemetry_data_pack_t packet;
    packet.Log_Timestamp = Log_Timestamp;
    packet.GNSS_Timestamp = GNSS_Timestamp;
    packet.Latitude = Latitude;
    packet.Longitude = Longitude;
    packet.GNSS_Altitude = GNSS_Altitude;
    packet.Altitude_Main_Altimeter = Altitude_Main_Altimeter;
    packet.Altitude_Payload_Altimeter = Altitude_Payload_Altimeter;
    packet.ECEF_Position_X = ECEF_Position_X;
    packet.ECEF_Position_Y = ECEF_Position_Y;
    packet.ECEF_Position_Z = ECEF_Position_Z;
    packet.ECEF_Velocity_X = ECEF_Velocity_X;
    packet.ECEF_Velocity_Y = ECEF_Velocity_Y;
    packet.ECEF_Velocity_Z = ECEF_Velocity_Z;
    packet.Quaternion_0 = Quaternion_0;
    packet.Quaternion_1 = Quaternion_1;
    packet.Quaternion_2 = Quaternion_2;
    packet.Quaternion_3 = Quaternion_3;
    packet.Telemetry_Status_Mask = Telemetry_Status_Mask;
    packet.Air_Speed_U = Air_Speed_U;
    packet.Air_Speed_V = Air_Speed_V;
    packet.Air_Speed_W = Air_Speed_W;
    packet.Air_Temperature = Air_Temperature;
    packet.Velocity_Horizontal = Velocity_Horizontal;
    packet.Velocity_Vertical = Velocity_Vertical;
    packet.Position_Accuracy = Position_Accuracy;
    packet.Speed_Accuracy = Speed_Accuracy;
    packet.Acceleration_X = Acceleration_X;
    packet.Acceleration_Y = Acceleration_Y;
    packet.Acceleration_Z = Acceleration_Z;
    packet.Roll_Angle = Roll_Angle;
    packet.Pitch_Angle = Pitch_Angle;
    packet.Yaw_Angle = Yaw_Angle;
    packet.Angular_Rate_Roll = Angular_Rate_Roll;
    packet.Angular_Rate_Pitch = Angular_Rate_Pitch;
    packet.Angular_Rate_Yaw = Angular_Rate_Yaw;
    packet.Satellite_Num = Satellite_Num;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TELEMETRY_DATA_PACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TELEMETRY_DATA_PACK;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TELEMETRY_DATA_PACK_MIN_LEN, MAVLINK_MSG_ID_TELEMETRY_DATA_PACK_LEN, MAVLINK_MSG_ID_TELEMETRY_DATA_PACK_CRC);
}

/**
 * @brief Encode a telemetry_data_pack struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param telemetry_data_pack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_telemetry_data_pack_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_telemetry_data_pack_t* telemetry_data_pack)
{
    return mavlink_msg_telemetry_data_pack_pack(system_id, component_id, msg, telemetry_data_pack->Log_Timestamp, telemetry_data_pack->GNSS_Timestamp, telemetry_data_pack->Latitude, telemetry_data_pack->Longitude, telemetry_data_pack->GNSS_Altitude, telemetry_data_pack->Air_Speed_U, telemetry_data_pack->Air_Speed_V, telemetry_data_pack->Air_Speed_W, telemetry_data_pack->Air_Temperature, telemetry_data_pack->Altitude_Main_Altimeter, telemetry_data_pack->Altitude_Payload_Altimeter, telemetry_data_pack->Velocity_Horizontal, telemetry_data_pack->Velocity_Vertical, telemetry_data_pack->Position_Accuracy, telemetry_data_pack->Speed_Accuracy, telemetry_data_pack->Acceleration_X, telemetry_data_pack->Acceleration_Y, telemetry_data_pack->Acceleration_Z, telemetry_data_pack->ECEF_Position_X, telemetry_data_pack->ECEF_Position_Y, telemetry_data_pack->ECEF_Position_Z, telemetry_data_pack->ECEF_Velocity_X, telemetry_data_pack->ECEF_Velocity_Y, telemetry_data_pack->ECEF_Velocity_Z, telemetry_data_pack->Roll_Angle, telemetry_data_pack->Pitch_Angle, telemetry_data_pack->Yaw_Angle, telemetry_data_pack->Angular_Rate_Roll, telemetry_data_pack->Angular_Rate_Pitch, telemetry_data_pack->Angular_Rate_Yaw, telemetry_data_pack->Quaternion_0, telemetry_data_pack->Quaternion_1, telemetry_data_pack->Quaternion_2, telemetry_data_pack->Quaternion_3, telemetry_data_pack->Telemetry_Status_Mask, telemetry_data_pack->Satellite_Num);
}

/**
 * @brief Encode a telemetry_data_pack struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param telemetry_data_pack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_telemetry_data_pack_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_telemetry_data_pack_t* telemetry_data_pack)
{
    return mavlink_msg_telemetry_data_pack_pack_chan(system_id, component_id, chan, msg, telemetry_data_pack->Log_Timestamp, telemetry_data_pack->GNSS_Timestamp, telemetry_data_pack->Latitude, telemetry_data_pack->Longitude, telemetry_data_pack->GNSS_Altitude, telemetry_data_pack->Air_Speed_U, telemetry_data_pack->Air_Speed_V, telemetry_data_pack->Air_Speed_W, telemetry_data_pack->Air_Temperature, telemetry_data_pack->Altitude_Main_Altimeter, telemetry_data_pack->Altitude_Payload_Altimeter, telemetry_data_pack->Velocity_Horizontal, telemetry_data_pack->Velocity_Vertical, telemetry_data_pack->Position_Accuracy, telemetry_data_pack->Speed_Accuracy, telemetry_data_pack->Acceleration_X, telemetry_data_pack->Acceleration_Y, telemetry_data_pack->Acceleration_Z, telemetry_data_pack->ECEF_Position_X, telemetry_data_pack->ECEF_Position_Y, telemetry_data_pack->ECEF_Position_Z, telemetry_data_pack->ECEF_Velocity_X, telemetry_data_pack->ECEF_Velocity_Y, telemetry_data_pack->ECEF_Velocity_Z, telemetry_data_pack->Roll_Angle, telemetry_data_pack->Pitch_Angle, telemetry_data_pack->Yaw_Angle, telemetry_data_pack->Angular_Rate_Roll, telemetry_data_pack->Angular_Rate_Pitch, telemetry_data_pack->Angular_Rate_Yaw, telemetry_data_pack->Quaternion_0, telemetry_data_pack->Quaternion_1, telemetry_data_pack->Quaternion_2, telemetry_data_pack->Quaternion_3, telemetry_data_pack->Telemetry_Status_Mask, telemetry_data_pack->Satellite_Num);
}

/**
 * @brief Send a telemetry_data_pack message
 * @param chan MAVLink channel to send the message
 *
 * @param Log_Timestamp [ms] Log timestamp since 1.1.1970 UTC.
 * @param GNSS_Timestamp [ms] GNSS Timestamp since 1.1.1970 UTC.
 * @param Latitude [deg] Latitude 10^7
 * @param Longitude [deg] Longitude 10^7
 * @param GNSS_Altitude [m] GNSS altitude 10^3
 * @param Air_Speed_U [m/s] Air speed U vector 10^2
 * @param Air_Speed_V [m/s] Air speed V vector 10^2
 * @param Air_Speed_W [m/s] Air speed W vector 10^2
 * @param Air_Temperature [°C] Air temperature 10^2
 * @param Altitude_Main_Altimeter [m] Altitude from main radar altimeter 10^2
 * @param Altitude_Payload_Altimeter [m] Altitude from payload radar altimeter 10^2
 * @param Velocity_Horizontal [m/s] Linear velocity horizontal 10^2
 * @param Velocity_Vertical [m/s] Linear velocity vertical 10^2
 * @param Position_Accuracy [m] GNSS position accuracy 10^2
 * @param Speed_Accuracy [m/s] GNSS speed accuracy 10^2
 * @param Acceleration_X [m/s^2] Linear acceleration X 10^2
 * @param Acceleration_Y [m/s^2] Linear acceleration Y 10^2
 * @param Acceleration_Z [m/s^2] Linear acceleration Z 10^2
 * @param ECEF_Position_X [m] ECEF vector position X
 * @param ECEF_Position_Y [m] ECEF vector position Y
 * @param ECEF_Position_Z [m] ECEF vector position Z
 * @param ECEF_Velocity_X [m/s] ECEF vector velocity X
 * @param ECEF_Velocity_Y [m/s] ECEF vector velocity Y
 * @param ECEF_Velocity_Z [m/s] ECEF vector velocity Z
 * @param Roll_Angle [deg] Roll angle 10^2
 * @param Pitch_Angle [deg] Pitch angle 10^2
 * @param Yaw_Angle [deg] Yaw angle 10^2
 * @param Angular_Rate_Roll [deg/s] Roll angle 10^2
 * @param Angular_Rate_Pitch [deg/s] Pitch angle 10^2
 * @param Angular_Rate_Yaw [deg/s] Yaw angle 10^2
 * @param Quaternion_0  Quaternion[0]
 * @param Quaternion_1  Quaternion[1]
 * @param Quaternion_2  Quaternion[2]
 * @param Quaternion_3  Quaternion[3] Scalar component
 * @param Telemetry_Status_Mask  Telemetry module status mask
 * @param Satellite_Num  Number of GPS satellite in view
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_telemetry_data_pack_send(mavlink_channel_t chan, uint64_t Log_Timestamp, uint64_t GNSS_Timestamp, int32_t Latitude, int32_t Longitude, uint32_t GNSS_Altitude, int16_t Air_Speed_U, int16_t Air_Speed_V, int16_t Air_Speed_W, int16_t Air_Temperature, int32_t Altitude_Main_Altimeter, int32_t Altitude_Payload_Altimeter, uint16_t Velocity_Horizontal, int16_t Velocity_Vertical, uint16_t Position_Accuracy, uint16_t Speed_Accuracy, int16_t Acceleration_X, int16_t Acceleration_Y, int16_t Acceleration_Z, float ECEF_Position_X, float ECEF_Position_Y, float ECEF_Position_Z, float ECEF_Velocity_X, float ECEF_Velocity_Y, float ECEF_Velocity_Z, int16_t Roll_Angle, int16_t Pitch_Angle, int16_t Yaw_Angle, int16_t Angular_Rate_Roll, int16_t Angular_Rate_Pitch, int16_t Angular_Rate_Yaw, float Quaternion_0, float Quaternion_1, float Quaternion_2, float Quaternion_3, uint32_t Telemetry_Status_Mask, uint8_t Satellite_Num)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TELEMETRY_DATA_PACK_LEN];
    _mav_put_uint64_t(buf, 0, Log_Timestamp);
    _mav_put_uint64_t(buf, 8, GNSS_Timestamp);
    _mav_put_int32_t(buf, 16, Latitude);
    _mav_put_int32_t(buf, 20, Longitude);
    _mav_put_uint32_t(buf, 24, GNSS_Altitude);
    _mav_put_int32_t(buf, 28, Altitude_Main_Altimeter);
    _mav_put_int32_t(buf, 32, Altitude_Payload_Altimeter);
    _mav_put_float(buf, 36, ECEF_Position_X);
    _mav_put_float(buf, 40, ECEF_Position_Y);
    _mav_put_float(buf, 44, ECEF_Position_Z);
    _mav_put_float(buf, 48, ECEF_Velocity_X);
    _mav_put_float(buf, 52, ECEF_Velocity_Y);
    _mav_put_float(buf, 56, ECEF_Velocity_Z);
    _mav_put_float(buf, 60, Quaternion_0);
    _mav_put_float(buf, 64, Quaternion_1);
    _mav_put_float(buf, 68, Quaternion_2);
    _mav_put_float(buf, 72, Quaternion_3);
    _mav_put_uint32_t(buf, 76, Telemetry_Status_Mask);
    _mav_put_int16_t(buf, 80, Air_Speed_U);
    _mav_put_int16_t(buf, 82, Air_Speed_V);
    _mav_put_int16_t(buf, 84, Air_Speed_W);
    _mav_put_int16_t(buf, 86, Air_Temperature);
    _mav_put_uint16_t(buf, 88, Velocity_Horizontal);
    _mav_put_int16_t(buf, 90, Velocity_Vertical);
    _mav_put_uint16_t(buf, 92, Position_Accuracy);
    _mav_put_uint16_t(buf, 94, Speed_Accuracy);
    _mav_put_int16_t(buf, 96, Acceleration_X);
    _mav_put_int16_t(buf, 98, Acceleration_Y);
    _mav_put_int16_t(buf, 100, Acceleration_Z);
    _mav_put_int16_t(buf, 102, Roll_Angle);
    _mav_put_int16_t(buf, 104, Pitch_Angle);
    _mav_put_int16_t(buf, 106, Yaw_Angle);
    _mav_put_int16_t(buf, 108, Angular_Rate_Roll);
    _mav_put_int16_t(buf, 110, Angular_Rate_Pitch);
    _mav_put_int16_t(buf, 112, Angular_Rate_Yaw);
    _mav_put_uint8_t(buf, 114, Satellite_Num);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TELEMETRY_DATA_PACK, buf, MAVLINK_MSG_ID_TELEMETRY_DATA_PACK_MIN_LEN, MAVLINK_MSG_ID_TELEMETRY_DATA_PACK_LEN, MAVLINK_MSG_ID_TELEMETRY_DATA_PACK_CRC);
#else
    mavlink_telemetry_data_pack_t packet;
    packet.Log_Timestamp = Log_Timestamp;
    packet.GNSS_Timestamp = GNSS_Timestamp;
    packet.Latitude = Latitude;
    packet.Longitude = Longitude;
    packet.GNSS_Altitude = GNSS_Altitude;
    packet.Altitude_Main_Altimeter = Altitude_Main_Altimeter;
    packet.Altitude_Payload_Altimeter = Altitude_Payload_Altimeter;
    packet.ECEF_Position_X = ECEF_Position_X;
    packet.ECEF_Position_Y = ECEF_Position_Y;
    packet.ECEF_Position_Z = ECEF_Position_Z;
    packet.ECEF_Velocity_X = ECEF_Velocity_X;
    packet.ECEF_Velocity_Y = ECEF_Velocity_Y;
    packet.ECEF_Velocity_Z = ECEF_Velocity_Z;
    packet.Quaternion_0 = Quaternion_0;
    packet.Quaternion_1 = Quaternion_1;
    packet.Quaternion_2 = Quaternion_2;
    packet.Quaternion_3 = Quaternion_3;
    packet.Telemetry_Status_Mask = Telemetry_Status_Mask;
    packet.Air_Speed_U = Air_Speed_U;
    packet.Air_Speed_V = Air_Speed_V;
    packet.Air_Speed_W = Air_Speed_W;
    packet.Air_Temperature = Air_Temperature;
    packet.Velocity_Horizontal = Velocity_Horizontal;
    packet.Velocity_Vertical = Velocity_Vertical;
    packet.Position_Accuracy = Position_Accuracy;
    packet.Speed_Accuracy = Speed_Accuracy;
    packet.Acceleration_X = Acceleration_X;
    packet.Acceleration_Y = Acceleration_Y;
    packet.Acceleration_Z = Acceleration_Z;
    packet.Roll_Angle = Roll_Angle;
    packet.Pitch_Angle = Pitch_Angle;
    packet.Yaw_Angle = Yaw_Angle;
    packet.Angular_Rate_Roll = Angular_Rate_Roll;
    packet.Angular_Rate_Pitch = Angular_Rate_Pitch;
    packet.Angular_Rate_Yaw = Angular_Rate_Yaw;
    packet.Satellite_Num = Satellite_Num;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TELEMETRY_DATA_PACK, (const char *)&packet, MAVLINK_MSG_ID_TELEMETRY_DATA_PACK_MIN_LEN, MAVLINK_MSG_ID_TELEMETRY_DATA_PACK_LEN, MAVLINK_MSG_ID_TELEMETRY_DATA_PACK_CRC);
#endif
}

/**
 * @brief Send a telemetry_data_pack message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_telemetry_data_pack_send_struct(mavlink_channel_t chan, const mavlink_telemetry_data_pack_t* telemetry_data_pack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_telemetry_data_pack_send(chan, telemetry_data_pack->Log_Timestamp, telemetry_data_pack->GNSS_Timestamp, telemetry_data_pack->Latitude, telemetry_data_pack->Longitude, telemetry_data_pack->GNSS_Altitude, telemetry_data_pack->Air_Speed_U, telemetry_data_pack->Air_Speed_V, telemetry_data_pack->Air_Speed_W, telemetry_data_pack->Air_Temperature, telemetry_data_pack->Altitude_Main_Altimeter, telemetry_data_pack->Altitude_Payload_Altimeter, telemetry_data_pack->Velocity_Horizontal, telemetry_data_pack->Velocity_Vertical, telemetry_data_pack->Position_Accuracy, telemetry_data_pack->Speed_Accuracy, telemetry_data_pack->Acceleration_X, telemetry_data_pack->Acceleration_Y, telemetry_data_pack->Acceleration_Z, telemetry_data_pack->ECEF_Position_X, telemetry_data_pack->ECEF_Position_Y, telemetry_data_pack->ECEF_Position_Z, telemetry_data_pack->ECEF_Velocity_X, telemetry_data_pack->ECEF_Velocity_Y, telemetry_data_pack->ECEF_Velocity_Z, telemetry_data_pack->Roll_Angle, telemetry_data_pack->Pitch_Angle, telemetry_data_pack->Yaw_Angle, telemetry_data_pack->Angular_Rate_Roll, telemetry_data_pack->Angular_Rate_Pitch, telemetry_data_pack->Angular_Rate_Yaw, telemetry_data_pack->Quaternion_0, telemetry_data_pack->Quaternion_1, telemetry_data_pack->Quaternion_2, telemetry_data_pack->Quaternion_3, telemetry_data_pack->Telemetry_Status_Mask, telemetry_data_pack->Satellite_Num);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TELEMETRY_DATA_PACK, (const char *)telemetry_data_pack, MAVLINK_MSG_ID_TELEMETRY_DATA_PACK_MIN_LEN, MAVLINK_MSG_ID_TELEMETRY_DATA_PACK_LEN, MAVLINK_MSG_ID_TELEMETRY_DATA_PACK_CRC);
#endif
}

#if MAVLINK_MSG_ID_TELEMETRY_DATA_PACK_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_telemetry_data_pack_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t Log_Timestamp, uint64_t GNSS_Timestamp, int32_t Latitude, int32_t Longitude, uint32_t GNSS_Altitude, int16_t Air_Speed_U, int16_t Air_Speed_V, int16_t Air_Speed_W, int16_t Air_Temperature, int32_t Altitude_Main_Altimeter, int32_t Altitude_Payload_Altimeter, uint16_t Velocity_Horizontal, int16_t Velocity_Vertical, uint16_t Position_Accuracy, uint16_t Speed_Accuracy, int16_t Acceleration_X, int16_t Acceleration_Y, int16_t Acceleration_Z, float ECEF_Position_X, float ECEF_Position_Y, float ECEF_Position_Z, float ECEF_Velocity_X, float ECEF_Velocity_Y, float ECEF_Velocity_Z, int16_t Roll_Angle, int16_t Pitch_Angle, int16_t Yaw_Angle, int16_t Angular_Rate_Roll, int16_t Angular_Rate_Pitch, int16_t Angular_Rate_Yaw, float Quaternion_0, float Quaternion_1, float Quaternion_2, float Quaternion_3, uint32_t Telemetry_Status_Mask, uint8_t Satellite_Num)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, Log_Timestamp);
    _mav_put_uint64_t(buf, 8, GNSS_Timestamp);
    _mav_put_int32_t(buf, 16, Latitude);
    _mav_put_int32_t(buf, 20, Longitude);
    _mav_put_uint32_t(buf, 24, GNSS_Altitude);
    _mav_put_int32_t(buf, 28, Altitude_Main_Altimeter);
    _mav_put_int32_t(buf, 32, Altitude_Payload_Altimeter);
    _mav_put_float(buf, 36, ECEF_Position_X);
    _mav_put_float(buf, 40, ECEF_Position_Y);
    _mav_put_float(buf, 44, ECEF_Position_Z);
    _mav_put_float(buf, 48, ECEF_Velocity_X);
    _mav_put_float(buf, 52, ECEF_Velocity_Y);
    _mav_put_float(buf, 56, ECEF_Velocity_Z);
    _mav_put_float(buf, 60, Quaternion_0);
    _mav_put_float(buf, 64, Quaternion_1);
    _mav_put_float(buf, 68, Quaternion_2);
    _mav_put_float(buf, 72, Quaternion_3);
    _mav_put_uint32_t(buf, 76, Telemetry_Status_Mask);
    _mav_put_int16_t(buf, 80, Air_Speed_U);
    _mav_put_int16_t(buf, 82, Air_Speed_V);
    _mav_put_int16_t(buf, 84, Air_Speed_W);
    _mav_put_int16_t(buf, 86, Air_Temperature);
    _mav_put_uint16_t(buf, 88, Velocity_Horizontal);
    _mav_put_int16_t(buf, 90, Velocity_Vertical);
    _mav_put_uint16_t(buf, 92, Position_Accuracy);
    _mav_put_uint16_t(buf, 94, Speed_Accuracy);
    _mav_put_int16_t(buf, 96, Acceleration_X);
    _mav_put_int16_t(buf, 98, Acceleration_Y);
    _mav_put_int16_t(buf, 100, Acceleration_Z);
    _mav_put_int16_t(buf, 102, Roll_Angle);
    _mav_put_int16_t(buf, 104, Pitch_Angle);
    _mav_put_int16_t(buf, 106, Yaw_Angle);
    _mav_put_int16_t(buf, 108, Angular_Rate_Roll);
    _mav_put_int16_t(buf, 110, Angular_Rate_Pitch);
    _mav_put_int16_t(buf, 112, Angular_Rate_Yaw);
    _mav_put_uint8_t(buf, 114, Satellite_Num);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TELEMETRY_DATA_PACK, buf, MAVLINK_MSG_ID_TELEMETRY_DATA_PACK_MIN_LEN, MAVLINK_MSG_ID_TELEMETRY_DATA_PACK_LEN, MAVLINK_MSG_ID_TELEMETRY_DATA_PACK_CRC);
#else
    mavlink_telemetry_data_pack_t *packet = (mavlink_telemetry_data_pack_t *)msgbuf;
    packet->Log_Timestamp = Log_Timestamp;
    packet->GNSS_Timestamp = GNSS_Timestamp;
    packet->Latitude = Latitude;
    packet->Longitude = Longitude;
    packet->GNSS_Altitude = GNSS_Altitude;
    packet->Altitude_Main_Altimeter = Altitude_Main_Altimeter;
    packet->Altitude_Payload_Altimeter = Altitude_Payload_Altimeter;
    packet->ECEF_Position_X = ECEF_Position_X;
    packet->ECEF_Position_Y = ECEF_Position_Y;
    packet->ECEF_Position_Z = ECEF_Position_Z;
    packet->ECEF_Velocity_X = ECEF_Velocity_X;
    packet->ECEF_Velocity_Y = ECEF_Velocity_Y;
    packet->ECEF_Velocity_Z = ECEF_Velocity_Z;
    packet->Quaternion_0 = Quaternion_0;
    packet->Quaternion_1 = Quaternion_1;
    packet->Quaternion_2 = Quaternion_2;
    packet->Quaternion_3 = Quaternion_3;
    packet->Telemetry_Status_Mask = Telemetry_Status_Mask;
    packet->Air_Speed_U = Air_Speed_U;
    packet->Air_Speed_V = Air_Speed_V;
    packet->Air_Speed_W = Air_Speed_W;
    packet->Air_Temperature = Air_Temperature;
    packet->Velocity_Horizontal = Velocity_Horizontal;
    packet->Velocity_Vertical = Velocity_Vertical;
    packet->Position_Accuracy = Position_Accuracy;
    packet->Speed_Accuracy = Speed_Accuracy;
    packet->Acceleration_X = Acceleration_X;
    packet->Acceleration_Y = Acceleration_Y;
    packet->Acceleration_Z = Acceleration_Z;
    packet->Roll_Angle = Roll_Angle;
    packet->Pitch_Angle = Pitch_Angle;
    packet->Yaw_Angle = Yaw_Angle;
    packet->Angular_Rate_Roll = Angular_Rate_Roll;
    packet->Angular_Rate_Pitch = Angular_Rate_Pitch;
    packet->Angular_Rate_Yaw = Angular_Rate_Yaw;
    packet->Satellite_Num = Satellite_Num;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TELEMETRY_DATA_PACK, (const char *)packet, MAVLINK_MSG_ID_TELEMETRY_DATA_PACK_MIN_LEN, MAVLINK_MSG_ID_TELEMETRY_DATA_PACK_LEN, MAVLINK_MSG_ID_TELEMETRY_DATA_PACK_CRC);
#endif
}
#endif

#endif

// MESSAGE TELEMETRY_DATA_PACK UNPACKING


/**
 * @brief Get field Log_Timestamp from telemetry_data_pack message
 *
 * @return [ms] Log timestamp since 1.1.1970 UTC.
 */
static inline uint64_t mavlink_msg_telemetry_data_pack_get_Log_Timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field GNSS_Timestamp from telemetry_data_pack message
 *
 * @return [ms] GNSS Timestamp since 1.1.1970 UTC.
 */
static inline uint64_t mavlink_msg_telemetry_data_pack_get_GNSS_Timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  8);
}

/**
 * @brief Get field Latitude from telemetry_data_pack message
 *
 * @return [deg] Latitude 10^7
 */
static inline int32_t mavlink_msg_telemetry_data_pack_get_Latitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  16);
}

/**
 * @brief Get field Longitude from telemetry_data_pack message
 *
 * @return [deg] Longitude 10^7
 */
static inline int32_t mavlink_msg_telemetry_data_pack_get_Longitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  20);
}

/**
 * @brief Get field GNSS_Altitude from telemetry_data_pack message
 *
 * @return [m] GNSS altitude 10^3
 */
static inline uint32_t mavlink_msg_telemetry_data_pack_get_GNSS_Altitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  24);
}

/**
 * @brief Get field Air_Speed_U from telemetry_data_pack message
 *
 * @return [m/s] Air speed U vector 10^2
 */
static inline int16_t mavlink_msg_telemetry_data_pack_get_Air_Speed_U(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  80);
}

/**
 * @brief Get field Air_Speed_V from telemetry_data_pack message
 *
 * @return [m/s] Air speed V vector 10^2
 */
static inline int16_t mavlink_msg_telemetry_data_pack_get_Air_Speed_V(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  82);
}

/**
 * @brief Get field Air_Speed_W from telemetry_data_pack message
 *
 * @return [m/s] Air speed W vector 10^2
 */
static inline int16_t mavlink_msg_telemetry_data_pack_get_Air_Speed_W(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  84);
}

/**
 * @brief Get field Air_Temperature from telemetry_data_pack message
 *
 * @return [°C] Air temperature 10^2
 */
static inline int16_t mavlink_msg_telemetry_data_pack_get_Air_Temperature(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  86);
}

/**
 * @brief Get field Altitude_Main_Altimeter from telemetry_data_pack message
 *
 * @return [m] Altitude from main radar altimeter 10^2
 */
static inline int32_t mavlink_msg_telemetry_data_pack_get_Altitude_Main_Altimeter(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  28);
}

/**
 * @brief Get field Altitude_Payload_Altimeter from telemetry_data_pack message
 *
 * @return [m] Altitude from payload radar altimeter 10^2
 */
static inline int32_t mavlink_msg_telemetry_data_pack_get_Altitude_Payload_Altimeter(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  32);
}

/**
 * @brief Get field Velocity_Horizontal from telemetry_data_pack message
 *
 * @return [m/s] Linear velocity horizontal 10^2
 */
static inline uint16_t mavlink_msg_telemetry_data_pack_get_Velocity_Horizontal(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  88);
}

/**
 * @brief Get field Velocity_Vertical from telemetry_data_pack message
 *
 * @return [m/s] Linear velocity vertical 10^2
 */
static inline int16_t mavlink_msg_telemetry_data_pack_get_Velocity_Vertical(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  90);
}

/**
 * @brief Get field Position_Accuracy from telemetry_data_pack message
 *
 * @return [m] GNSS position accuracy 10^2
 */
static inline uint16_t mavlink_msg_telemetry_data_pack_get_Position_Accuracy(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  92);
}

/**
 * @brief Get field Speed_Accuracy from telemetry_data_pack message
 *
 * @return [m/s] GNSS speed accuracy 10^2
 */
static inline uint16_t mavlink_msg_telemetry_data_pack_get_Speed_Accuracy(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  94);
}

/**
 * @brief Get field Acceleration_X from telemetry_data_pack message
 *
 * @return [m/s^2] Linear acceleration X 10^2
 */
static inline int16_t mavlink_msg_telemetry_data_pack_get_Acceleration_X(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  96);
}

/**
 * @brief Get field Acceleration_Y from telemetry_data_pack message
 *
 * @return [m/s^2] Linear acceleration Y 10^2
 */
static inline int16_t mavlink_msg_telemetry_data_pack_get_Acceleration_Y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  98);
}

/**
 * @brief Get field Acceleration_Z from telemetry_data_pack message
 *
 * @return [m/s^2] Linear acceleration Z 10^2
 */
static inline int16_t mavlink_msg_telemetry_data_pack_get_Acceleration_Z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  100);
}

/**
 * @brief Get field ECEF_Position_X from telemetry_data_pack message
 *
 * @return [m] ECEF vector position X
 */
static inline float mavlink_msg_telemetry_data_pack_get_ECEF_Position_X(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field ECEF_Position_Y from telemetry_data_pack message
 *
 * @return [m] ECEF vector position Y
 */
static inline float mavlink_msg_telemetry_data_pack_get_ECEF_Position_Y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field ECEF_Position_Z from telemetry_data_pack message
 *
 * @return [m] ECEF vector position Z
 */
static inline float mavlink_msg_telemetry_data_pack_get_ECEF_Position_Z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Get field ECEF_Velocity_X from telemetry_data_pack message
 *
 * @return [m/s] ECEF vector velocity X
 */
static inline float mavlink_msg_telemetry_data_pack_get_ECEF_Velocity_X(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  48);
}

/**
 * @brief Get field ECEF_Velocity_Y from telemetry_data_pack message
 *
 * @return [m/s] ECEF vector velocity Y
 */
static inline float mavlink_msg_telemetry_data_pack_get_ECEF_Velocity_Y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  52);
}

/**
 * @brief Get field ECEF_Velocity_Z from telemetry_data_pack message
 *
 * @return [m/s] ECEF vector velocity Z
 */
static inline float mavlink_msg_telemetry_data_pack_get_ECEF_Velocity_Z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  56);
}

/**
 * @brief Get field Roll_Angle from telemetry_data_pack message
 *
 * @return [deg] Roll angle 10^2
 */
static inline int16_t mavlink_msg_telemetry_data_pack_get_Roll_Angle(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  102);
}

/**
 * @brief Get field Pitch_Angle from telemetry_data_pack message
 *
 * @return [deg] Pitch angle 10^2
 */
static inline int16_t mavlink_msg_telemetry_data_pack_get_Pitch_Angle(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  104);
}

/**
 * @brief Get field Yaw_Angle from telemetry_data_pack message
 *
 * @return [deg] Yaw angle 10^2
 */
static inline int16_t mavlink_msg_telemetry_data_pack_get_Yaw_Angle(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  106);
}

/**
 * @brief Get field Angular_Rate_Roll from telemetry_data_pack message
 *
 * @return [deg/s] Roll angle 10^2
 */
static inline int16_t mavlink_msg_telemetry_data_pack_get_Angular_Rate_Roll(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  108);
}

/**
 * @brief Get field Angular_Rate_Pitch from telemetry_data_pack message
 *
 * @return [deg/s] Pitch angle 10^2
 */
static inline int16_t mavlink_msg_telemetry_data_pack_get_Angular_Rate_Pitch(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  110);
}

/**
 * @brief Get field Angular_Rate_Yaw from telemetry_data_pack message
 *
 * @return [deg/s] Yaw angle 10^2
 */
static inline int16_t mavlink_msg_telemetry_data_pack_get_Angular_Rate_Yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  112);
}

/**
 * @brief Get field Quaternion_0 from telemetry_data_pack message
 *
 * @return  Quaternion[0]
 */
static inline float mavlink_msg_telemetry_data_pack_get_Quaternion_0(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  60);
}

/**
 * @brief Get field Quaternion_1 from telemetry_data_pack message
 *
 * @return  Quaternion[1]
 */
static inline float mavlink_msg_telemetry_data_pack_get_Quaternion_1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  64);
}

/**
 * @brief Get field Quaternion_2 from telemetry_data_pack message
 *
 * @return  Quaternion[2]
 */
static inline float mavlink_msg_telemetry_data_pack_get_Quaternion_2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  68);
}

/**
 * @brief Get field Quaternion_3 from telemetry_data_pack message
 *
 * @return  Quaternion[3] Scalar component
 */
static inline float mavlink_msg_telemetry_data_pack_get_Quaternion_3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  72);
}

/**
 * @brief Get field Telemetry_Status_Mask from telemetry_data_pack message
 *
 * @return  Telemetry module status mask
 */
static inline uint32_t mavlink_msg_telemetry_data_pack_get_Telemetry_Status_Mask(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  76);
}

/**
 * @brief Get field Satellite_Num from telemetry_data_pack message
 *
 * @return  Number of GPS satellite in view
 */
static inline uint8_t mavlink_msg_telemetry_data_pack_get_Satellite_Num(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  114);
}

/**
 * @brief Decode a telemetry_data_pack message into a struct
 *
 * @param msg The message to decode
 * @param telemetry_data_pack C-struct to decode the message contents into
 */
static inline void mavlink_msg_telemetry_data_pack_decode(const mavlink_message_t* msg, mavlink_telemetry_data_pack_t* telemetry_data_pack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    telemetry_data_pack->Log_Timestamp = mavlink_msg_telemetry_data_pack_get_Log_Timestamp(msg);
    telemetry_data_pack->GNSS_Timestamp = mavlink_msg_telemetry_data_pack_get_GNSS_Timestamp(msg);
    telemetry_data_pack->Latitude = mavlink_msg_telemetry_data_pack_get_Latitude(msg);
    telemetry_data_pack->Longitude = mavlink_msg_telemetry_data_pack_get_Longitude(msg);
    telemetry_data_pack->GNSS_Altitude = mavlink_msg_telemetry_data_pack_get_GNSS_Altitude(msg);
    telemetry_data_pack->Altitude_Main_Altimeter = mavlink_msg_telemetry_data_pack_get_Altitude_Main_Altimeter(msg);
    telemetry_data_pack->Altitude_Payload_Altimeter = mavlink_msg_telemetry_data_pack_get_Altitude_Payload_Altimeter(msg);
    telemetry_data_pack->ECEF_Position_X = mavlink_msg_telemetry_data_pack_get_ECEF_Position_X(msg);
    telemetry_data_pack->ECEF_Position_Y = mavlink_msg_telemetry_data_pack_get_ECEF_Position_Y(msg);
    telemetry_data_pack->ECEF_Position_Z = mavlink_msg_telemetry_data_pack_get_ECEF_Position_Z(msg);
    telemetry_data_pack->ECEF_Velocity_X = mavlink_msg_telemetry_data_pack_get_ECEF_Velocity_X(msg);
    telemetry_data_pack->ECEF_Velocity_Y = mavlink_msg_telemetry_data_pack_get_ECEF_Velocity_Y(msg);
    telemetry_data_pack->ECEF_Velocity_Z = mavlink_msg_telemetry_data_pack_get_ECEF_Velocity_Z(msg);
    telemetry_data_pack->Quaternion_0 = mavlink_msg_telemetry_data_pack_get_Quaternion_0(msg);
    telemetry_data_pack->Quaternion_1 = mavlink_msg_telemetry_data_pack_get_Quaternion_1(msg);
    telemetry_data_pack->Quaternion_2 = mavlink_msg_telemetry_data_pack_get_Quaternion_2(msg);
    telemetry_data_pack->Quaternion_3 = mavlink_msg_telemetry_data_pack_get_Quaternion_3(msg);
    telemetry_data_pack->Telemetry_Status_Mask = mavlink_msg_telemetry_data_pack_get_Telemetry_Status_Mask(msg);
    telemetry_data_pack->Air_Speed_U = mavlink_msg_telemetry_data_pack_get_Air_Speed_U(msg);
    telemetry_data_pack->Air_Speed_V = mavlink_msg_telemetry_data_pack_get_Air_Speed_V(msg);
    telemetry_data_pack->Air_Speed_W = mavlink_msg_telemetry_data_pack_get_Air_Speed_W(msg);
    telemetry_data_pack->Air_Temperature = mavlink_msg_telemetry_data_pack_get_Air_Temperature(msg);
    telemetry_data_pack->Velocity_Horizontal = mavlink_msg_telemetry_data_pack_get_Velocity_Horizontal(msg);
    telemetry_data_pack->Velocity_Vertical = mavlink_msg_telemetry_data_pack_get_Velocity_Vertical(msg);
    telemetry_data_pack->Position_Accuracy = mavlink_msg_telemetry_data_pack_get_Position_Accuracy(msg);
    telemetry_data_pack->Speed_Accuracy = mavlink_msg_telemetry_data_pack_get_Speed_Accuracy(msg);
    telemetry_data_pack->Acceleration_X = mavlink_msg_telemetry_data_pack_get_Acceleration_X(msg);
    telemetry_data_pack->Acceleration_Y = mavlink_msg_telemetry_data_pack_get_Acceleration_Y(msg);
    telemetry_data_pack->Acceleration_Z = mavlink_msg_telemetry_data_pack_get_Acceleration_Z(msg);
    telemetry_data_pack->Roll_Angle = mavlink_msg_telemetry_data_pack_get_Roll_Angle(msg);
    telemetry_data_pack->Pitch_Angle = mavlink_msg_telemetry_data_pack_get_Pitch_Angle(msg);
    telemetry_data_pack->Yaw_Angle = mavlink_msg_telemetry_data_pack_get_Yaw_Angle(msg);
    telemetry_data_pack->Angular_Rate_Roll = mavlink_msg_telemetry_data_pack_get_Angular_Rate_Roll(msg);
    telemetry_data_pack->Angular_Rate_Pitch = mavlink_msg_telemetry_data_pack_get_Angular_Rate_Pitch(msg);
    telemetry_data_pack->Angular_Rate_Yaw = mavlink_msg_telemetry_data_pack_get_Angular_Rate_Yaw(msg);
    telemetry_data_pack->Satellite_Num = mavlink_msg_telemetry_data_pack_get_Satellite_Num(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TELEMETRY_DATA_PACK_LEN? msg->len : MAVLINK_MSG_ID_TELEMETRY_DATA_PACK_LEN;
        memset(telemetry_data_pack, 0, MAVLINK_MSG_ID_TELEMETRY_DATA_PACK_LEN);
    memcpy(telemetry_data_pack, _MAV_PAYLOAD(msg), len);
#endif
}
