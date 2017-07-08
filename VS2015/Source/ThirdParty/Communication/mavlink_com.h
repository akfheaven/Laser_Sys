#include "../mavlink/common/mavlink.h"
#define MAV_TYPE_GIMBAL 26
#define	MAV_COMP_ID_IMU 200

#define MAV_COMP_ID_CONTROLLER 70

#define MAV_CMD_DO_SET_PARAMETER 180

#define X25_INIT_CRC 0xffff
#define X25_VALIDATE_CRC 0xf0b8


#define MAVLINK_STX 0xFE
#define MAX_MAV_LENTH 256

#define MAVLINK_XBEE_RX_STX 1
#define MAVLINK_XBEE_RX_PLTH 2
#define MAVLINK_XBEE_RX_PSEQ 3
#define MAVLINK_XBEE_RX_SYSID 4
#define MAVLINK_XBEE_RX_COMPID 5
#define MAVLINK_XBEE_RX_MSGID 6
#define MAVLINK_XBEE_RX_DATA 7
#define MAVLINK_XBEE_RX_CRCL 8
#define MAVLINK_XBEE_RX_CRCH 9
#define MAVLINK_XBEE_RX_STOP 0

//TEST PACK INFO
#define MAVLINK_MSG_ID_TEST_LEN 4
#define MAVLINK_MSG_ID_TEST_CRC 246
#define MAVLINK_MSG_ID_TEST 31

// ATTITUDE_QUATERNION PACKING INFO
#define MAVLINK_MSG_ID_ATTITUDE_QUATERNION 31

#define MAVLINK_MSG_ID_ATTITUDE_QUATERNION_LEN 4
#define MAVLINK_MSG_ID_ATTITUDE_QUATERNION_MIN_LEN 32
#define MAVLINK_MSG_ID_31_LEN 32
#define MAVLINK_MSG_ID_31_MIN_LEN 32

#define MAVLINK_MSG_ID_ATTITUDE_QUATERNION_CRC 246
#define MAVLINK_MSG_ID_31_CRC 246

// ATTITUDE PACKING INFO
#define MAVLINK_MSG_ID_ATTITUDE 30

#define MAVLINK_MSG_ID_ATTITUDE_LEN 28
#define MAVLINK_MSG_ID_ATTITUDE_MIN_LEN 28
#define MAVLINK_MSG_ID_30_LEN 28
#define MAVLINK_MSG_ID_30_MIN_LEN 28

#define MAVLINK_MSG_ID_ATTITUDE_CRC 39
#define MAVLINK_MSG_ID_30_CRC 39

// CONTROL PARAMETER PACKING INFO
#define MAVLINK_MSG_ID_CONTROL_PARAM MAV_CMD_DO_SET_PARAMETER

#define MAVLINK_MSG_ID_CONTROL_PARAM_LEN 29
#define MAVLINK_MSG_ID_CONTROL_PARAM_MIN_LEN 29
#define MAVLINK_MSG_ID_180_LEN 29
#define MAVLINK_MSG_ID_180_MIN_LEN 29

#define MAVLINK_MSG_ID_CONTROL_PARAM_CRC 70
#define MAVLINK_MSG_ID_180_CRC 70

#define MAVLINK_MSG_ID_CONTROL_PARAM_AXIS_ROLL 0
#define MAVLINK_MSG_ID_CONTROL_PARAM_AXIS_PITCH 1
#define MAVLINK_MSG_ID_CONTROL_PARAM_AXIS_YAW 2

// EFFICIENT DATA PACKING INFO
#define MAVLINK_MSG_ID_EFF_DATA 77
#define MAVLINK_MSG_ID_EFF_DATA_LEN 22
#define MAVLINK_MSG_ID_EFF_DATA_CRC 19

#define MAVLINK_AX_ROLL 0
#define MAVLINK_AX_PITCH 1
#define MAVLINK_AX_YAW 2

enum
{
		MAVLINK_PARAM_RATE_P,
		MAVLINK_PARAM_RATE_I,
		MAVLINK_PARAM_RATE_D,
		MAVLINK_PARAM_RATE_I_MAX,
		MAVLINK_PARAM_RATE_F_HZ,
		MAVLINK_PARAM_STAB_P,
		MAVLINK_PARAM_STAB_D,
	  KILL,
};

typedef struct
{
	uint8_t stx;
	uint8_t	payload_lth;
	uint8_t packet_seq;
	uint8_t sys_id;
	uint8_t comp_id;
	uint8_t msg_id;
	uint8_t data[MAX_MAV_LENTH];
	uint8_t crcl;
	uint8_t crch;
}Mavlink_msg_t;

