#pragma once
// MESSAGE MOTOR_STATUS_PACK PACKING

#define MAVLINK_MSG_ID_MOTOR_STATUS_PACK 13002


typedef struct __mavlink_motor_status_pack_t {
 uint64_t Log_Timestamp; /*< [ms] Log timestamp since 1.1.1970 UTC.*/
 int32_t Motor_A_Real_Position; /*<  Motor A real position (Adimensional value) 10^3*/
 int32_t Motor_B_Real_Position; /*<  Motor B real position (Adimensional value) 10^3*/
 int32_t Motor_A_Demand_Position; /*<  Motor A demand position (Adimensional value) 10^3*/
 int32_t Motor_B_Demand_Position; /*<  Motor B demand position (Adimensional value) 10^3*/
 int32_t Motor_A_Torque; /*< [Nm] Motor A torque 10^2*/
 int32_t Motor_B_Torque; /*< [Nm] Motor B torque 10^2*/
 uint32_t Motor_Control_Status_Mask; /*<  Motor control module status mask*/
 uint32_t Motor_A_Faults_Mask; /*<  Motor A faults mask*/
 uint32_t Motor_B_Faults_Mask; /*<  Motor B faults mask*/
 uint32_t BMS_Faults_Mask; /*<  Battery management system faults mask*/
 int16_t Motor_A_Temperature; /*< [°C] Motor A temperature 10^2*/
 int16_t Motor_B_Temperature; /*< [°C] Motor B temperature 10^2*/
 uint16_t BMS_Voltage; /*< [V] Battery management system voltage 10^2*/
 int16_t BMS_Absorption; /*< [A] Battery management system current absorption 10^2*/
 int16_t BMS_Temperature; /*< [°C] Battery management system temperature 10^2*/
} mavlink_motor_status_pack_t;

#define MAVLINK_MSG_ID_MOTOR_STATUS_PACK_LEN 58
#define MAVLINK_MSG_ID_MOTOR_STATUS_PACK_MIN_LEN 58
#define MAVLINK_MSG_ID_13002_LEN 58
#define MAVLINK_MSG_ID_13002_MIN_LEN 58

