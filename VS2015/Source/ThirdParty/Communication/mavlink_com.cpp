#include "mavlink_com.h"

// Extract a float number frome Mavlink msg->data
float return_float(const Mavlink_msg_t *msg, uint8_t ofs) 
{ 
	return *(const float *)(&msg->data[ofs]);
}
// Extract a uint32 number frome Mavlink msg->data
uint32_t return_uint32(const Mavlink_msg_t *msg, uint8_t ofs)
{  
	return *(const uint32_t *)(&msg->data[ofs]);
}





uint16_t Mavlink::test_pack(uint8_t system_id, uint8_t component_id, Mavlink_msg_t * msg, int val)
{
	 Mavlink_Test_t pck;
	 pck.val = val;


	 //msg->stx = MAVLINK_STX;
	 //msg->payload_lth = MAVLINK_MSG_ID_TEST_LEN;
	 //msg->packet_seq = 0;
	 //msg->sys_id = system_id;
	 //msg->comp_id = component_id;
	 //msg->msg_id = MAVLINK_MSG_ID_TEST;
	 //memcpy(msg->data, &pck, MAVLINK_MSG_ID_TEST_LEN);
	 //mavlink_crc_get(msg, MAVLINK_MSG_ID_TEST_CRC);

	 //Mavlink_attitude_quaternion_t pck;
	 //pck.time_boot_ms = time_boot_ms;//time_boot_ms;
		//							 /*  pck.q1 = q1;
		//							 pck.q2 = q2;
		//							 pck.q3 = q3;
		//							 pck.q4 = q4;
		//							 pck.rollspeed = rollspeed;
		//							 pck.pitchspeed = pitchspeed;
		//							 pck.yawspeed  = yawspeed;
		//							 pck.name[0] = 'T';
		//							 pck.name[1] = 'E';
		//							 pck.name[2] = 'S';
		//							 pck.name[3] = 'T';
		//							 pck.name[4] = '\0';*/

	 msg->stx = MAVLINK_STX;
	 msg->payload_lth = MAVLINK_MSG_ID_ATTITUDE_QUATERNION_LEN;
	 msg->packet_seq = 0;
	 msg->sys_id = system_id;
	 msg->comp_id = component_id;
	 msg->msg_id = MAVLINK_MSG_ID_TEST;
	 memcpy(msg->data, &pck, MAVLINK_MSG_ID_ATTITUDE_QUATERNION_LEN);
	 mavlink_crc_get(msg, MAVLINK_MSG_ID_ATTITUDE_QUATERNION_CRC);

	return 0;
}
int32_t time = 0;
// Encoding an attitude package bo a Mavlink msg
uint16_t Mavlink::attitude_quaternion_pack(uint8_t system_id, uint8_t component_id, Mavlink_msg_t* msg, 
																					 uint32_t time_boot_ms, 
																					 float q1, float q2, float q3, float q4, 
																					 float rollspeed, float pitchspeed, float yawspeed)
{
	  Mavlink_attitude_quaternion_t pck;
	  pck.time_boot_ms = time_boot_ms;//time_boot_ms;
	/*  pck.q1 = q1;
	  pck.q2 = q2;
	  pck.q3 = q3;
	  pck.q4 = q4;
	  pck.rollspeed = rollspeed;
	  pck.pitchspeed = pitchspeed;
	  pck.yawspeed  = yawspeed;
	  pck.name[0] = 'T';
	  pck.name[1] = 'E';
	  pck.name[2] = 'S';
	  pck.name[3] = 'T';
	  pck.name[4] = '\0';*/
	
	  msg->stx = MAVLINK_STX;
	  msg->payload_lth = MAVLINK_MSG_ID_ATTITUDE_QUATERNION_LEN;
	  msg->packet_seq = 0;
	  msg->sys_id = system_id;
	  msg->comp_id = component_id;
	  msg->msg_id = MAVLINK_MSG_ID_ATTITUDE_QUATERNION;
	  memcpy(msg->data,&pck,MAVLINK_MSG_ID_ATTITUDE_QUATERNION_LEN);
	  mavlink_crc_get(msg,MAVLINK_MSG_ID_ATTITUDE_QUATERNION_CRC);
	  return 0;
}

