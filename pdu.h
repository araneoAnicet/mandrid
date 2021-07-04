#define TYPE_STEARING 0x00
#define TYPE_STATE 0x01
#define TYPE_SENSORS 0x02
#define TYPE_VIDEO 0x03

#define STEARING_ENABLE_FORWARD_BACK_MOVEMENT 0x08
#define STEARING_ENABLE_LEFT_RIGHT_MOVEMENT 0x04
#define STEARING_FORWART 0x02
#define STEARING_LEFT 0x01

#define STATE_DISABLED 0x00
#define STATE_WAITING_FOR_CONNECTION 0x01
#define STATE_CONNECTED 0x02
/*
This type of PDU is used to control robot movement.
It is sent over UDP.*/
struct stearing_PDU {
    unsigned int type: 2;
    unsigned int direction: 4;
    unsigned int seq_number;
};


/*
This type of PDU is used to change robot state.
It is sent over TCP.
*/
struct state_PDU {
    unsigned int type: 2;
    unsigned int state: 2;
};

/*
This type of PDU is used to send information collected by sensors.
It is sent over UDP.
*/
struct sensors_PDU {
    unsigned int type: 2;
    float gps_latitude;
    float gps_longitude;
    float wheel_speed_1;
    float wheel_speed_2;
    float wheel_speed_3;
    float wheel_speed_4;
};

typedef struct stearing_PDU stearing_pdu_t;
typedef struct state_PDU state_pdu_t;
typedef struct sensors_PDU sensors_pdu_t;