#define MAVLINK_MSG_ID_MOTOR_STATUS_PACK_CRC 197
#define MAVLINK_MSG_ID_13002_CRC 197



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MOTOR_STATUS_PACK { \
    13002, \
    "MOTOR_STATUS_PACK", \
    16, \
    {  { "Log_Timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_motor_status_pack_t, Log_Timestamp) }, \
         { "Motor_A_Real_Position", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_motor_status_pack_t, Motor_A_Real_Position) }, \
         { "Motor_B_Real_Position", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_motor_status_pack_t, Motor_B_Real_Position) }, \
         { "Motor_A_Demand_Position", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_motor_status_pack_t, Motor_A_Demand_Position) }, \
         { "Motor_B_Demand_Position", NULL, MAVLINK_TYPE_INT32_T, 0, 20, offsetof(mavlink_motor_status_pack_t, Motor_B_Demand_Position) }, \
         { "Motor_A_Torque", NULL, MAVLINK_TYPE_INT32_T, 0, 24, offsetof(mavlink_motor_status_pack_t, Motor_A_Torque) }, \
         { "Motor_B_Torque", NULL, MAVLINK_TYPE_INT32_T, 0, 28, offsetof(mavlink_motor_status_pack_t, Motor_B_Torque) }, \
         { "Motor_A_Temperature", NULL, MAVLINK_TYPE_INT16_T, 0, 48, offsetof(mavlink_motor_status_pack_t, Motor_A_Temperature) }, \
         { "Motor_B_Temperature", NULL, MAVLINK_TYPE_INT16_T, 0, 50, offsetof(mavlink_motor_status_pack_t, Motor_B_Temperature) }, \
         { "BMS_Voltage", NULL, MAVLINK_TYPE_UINT16_T, 0, 52, offsetof(mavlink_motor_status_pack_t, BMS_Voltage) }, \
         { "BMS_Absorption", NULL, MAVLINK_TYPE_INT16_T, 0, 54, offsetof(mavlink_motor_status_pack_t, BMS_Absorption) }, \
         { "BMS_Temperature", NULL, MAVLINK_TYPE_INT16_T, 0, 56, offsetof(mavlink_motor_status_pack_t, BMS_Temperature) }, \
         { "Motor_Control_Status_Mask", NULL, MAVLINK_TYPE_UINT32_T, 0, 32, offsetof(mavlink_motor_status_pack_t, Motor_Control_Status_Mask) }, \
         { "Motor_A_Faults_Mask", NULL, MAVLINK_TYPE_UINT32_T, 0, 36, offsetof(mavlink_motor_status_pack_t, Motor_A_Faults_Mask) }, \
         { "Motor_B_Faults_Mask", NULL, MAVLINK_TYPE_UINT32_T, 0, 40, offsetof(mavlink_motor_status_pack_t, Motor_B_Faults_Mask) }, \
         { "BMS_Faults_Mask", NULL, MAVLINK_TYPE_UINT32_T, 0, 44, offsetof(mavlink_motor_status_pack_t, BMS_Faults_Mask) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MOTOR_STATUS_PACK { \
    "MOTOR_STATUS_PACK", \
    16, \
    {  { "Log_Timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_motor_status_pack_t, Log_Timestamp) }, \
         { "Motor_A_Real_Position", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_motor_status_pack_t, Motor_A_Real_Position) }, \
         { "Motor_B_Real_Position", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_motor_status_pack_t, Motor_B_Real_Position) }, \
         { "Motor_A_Demand_Position", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_motor_status_pack_t, Motor_A_Demand_Position) }, \
         { "Motor_B_Demand_Position", NULL, MAVLINK_TYPE_INT32_T, 0, 20, offsetof(mavlink_motor_status_pack_t, Motor_B_Demand_Position) }, \
         { "Motor_A_Torque", NULL, MAVLINK_TYPE_INT32_T, 0, 24, offsetof(mavlink_motor_status_pack_t, Motor_A_Torque) }, \
         { "Motor_B_Torque", NULL, MAVLINK_TYPE_INT32_T, 0, 28, offsetof(mavlink_motor_status_pack_t, Motor_B_Torque) }, \
         { "Motor_A_Temperature", NULL, MAVLINK_TYPE_INT16_T, 0, 48, offsetof(mavlink_motor_status_pack_t, Motor_A_Temperature) }, \
         { "Motor_B_Temperature", NULL, MAVLINK_TYPE_INT16_T, 0, 50, offsetof(mavlink_motor_status_pack_t, Motor_B_Temperature) }, \
         { "BMS_Voltage", NULL, MAVLINK_TYPE_UINT16_T, 0, 52, offsetof(mavlink_motor_status_pack_t, BMS_Voltage) }, \
         { "BMS_Absorption", NULL, MAVLINK_TYPE_INT16_T, 0, 54, offsetof(mavlink_motor_status_pack_t, BMS_Absorption) }, \
         { "BMS_Temperature", NULL, MAVLINK_TYPE_INT16_T, 0, 56, offsetof(mavlink_motor_status_pack_t, BMS_Temperature) }, \
         { "Motor_Control_Status_Mask", NULL, MAVLINK_TYPE_UINT32_T, 0, 32, offsetof(mavlink_motor_status_pack_t, Motor_Control_Status_Mask) }, \
         { "Motor_A_Faults_Mask", NULL, MAVLINK_TYPE_UINT32_T, 0, 36, offsetof(mavlink_motor_status_pack_t, Motor_A_Faults_Mask) }, \
         { "Motor_B_Faults_Mask", NULL, MAVLINK_TYPE_UINT32_T, 0, 40, offsetof(mavlink_motor_status_pack_t, Motor_B_Faults_Mask) }, \
         { "BMS_Faults_Mask", NULL, MAVLINK_TYPE_UINT32_T, 0, 44, offsetof(mavlink_motor_status_pack_t, BMS_Faults_Mask) }, \
         } \
}
#endif

