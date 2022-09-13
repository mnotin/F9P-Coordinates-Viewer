/** @file
 *	@brief MAVLink comm testsuite protocol generated from AGU_MAVLINK.xml
 *	@see http://mavlink.org
 */

#pragma once

#include <gtest/gtest.h>
#include "AGU_MAVLINK.hpp"

#ifdef TEST_INTEROP
using namespace mavlink;
#undef MAVLINK_HELPER
#include "mavlink.h"
#endif


TEST(AGU_MAVLINK, SYSTEM_STATUS_PACK)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::AGU_MAVLINK::msg::SYSTEM_STATUS_PACK packet_in{};
    packet_in.Log_Timestamp = 93372036854775807ULL;
    packet_in.Core_Module_Status_Mask = 963497880;
    packet_in.Telemetry_Module_Status_Mask = 963498088;
    packet_in.Storage_Module_Status_Mask = 963498296;
    packet_in.Radio_Link_Module_Status_Mask = 963498504;
    packet_in.Motor_Control_Module_Status_Mask = 963498712;
    packet_in.Guidance_Module_Status_Mask = 963498920;
    packet_in.Flight_Phase = 113;
    packet_in.Flight_Mode = 180;
    packet_in.Flight_Phase_Time = 963499128;

    mavlink::AGU_MAVLINK::msg::SYSTEM_STATUS_PACK packet1{};
    mavlink::AGU_MAVLINK::msg::SYSTEM_STATUS_PACK packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.Log_Timestamp, packet2.Log_Timestamp);
    EXPECT_EQ(packet1.Core_Module_Status_Mask, packet2.Core_Module_Status_Mask);
    EXPECT_EQ(packet1.Telemetry_Module_Status_Mask, packet2.Telemetry_Module_Status_Mask);
    EXPECT_EQ(packet1.Storage_Module_Status_Mask, packet2.Storage_Module_Status_Mask);
    EXPECT_EQ(packet1.Radio_Link_Module_Status_Mask, packet2.Radio_Link_Module_Status_Mask);
    EXPECT_EQ(packet1.Motor_Control_Module_Status_Mask, packet2.Motor_Control_Module_Status_Mask);
    EXPECT_EQ(packet1.Guidance_Module_Status_Mask, packet2.Guidance_Module_Status_Mask);
    EXPECT_EQ(packet1.Flight_Phase, packet2.Flight_Phase);
    EXPECT_EQ(packet1.Flight_Mode, packet2.Flight_Mode);
    EXPECT_EQ(packet1.Flight_Phase_Time, packet2.Flight_Phase_Time);
}