typedef struct {
 float time_boot_ms; /*< Timestamp (milliseconds since system boot)*/
 //float q1; /*< Quaternion component 1, w (1 in null-rotation)*/
 //float q2; /*< Quaternion component 2, x (0 in null-rotation)*/
 //float q3; /*< Quaternion component 3, y (0 in null-rotation)*/
 //float q4; /*< Quaternion component 4, z (0 in null-rotation)*/
 //float rollspeed; /*< Roll angular speed (rad/s)*/
 //float pitchspeed; /*< Pitch angular speed (rad/s)*/
 //float yawspeed; /*< Yaw angular speed (rad/s)*/
 //char name[5];
} Mavlink_attitude_quaternion_t;

typedef struct {
	float val;
} Mavlink_Test_t;

typedef struct {
 uint32_t time_boot_ms; /*< Timestamp (milliseconds since system boot)*/
 float roll; /*< Roll angle (rad, -pi..+pi)*/
 float pitch; /*< Pitch angle (rad, -pi..+pi)*/
 float yaw; /*< Yaw angle (rad, -pi..+pi)*/
 float rollspeed; /*< Roll angular speed (rad/s)*/
 float pitchspeed; /*< Pitch angular speed (rad/s)*/
 float yawspeed; /*< Yaw angular speed (rad/s)*/
} Mavlink_attitude_t;

typedef struct {
	uint8_t axis_id;
	float rate_p;
	float rate_i;
	float rate_d;
	float rate_i_max;
	float rate_filt_hz;
	float stabilize_p;
	float stabilize_d;
} Mavlink_control_param_t;

//typedef struct {
//	uint8_t axis_id;
//	uint8_t param_id;
//	float param;
//	float q0;
//	float q1;
//	float q2;
//	float q3;
//}__attribute__((packed)) Mavlink_efficient_data_t;
typedef struct {
	uint8_t axis_id;
	uint8_t param_id;
	float param;
	float q0;
	float q1;
	float q2;
	float q3;
}Mavlink_efficient_data_t;

	
	

class Mavlink
{
	public:
		uint8_t eff_ax_update;
	  uint8_t eff_param_update;
	  Mavlink()
    {
			eff_ax_update = 0;
			eff_param_update = 0;
    }			
	  uint16_t test_pack(uint8_t system_id, uint8_t component_id, Mavlink_msg_t* msg, int val);
		uint16_t attitude_quaternion_pack(uint8_t system_id, uint8_t component_id, Mavlink_msg_t* msg, uint32_t time_boot_ms, float q1, float q2, float q3, float q4, float rollspeed, float pitchspeed, float yawspeed);
		void attitude_quaternion_decode(const Mavlink_msg_t* msg, Mavlink_attitude_quaternion_t* attitude_quaternion);
																									
		uint16_t attitude_pack(uint8_t system_id, uint8_t component_id, Mavlink_msg_t* msg, uint32_t time_boot_ms, float roll, float pitch, float yaw, float rollspeed, float pitchspeed, float yawspeed);
		void attitude_decode(const Mavlink_msg_t* msg, Mavlink_attitude_t* attitude);		

		uint16_t control_param_pack(uint8_t system_id, uint8_t component_id, Mavlink_msg_t* msg,
																uint8_t axis_id, float rate_p, float rate_i, float rate_d, float rate_i_max, float rate_filt_hz,
																float stabilize_p, float stabilize_d);
		void control_param_decode(const Mavlink_msg_t* msg, Mavlink_control_param_t* control_param);		

	  uint16_t efficient_data_packing(uint8_t system_id, uint8_t component_id, Mavlink_msg_t* msg,
																 uint8_t axis_id, uint8_t param_id, float param,
																 float q0, float q1, float q2, float q3);
																 
		void efficient_data_decode(const Mavlink_msg_t* msg, Mavlink_efficient_data_t* efficient_data);
		
		void update_eff_param();
	
	private:
		void crc_accumulate(uint8_t data, uint16_t *crcAccum);
	  void crc_init(uint16_t* crcAccum);
	  uint16_t crc_calculate(const uint8_t* pBuffer, uint16_t length);
	  void crc_accumulate_buffer(uint16_t *crcAccum, const char *pBuffer, uint16_t length);
	  uint16_t mavlink_crc_get(Mavlink_msg_t* msg, uint8_t crc_extra);
	
};
		



	  
	
	  
	




















