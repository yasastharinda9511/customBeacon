#define EMERGENCY_VEHICLE_MESSAGE 0x01
#define LANE_CHANGING_MESSAGE 0x02
#define BASIC_SAFETY_MESSAGE 0x03
#define SUDDEN_BRAKE_MESSAGE 0x04

typedef struct MessageType{
	char priority;
	uint8_t messageType;
	uint32_t count;
} MsgType;


typedef struct VehicelInformation{

	uint8_t type;
	uint8_t vehicle_id[4];
	uint16_t present;
	uint32_t acceleration;
	uint32_t speed;
	uint32_t pos;
	uint8_t dir;
	uint8_t lane;
}VehicleInfo;


typedef struct MainFrame{

	MsgType message_type;
	VehicleInfo vehicle_info;

} Frame;


uint8_t getVehicleType(){
	
	return 5;
	
}