/**
 * @brief Pack a motor_status_pack message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param Log_Timestamp [ms] Log timestamp since 1.1.1970 UTC.
 * @param Motor_A_Real_Position  Motor A real position (Adimensional value) 10^3
 * @param Motor_B_Real_Position  Motor B real position (Adimensional value) 10^3
 * @param Motor_A_Demand_Position  Motor A demand position (Adimensional value) 10^3
 * @param Motor_B_Demand_Position  Motor B demand position (Adimensional value) 10^3
 * @param Motor_A_Torque [Nm] Motor A torque 10^2
 * @param Motor_B_Torque [Nm] Motor B torque 10^2
 * @param Motor_A_Temperature [°C] Motor A temperature 10^2
 * @param Motor_B_Temperature [°C] Motor B temperature 10^2
 * @param BMS_Voltage [V] Battery management system voltage 10^2
 * @param BMS_Absorption [A] Battery management system current absorption 10^2
 * @param BMS_Temperature [°C] Battery management system temperature 10^2
 * @param Motor_Control_Status_Mask  Motor control module status mask
 * @param Motor_A_Faults_Mask  Motor A faults mask
 * @param Motor_B_Faults_Mask  Motor B faults mask
 * @param BMS_Faults_Mask  Battery management system faults mask
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_motor_status_pack_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t Log_Timestamp, int32_t Motor_A_Real_Position, int32_t Motor_B_Real_Position, int32_t Motor_A_Demand_Position, int32_t Motor_B_Demand_Position, int32_t Motor_A_Torque, int32_t Motor_B_Torque, int16_t Motor_A_Temperature, int16_t Motor_B_Temperature, uint16_t BMS_Voltage, int16_t BMS_Absorption, int16_t BMS_Temperature, uint32_t Motor_Control_Status_Mask, uint32_t Motor_A_Faults_Mask, uint32_t Motor_B_Faults_Mask, uint32_t BMS_Faults_Mask)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MOTOR_STATUS_PACK_LEN];
    _mav_put_uint64_t(buf, 0, Log_Timestamp);
    _mav_put_int32_t(buf, 8, Motor_A_Real_Position);
    _mav_put_int32_t(buf, 12, Motor_B_Real_Position);
    _mav_put_int32_t(buf, 16, Motor_A_Demand_Position);
    _mav_put_int32_t(buf, 20, Motor_B_Demand_Position);
    _mav_put_int32_t(buf, 24, Motor_A_Torque);
    _mav_put_int32_t(buf, 28, Motor_B_Torque);
    _mav_put_uint32_t(buf, 32, Motor_Control_Status_Mask);
    _mav_put_uint32_t(buf, 36, Motor_A_Faults_Mask);
    _mav_put_uint32_t(buf, 40, Motor_B_Faults_Mask);
    _mav_put_uint32_t(buf, 44, BMS_Faults_Mask);
    _mav_put_int16_t(buf, 48, Motor_A_Temperature);
    _mav_put_int16_t(buf, 50, Motor_B_Temperature);
    _mav_put_uint16_t(buf, 52, BMS_Voltage);
    _mav_put_int16_t(buf, 54, BMS_Absorption);
    _mav_put_int16_t(buf, 56, BMS_Temperature);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MOTOR_STATUS_PACK_LEN);
#else
    mavlink_motor_status_pack_t packet;
    packet.Log_Timestamp = Log_Timestamp;
    packet.Motor_A_Real_Position = Motor_A_Real_Position;
    packet.Motor_B_Real_Position = Motor_B_Real_Position;
    packet.Motor_A_Demand_Position = Motor_A_Demand_Position;
    packet.Motor_B_Demand_Position = Motor_B_Demand_Position;
    packet.Motor_A_Torque = Motor_A_Torque;
    packet.Motor_B_Torque = Motor_B_Torque;
    packet.Motor_Control_Status_Mask = Motor_Control_Status_Mask;
    packet.Motor_A_Faults_Mask = Motor_A_Faults_Mask;
    packet.Motor_B_Faults_Mask = Motor_B_Faults_Mask;
    packet.BMS_Faults_Mask = BMS_Faults_Mask;
    packet.Motor_A_Temperature = Motor_A_Temperature;
    packet.Motor_B_Temperature = Motor_B_Temperature;
    packet.BMS_Voltage = BMS_Voltage;
    packet.BMS_Absorption = BMS_Absorption;
    packet.BMS_Temperature = BMS_Temperature;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MOTOR_STATUS_PACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MOTOR_STATUS_PACK;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MOTOR_STATUS_PACK_MIN_LEN, MAVLINK_MSG_ID_MOTOR_STATUS_PACK_LEN, MAVLINK_MSG_ID_MOTOR_STATUS_PACK_CRC);
}

/**
 * @brief Pack a motor_status_pack message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param Log_Timestamp [ms] Log timestamp since 1.1.1970 UTC.
 * @param Motor_A_Real_Position  Motor A real position (Adimensional value) 10^3
 * @param Motor_B_Real_Position  Motor B real position (Adimensional value) 10^3
 * @param Motor_A_Demand_Position  Motor A demand position (Adimensional value) 10^3
 * @param Motor_B_Demand_Position  Motor B demand position (Adimensional value) 10^3
 * @param Motor_A_Torque [Nm] Motor A torque 10^2
 * @param Motor_B_Torque [Nm] Motor B torque 10^2
 * @param Motor_A_Temperature [°C] Motor A temperature 10^2
 * @param Motor_B_Temperature [°C] Motor B temperature 10^2
 * @param BMS_Voltage [V] Battery management system voltage 10^2
 * @param BMS_Absorption [A] Battery management system current absorption 10^2
 * @param BMS_Temperature [°C] Battery management system temperature 10^2
 * @param Motor_Control_Status_Mask  Motor control module status mask
 * @param Motor_A_Faults_Mask  Motor A faults mask
 * @param Motor_B_Faults_Mask  Motor B faults mask
 * @param BMS_Faults_Mask  Battery management system faults mask
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_motor_status_pack_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t Log_Timestamp,int32_t Motor_A_Real_Position,int32_t Motor_B_Real_Position,int32_t Motor_A_Demand_Position,int32_t Motor_B_Demand_Position,int32_t Motor_A_Torque,int32_t Motor_B_Torque,int16_t Motor_A_Temperature,int16_t Motor_B_Temperature,uint16_t BMS_Voltage,int16_t BMS_Absorption,int16_t BMS_Temperature,uint32_t Motor_Control_Status_Mask,uint32_t Motor_A_Faults_Mask,uint32_t Motor_B_Faults_Mask,uint32_t BMS_Faults_Mask)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MOTOR_STATUS_PACK_LEN];
    _mav_put_uint64_t(buf, 0, Log_Timestamp);
    _mav_put_int32_t(buf, 8, Motor_A_Real_Position);
    _mav_put_int32_t(buf, 12, Motor_B_Real_Position);
    _mav_put_int32_t(buf, 16, Motor_A_Demand_Position);
    _mav_put_int32_t(buf, 20, Motor_B_Demand_Position);
    _mav_put_int32_t(buf, 24, Motor_A_Torque);
    _mav_put_int32_t(buf, 28, Motor_B_Torque);
    _mav_put_uint32_t(buf, 32, Motor_Control_Status_Mask);
    _mav_put_uint32_t(buf, 36, Motor_A_Faults_Mask);
    _mav_put_uint32_t(buf, 40, Motor_B_Faults_Mask);
    _mav_put_uint32_t(buf, 44, BMS_Faults_Mask);
    _mav_put_int16_t(buf, 48, Motor_A_Temperature);
    _mav_put_int16_t(buf, 50, Motor_B_Temperature);
    _mav_put_uint16_t(buf, 52, BMS_Voltage);
    _mav_put_int16_t(buf, 54, BMS_Absorption);
    _mav_put_int16_t(buf, 56, BMS_Temperature);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MOTOR_STATUS_PACK_LEN);
#else
    mavlink_motor_status_pack_t packet;
    packet.Log_Timestamp = Log_Timestamp;
    packet.Motor_A_Real_Position = Motor_A_Real_Position;
    packet.Motor_B_Real_Position = Motor_B_Real_Position;
    packet.Motor_A_Demand_Position = Motor_A_Demand_Position;
    packet.Motor_B_Demand_Position = Motor_B_Demand_Position;
    packet.Motor_A_Torque = Motor_A_Torque;
    packet.Motor_B_Torque = Motor_B_Torque;
    packet.Motor_Control_Status_Mask = Motor_Control_Status_Mask;
    packet.Motor_A_Faults_Mask = Motor_A_Faults_Mask;
    packet.Motor_B_Faults_Mask = Motor_B_Faults_Mask;
    packet.BMS_Faults_Mask = BMS_Faults_Mask;
    packet.Motor_A_Temperature = Motor_A_Temperature;
    packet.Motor_B_Temperature = Motor_B_Temperature;
    packet.BMS_Voltage = BMS_Voltage;
    packet.BMS_Absorption = BMS_Absorption;
    packet.BMS_Temperature = BMS_Temperature;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MOTOR_STATUS_PACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MOTOR_STATUS_PACK;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MOTOR_STATUS_PACK_MIN_LEN, MAVLINK_MSG_ID_MOTOR_STATUS_PACK_LEN, MAVLINK_MSG_ID_MOTOR_STATUS_PACK_CRC);
}

/**
 * @brief Encode a motor_status_pack struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param motor_status_pack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_motor_status_pack_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_motor_status_pack_t* motor_status_pack)
{
    return mavlink_msg_motor_status_pack_pack(system_id, component_id, msg, motor_status_pack->Log_Timestamp, motor_status_pack->Motor_A_Real_Position, motor_status_pack->Motor_B_Real_Position, motor_status_pack->Motor_A_Demand_Position, motor_status_pack->Motor_B_Demand_Position, motor_status_pack->Motor_A_Torque, motor_status_pack->Motor_B_Torque, motor_status_pack->Motor_A_Temperature, motor_status_pack->Motor_B_Temperature, motor_status_pack->BMS_Voltage, motor_status_pack->BMS_Absorption, motor_status_pack->BMS_Temperature, motor_status_pack->Motor_Control_Status_Mask, motor_status_pack->Motor_A_Faults_Mask, motor_status_pack->Motor_B_Faults_Mask, motor_status_pack->BMS_Faults_Mask);
}

/**
 * @brief Encode a motor_status_pack struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param motor_status_pack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_motor_status_pack_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_motor_status_pack_t* motor_status_pack)
{
    return mavlink_msg_motor_status_pack_pack_chan(system_id, component_id, chan, msg, motor_status_pack->Log_Timestamp, motor_status_pack->Motor_A_Real_Position, motor_status_pack->Motor_B_Real_Position, motor_status_pack->Motor_A_Demand_Position, motor_status_pack->Motor_B_Demand_Position, motor_status_pack->Motor_A_Torque, motor_status_pack->Motor_B_Torque, motor_status_pack->Motor_A_Temperature, motor_status_pack->Motor_B_Temperature, motor_status_pack->BMS_Voltage, motor_status_pack->BMS_Absorption, motor_status_pack->BMS_Temperature, motor_status_pack->Motor_Control_Status_Mask, motor_status_pack->Motor_A_Faults_Mask, motor_status_pack->Motor_B_Faults_Mask, motor_status_pack->BMS_Faults_Mask);
}

/**
 * @brief Send a motor_status_pack message
 * @param chan MAVLink channel to send the message
 *
 * @param Log_Timestamp [ms] Log timestamp since 1.1.1970 UTC.
 * @param Motor_A_Real_Position  Motor A real position (Adimensional value) 10^3
 * @param Motor_B_Real_Position  Motor B real position (Adimensional value) 10^3
 * @param Motor_A_Demand_Position  Motor A demand position (Adimensional value) 10^3
 * @param Motor_B_Demand_Position  Motor B demand position (Adimensional value) 10^3
 * @param Motor_A_Torque [Nm] Motor A torque 10^2
 * @param Motor_B_Torque [Nm] Motor B torque 10^2
 * @param Motor_A_Temperature [°C] Motor A temperature 10^2
 * @param Motor_B_Temperature [°C] Motor B temperature 10^2
 * @param BMS_Voltage [V] Battery management system voltage 10^2
 * @param BMS_Absorption [A] Battery management system current absorption 10^2
 * @param BMS_Temperature [°C] Battery management system temperature 10^2
 * @param Motor_Control_Status_Mask  Motor control module status mask
 * @param Motor_A_Faults_Mask  Motor A faults mask
 * @param Motor_B_Faults_Mask  Motor B faults mask
 * @param BMS_Faults_Mask  Battery management system faults mask
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_motor_status_pack_send(mavlink_channel_t chan, uint64_t Log_Timestamp, int32_t Motor_A_Real_Position, int32_t Motor_B_Real_Position, int32_t Motor_A_Demand_Position, int32_t Motor_B_Demand_Position, int32_t Motor_A_Torque, int32_t Motor_B_Torque, int16_t Motor_A_Temperature, int16_t Motor_B_Temperature, uint16_t BMS_Voltage, int16_t BMS_Absorption, int16_t BMS_Temperature, uint32_t Motor_Control_Status_Mask, uint32_t Motor_A_Faults_Mask, uint32_t Motor_B_Faults_Mask, uint32_t BMS_Faults_Mask)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MOTOR_STATUS_PACK_LEN];
    _mav_put_uint64_t(buf, 0, Log_Timestamp);
    _mav_put_int32_t(buf, 8, Motor_A_Real_Position);
    _mav_put_int32_t(buf, 12, Motor_B_Real_Position);
    _mav_put_int32_t(buf, 16, Motor_A_Demand_Position);
    _mav_put_int32_t(buf, 20, Motor_B_Demand_Position);
    _mav_put_int32_t(buf, 24, Motor_A_Torque);
    _mav_put_int32_t(buf, 28, Motor_B_Torque);
    _mav_put_uint32_t(buf, 32, Motor_Control_Status_Mask);
    _mav_put_uint32_t(buf, 36, Motor_A_Faults_Mask);
    _mav_put_uint32_t(buf, 40, Motor_B_Faults_Mask);
    _mav_put_uint32_t(buf, 44, BMS_Faults_Mask);
    _mav_put_int16_t(buf, 48, Motor_A_Temperature);
    _mav_put_int16_t(buf, 50, Motor_B_Temperature);
    _mav_put_uint16_t(buf, 52, BMS_Voltage);
    _mav_put_int16_t(buf, 54, BMS_Absorption);
    _mav_put_int16_t(buf, 56, BMS_Temperature);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_STATUS_PACK, buf, MAVLINK_MSG_ID_MOTOR_STATUS_PACK_MIN_LEN, MAVLINK_MSG_ID_MOTOR_STATUS_PACK_LEN, MAVLINK_MSG_ID_MOTOR_STATUS_PACK_CRC);
#else
    mavlink_motor_status_pack_t packet;
    packet.Log_Timestamp = Log_Timestamp;
    packet.Motor_A_Real_Position = Motor_A_Real_Position;
    packet.Motor_B_Real_Position = Motor_B_Real_Position;
    packet.Motor_A_Demand_Position = Motor_A_Demand_Position;
    packet.Motor_B_Demand_Position = Motor_B_Demand_Position;
    packet.Motor_A_Torque = Motor_A_Torque;
    packet.Motor_B_Torque = Motor_B_Torque;
    packet.Motor_Control_Status_Mask = Motor_Control_Status_Mask;
    packet.Motor_A_Faults_Mask = Motor_A_Faults_Mask;
    packet.Motor_B_Faults_Mask = Motor_B_Faults_Mask;
    packet.BMS_Faults_Mask = BMS_Faults_Mask;
    packet.Motor_A_Temperature = Motor_A_Temperature;
    packet.Motor_B_Temperature = Motor_B_Temperature;
    packet.BMS_Voltage = BMS_Voltage;
    packet.BMS_Absorption = BMS_Absorption;
    packet.BMS_Temperature = BMS_Temperature;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_STATUS_PACK, (const char *)&packet, MAVLINK_MSG_ID_MOTOR_STATUS_PACK_MIN_LEN, MAVLINK_MSG_ID_MOTOR_STATUS_PACK_LEN, MAVLINK_MSG_ID_MOTOR_STATUS_PACK_CRC);
#endif
}

/**
 * @brief Send a motor_status_pack message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_motor_status_pack_send_struct(mavlink_channel_t chan, const mavlink_motor_status_pack_t* motor_status_pack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_motor_status_pack_send(chan, motor_status_pack->Log_Timestamp, motor_status_pack->Motor_A_Real_Position, motor_status_pack->Motor_B_Real_Position, motor_status_pack->Motor_A_Demand_Position, motor_status_pack->Motor_B_Demand_Position, motor_status_pack->Motor_A_Torque, motor_status_pack->Motor_B_Torque, motor_status_pack->Motor_A_Temperature, motor_status_pack->Motor_B_Temperature, motor_status_pack->BMS_Voltage, motor_status_pack->BMS_Absorption, motor_status_pack->BMS_Temperature, motor_status_pack->Motor_Control_Status_Mask, motor_status_pack->Motor_A_Faults_Mask, motor_status_pack->Motor_B_Faults_Mask, motor_status_pack->BMS_Faults_Mask);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_STATUS_PACK, (const char *)motor_status_pack, MAVLINK_MSG_ID_MOTOR_STATUS_PACK_MIN_LEN, MAVLINK_MSG_ID_MOTOR_STATUS_PACK_LEN, MAVLINK_MSG_ID_MOTOR_STATUS_PACK_CRC);
#endif
}

#if MAVLINK_MSG_ID_MOTOR_STATUS_PACK_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_motor_status_pack_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t Log_Timestamp, int32_t Motor_A_Real_Position, int32_t Motor_B_Real_Position, int32_t Motor_A_Demand_Position, int32_t Motor_B_Demand_Position, int32_t Motor_A_Torque, int32_t Motor_B_Torque, int16_t Motor_A_Temperature, int16_t Motor_B_Temperature, uint16_t BMS_Voltage, int16_t BMS_Absorption, int16_t BMS_Temperature, uint32_t Motor_Control_Status_Mask, uint32_t Motor_A_Faults_Mask, uint32_t Motor_B_Faults_Mask, uint32_t BMS_Faults_Mask)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, Log_Timestamp);
    _mav_put_int32_t(buf, 8, Motor_A_Real_Position);
    _mav_put_int32_t(buf, 12, Motor_B_Real_Position);
    _mav_put_int32_t(buf, 16, Motor_A_Demand_Position);
    _mav_put_int32_t(buf, 20, Motor_B_Demand_Position);
    _mav_put_int32_t(buf, 24, Motor_A_Torque);
    _mav_put_int32_t(buf, 28, Motor_B_Torque);
    _mav_put_uint32_t(buf, 32, Motor_Control_Status_Mask);
    _mav_put_uint32_t(buf, 36, Motor_A_Faults_Mask);
    _mav_put_uint32_t(buf, 40, Motor_B_Faults_Mask);
    _mav_put_uint32_t(buf, 44, BMS_Faults_Mask);
    _mav_put_int16_t(buf, 48, Motor_A_Temperature);
    _mav_put_int16_t(buf, 50, Motor_B_Temperature);
    _mav_put_uint16_t(buf, 52, BMS_Voltage);
    _mav_put_int16_t(buf, 54, BMS_Absorption);
    _mav_put_int16_t(buf, 56, BMS_Temperature);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_STATUS_PACK, buf, MAVLINK_MSG_ID_MOTOR_STATUS_PACK_MIN_LEN, MAVLINK_MSG_ID_MOTOR_STATUS_PACK_LEN, MAVLINK_MSG_ID_MOTOR_STATUS_PACK_CRC);
#else
    mavlink_motor_status_pack_t *packet = (mavlink_motor_status_pack_t *)msgbuf;
    packet->Log_Timestamp = Log_Timestamp;
    packet->Motor_A_Real_Position = Motor_A_Real_Position;
    packet->Motor_B_Real_Position = Motor_B_Real_Position;
    packet->Motor_A_Demand_Position = Motor_A_Demand_Position;
    packet->Motor_B_Demand_Position = Motor_B_Demand_Position;
    packet->Motor_A_Torque = Motor_A_Torque;
    packet->Motor_B_Torque = Motor_B_Torque;
    packet->Motor_Control_Status_Mask = Motor_Control_Status_Mask;
    packet->Motor_A_Faults_Mask = Motor_A_Faults_Mask;
    packet->Motor_B_Faults_Mask = Motor_B_Faults_Mask;
    packet->BMS_Faults_Mask = BMS_Faults_Mask;
    packet->Motor_A_Temperature = Motor_A_Temperature;
    packet->Motor_B_Temperature = Motor_B_Temperature;
    packet->BMS_Voltage = BMS_Voltage;
    packet->BMS_Absorption = BMS_Absorption;
    packet->BMS_Temperature = BMS_Temperature;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_STATUS_PACK, (const char *)packet, MAVLINK_MSG_ID_MOTOR_STATUS_PACK_MIN_LEN, MAVLINK_MSG_ID_MOTOR_STATUS_PACK_LEN, MAVLINK_MSG_ID_MOTOR_STATUS_PACK_CRC);
#endif
}
#endif

#endif

// MESSAGE MOTOR_STATUS_PACK UNPACKING


/**
 * @brief Get field Log_Timestamp from motor_status_pack message
 *
 * @return [ms] Log timestamp since 1.1.1970 UTC.
 */
