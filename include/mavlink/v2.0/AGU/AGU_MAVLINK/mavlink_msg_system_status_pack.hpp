// MESSAGE SYSTEM_STATUS_PACK support class

#pragma once

namespace mavlink {
namespace AGU_MAVLINK {
namespace msg {

/**
 * @brief SYSTEM_STATUS_PACK message
 *
 * System status message.
 */
struct SYSTEM_STATUS_PACK : mavlink::Message {
    static constexpr msgid_t MSG_ID = 13000;
    static constexpr size_t LENGTH = 42;
    static constexpr size_t MIN_LENGTH = 42;
    static constexpr uint8_t CRC_EXTRA = 210;
    static constexpr auto NAME = "SYSTEM_STATUS_PACK";


    uint64_t Log_Timestamp; /*< [ms] Log timestamp since 1.1.1970 UTC. */
    uint32_t Core_Module_Status_Mask; /*<  Core module status mask */
    uint64_t Telemetry_Module_Status_Mask; /*<  Telemetry module status mask */
    uint32_t Storage_Module_Status_Mask; /*<  Storage module status mask */
    uint32_t Radio_Link_Module_Status_Mask; /*<  Radio link module status mask */
    uint32_t Motor_Control_Module_Status_Mask; /*<  Motor control module status mask */
    uint32_t Guidance_Module_Status_Mask; /*<  Guidance module status mask */
    uint8_t Flight_Phase; /*<  Flight phase id */
    uint8_t Flight_Mode; /*<  Flight mode id */
    uint32_t Flight_Phase_Time; /*< [ms] Flight phase execution time */


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
        ss << "  Core_Module_Status_Mask: " << Core_Module_Status_Mask << std::endl;
        ss << "  Telemetry_Module_Status_Mask: " << Telemetry_Module_Status_Mask << std::endl;
        ss << "  Storage_Module_Status_Mask: " << Storage_Module_Status_Mask << std::endl;
        ss << "  Radio_Link_Module_Status_Mask: " << Radio_Link_Module_Status_Mask << std::endl;
        ss << "  Motor_Control_Module_Status_Mask: " << Motor_Control_Module_Status_Mask << std::endl;
        ss << "  Guidance_Module_Status_Mask: " << Guidance_Module_Status_Mask << std::endl;
        ss << "  Flight_Phase: " << +Flight_Phase << std::endl;
        ss << "  Flight_Mode: " << +Flight_Mode << std::endl;
        ss << "  Flight_Phase_Time: " << Flight_Phase_Time << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << Log_Timestamp;                 // offset: 0
        map << Telemetry_Module_Status_Mask;  // offset: 8
        map << Core_Module_Status_Mask;       // offset: 16
        map << Storage_Module_Status_Mask;    // offset: 20
        map << Radio_Link_Module_Status_Mask; // offset: 24
        map << Motor_Control_Module_Status_Mask; // offset: 28
        map << Guidance_Module_Status_Mask;   // offset: 32
        map << Flight_Phase_Time;             // offset: 36
        map << Flight_Phase;                  // offset: 40
        map << Flight_Mode;                   // offset: 41
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> Log_Timestamp;                 // offset: 0
        map >> Telemetry_Module_Status_Mask;  // offset: 8
        map >> Core_Module_Status_Mask;       // offset: 16
        map >> Storage_Module_Status_Mask;    // offset: 20
        map >> Radio_Link_Module_Status_Mask; // offset: 24
        map >> Motor_Control_Module_Status_Mask; // offset: 28
        map >> Guidance_Module_Status_Mask;   // offset: 32
        map >> Flight_Phase_Time;             // offset: 36
        map >> Flight_Phase;                  // offset: 40
        map >> Flight_Mode;                   // offset: 41
    }
};

} // namespace msg
} // namespace AGU_MAVLINK
} // namespace mavlink
