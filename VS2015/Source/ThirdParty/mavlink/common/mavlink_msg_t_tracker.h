#pragma once
// MESSAGE T_TRACKER PACKING

#define MAVLINK_MSG_ID_T_TRACKER 151

MAVPACKED(
typedef struct __mavlink_t_tracker_t {
 float Qx; /*< Quaternion x*/
 float Qy; /*< Quaternion y*/
 float Qz; /*< Quaternion z*/
 float Qw; /*< Quaternion w*/
 float Px; /*< Position x*/
 float Py; /*< Position y*/
 float Pz; /*< Position z*/
 uint8_t ID; /*< custom id.*/
}) mavlink_t_tracker_t;

#define MAVLINK_MSG_ID_T_TRACKER_LEN 29
#define MAVLINK_MSG_ID_T_TRACKER_MIN_LEN 29
#define MAVLINK_MSG_ID_151_LEN 29
#define MAVLINK_MSG_ID_151_MIN_LEN 29

#define MAVLINK_MSG_ID_T_TRACKER_CRC 18
#define MAVLINK_MSG_ID_151_CRC 18



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_T_TRACKER { \
    151, \
    "T_TRACKER", \
    8, \
    {  { "Qx", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_t_tracker_t, Qx) }, \
         { "Qy", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_t_tracker_t, Qy) }, \
         { "Qz", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_t_tracker_t, Qz) }, \
         { "Qw", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_t_tracker_t, Qw) }, \
         { "Px", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_t_tracker_t, Px) }, \
         { "Py", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_t_tracker_t, Py) }, \
         { "Pz", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_t_tracker_t, Pz) }, \
         { "ID", NULL, MAVLINK_TYPE_UINT8_T, 0, 28, offsetof(mavlink_t_tracker_t, ID) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_T_TRACKER { \
    "T_TRACKER", \
    8, \
    {  { "Qx", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_t_tracker_t, Qx) }, \
         { "Qy", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_t_tracker_t, Qy) }, \
         { "Qz", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_t_tracker_t, Qz) }, \
         { "Qw", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_t_tracker_t, Qw) }, \
         { "Px", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_t_tracker_t, Px) }, \
         { "Py", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_t_tracker_t, Py) }, \
         { "Pz", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_t_tracker_t, Pz) }, \
         { "ID", NULL, MAVLINK_TYPE_UINT8_T, 0, 28, offsetof(mavlink_t_tracker_t, ID) }, \
         } \
}
#endif

