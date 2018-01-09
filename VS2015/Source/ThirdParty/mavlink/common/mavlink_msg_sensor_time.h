#pragma once
// MESSAGE SENSOR_TIME PACKING

#define MAVLINK_MSG_ID_SENSOR_TIME 63

MAVPACKED(
typedef struct __mavlink_sensor_time_t {
 float timeX[5]; /*< Quaternion x*/
 float timeY[5]; /*< Quaternion y*/
 uint8_t TID; /*< Tower id.*/
}) mavlink_sensor_time_t;

#define MAVLINK_MSG_ID_SENSOR_TIME_LEN 41
#define MAVLINK_MSG_ID_SENSOR_TIME_MIN_LEN 41
#define MAVLINK_MSG_ID_63_LEN 41
#define MAVLINK_MSG_ID_63_MIN_LEN 41

#define MAVLINK_MSG_ID_SENSOR_TIME_CRC 115
#define MAVLINK_MSG_ID_63_CRC 115

#define MAVLINK_MSG_SENSOR_TIME_FIELD_TIMEX_LEN 5
#define MAVLINK_MSG_SENSOR_TIME_FIELD_TIMEY_LEN 5

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SENSOR_TIME { \
    63, \
    "SENSOR_TIME", \
    3, \
    {  { "timeX", NULL, MAVLINK_TYPE_FLOAT, 5, 0, offsetof(mavlink_sensor_time_t, timeX) }, \
         { "timeY", NULL, MAVLINK_TYPE_FLOAT, 5, 20, offsetof(mavlink_sensor_time_t, timeY) }, \
         { "TID", NULL, MAVLINK_TYPE_UINT8_T, 0, 40, offsetof(mavlink_sensor_time_t, TID) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SENSOR_TIME { \
    "SENSOR_TIME", \
    3, \
    {  { "timeX", NULL, MAVLINK_TYPE_FLOAT, 5, 0, offsetof(mavlink_sensor_time_t, timeX) }, \
         { "timeY", NULL, MAVLINK_TYPE_FLOAT, 5, 20, offsetof(mavlink_sensor_time_t, timeY) }, \
         { "TID", NULL, MAVLINK_TYPE_UINT8_T, 0, 40, offsetof(mavlink_sensor_time_t, TID) }, \
         } \
}
#endif

/**
 * @brief Pack a sensor_time message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param TID Tower id.
 * @param timeX Quaternion x
 * @param timeY Quaternion y
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sensor_time_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t TID, const float *timeX, const float *timeY)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SENSOR_TIME_LEN];
    _mav_put_uint8_t(buf, 40, TID);
    _mav_put_float_array(buf, 0, timeX, 5);
    _mav_put_float_array(buf, 20, timeY, 5);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SENSOR_TIME_LEN);
#else
    mavlink_sensor_time_t packet;
    packet.TID = TID;
    mav_array_memcpy(packet.timeX, timeX, sizeof(float)*5);
    mav_array_memcpy(packet.timeY, timeY, sizeof(float)*5);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SENSOR_TIME_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SENSOR_TIME;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SENSOR_TIME_MIN_LEN, MAVLINK_MSG_ID_SENSOR_TIME_LEN, MAVLINK_MSG_ID_SENSOR_TIME_CRC);
}

/**
 * @brief Pack a sensor_time message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param TID Tower id.
 * @param timeX Quaternion x
 * @param timeY Quaternion y
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sensor_time_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t TID,const float *timeX,const float *timeY)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SENSOR_TIME_LEN];
    _mav_put_uint8_t(buf, 40, TID);
    _mav_put_float_array(buf, 0, timeX, 5);
    _mav_put_float_array(buf, 20, timeY, 5);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SENSOR_TIME_LEN);
#else
    mavlink_sensor_time_t packet;
    packet.TID = TID;
    mav_array_memcpy(packet.timeX, timeX, sizeof(float)*5);
    mav_array_memcpy(packet.timeY, timeY, sizeof(float)*5);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SENSOR_TIME_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SENSOR_TIME;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SENSOR_TIME_MIN_LEN, MAVLINK_MSG_ID_SENSOR_TIME_LEN, MAVLINK_MSG_ID_SENSOR_TIME_CRC);
}

/**
 * @brief Encode a sensor_time struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param sensor_time C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sensor_time_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_sensor_time_t* sensor_time)
{
    return mavlink_msg_sensor_time_pack(system_id, component_id, msg, sensor_time->TID, sensor_time->timeX, sensor_time->timeY);
}

/**
 * @brief Encode a sensor_time struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param sensor_time C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sensor_time_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_sensor_time_t* sensor_time)
{
    return mavlink_msg_sensor_time_pack_chan(system_id, component_id, chan, msg, sensor_time->TID, sensor_time->timeX, sensor_time->timeY);
}

/**
 * @brief Send a sensor_time message
 * @param chan MAVLink channel to send the message
 *
 * @param TID Tower id.
 * @param timeX Quaternion x
 * @param timeY Quaternion y
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_sensor_time_send(mavlink_channel_t chan, uint8_t TID, const float *timeX, const float *timeY)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SENSOR_TIME_LEN];
    _mav_put_uint8_t(buf, 40, TID);
    _mav_put_float_array(buf, 0, timeX, 5);
    _mav_put_float_array(buf, 20, timeY, 5);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_TIME, buf, MAVLINK_MSG_ID_SENSOR_TIME_MIN_LEN, MAVLINK_MSG_ID_SENSOR_TIME_LEN, MAVLINK_MSG_ID_SENSOR_TIME_CRC);
#else
    mavlink_sensor_time_t packet;
    packet.TID = TID;
    mav_array_memcpy(packet.timeX, timeX, sizeof(float)*5);
    mav_array_memcpy(packet.timeY, timeY, sizeof(float)*5);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_TIME, (const char *)&packet, MAVLINK_MSG_ID_SENSOR_TIME_MIN_LEN, MAVLINK_MSG_ID_SENSOR_TIME_LEN, MAVLINK_MSG_ID_SENSOR_TIME_CRC);
#endif
}

/**
 * @brief Send a sensor_time message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_sensor_time_send_struct(mavlink_channel_t chan, const mavlink_sensor_time_t* sensor_time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_sensor_time_send(chan, sensor_time->TID, sensor_time->timeX, sensor_time->timeY);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_TIME, (const char *)sensor_time, MAVLINK_MSG_ID_SENSOR_TIME_MIN_LEN, MAVLINK_MSG_ID_SENSOR_TIME_LEN, MAVLINK_MSG_ID_SENSOR_TIME_CRC);
#endif
}

#if MAVLINK_MSG_ID_SENSOR_TIME_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_sensor_time_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t TID, const float *timeX, const float *timeY)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 40, TID);
    _mav_put_float_array(buf, 0, timeX, 5);
    _mav_put_float_array(buf, 20, timeY, 5);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_TIME, buf, MAVLINK_MSG_ID_SENSOR_TIME_MIN_LEN, MAVLINK_MSG_ID_SENSOR_TIME_LEN, MAVLINK_MSG_ID_SENSOR_TIME_CRC);
#else
    mavlink_sensor_time_t *packet = (mavlink_sensor_time_t *)msgbuf;
    packet->TID = TID;
    mav_array_memcpy(packet->timeX, timeX, sizeof(float)*5);
    mav_array_memcpy(packet->timeY, timeY, sizeof(float)*5);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_TIME, (const char *)packet, MAVLINK_MSG_ID_SENSOR_TIME_MIN_LEN, MAVLINK_MSG_ID_SENSOR_TIME_LEN, MAVLINK_MSG_ID_SENSOR_TIME_CRC);
#endif
}
#endif

#endif

// MESSAGE SENSOR_TIME UNPACKING


/**
 * @brief Get field TID from sensor_time message
 *
 * @return Tower id.
 */
static inline uint8_t mavlink_msg_sensor_time_get_TID(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  40);
}

/**
 * @brief Get field timeX from sensor_time message
 *
 * @return Quaternion x
 */
static inline uint16_t mavlink_msg_sensor_time_get_timeX(const mavlink_message_t* msg, float *timeX)
{
    return _MAV_RETURN_float_array(msg, timeX, 5,  0);
}

/**
 * @brief Get field timeY from sensor_time message
 *
 * @return Quaternion y
 */
static inline uint16_t mavlink_msg_sensor_time_get_timeY(const mavlink_message_t* msg, float *timeY)
{
    return _MAV_RETURN_float_array(msg, timeY, 5,  20);
}

/**
 * @brief Decode a sensor_time message into a struct
 *
 * @param msg The message to decode
 * @param sensor_time C-struct to decode the message contents into
 */
static inline void mavlink_msg_sensor_time_decode(const mavlink_message_t* msg, mavlink_sensor_time_t* sensor_time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_sensor_time_get_timeX(msg, sensor_time->timeX);
    mavlink_msg_sensor_time_get_timeY(msg, sensor_time->timeY);
    sensor_time->TID = mavlink_msg_sensor_time_get_TID(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SENSOR_TIME_LEN? msg->len : MAVLINK_MSG_ID_SENSOR_TIME_LEN;
        memset(sensor_time, 0, MAVLINK_MSG_ID_SENSOR_TIME_LEN);
    memcpy(sensor_time, _MAV_PAYLOAD(msg), len);
#endif
}