static inline uint64_t mavlink_msg_motor_status_pack_get_Log_Timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field Motor_A_Real_Position from motor_status_pack message
 *
 * @return  Motor A real position (Adimensional value) 10^3
 */
static inline int32_t mavlink_msg_motor_status_pack_get_Motor_A_Real_Position(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field Motor_B_Real_Position from motor_status_pack message
 *
 * @return  Motor B real position (Adimensional value) 10^3
 */
static inline int32_t mavlink_msg_motor_status_pack_get_Motor_B_Real_Position(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field Motor_A_Demand_Position from motor_status_pack message
 *
 * @return  Motor A demand position (Adimensional value) 10^3
 */
static inline int32_t mavlink_msg_motor_status_pack_get_Motor_A_Demand_Position(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  16);
}

/**
 * @brief Get field Motor_B_Demand_Position from motor_status_pack message
 *
 * @return  Motor B demand position (Adimensional value) 10^3
 */
static inline int32_t mavlink_msg_motor_status_pack_get_Motor_B_Demand_Position(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  20);
}

/**
 * @brief Get field Motor_A_Torque from motor_status_pack message
 *
 * @return [Nm] Motor A torque 10^2
 */
static inline int32_t mavlink_msg_motor_status_pack_get_Motor_A_Torque(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  24);
}