/**
 * @brief Pack a t_tracker message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param ID custom id.
 * @param Qx Quaternion x
 * @param Qy Quaternion y
 * @param Qz Quaternion z
 * @param Qw Quaternion w
 * @param Px Position x
 * @param Py Position y
 * @param Pz Position z
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_t_tracker_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t ID, float Qx, float Qy, float Qz, float Qw, float Px, float Py, float Pz)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_T_TRACKER_LEN];
    _mav_put_float(buf, 0, Qx);
    _mav_put_float(buf, 4, Qy);
    _mav_put_float(buf, 8, Qz);
    _mav_put_float(buf, 12, Qw);
    _mav_put_float(buf, 16, Px);
    _mav_put_float(buf, 20, Py);
    _mav_put_float(buf, 24, Pz);
    _mav_put_uint8_t(buf, 28, ID);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_T_TRACKER_LEN);
#else
    mavlink_t_tracker_t packet;
    packet.Qx = Qx;
    packet.Qy = Qy;
    packet.Qz = Qz;
    packet.Qw = Qw;
    packet.Px = Px;
    packet.Py = Py;
    packet.Pz = Pz;
    packet.ID = ID;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_T_TRACKER_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_T_TRACKER;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_T_TRACKER_MIN_LEN, MAVLINK_MSG_ID_T_TRACKER_LEN, MAVLINK_MSG_ID_T_TRACKER_CRC);
}

/**
 * @brief Pack a t_tracker message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ID custom id.
 * @param Qx Quaternion x
 * @param Qy Quaternion y
 * @param Qz Quaternion z
 * @param Qw Quaternion w
 * @param Px Position x
 * @param Py Position y
 * @param Pz Position z
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_t_tracker_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t ID,float Qx,float Qy,float Qz,float Qw,float Px,float Py,float Pz)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_T_TRACKER_LEN];
    _mav_put_float(buf, 0, Qx);
    _mav_put_float(buf, 4, Qy);
    _mav_put_float(buf, 8, Qz);
    _mav_put_float(buf, 12, Qw);
    _mav_put_float(buf, 16, Px);
    _mav_put_float(buf, 20, Py);
    _mav_put_float(buf, 24, Pz);
    _mav_put_uint8_t(buf, 28, ID);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_T_TRACKER_LEN);
#else
    mavlink_t_tracker_t packet;
    packet.Qx = Qx;
    packet.Qy = Qy;
    packet.Qz = Qz;
    packet.Qw = Qw;
    packet.Px = Px;
    packet.Py = Py;
    packet.Pz = Pz;
    packet.ID = ID;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_T_TRACKER_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_T_TRACKER;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_T_TRACKER_MIN_LEN, MAVLINK_MSG_ID_T_TRACKER_LEN, MAVLINK_MSG_ID_T_TRACKER_CRC);
}

/**
 * @brief Encode a t_tracker struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param t_tracker C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_t_tracker_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_t_tracker_t* t_tracker)
{
    return mavlink_msg_t_tracker_pack(system_id, component_id, msg, t_tracker->ID, t_tracker->Qx, t_tracker->Qy, t_tracker->Qz, t_tracker->Qw, t_tracker->Px, t_tracker->Py, t_tracker->Pz);
}

/**
 * @brief Encode a t_tracker struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param t_tracker C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_t_tracker_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_t_tracker_t* t_tracker)
{
    return mavlink_msg_t_tracker_pack_chan(system_id, component_id, chan, msg, t_tracker->ID, t_tracker->Qx, t_tracker->Qy, t_tracker->Qz, t_tracker->Qw, t_tracker->Px, t_tracker->Py, t_tracker->Pz);
}

/**
 * @brief Send a t_tracker message
 * @param chan MAVLink channel to send the message
 *
 * @param ID custom id.
 * @param Qx Quaternion x
 * @param Qy Quaternion y
 * @param Qz Quaternion z
 * @param Qw Quaternion w
 * @param Px Position x
 * @param Py Position y
 * @param Pz Position z
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_t_tracker_send(mavlink_channel_t chan, uint8_t ID, float Qx, float Qy, float Qz, float Qw, float Px, float Py, float Pz)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_T_TRACKER_LEN];
    _mav_put_float(buf, 0, Qx);
    _mav_put_float(buf, 4, Qy);
    _mav_put_float(buf, 8, Qz);
    _mav_put_float(buf, 12, Qw);
    _mav_put_float(buf, 16, Px);
    _mav_put_float(buf, 20, Py);
    _mav_put_float(buf, 24, Pz);
    _mav_put_uint8_t(buf, 28, ID);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_T_TRACKER, buf, MAVLINK_MSG_ID_T_TRACKER_MIN_LEN, MAVLINK_MSG_ID_T_TRACKER_LEN, MAVLINK_MSG_ID_T_TRACKER_CRC);
#else
    mavlink_t_tracker_t packet;
    packet.Qx = Qx;
    packet.Qy = Qy;
    packet.Qz = Qz;
    packet.Qw = Qw;
    packet.Px = Px;
    packet.Py = Py;
    packet.Pz = Pz;
    packet.ID = ID;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_T_TRACKER, (const char *)&packet, MAVLINK_MSG_ID_T_TRACKER_MIN_LEN, MAVLINK_MSG_ID_T_TRACKER_LEN, MAVLINK_MSG_ID_T_TRACKER_CRC);
#endif
}

/**
 * @brief Send a t_tracker message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_t_tracker_send_struct(mavlink_channel_t chan, const mavlink_t_tracker_t* t_tracker)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_t_tracker_send(chan, t_tracker->ID, t_tracker->Qx, t_tracker->Qy, t_tracker->Qz, t_tracker->Qw, t_tracker->Px, t_tracker->Py, t_tracker->Pz);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_T_TRACKER, (const char *)t_tracker, MAVLINK_MSG_ID_T_TRACKER_MIN_LEN, MAVLINK_MSG_ID_T_TRACKER_LEN, MAVLINK_MSG_ID_T_TRACKER_CRC);
#endif
}

#if MAVLINK_MSG_ID_T_TRACKER_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_t_tracker_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t ID, float Qx, float Qy, float Qz, float Qw, float Px, float Py, float Pz)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, Qx);
    _mav_put_float(buf, 4, Qy);
    _mav_put_float(buf, 8, Qz);
    _mav_put_float(buf, 12, Qw);
    _mav_put_float(buf, 16, Px);
    _mav_put_float(buf, 20, Py);
    _mav_put_float(buf, 24, Pz);
    _mav_put_uint8_t(buf, 28, ID);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_T_TRACKER, buf, MAVLINK_MSG_ID_T_TRACKER_MIN_LEN, MAVLINK_MSG_ID_T_TRACKER_LEN, MAVLINK_MSG_ID_T_TRACKER_CRC);
#else
    mavlink_t_tracker_t *packet = (mavlink_t_tracker_t *)msgbuf;
    packet->Qx = Qx;
    packet->Qy = Qy;
    packet->Qz = Qz;
    packet->Qw = Qw;
    packet->Px = Px;
    packet->Py = Py;
    packet->Pz = Pz;
    packet->ID = ID;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_T_TRACKER, (const char *)packet, MAVLINK_MSG_ID_T_TRACKER_MIN_LEN, MAVLINK_MSG_ID_T_TRACKER_LEN, MAVLINK_MSG_ID_T_TRACKER_CRC);
#endif
}
#endif

#endif

// MESSAGE T_TRACKER UNPACKING


/**
 * @brief Get field ID from t_tracker message
 *
 * @return custom id.
 */