#ifdef TEST_INTEROP
TEST(AGU_MAVLINK_interop, SYSTEM_STATUS_PACK)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_system_status_pack_t packet_c {
         93372036854775807ULL, 963497880, 963498088, 963498296, 963498504, 963498712, 963498920, 963499128, 113, 180
    };

    mavlink::AGU_MAVLINK::msg::SYSTEM_STATUS_PACK packet_in{};
    packet_in.Log_Timestamp = 93372036854775807ULL;
    packet_in.Core_Module_Status_Mask = 963497880;
    packet_in.Telemetry_Module_Status_Mask = 963498088;
    packet_in.Storage_Module_Status_Mask = 963498296;
    packet_in.Radio_Link_Module_Status_Mask = 963498504;
    packet_in.Motor_Control_Module_Status_Mask = 963498712;
    packet_in.Guidance_Module_Status_Mask = 963498920;
    packet_in.Flight_Phase = 113;
    packet_in.Flight_Mode = 180;
    packet_in.Flight_Phase_Time = 963499128;

    mavlink::AGU_MAVLINK::msg::SYSTEM_STATUS_PACK packet2{};

    mavlink_msg_system_status_pack_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.Log_Timestamp, packet2.Log_Timestamp);
    EXPECT_EQ(packet_in.Core_Module_Status_Mask, packet2.Core_Module_Status_Mask);
    EXPECT_EQ(packet_in.Telemetry_Module_Status_Mask, packet2.Telemetry_Module_Status_Mask);
    EXPECT_EQ(packet_in.Storage_Module_Status_Mask, packet2.Storage_Module_Status_Mask);
    EXPECT_EQ(packet_in.Radio_Link_Module_Status_Mask, packet2.Radio_Link_Module_Status_Mask);
    EXPECT_EQ(packet_in.Motor_Control_Module_Status_Mask, packet2.Motor_Control_Module_Status_Mask);
    EXPECT_EQ(packet_in.Guidance_Module_Status_Mask, packet2.Guidance_Module_Status_Mask);
    EXPECT_EQ(packet_in.Flight_Phase, packet2.Flight_Phase);
    EXPECT_EQ(packet_in.Flight_Mode, packet2.Flight_Mode);
    EXPECT_EQ(packet_in.Flight_Phase_Time, packet2.Flight_Phase_Time);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(AGU_MAVLINK, TELEMETRY_DATA_PACK)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::AGU_MAVLINK::msg::TELEMETRY_DATA_PACK packet_in{};
    packet_in.Log_Timestamp = 93372036854775807ULL;
    packet_in.GNSS_Timestamp = 93372036854776311ULL;
    packet_in.Latitude = 963498296;
    packet_in.Longitude = 963498504;
    packet_in.GNSS_Altitude = 963498712;
    packet_in.Air_Speed_U = 21395;
    packet_in.Air_Speed_V = 21499;
    packet_in.Air_Speed_W = 21603;
    packet_in.Air_Temperature = 21707;
    packet_in.Altitude_Main_Altimeter = 963498920;
    packet_in.Altitude_Payload_Altimeter = 963499128;
    packet_in.Velocity_Horizontal = 21811;
    packet_in.Velocity_Vertical = 21915;
    packet_in.Position_Accuracy = 22019;
    packet_in.Speed_Accuracy = 22123;
    packet_in.Acceleration_X = 22227;
    packet_in.Acceleration_Y = 22331;
    packet_in.Acceleration_Z = 22435;
    packet_in.ECEF_Position_X = 269.0;
    packet_in.ECEF_Position_Y = 297.0;
    packet_in.ECEF_Position_Z = 325.0;
    packet_in.ECEF_Velocity_X = 353.0;
    packet_in.ECEF_Velocity_Y = 381.0;
    packet_in.ECEF_Velocity_Z = 409.0;
    packet_in.Roll_Angle = 22539;
    packet_in.Pitch_Angle = 22643;
    packet_in.Yaw_Angle = 22747;
    packet_in.Angular_Rate_Roll = 22851;
    packet_in.Angular_Rate_Pitch = 22955;
    packet_in.Angular_Rate_Yaw = 23059;
    packet_in.Quaternion_0 = 437.0;
    packet_in.Quaternion_1 = 465.0;
    packet_in.Quaternion_2 = 493.0;
    packet_in.Quaternion_3 = 521.0;
    packet_in.Telemetry_Status_Mask = 963501416;
    packet_in.Satellite_Num = 219;

    mavlink::AGU_MAVLINK::msg::TELEMETRY_DATA_PACK packet1{};
    mavlink::AGU_MAVLINK::msg::TELEMETRY_DATA_PACK packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.Log_Timestamp, packet2.Log_Timestamp);
    EXPECT_EQ(packet1.GNSS_Timestamp, packet2.GNSS_Timestamp);
    EXPECT_EQ(packet1.Latitude, packet2.Latitude);
    EXPECT_EQ(packet1.Longitude, packet2.Longitude);
    EXPECT_EQ(packet1.GNSS_Altitude, packet2.GNSS_Altitude);
    EXPECT_EQ(packet1.Air_Speed_U, packet2.Air_Speed_U);
    EXPECT_EQ(packet1.Air_Speed_V, packet2.Air_Speed_V);
    EXPECT_EQ(packet1.Air_Speed_W, packet2.Air_Speed_W);
    EXPECT_EQ(packet1.Air_Temperature, packet2.Air_Temperature);
    EXPECT_EQ(packet1.Altitude_Main_Altimeter, packet2.Altitude_Main_Altimeter);
    EXPECT_EQ(packet1.Altitude_Payload_Altimeter, packet2.Altitude_Payload_Altimeter);
    EXPECT_EQ(packet1.Velocity_Horizontal, packet2.Velocity_Horizontal);
    EXPECT_EQ(packet1.Velocity_Vertical, packet2.Velocity_Vertical);
    EXPECT_EQ(packet1.Position_Accuracy, packet2.Position_Accuracy);
    EXPECT_EQ(packet1.Speed_Accuracy, packet2.Speed_Accuracy);
    EXPECT_EQ(packet1.Acceleration_X, packet2.Acceleration_X);
    EXPECT_EQ(packet1.Acceleration_Y, packet2.Acceleration_Y);
    EXPECT_EQ(packet1.Acceleration_Z, packet2.Acceleration_Z);
    EXPECT_EQ(packet1.ECEF_Position_X, packet2.ECEF_Position_X);
    EXPECT_EQ(packet1.ECEF_Position_Y, packet2.ECEF_Position_Y);
    EXPECT_EQ(packet1.ECEF_Position_Z, packet2.ECEF_Position_Z);
    EXPECT_EQ(packet1.ECEF_Velocity_X, packet2.ECEF_Velocity_X);
    EXPECT_EQ(packet1.ECEF_Velocity_Y, packet2.ECEF_Velocity_Y);
    EXPECT_EQ(packet1.ECEF_Velocity_Z, packet2.ECEF_Velocity_Z);
    EXPECT_EQ(packet1.Roll_Angle, packet2.Roll_Angle);
    EXPECT_EQ(packet1.Pitch_Angle, packet2.Pitch_Angle);
    EXPECT_EQ(packet1.Yaw_Angle, packet2.Yaw_Angle);
    EXPECT_EQ(packet1.Angular_Rate_Roll, packet2.Angular_Rate_Roll);
    EXPECT_EQ(packet1.Angular_Rate_Pitch, packet2.Angular_Rate_Pitch);
    EXPECT_EQ(packet1.Angular_Rate_Yaw, packet2.Angular_Rate_Yaw);
    EXPECT_EQ(packet1.Quaternion_0, packet2.Quaternion_0);
    EXPECT_EQ(packet1.Quaternion_1, packet2.Quaternion_1);
    EXPECT_EQ(packet1.Quaternion_2, packet2.Quaternion_2);
    EXPECT_EQ(packet1.Quaternion_3, packet2.Quaternion_3);
    EXPECT_EQ(packet1.Telemetry_Status_Mask, packet2.Telemetry_Status_Mask);
    EXPECT_EQ(packet1.Satellite_Num, packet2.Satellite_Num);
}