/**
 * @brief Get field Motor_B_Torque from motor_status_pack message
 *
 * @return [Nm] Motor B torque 10^2
 */
static inline int32_t mavlink_msg_motor_status_pack_get_Motor_B_Torque(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  28);
}

/**
 * @brief Get field Motor_A_Temperature from motor_status_pack message
 *
 * @return [°C] Motor A temperature 10^2
 */
static inline int16_t mavlink_msg_motor_status_pack_get_Motor_A_Temperature(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  48);
}

/**
 * @brief Get field Motor_B_Temperature from motor_status_pack message
 *
 * @return [°C] Motor B temperature 10^2
 */
static inline int16_t mavlink_msg_motor_status_pack_get_Motor_B_Temperature(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  50);
}

/**
 * @brief Get field BMS_Voltage from motor_status_pack message
 *
 * @return [V] Battery management system voltage 10^2
 */
static inline uint16_t mavlink_msg_motor_status_pack_get_BMS_Voltage(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  52);
}

/**
 * @brief Get field BMS_Absorption from motor_status_pack message
 *
 * @return [A] Battery management system current absorption 10^2
 */
static inline int16_t mavlink_msg_motor_status_pack_get_BMS_Absorption(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  54);
}

/**
 * @brief Get field BMS_Temperature from motor_status_pack message
 *
 * @return [°C] Battery management system temperature 10^2
 */