static inline uint8_t mavlink_msg_t_tracker_get_ID(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  28);
}

/**
 * @brief Get field Qx from t_tracker message
 *
 * @return Quaternion x
 */
static inline float mavlink_msg_t_tracker_get_Qx(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field Qy from t_tracker message
 *
 * @return Quaternion y
 */
static inline float mavlink_msg_t_tracker_get_Qy(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field Qz from t_tracker message
 *
 * @return Quaternion z
 */
static inline float mavlink_msg_t_tracker_get_Qz(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field Qw from t_tracker message
 *
 * @return Quaternion w
 */
static inline float mavlink_msg_t_tracker_get_Qw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field Px from t_tracker message
 *
 * @return Position x
 */
static inline float mavlink_msg_t_tracker_get_Px(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field Py from t_tracker message
 *
 * @return Position y
 */
static inline float mavlink_msg_t_tracker_get_Py(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field Pz from t_tracker message
 *
 * @return Position z
 */
static inline float mavlink_msg_t_tracker_get_Pz(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Decode a t_tracker message into a struct
 *
 * @param msg The message to decode
 * @param t_tracker C-struct to decode the message contents into
 */
static inline void mavlink_msg_t_tracker_decode(const mavlink_message_t* msg, mavlink_t_tracker_t* t_tracker)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    t_tracker->Qx = mavlink_msg_t_tracker_get_Qx(msg);
    t_tracker->Qy = mavlink_msg_t_tracker_get_Qy(msg);
    t_tracker->Qz = mavlink_msg_t_tracker_get_Qz(msg);
    t_tracker->Qw = mavlink_msg_t_tracker_get_Qw(msg);
    t_tracker->Px = mavlink_msg_t_tracker_get_Px(msg);
    t_tracker->Py = mavlink_msg_t_tracker_get_Py(msg);
    t_tracker->Pz = mavlink_msg_t_tracker_get_Pz(msg);
    t_tracker->ID = mavlink_msg_t_tracker_get_ID(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_T_TRACKER_LEN? msg->len : MAVLINK_MSG_ID_T_TRACKER_LEN;
        memset(t_tracker, 0, MAVLINK_MSG_ID_T_TRACKER_LEN);
    memcpy(t_tracker, _MAV_PAYLOAD(msg), len);
#endif
}