#ifdef TEST_INTEROP
TEST(AGU_MAVLINK_interop, TELEMETRY_DATA_PACK)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_telemetry_data_pack_t packet_c {
         93372036854775807ULL, 93372036854776311ULL, 963498296, 963498504, 963498712, 963498920, 963499128, 269.0, 297.0, 325.0, 353.0, 381.0, 409.0, 437.0, 465.0, 493.0, 521.0, 963501416, 21395, 21499, 21603, 21707, 21811, 21915, 22019, 22123, 22227, 22331, 22435, 22539, 22643, 22747, 22851, 22955, 23059, 219
    };

    mavlink::AGU_MAVLINK::msg::TELEMETRY_DATA_PACK packet_in{};
    packet_in.Log_Timestamp = 93372036854775807ULL;
    packet_in.GNSS_Timestamp = 93372036854776311ULL;
    packet_in.Latitude = 963498296;
    packet_in.Longitude = 963498504;
    packet_in.GNSS_Altitude = 963498712;
    packet_in.Air_Speed_U = 21395;
    packet_in.Air_Speed_V = 21499;
    packet_in.Air_Speed_W = 21603;
    packet_in.Air_Temperature = 21707;
    packet_in.Altitude_Main_Altimeter = 963498920;
    packet_in.Altitude_Payload_Altimeter = 963499128;
    packet_in.Velocity_Horizontal = 21811;
    packet_in.Velocity_Vertical = 21915;
    packet_in.Position_Accuracy = 22019;
    packet_in.Speed_Accuracy = 22123;
    packet_in.Acceleration_X = 22227;
    packet_in.Acceleration_Y = 22331;
    packet_in.Acceleration_Z = 22435;
    packet_in.ECEF_Position_X = 269.0;
    packet_in.ECEF_Position_Y = 297.0;
    packet_in.ECEF_Position_Z = 325.0;
    packet_in.ECEF_Velocity_X = 353.0;
    packet_in.ECEF_Velocity_Y = 381.0;
    packet_in.ECEF_Velocity_Z = 409.0;
    packet_in.Roll_Angle = 22539;
    packet_in.Pitch_Angle = 22643;
    packet_in.Yaw_Angle = 22747;
    packet_in.Angular_Rate_Roll = 22851;
    packet_in.Angular_Rate_Pitch = 22955;
    packet_in.Angular_Rate_Yaw = 23059;
    packet_in.Quaternion_0 = 437.0;
    packet_in.Quaternion_1 = 465.0;
    packet_in.Quaternion_2 = 493.0;
    packet_in.Quaternion_3 = 521.0;
    packet_in.Telemetry_Status_Mask = 963501416;
    packet_in.Satellite_Num = 219;

    mavlink::AGU_MAVLINK::msg::TELEMETRY_DATA_PACK packet2{};

    mavlink_msg_telemetry_data_pack_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.Log_Timestamp, packet2.Log_Timestamp);
    EXPECT_EQ(packet_in.GNSS_Timestamp, packet2.GNSS_Timestamp);
    EXPECT_EQ(packet_in.Latitude, packet2.Latitude);
    EXPECT_EQ(packet_in.Longitude, packet2.Longitude);
    EXPECT_EQ(packet_in.GNSS_Altitude, packet2.GNSS_Altitude);
    EXPECT_EQ(packet_in.Air_Speed_U, packet2.Air_Speed_U);
    EXPECT_EQ(packet_in.Air_Speed_V, packet2.Air_Speed_V);
    EXPECT_EQ(packet_in.Air_Speed_W, packet2.Air_Speed_W);
    EXPECT_EQ(packet_in.Air_Temperature, packet2.Air_Temperature);
    EXPECT_EQ(packet_in.Altitude_Main_Altimeter, packet2.Altitude_Main_Altimeter);
    EXPECT_EQ(packet_in.Altitude_Payload_Altimeter, packet2.Altitude_Payload_Altimeter);
    EXPECT_EQ(packet_in.Velocity_Horizontal, packet2.Velocity_Horizontal);
    EXPECT_EQ(packet_in.Velocity_Vertical, packet2.Velocity_Vertical);
    EXPECT_EQ(packet_in.Position_Accuracy, packet2.Position_Accuracy);
    EXPECT_EQ(packet_in.Speed_Accuracy, packet2.Speed_Accuracy);
    EXPECT_EQ(packet_in.Acceleration_X, packet2.Acceleration_X);
    EXPECT_EQ(packet_in.Acceleration_Y, packet2.Acceleration_Y);
    EXPECT_EQ(packet_in.Acceleration_Z, packet2.Acceleration_Z);
    EXPECT_EQ(packet_in.ECEF_Position_X, packet2.ECEF_Position_X);
    EXPECT_EQ(packet_in.ECEF_Position_Y, packet2.ECEF_Position_Y);
    EXPECT_EQ(packet_in.ECEF_Position_Z, packet2.ECEF_Position_Z);
    EXPECT_EQ(packet_in.ECEF_Velocity_X, packet2.ECEF_Velocity_X);
    EXPECT_EQ(packet_in.ECEF_Velocity_Y, packet2.ECEF_Velocity_Y);
    EXPECT_EQ(packet_in.ECEF_Velocity_Z, packet2.ECEF_Velocity_Z);
    EXPECT_EQ(packet_in.Roll_Angle, packet2.Roll_Angle);
    EXPECT_EQ(packet_in.Pitch_Angle, packet2.Pitch_Angle);
    EXPECT_EQ(packet_in.Yaw_Angle, packet2.Yaw_Angle);
    EXPECT_EQ(packet_in.Angular_Rate_Roll, packet2.Angular_Rate_Roll);
    EXPECT_EQ(packet_in.Angular_Rate_Pitch, packet2.Angular_Rate_Pitch);
    EXPECT_EQ(packet_in.Angular_Rate_Yaw, packet2.Angular_Rate_Yaw);
    EXPECT_EQ(packet_in.Quaternion_0, packet2.Quaternion_0);
    EXPECT_EQ(packet_in.Quaternion_1, packet2.Quaternion_1);
    EXPECT_EQ(packet_in.Quaternion_2, packet2.Quaternion_2);
    EXPECT_EQ(packet_in.Quaternion_3, packet2.Quaternion_3);
    EXPECT_EQ(packet_in.Telemetry_Status_Mask, packet2.Telemetry_Status_Mask);
    EXPECT_EQ(packet_in.Satellite_Num, packet2.Satellite_Num);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(AGU_MAVLINK, MOTOR_STATUS_PACK)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::AGU_MAVLINK::msg::MOTOR_STATUS_PACK packet_in{};
    packet_in.Log_Timestamp = 93372036854775807ULL;
    packet_in.Motor_A_Real_Position = 963497880;
    packet_in.Motor_B_Real_Position = 963498088;
    packet_in.Motor_A_Demand_Position = 963498296;
    packet_in.Motor_B_Demand_Position = 963498504;
    packet_in.Motor_A_Torque = 963498712;
    packet_in.Motor_B_Torque = 963498920;
    packet_in.Motor_A_Temperature = 963499128;
    packet_in.Motor_B_Temperature = 963499336;
    packet_in.BMS_Voltage = 20147;
    packet_in.BMS_Absorption = 20251;
    packet_in.BMS_Temperature = 20355;
    packet_in.Motor_Control_Status_Mask = 963499544;
    packet_in.Motor_A_Faults_Mask = 963499752;
    packet_in.Motor_B_Faults_Mask = 963499960;
    packet_in.BMS_Faults_Mask = 963500168;

    mavlink::AGU_MAVLINK::msg::MOTOR_STATUS_PACK packet1{};
    mavlink::AGU_MAVLINK::msg::MOTOR_STATUS_PACK packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.Log_Timestamp, packet2.Log_Timestamp);
    EXPECT_EQ(packet1.Motor_A_Real_Position, packet2.Motor_A_Real_Position);
    EXPECT_EQ(packet1.Motor_B_Real_Position, packet2.Motor_B_Real_Position);
    EXPECT_EQ(packet1.Motor_A_Demand_Position, packet2.Motor_A_Demand_Position);
    EXPECT_EQ(packet1.Motor_B_Demand_Position, packet2.Motor_B_Demand_Position);
    EXPECT_EQ(packet1.Motor_A_Torque, packet2.Motor_A_Torque);
    EXPECT_EQ(packet1.Motor_B_Torque, packet2.Motor_B_Torque);
    EXPECT_EQ(packet1.Motor_A_Temperature, packet2.Motor_A_Temperature);
    EXPECT_EQ(packet1.Motor_B_Temperature, packet2.Motor_B_Temperature);
    EXPECT_EQ(packet1.BMS_Voltage, packet2.BMS_Voltage);
    EXPECT_EQ(packet1.BMS_Absorption, packet2.BMS_Absorption);
    EXPECT_EQ(packet1.BMS_Temperature, packet2.BMS_Temperature);
    EXPECT_EQ(packet1.Motor_Control_Status_Mask, packet2.Motor_Control_Status_Mask);
    EXPECT_EQ(packet1.Motor_A_Faults_Mask, packet2.Motor_A_Faults_Mask);
    EXPECT_EQ(packet1.Motor_B_Faults_Mask, packet2.Motor_B_Faults_Mask);
    EXPECT_EQ(packet1.BMS_Faults_Mask, packet2.BMS_Faults_Mask);
}