static inline int16_t mavlink_msg_motor_status_pack_get_BMS_Temperature(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  56);
}

/**
 * @brief Get field Motor_Control_Status_Mask from motor_status_pack message
 *
 * @return  Motor control module status mask
 */
static inline uint32_t mavlink_msg_motor_status_pack_get_Motor_Control_Status_Mask(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  32);
}

/**
 * @brief Get field Motor_A_Faults_Mask from motor_status_pack message
 *
 * @return  Motor A faults mask
 */
static inline uint32_t mavlink_msg_motor_status_pack_get_Motor_A_Faults_Mask(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  36);
}

/**
 * @brief Get field Motor_B_Faults_Mask from motor_status_pack message
 *
 * @return  Motor B faults mask
 */
static inline uint32_t mavlink_msg_motor_status_pack_get_Motor_B_Faults_Mask(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  40);
}

/**
 * @brief Get field BMS_Faults_Mask from motor_status_pack message
 *
 * @return  Battery management system faults mask
 */
static inline uint32_t mavlink_msg_motor_status_pack_get_BMS_Faults_Mask(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  44);
}

/**
 * @brief Decode a motor_status_pack message into a struct
 *
 * @param msg The message to decode
 * @param motor_status_pack C-struct to decode the message contents into
 */
static inline void mavlink_msg_motor_status_pack_decode(const mavlink_message_t* msg, mavlink_motor_status_pack_t* motor_status_pack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    motor_status_pack->Log_Timestamp = mavlink_msg_motor_status_pack_get_Log_Timestamp(msg);
    motor_status_pack->Motor_A_Real_Position = mavlink_msg_motor_status_pack_get_Motor_A_Real_Position(msg);
    motor_status_pack->Motor_B_Real_Position = mavlink_msg_motor_status_pack_get_Motor_B_Real_Position(msg);
    motor_status_pack->Motor_A_Demand_Position = mavlink_msg_motor_status_pack_get_Motor_A_Demand_Position(msg);
    motor_status_pack->Motor_B_Demand_Position = mavlink_msg_motor_status_pack_get_Motor_B_Demand_Position(msg);
    motor_status_pack->Motor_A_Torque = mavlink_msg_motor_status_pack_get_Motor_A_Torque(msg);
    motor_status_pack->Motor_B_Torque = mavlink_msg_motor_status_pack_get_Motor_B_Torque(msg);
    motor_status_pack->Motor_Control_Status_Mask = mavlink_msg_motor_status_pack_get_Motor_Control_Status_Mask(msg);
    motor_status_pack->Motor_A_Faults_Mask = mavlink_msg_motor_status_pack_get_Motor_A_Faults_Mask(msg);
    motor_status_pack->Motor_B_Faults_Mask = mavlink_msg_motor_status_pack_get_Motor_B_Faults_Mask(msg);
    motor_status_pack->BMS_Faults_Mask = mavlink_msg_motor_status_pack_get_BMS_Faults_Mask(msg);
    motor_status_pack->Motor_A_Temperature = mavlink_msg_motor_status_pack_get_Motor_A_Temperature(msg);
    motor_status_pack->Motor_B_Temperature = mavlink_msg_motor_status_pack_get_Motor_B_Temperature(msg);
    motor_status_pack->BMS_Voltage = mavlink_msg_motor_status_pack_get_BMS_Voltage(msg);
    motor_status_pack->BMS_Absorption = mavlink_msg_motor_status_pack_get_BMS_Absorption(msg);
    motor_status_pack->BMS_Temperature = mavlink_msg_motor_status_pack_get_BMS_Temperature(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MOTOR_STATUS_PACK_LEN? msg->len : MAVLINK_MSG_ID_MOTOR_STATUS_PACK_LEN;
        memset(motor_status_pack, 0, MAVLINK_MSG_ID_MOTOR_STATUS_PACK_LEN);
    memcpy(motor_status_pack, _MAV_PAYLOAD(msg), len);
#endif
}