// Decoding a Mavlink msg to an attitude package 
void Mavlink::attitude_quaternion_decode(const Mavlink_msg_t* msg, Mavlink_attitude_quaternion_t* pck)
{
	uint8_t len = msg->payload_lth < MAVLINK_MSG_ID_ATTITUDE_QUATERNION ? msg->payload_lth : MAVLINK_MSG_ID_ATTITUDE_QUATERNION;
	memcpy(pck,msg->data,len);
}
					
// Encoding an attitude package to a Mavlink msg
uint16_t Mavlink::attitude_pack(uint8_t system_id, uint8_t component_id, Mavlink_msg_t* msg,
																			 uint32_t time_boot_ms, 
																			 float roll, float pitch, float yaw,
																			 float rollspeed, float pitchspeed, float yawspeed)
{			
	Mavlink_attitude_t pck;
	pck.time_boot_ms = time_boot_ms;
	pck.roll = roll;
	pck.pitch = pitch;
	pck.yaw = yaw;
	pck.rollspeed = rollspeed;
	pck.pitchspeed = pitchspeed;
	pck.yawspeed = yawspeed;
	
	msg->stx = MAVLINK_STX;
	msg->payload_lth = MAVLINK_MSG_ID_ATTITUDE_LEN;
	msg->packet_seq = 0;
	msg->sys_id = system_id;
	msg->comp_id = component_id;
	msg->msg_id = MAVLINK_MSG_ID_ATTITUDE;
	memcpy(msg->data,&pck,MAVLINK_MSG_ID_ATTITUDE_LEN);
	mavlink_crc_get(msg,MAVLINK_MSG_ID_ATTITUDE_CRC);
	return 0;
}	

// Decoding a Mavlink msg to an attitude package
void Mavlink::attitude_decode(const Mavlink_msg_t* msg, Mavlink_attitude_t* pck)
{
	/*
	pck->time_boot_ms = return_uint32(msg,0);
	pck->roll = return_float(msg,4);
	pck->pitch = return_float(msg,8);
	pck->yaw = return_float(msg,12);
	pck->rollspeed = return_float(msg,16);
	pck->pitchspeed = return_float(msg,20);
	pck->yawspeed = return_float(msg,24);
	*/
	uint8_t len = msg->payload_lth < MAVLINK_MSG_ID_ATTITUDE_LEN ? msg->payload_lth : MAVLINK_MSG_ID_ATTITUDE_LEN;
	memcpy(pck,msg->data,len);

}	

// Encoding a Control parameter to a Mavlink message
uint16_t Mavlink::control_param_pack(uint8_t system_id, uint8_t component_id, Mavlink_msg_t* msg,
																uint8_t axis_id, float rate_p, float rate_i, float rate_d, float rate_i_max, float rate_filt_hz,
																float stabilize_p, float stabilize_d)
{
		Mavlink_control_param_t pck;
		pck.axis_id = axis_id;
		pck.rate_p = rate_p;
	  pck.rate_i = rate_i;
	  pck.rate_d = rate_d;
	  pck.rate_i_max = rate_i_max;
	  pck.rate_filt_hz = rate_filt_hz;
	  pck.stabilize_p = stabilize_p;
	  pck.stabilize_d = stabilize_d;
	
		msg->stx = MAVLINK_STX;
	  msg->payload_lth = MAVLINK_MSG_ID_CONTROL_PARAM_LEN;
	  msg->packet_seq = 0;
	  msg->sys_id = system_id;
	  msg->comp_id = component_id;
	  msg->msg_id = MAVLINK_MSG_ID_CONTROL_PARAM;
	  memcpy(msg->data, &pck, MAVLINK_MSG_ID_CONTROL_PARAM_LEN);
	  mavlink_crc_get(msg, MAVLINK_MSG_ID_CONTROL_PARAM_CRC);

	  return 0;
}

// Decode a Mavlink message to a Control parameter pck
void Mavlink::control_param_decode(const Mavlink_msg_t* msg, Mavlink_control_param_t* control_param)	
{
		uint8_t len = msg->payload_lth < MAVLINK_MSG_ID_CONTROL_PARAM_LEN ? msg->payload_lth : MAVLINK_MSG_ID_CONTROL_PARAM_LEN;
		memcpy(control_param, msg->data, len);
}


uint16_t Mavlink::efficient_data_packing(uint8_t system_id, uint8_t component_id, Mavlink_msg_t* msg,
																 uint8_t axis_id, uint8_t param_id, float param,
																 float q0, float q1, float q2, float q3)
{
		Mavlink_efficient_data_t pck;
		pck.axis_id = axis_id;
		pck.param_id = param_id;
	  pck.param = param;
	  pck.q0 = q0;
	  pck.q1 = q1;
	  pck.q2 = q2;
	  pck.q3 = q3;
	
		msg->stx = MAVLINK_STX;
	  msg->payload_lth = MAVLINK_MSG_ID_EFF_DATA_LEN;
	  msg->packet_seq = 0;
	  msg->sys_id = system_id;
	  msg->comp_id = component_id;
	  msg->msg_id = MAVLINK_MSG_ID_EFF_DATA;
	  memcpy(msg->data, &pck, MAVLINK_MSG_ID_EFF_DATA_LEN);
	  mavlink_crc_get(msg, MAVLINK_MSG_ID_EFF_DATA_CRC);
	  return 0;
}

void Mavlink::efficient_data_decode(const Mavlink_msg_t* msg, Mavlink_efficient_data_t* efficient_data)
{
		uint8_t len = msg->payload_lth < MAVLINK_MSG_ID_EFF_DATA_LEN ? msg->payload_lth : MAVLINK_MSG_ID_EFF_DATA_LEN;
		memcpy(efficient_data, msg->data, len);	
}

void Mavlink::update_eff_param()
{
	  eff_param_update++;
	  if(eff_param_update == KILL)
		{
			eff_param_update = MAVLINK_PARAM_RATE_P;
			eff_ax_update++;
			if(eff_ax_update == 3) eff_ax_update = 0;
		}
}
																							


/**
 * @brief Accumulate the X.25 CRC by adding one char at a time.
 *
 * The checksum function adds the hash of one char at a time to the
 * 16 bit checksum (uint16_t).
 *
 * @param data new char to hash
 * @param crcAccum the already accumulated checksum
 **/
void Mavlink::crc_accumulate(uint8_t data, uint16_t *crcAccum)
{
        /*Accumulate one byte of data into the CRC*/
        uint8_t tmp;

        tmp = data ^ (uint8_t)(*crcAccum &0xff);
        tmp ^= (tmp<<4);
        *crcAccum = (*crcAccum>>8) ^ (tmp<<8) ^ (tmp <<3) ^ (tmp>>4);
}


/**
 * @brief Initiliaze the buffer for the X.25 CRC
 *
 * @param crcAccum the 16 bit X.25 CRC
 */
void Mavlink::crc_init(uint16_t* crcAccum)
{
        *crcAccum = X25_INIT_CRC;
}


/**
 * @brief Calculates the X.25 checksum on a byte buffer
 *
 * @param  pBuffer buffer containing the byte array to hash
 * @param  length  length of the byte array
 * @return the checksum over the buffer bytes
 **/
uint16_t Mavlink::crc_calculate(const uint8_t* pBuffer, uint16_t length)
{
        uint16_t crcTmp;
        crc_init(&crcTmp);
	while (length--) {
                crc_accumulate(*pBuffer++, &crcTmp);
        }
        return crcTmp;
}


/**
 * @brief Accumulate the X.25 CRC by adding an array of bytes
 *
 * The checksum function adds the hash of one char at a time to the
 * 16 bit checksum (uint16_t).
 *
 * @param data new bytes to hash
 * @param crcAccum the already accumulated checksum
 **/
void Mavlink::crc_accumulate_buffer(uint16_t *crcAccum, const char *pBuffer, uint16_t length)
{
	const uint8_t *p = (const uint8_t *)pBuffer;
	while (length--) {
                crc_accumulate(*p++, crcAccum);
        }
}

uint16_t Mavlink::mavlink_crc_get(Mavlink_msg_t* msg, uint8_t crc_extra)
{
	uint16_t checksum;
	checksum=crc_calculate(((const uint8_t*)(msg))+1,5);
	crc_accumulate_buffer(&checksum, ((const char *)(&((msg)->data[0]))),msg->payload_lth);
	crc_accumulate(crc_extra, &checksum);
	msg->crcl=((checksum)&0xFF);
	msg->crch=((checksum)>>8);
	
	return (msg->payload_lth)+8;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	