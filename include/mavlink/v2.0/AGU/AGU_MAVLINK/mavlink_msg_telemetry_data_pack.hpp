// MESSAGE TELEMETRY_DATA_PACK support class

#pragma once

namespace mavlink {
namespace AGU_MAVLINK {
namespace msg {

/**
 * @brief TELEMETRY_DATA_PACK message
 *
 * Telemetry data message.
 */
struct TELEMETRY_DATA_PACK : mavlink::Message {
    static constexpr msgid_t MSG_ID = 13001;
    static constexpr size_t LENGTH = 115;
    static constexpr size_t MIN_LENGTH = 115;
    static constexpr uint8_t CRC_EXTRA = 84;
    static constexpr auto NAME = "TELEMETRY_DATA_PACK";


    uint64_t Log_Timestamp; /*< [ms] Log timestamp since 1.1.1970 UTC. */
    uint64_t GNSS_Timestamp; /*< [ms] GNSS Timestamp since 1.1.1970 UTC. */
    int32_t Latitude; /*< [deg] Latitude 10^7 */
    int32_t Longitude; /*< [deg] Longitude 10^7 */
    uint32_t GNSS_Altitude; /*< [m] GNSS altitude 10^3 */
    int16_t Air_Speed_U; /*< [m/s] Air speed U vector 10^2 */
    int16_t Air_Speed_V; /*< [m/s] Air speed V vector 10^2 */
    int16_t Air_Speed_W; /*< [m/s] Air speed W vector 10^2 */
    int16_t Air_Temperature; /*< [°C] Air temperature 10^2 */
    int32_t Altitude_Main_Altimeter; /*< [m] Altitude from main radar altimeter 10^2 */
    int32_t Altitude_Payload_Altimeter; /*< [m] Altitude from payload radar altimeter 10^2 */
    uint16_t Velocity_Horizontal; /*< [m/s] Linear velocity horizontal 10^2 */
    int16_t Velocity_Vertical; /*< [m/s] Linear velocity vertical 10^2 */
    uint16_t Position_Accuracy; /*< [m] GNSS position accuracy 10^2 */
    uint16_t Speed_Accuracy; /*< [m/s] GNSS speed accuracy 10^2 */
    int16_t Acceleration_X; /*< [m/s^2] Linear acceleration X 10^2 */
    int16_t Acceleration_Y; /*< [m/s^2] Linear acceleration Y 10^2 */
    int16_t Acceleration_Z; /*< [m/s^2] Linear acceleration Z 10^2 */
    float ECEF_Position_X; /*< [m] ECEF vector position X */
    float ECEF_Position_Y; /*< [m] ECEF vector position Y */
    float ECEF_Position_Z; /*< [m] ECEF vector position Z */
    float ECEF_Velocity_X; /*< [m/s] ECEF vector velocity X */
    float ECEF_Velocity_Y; /*< [m/s] ECEF vector velocity Y */
    float ECEF_Velocity_Z; /*< [m/s] ECEF vector velocity Z */
    int16_t Roll_Angle; /*< [deg] Roll angle 10^2 */
    int16_t Pitch_Angle; /*< [deg] Pitch angle 10^2 */
    int16_t Yaw_Angle; /*< [deg] Yaw angle 10^2 */
    int16_t Angular_Rate_Roll; /*< [deg/s] Roll angle 10^2 */
    int16_t Angular_Rate_Pitch; /*< [deg/s] Pitch angle 10^2 */
    int16_t Angular_Rate_Yaw; /*< [deg/s] Yaw angle 10^2 */
    float Quaternion_0; /*<  Quaternion[0] */
    float Quaternion_1; /*<  Quaternion[1] */
    float Quaternion_2; /*<  Quaternion[2] */
    float Quaternion_3; /*<  Quaternion[3] Scalar component */
    uint32_t Telemetry_Status_Mask; /*<  Telemetry module status mask */
    uint8_t Satellite_Num; /*<  Number of GPS satellite in view */


    inline std::string get_name(void) const override
    {
            return NAME;
    }

    inline Info get_message_info(void) const override
    {
            return { MSG_ID, LENGTH, MIN_LENGTH, CRC_EXTRA };
    }

    inline std::string to_yaml(void) const override
    {
        std::stringstream ss;

        ss << NAME << ":" << std::endl;
        ss << "  Log_Timestamp: " << Log_Timestamp << std::endl;
        ss << "  GNSS_Timestamp: " << GNSS_Timestamp << std::endl;
        ss << "  Latitude: " << Latitude << std::endl;
        ss << "  Longitude: " << Longitude << std::endl;
        ss << "  GNSS_Altitude: " << GNSS_Altitude << std::endl;
        ss << "  Air_Speed_U: " << Air_Speed_U << std::endl;
        ss << "  Air_Speed_V: " << Air_Speed_V << std::endl;
        ss << "  Air_Speed_W: " << Air_Speed_W << std::endl;
        ss << "  Air_Temperature: " << Air_Temperature << std::endl;
        ss << "  Altitude_Main_Altimeter: " << Altitude_Main_Altimeter << std::endl;
        ss << "  Altitude_Payload_Altimeter: " << Altitude_Payload_Altimeter << std::endl;
        ss << "  Velocity_Horizontal: " << Velocity_Horizontal << std::endl;
        ss << "  Velocity_Vertical: " << Velocity_Vertical << std::endl;
        ss << "  Position_Accuracy: " << Position_Accuracy << std::endl;
        ss << "  Speed_Accuracy: " << Speed_Accuracy << std::endl;
        ss << "  Acceleration_X: " << Acceleration_X << std::endl;
        ss << "  Acceleration_Y: " << Acceleration_Y << std::endl;
        ss << "  Acceleration_Z: " << Acceleration_Z << std::endl;
        ss << "  ECEF_Position_X: " << ECEF_Position_X << std::endl;
        ss << "  ECEF_Position_Y: " << ECEF_Position_Y << std::endl;
        ss << "  ECEF_Position_Z: " << ECEF_Position_Z << std::endl;
        ss << "  ECEF_Velocity_X: " << ECEF_Velocity_X << std::endl;
        ss << "  ECEF_Velocity_Y: " << ECEF_Velocity_Y << std::endl;
        ss << "  ECEF_Velocity_Z: " << ECEF_Velocity_Z << std::endl;
        ss << "  Roll_Angle: " << Roll_Angle << std::endl;
        ss << "  Pitch_Angle: " << Pitch_Angle << std::endl;
        ss << "  Yaw_Angle: " << Yaw_Angle << std::endl;
        ss << "  Angular_Rate_Roll: " << Angular_Rate_Roll << std::endl;
        ss << "  Angular_Rate_Pitch: " << Angular_Rate_Pitch << std::endl;
        ss << "  Angular_Rate_Yaw: " << Angular_Rate_Yaw << std::endl;
        ss << "  Quaternion_0: " << Quaternion_0 << std::endl;
        ss << "  Quaternion_1: " << Quaternion_1 << std::endl;
        ss << "  Quaternion_2: " << Quaternion_2 << std::endl;
        ss << "  Quaternion_3: " << Quaternion_3 << std::endl;
        ss << "  Telemetry_Status_Mask: " << Telemetry_Status_Mask << std::endl;
        ss << "  Satellite_Num: " << +Satellite_Num << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << Log_Timestamp;                 // offset: 0
        map << GNSS_Timestamp;                // offset: 8
        map << Latitude;                      // offset: 16
        map << Longitude;                     // offset: 20
        map << GNSS_Altitude;                 // offset: 24
        map << Altitude_Main_Altimeter;       // offset: 28
        map << Altitude_Payload_Altimeter;    // offset: 32
        map << ECEF_Position_X;               // offset: 36
        map << ECEF_Position_Y;               // offset: 40
        map << ECEF_Position_Z;               // offset: 44
        map << ECEF_Velocity_X;               // offset: 48
        map << ECEF_Velocity_Y;               // offset: 52
        map << ECEF_Velocity_Z;               // offset: 56
        map << Quaternion_0;                  // offset: 60
        map << Quaternion_1;                  // offset: 64
        map << Quaternion_2;                  // offset: 68
        map << Quaternion_3;                  // offset: 72
        map << Telemetry_Status_Mask;         // offset: 76
        map << Air_Speed_U;                   // offset: 80
        map << Air_Speed_V;                   // offset: 82
        map << Air_Speed_W;                   // offset: 84
        map << Air_Temperature;               // offset: 86
        map << Velocity_Horizontal;           // offset: 88
        map << Velocity_Vertical;             // offset: 90
        map << Position_Accuracy;             // offset: 92
        map << Speed_Accuracy;                // offset: 94
        map << Acceleration_X;                // offset: 96
        map << Acceleration_Y;                // offset: 98
        map << Acceleration_Z;                // offset: 100
        map << Roll_Angle;                    // offset: 102
        map << Pitch_Angle;                   // offset: 104
        map << Yaw_Angle;                     // offset: 106
        map << Angular_Rate_Roll;             // offset: 108
        map << Angular_Rate_Pitch;            // offset: 110
        map << Angular_Rate_Yaw;              // offset: 112
        map << Satellite_Num;                 // offset: 114
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> Log_Timestamp;                 // offset: 0
        map >> GNSS_Timestamp;                // offset: 8
        map >> Latitude;                      // offset: 16
        map >> Longitude;                     // offset: 20
        map >> GNSS_Altitude;                 // offset: 24
        map >> Altitude_Main_Altimeter;       // offset: 28
        map >> Altitude_Payload_Altimeter;    // offset: 32
        map >> ECEF_Position_X;               // offset: 36
        map >> ECEF_Position_Y;               // offset: 40
        map >> ECEF_Position_Z;               // offset: 44
        map >> ECEF_Velocity_X;               // offset: 48
        map >> ECEF_Velocity_Y;               // offset: 52
        map >> ECEF_Velocity_Z;               // offset: 56
        map >> Quaternion_0;                  // offset: 60
        map >> Quaternion_1;                  // offset: 64
        map >> Quaternion_2;                  // offset: 68
        map >> Quaternion_3;                  // offset: 72
        map >> Telemetry_Status_Mask;         // offset: 76
        map >> Air_Speed_U;                   // offset: 80
        map >> Air_Speed_V;                   // offset: 82
        map >> Air_Speed_W;                   // offset: 84
        map >> Air_Temperature;               // offset: 86
        map >> Velocity_Horizontal;           // offset: 88
        map >> Velocity_Vertical;             // offset: 90
        map >> Position_Accuracy;             // offset: 92
        map >> Speed_Accuracy;                // offset: 94
        map >> Acceleration_X;                // offset: 96
        map >> Acceleration_Y;                // offset: 98
        map >> Acceleration_Z;                // offset: 100
        map >> Roll_Angle;                    // offset: 102
        map >> Pitch_Angle;                   // offset: 104
        map >> Yaw_Angle;                     // offset: 106
        map >> Angular_Rate_Roll;             // offset: 108
        map >> Angular_Rate_Pitch;            // offset: 110
        map >> Angular_Rate_Yaw;              // offset: 112
        map >> Satellite_Num;                 // offset: 114
    }
};

} // namespace msg
} // namespace AGU_MAVLINK
} // namespace mavlink