#ifdef TEST_INTEROP
TEST(AGU_MAVLINK_interop, MOTOR_STATUS_PACK)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_motor_status_pack_t packet_c {
         93372036854775807ULL, 963497880, 963498088, 963498296, 963498504, 963498712, 963498920, 963499128, 963499336, 963499544, 963499752, 963499960, 963500168, 20147, 20251, 20355
    };

    mavlink::AGU_MAVLINK::msg::MOTOR_STATUS_PACK packet_in{};
    packet_in.Log_Timestamp = 93372036854775807ULL;
    packet_in.Motor_A_Real_Position = 963497880;
    packet_in.Motor_B_Real_Position = 963498088;
    packet_in.Motor_A_Demand_Position = 963498296;
    packet_in.Motor_B_Demand_Position = 963498504;
    packet_in.Motor_A_Torque = 963498712;
    packet_in.Motor_B_Torque = 963498920;
    packet_in.Motor_A_Temperature = 963499128;
    packet_in.Motor_B_Temperature = 963499336;
    packet_in.BMS_Voltage = 20147;
    packet_in.BMS_Absorption = 20251;
    packet_in.BMS_Temperature = 20355;
    packet_in.Motor_Control_Status_Mask = 963499544;
    packet_in.Motor_A_Faults_Mask = 963499752;
    packet_in.Motor_B_Faults_Mask = 963499960;
    packet_in.BMS_Faults_Mask = 963500168;

    mavlink::AGU_MAVLINK::msg::MOTOR_STATUS_PACK packet2{};

    mavlink_msg_motor_status_pack_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.Log_Timestamp, packet2.Log_Timestamp);
    EXPECT_EQ(packet_in.Motor_A_Real_Position, packet2.Motor_A_Real_Position);
    EXPECT_EQ(packet_in.Motor_B_Real_Position, packet2.Motor_B_Real_Position);
    EXPECT_EQ(packet_in.Motor_A_Demand_Position, packet2.Motor_A_Demand_Position);
    EXPECT_EQ(packet_in.Motor_B_Demand_Position, packet2.Motor_B_Demand_Position);
    EXPECT_EQ(packet_in.Motor_A_Torque, packet2.Motor_A_Torque);
    EXPECT_EQ(packet_in.Motor_B_Torque, packet2.Motor_B_Torque);
    EXPECT_EQ(packet_in.Motor_A_Temperature, packet2.Motor_A_Temperature);
    EXPECT_EQ(packet_in.Motor_B_Temperature, packet2.Motor_B_Temperature);
    EXPECT_EQ(packet_in.BMS_Voltage, packet2.BMS_Voltage);
    EXPECT_EQ(packet_in.BMS_Absorption, packet2.BMS_Absorption);
    EXPECT_EQ(packet_in.BMS_Temperature, packet2.BMS_Temperature);
    EXPECT_EQ(packet_in.Motor_Control_Status_Mask, packet2.Motor_Control_Status_Mask);
    EXPECT_EQ(packet_in.Motor_A_Faults_Mask, packet2.Motor_A_Faults_Mask);
    EXPECT_EQ(packet_in.Motor_B_Faults_Mask, packet2.Motor_B_Faults_Mask);
    EXPECT_EQ(packet_in.BMS_Faults_Mask, packet2.BMS_Faults_Mask);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif
