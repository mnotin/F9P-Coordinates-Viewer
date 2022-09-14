/** @file
 *    @brief MAVLink comm protocol testsuite generated from AGU_MAVLINK.xml
 *    @see https://mavlink.io/en/
 */
#pragma once
#ifndef AGU_MAVLINK_TESTSUITE_H
#define AGU_MAVLINK_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_standard(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_AGU_MAVLINK(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_standard(system_id, component_id, last_msg);
    mavlink_test_AGU_MAVLINK(system_id, component_id, last_msg);
}
#endif

#include "../standard/testsuite.h"


static void mavlink_test_system_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_SYSTEM_STATUS_PACK >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_system_status_pack_t packet_in = {
        93372036854775807ULL,93372036854776311ULL,963498296,963498504,963498712,963498920,963499128,963499336,125,192
    };
    mavlink_system_status_pack_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.Log_Timestamp = packet_in.Log_Timestamp;
        packet1.Telemetry_Module_Status_Mask = packet_in.Telemetry_Module_Status_Mask;
        packet1.Core_Module_Status_Mask = packet_in.Core_Module_Status_Mask;
        packet1.Storage_Module_Status_Mask = packet_in.Storage_Module_Status_Mask;
        packet1.Radio_Link_Module_Status_Mask = packet_in.Radio_Link_Module_Status_Mask;
        packet1.Motor_Control_Module_Status_Mask = packet_in.Motor_Control_Module_Status_Mask;
        packet1.Guidance_Module_Status_Mask = packet_in.Guidance_Module_Status_Mask;
        packet1.Flight_Phase_Time = packet_in.Flight_Phase_Time;
        packet1.Flight_Phase = packet_in.Flight_Phase;
        packet1.Flight_Mode = packet_in.Flight_Mode;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_SYSTEM_STATUS_PACK_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_SYSTEM_STATUS_PACK_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_system_status_pack_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_system_status_pack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_system_status_pack_pack(system_id, component_id, &msg , packet1.Log_Timestamp , packet1.Core_Module_Status_Mask , packet1.Telemetry_Module_Status_Mask , packet1.Storage_Module_Status_Mask , packet1.Radio_Link_Module_Status_Mask , packet1.Motor_Control_Module_Status_Mask , packet1.Guidance_Module_Status_Mask , packet1.Flight_Phase , packet1.Flight_Mode , packet1.Flight_Phase_Time );
    mavlink_msg_system_status_pack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_system_status_pack_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.Log_Timestamp , packet1.Core_Module_Status_Mask , packet1.Telemetry_Module_Status_Mask , packet1.Storage_Module_Status_Mask , packet1.Radio_Link_Module_Status_Mask , packet1.Motor_Control_Module_Status_Mask , packet1.Guidance_Module_Status_Mask , packet1.Flight_Phase , packet1.Flight_Mode , packet1.Flight_Phase_Time );
    mavlink_msg_system_status_pack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_system_status_pack_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_system_status_pack_send(MAVLINK_COMM_1 , packet1.Log_Timestamp , packet1.Core_Module_Status_Mask , packet1.Telemetry_Module_Status_Mask , packet1.Storage_Module_Status_Mask , packet1.Radio_Link_Module_Status_Mask , packet1.Motor_Control_Module_Status_Mask , packet1.Guidance_Module_Status_Mask , packet1.Flight_Phase , packet1.Flight_Mode , packet1.Flight_Phase_Time );
    mavlink_msg_system_status_pack_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("SYSTEM_STATUS_PACK") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_SYSTEM_STATUS_PACK) != NULL);
#endif
}

static void mavlink_test_telemetry_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_TELEMETRY_DATA_PACK >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_telemetry_data_pack_t packet_in = {
        93372036854775807ULL,93372036854776311ULL,93372036854776815ULL,963498712,963498920,963499128,963499336,963499544,325.0,353.0,381.0,409.0,437.0,465.0,493.0,521.0,549.0,577.0,21603,21707,21811,21915,22019,22123,22227,22331,22435,22539,22643,22747,22851,22955,23059,23163,23267,231
    };
    mavlink_telemetry_data_pack_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.Log_Timestamp = packet_in.Log_Timestamp;
        packet1.GNSS_Timestamp = packet_in.GNSS_Timestamp;
        packet1.Telemetry_Status_Mask = packet_in.Telemetry_Status_Mask;
        packet1.Latitude = packet_in.Latitude;
        packet1.Longitude = packet_in.Longitude;
        packet1.GNSS_Altitude = packet_in.GNSS_Altitude;
        packet1.Altitude_Main_Altimeter = packet_in.Altitude_Main_Altimeter;
        packet1.Altitude_Payload_Altimeter = packet_in.Altitude_Payload_Altimeter;
        packet1.ECEF_Position_X = packet_in.ECEF_Position_X;
        packet1.ECEF_Position_Y = packet_in.ECEF_Position_Y;
        packet1.ECEF_Position_Z = packet_in.ECEF_Position_Z;
        packet1.ECEF_Velocity_X = packet_in.ECEF_Velocity_X;
        packet1.ECEF_Velocity_Y = packet_in.ECEF_Velocity_Y;
        packet1.ECEF_Velocity_Z = packet_in.ECEF_Velocity_Z;
        packet1.Quaternion_0 = packet_in.Quaternion_0;
        packet1.Quaternion_1 = packet_in.Quaternion_1;
        packet1.Quaternion_2 = packet_in.Quaternion_2;
        packet1.Quaternion_3 = packet_in.Quaternion_3;
        packet1.Air_Speed_U = packet_in.Air_Speed_U;
        packet1.Air_Speed_V = packet_in.Air_Speed_V;
        packet1.Air_Speed_W = packet_in.Air_Speed_W;
        packet1.Air_Temperature = packet_in.Air_Temperature;
        packet1.Velocity_Horizontal = packet_in.Velocity_Horizontal;
        packet1.Velocity_Vertical = packet_in.Velocity_Vertical;
        packet1.Position_Accuracy = packet_in.Position_Accuracy;
        packet1.Speed_Accuracy = packet_in.Speed_Accuracy;
        packet1.Acceleration_X = packet_in.Acceleration_X;
        packet1.Acceleration_Y = packet_in.Acceleration_Y;
        packet1.Acceleration_Z = packet_in.Acceleration_Z;
        packet1.Roll_Angle = packet_in.Roll_Angle;
        packet1.Pitch_Angle = packet_in.Pitch_Angle;
        packet1.Yaw_Angle = packet_in.Yaw_Angle;
        packet1.Angular_Rate_Roll = packet_in.Angular_Rate_Roll;
        packet1.Angular_Rate_Pitch = packet_in.Angular_Rate_Pitch;
        packet1.Angular_Rate_Yaw = packet_in.Angular_Rate_Yaw;
        packet1.Satellite_Num = packet_in.Satellite_Num;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_TELEMETRY_DATA_PACK_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_TELEMETRY_DATA_PACK_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_telemetry_data_pack_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_telemetry_data_pack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_telemetry_data_pack_pack(system_id, component_id, &msg , packet1.Log_Timestamp , packet1.GNSS_Timestamp , packet1.Latitude , packet1.Longitude , packet1.GNSS_Altitude , packet1.Air_Speed_U , packet1.Air_Speed_V , packet1.Air_Speed_W , packet1.Air_Temperature , packet1.Altitude_Main_Altimeter , packet1.Altitude_Payload_Altimeter , packet1.Velocity_Horizontal , packet1.Velocity_Vertical , packet1.Position_Accuracy , packet1.Speed_Accuracy , packet1.Acceleration_X , packet1.Acceleration_Y , packet1.Acceleration_Z , packet1.ECEF_Position_X , packet1.ECEF_Position_Y , packet1.ECEF_Position_Z , packet1.ECEF_Velocity_X , packet1.ECEF_Velocity_Y , packet1.ECEF_Velocity_Z , packet1.Roll_Angle , packet1.Pitch_Angle , packet1.Yaw_Angle , packet1.Angular_Rate_Roll , packet1.Angular_Rate_Pitch , packet1.Angular_Rate_Yaw , packet1.Quaternion_0 , packet1.Quaternion_1 , packet1.Quaternion_2 , packet1.Quaternion_3 , packet1.Telemetry_Status_Mask , packet1.Satellite_Num );
    mavlink_msg_telemetry_data_pack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_telemetry_data_pack_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.Log_Timestamp , packet1.GNSS_Timestamp , packet1.Latitude , packet1.Longitude , packet1.GNSS_Altitude , packet1.Air_Speed_U , packet1.Air_Speed_V , packet1.Air_Speed_W , packet1.Air_Temperature , packet1.Altitude_Main_Altimeter , packet1.Altitude_Payload_Altimeter , packet1.Velocity_Horizontal , packet1.Velocity_Vertical , packet1.Position_Accuracy , packet1.Speed_Accuracy , packet1.Acceleration_X , packet1.Acceleration_Y , packet1.Acceleration_Z , packet1.ECEF_Position_X , packet1.ECEF_Position_Y , packet1.ECEF_Position_Z , packet1.ECEF_Velocity_X , packet1.ECEF_Velocity_Y , packet1.ECEF_Velocity_Z , packet1.Roll_Angle , packet1.Pitch_Angle , packet1.Yaw_Angle , packet1.Angular_Rate_Roll , packet1.Angular_Rate_Pitch , packet1.Angular_Rate_Yaw , packet1.Quaternion_0 , packet1.Quaternion_1 , packet1.Quaternion_2 , packet1.Quaternion_3 , packet1.Telemetry_Status_Mask , packet1.Satellite_Num );
    mavlink_msg_telemetry_data_pack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_telemetry_data_pack_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_telemetry_data_pack_send(MAVLINK_COMM_1 , packet1.Log_Timestamp , packet1.GNSS_Timestamp , packet1.Latitude , packet1.Longitude , packet1.GNSS_Altitude , packet1.Air_Speed_U , packet1.Air_Speed_V , packet1.Air_Speed_W , packet1.Air_Temperature , packet1.Altitude_Main_Altimeter , packet1.Altitude_Payload_Altimeter , packet1.Velocity_Horizontal , packet1.Velocity_Vertical , packet1.Position_Accuracy , packet1.Speed_Accuracy , packet1.Acceleration_X , packet1.Acceleration_Y , packet1.Acceleration_Z , packet1.ECEF_Position_X , packet1.ECEF_Position_Y , packet1.ECEF_Position_Z , packet1.ECEF_Velocity_X , packet1.ECEF_Velocity_Y , packet1.ECEF_Velocity_Z , packet1.Roll_Angle , packet1.Pitch_Angle , packet1.Yaw_Angle , packet1.Angular_Rate_Roll , packet1.Angular_Rate_Pitch , packet1.Angular_Rate_Yaw , packet1.Quaternion_0 , packet1.Quaternion_1 , packet1.Quaternion_2 , packet1.Quaternion_3 , packet1.Telemetry_Status_Mask , packet1.Satellite_Num );
    mavlink_msg_telemetry_data_pack_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("TELEMETRY_DATA_PACK") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_TELEMETRY_DATA_PACK) != NULL);
#endif
}

static void mavlink_test_motor_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_MOTOR_STATUS_PACK >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_motor_status_pack_t packet_in = {
        93372036854775807ULL,963497880,963498088,963498296,963498504,963498712,963498920,963499128,963499336,963499544,963499752,19731,19835,19939,20043,20147
    };
    mavlink_motor_status_pack_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.Log_Timestamp = packet_in.Log_Timestamp;
        packet1.Motor_A_Real_Position = packet_in.Motor_A_Real_Position;
        packet1.Motor_B_Real_Position = packet_in.Motor_B_Real_Position;
        packet1.Motor_A_Demand_Position = packet_in.Motor_A_Demand_Position;
        packet1.Motor_B_Demand_Position = packet_in.Motor_B_Demand_Position;
        packet1.Motor_A_Torque = packet_in.Motor_A_Torque;
        packet1.Motor_B_Torque = packet_in.Motor_B_Torque;
        packet1.Motor_Control_Status_Mask = packet_in.Motor_Control_Status_Mask;
        packet1.Motor_A_Faults_Mask = packet_in.Motor_A_Faults_Mask;
        packet1.Motor_B_Faults_Mask = packet_in.Motor_B_Faults_Mask;
        packet1.BMS_Faults_Mask = packet_in.BMS_Faults_Mask;
        packet1.Motor_A_Temperature = packet_in.Motor_A_Temperature;
        packet1.Motor_B_Temperature = packet_in.Motor_B_Temperature;
        packet1.BMS_Voltage = packet_in.BMS_Voltage;
        packet1.BMS_Absorption = packet_in.BMS_Absorption;
        packet1.BMS_Temperature = packet_in.BMS_Temperature;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_MOTOR_STATUS_PACK_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_MOTOR_STATUS_PACK_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_motor_status_pack_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_motor_status_pack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_motor_status_pack_pack(system_id, component_id, &msg , packet1.Log_Timestamp , packet1.Motor_A_Real_Position , packet1.Motor_B_Real_Position , packet1.Motor_A_Demand_Position , packet1.Motor_B_Demand_Position , packet1.Motor_A_Torque , packet1.Motor_B_Torque , packet1.Motor_A_Temperature , packet1.Motor_B_Temperature , packet1.BMS_Voltage , packet1.BMS_Absorption , packet1.BMS_Temperature , packet1.Motor_Control_Status_Mask , packet1.Motor_A_Faults_Mask , packet1.Motor_B_Faults_Mask , packet1.BMS_Faults_Mask );
    mavlink_msg_motor_status_pack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_motor_status_pack_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.Log_Timestamp , packet1.Motor_A_Real_Position , packet1.Motor_B_Real_Position , packet1.Motor_A_Demand_Position , packet1.Motor_B_Demand_Position , packet1.Motor_A_Torque , packet1.Motor_B_Torque , packet1.Motor_A_Temperature , packet1.Motor_B_Temperature , packet1.BMS_Voltage , packet1.BMS_Absorption , packet1.BMS_Temperature , packet1.Motor_Control_Status_Mask , packet1.Motor_A_Faults_Mask , packet1.Motor_B_Faults_Mask , packet1.BMS_Faults_Mask );
    mavlink_msg_motor_status_pack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_motor_status_pack_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_motor_status_pack_send(MAVLINK_COMM_1 , packet1.Log_Timestamp , packet1.Motor_A_Real_Position , packet1.Motor_B_Real_Position , packet1.Motor_A_Demand_Position , packet1.Motor_B_Demand_Position , packet1.Motor_A_Torque , packet1.Motor_B_Torque , packet1.Motor_A_Temperature , packet1.Motor_B_Temperature , packet1.BMS_Voltage , packet1.BMS_Absorption , packet1.BMS_Temperature , packet1.Motor_Control_Status_Mask , packet1.Motor_A_Faults_Mask , packet1.Motor_B_Faults_Mask , packet1.BMS_Faults_Mask );
    mavlink_msg_motor_status_pack_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("MOTOR_STATUS_PACK") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_MOTOR_STATUS_PACK) != NULL);
#endif
}

static void mavlink_test_AGU_MAVLINK(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_system_status_pack(system_id, component_id, last_msg);
    mavlink_test_telemetry_data_pack(system_id, component_id, last_msg);
    mavlink_test_motor_status_pack(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // AGU_MAVLINK_TESTSUITE_H
