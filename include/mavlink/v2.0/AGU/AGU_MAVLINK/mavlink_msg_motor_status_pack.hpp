// MESSAGE MOTOR_STATUS_PACK support class

#pragma once

namespace mavlink {
namespace AGU_MAVLINK {
namespace msg {

/**
 * @brief MOTOR_STATUS_PACK message
 *
 * Motor control module status message.
 */
struct MOTOR_STATUS_PACK : mavlink::Message {
    static constexpr msgid_t MSG_ID = 13002;
    static constexpr size_t LENGTH = 62;
    static constexpr size_t MIN_LENGTH = 62;
    static constexpr uint8_t CRC_EXTRA = 86;
    static constexpr auto NAME = "MOTOR_STATUS_PACK";


    uint64_t Log_Timestamp; /*< [ms] Log timestamp since 1.1.1970 UTC. */
    int32_t Motor_A_Real_Position; /*<  Motor A real position (Adimensional value) 10^3 */
    int32_t Motor_B_Real_Position; /*<  Motor B real position (Adimensional value) 10^3 */
    int32_t Motor_A_Demand_Position; /*<  Motor A demand position (Adimensional value) 10^3 */
    int32_t Motor_B_Demand_Position; /*<  Motor B demand position (Adimensional value) 10^3 */
    int32_t Motor_A_Torque; /*< [Nm] Motor A torque 10^2 */
    int32_t Motor_B_Torque; /*< [Nm] Motor B torque 10^2 */
    int32_t Motor_A_Temperature; /*< [°C] Motor A temperature 10^2 */
    int32_t Motor_B_Temperature; /*< [°C] Motor B temperature 10^2 */
    uint16_t BMS_Voltage; /*< [V] Battery management system voltage 10^2 */
    int16_t BMS_Absorption; /*< [A] Battery management system current absorption 10^2 */
    int16_t BMS_Temperature; /*< [°C] Battery management system temperature 10^2 */
    uint32_t Motor_Control_Status_Mask; /*<  Motor control module status mask */
    uint32_t Motor_A_Faults_Mask; /*<  Motor A faults mask */
    uint32_t Motor_B_Faults_Mask; /*<  Motor B faults mask */
    uint32_t BMS_Faults_Mask; /*<  Battery management system faults mask */


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
        ss << "  Motor_A_Real_Position: " << Motor_A_Real_Position << std::endl;
        ss << "  Motor_B_Real_Position: " << Motor_B_Real_Position << std::endl;
        ss << "  Motor_A_Demand_Position: " << Motor_A_Demand_Position << std::endl;
        ss << "  Motor_B_Demand_Position: " << Motor_B_Demand_Position << std::endl;
        ss << "  Motor_A_Torque: " << Motor_A_Torque << std::endl;
        ss << "  Motor_B_Torque: " << Motor_B_Torque << std::endl;
        ss << "  Motor_A_Temperature: " << Motor_A_Temperature << std::endl;
        ss << "  Motor_B_Temperature: " << Motor_B_Temperature << std::endl;
        ss << "  BMS_Voltage: " << BMS_Voltage << std::endl;
        ss << "  BMS_Absorption: " << BMS_Absorption << std::endl;
        ss << "  BMS_Temperature: " << BMS_Temperature << std::endl;
        ss << "  Motor_Control_Status_Mask: " << Motor_Control_Status_Mask << std::endl;
        ss << "  Motor_A_Faults_Mask: " << Motor_A_Faults_Mask << std::endl;
        ss << "  Motor_B_Faults_Mask: " << Motor_B_Faults_Mask << std::endl;
        ss << "  BMS_Faults_Mask: " << BMS_Faults_Mask << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << Log_Timestamp;                 // offset: 0
        map << Motor_A_Real_Position;         // offset: 8
        map << Motor_B_Real_Position;         // offset: 12
        map << Motor_A_Demand_Position;       // offset: 16
        map << Motor_B_Demand_Position;       // offset: 20
        map << Motor_A_Torque;                // offset: 24
        map << Motor_B_Torque;                // offset: 28
        map << Motor_A_Temperature;           // offset: 32
        map << Motor_B_Temperature;           // offset: 36
        map << Motor_Control_Status_Mask;     // offset: 40
        map << Motor_A_Faults_Mask;           // offset: 44
        map << Motor_B_Faults_Mask;           // offset: 48
        map << BMS_Faults_Mask;               // offset: 52
        map << BMS_Voltage;                   // offset: 56
        map << BMS_Absorption;                // offset: 58
        map << BMS_Temperature;               // offset: 60
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> Log_Timestamp;                 // offset: 0
        map >> Motor_A_Real_Position;         // offset: 8
        map >> Motor_B_Real_Position;         // offset: 12
        map >> Motor_A_Demand_Position;       // offset: 16
        map >> Motor_B_Demand_Position;       // offset: 20
        map >> Motor_A_Torque;                // offset: 24
        map >> Motor_B_Torque;                // offset: 28
        map >> Motor_A_Temperature;           // offset: 32
        map >> Motor_B_Temperature;           // offset: 36
        map >> Motor_Control_Status_Mask;     // offset: 40
        map >> Motor_A_Faults_Mask;           // offset: 44
        map >> Motor_B_Faults_Mask;           // offset: 48
        map >> BMS_Faults_Mask;               // offset: 52
        map >> BMS_Voltage;                   // offset: 56
        map >> BMS_Absorption;                // offset: 58
        map >> BMS_Temperature;               // offset: 60
    }
};

} // namespace msg
} // namespace AGU_MAVLINK
} // namespace mavlink
