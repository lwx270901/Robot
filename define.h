#ifndef _MY_DEFINE_
#define _MY_DEFINE_

//----------------------------------------------
//----------------------------------------------
//----------------------------------------------
//#define SONAR_COUNTER	30
//----------------------------------------------
//----------------------------------------------
//----------------------------------------------
//----------------------------------------------
									//switch input define with value can see on LCD when we put input2
#define	L1_INDEX		0xf7
#define 	L2_INDEX		0xf6
#define 	L3_INDEX		0xf5
#define 	L4_INDEX		0xf4
#define 	R1_INDEX		0xf3
#define 	R2_INDEX		0xf2
#define 	R3_INDEX		0xf1
#define 	R4_INDEX		0xf0

#define B_LEFT		254
#define B_RIGHT		239
//----------------------------------------------
//----------------------------------------------
//----------------------------------------------
//----------------------------------------------
									//real speed - PD function (speed.c)
#define Kp_LEFT		5				
#define Kd_LEFT		5
#define Kp_RIGHT	5
#define Kd_RIGHT	5
#define ERROR_MIN	20		//minimum error to calculate PD

//----------------------------------------------
//----------------------------------------------
//----------------------------------------------
//----------------------------------------------
//----------------------------------------------
									//test_forward_pd()

#define Div_P	5
#define Div_D	5
//PID const
#define 	K_PRO 			3			//* proportional constant */
#define 	K_DRV 			4			//* derivative constant */
#define 	TMAX 			150*128	//* maximum output value */ //ko vuot qua 127									
									//keep_stable()
#define			KEEP_STABLE_KP			1
#define			KEEP_STABLE_SPEED_MAX	30
#define			TIME_FOR_STABLE	 25
#define			SPEED_MAX		 250
#define			SPEED_MIN		 10
/* Mask value setting x: With Mask (Invalid) o:Without mask (Valid)     */
#define         MASK2_2         0x18    /* oox00xoo */
#define         MASK3_C         0x3c    /* ooxxxxoo */
#define         MASK1_1         0x18    /* oooxxooo */
#define         MASK3_3         0xe7    /* xx0000xx */
#define         MASK0_3         0x07    /* 00000xxx */
#define         MASK3_0         0xe0    /* xxx00000 */



#define OK				    0
#define LEFT_CENTER_OUT1	1	//00011100
#define	LEFT_OUT1			2
#define	LEFT_OUT2			3
#define	LEFT_OUT3			4
#define	RIGHT_CENTER_OUT1	11
#define	RIGHT_OUT1			12
#define	RIGHT_OUT2			13
#define	RIGHT_OUT3			14
//----------------------------------------------
#define			LEFT		0
#define			RIGHT		1
//----------------------------------------------
//----------------------------------------------
//----------------------------------------------- wheel_action
#define 	NO_THING		0
//Forward1
#define 	FORWARD1		1
#define 	FORWARD1_1		2
#define 	FORWARD1_2		3
#define 	FORWARD1_3		4
#define 	FORWARD1_31		131
#define 	FORWARD1_32		132
#define 	FORWARD1_33		133
#define 	FORWARD1_4		5
#define 	FORWARD1_41		141
#define 	FORWARD1_42		142
#define 	FORWARD1_43		143
#define 	FORWARD1_5		6
#define 	FORWARD1_6		7
#define 	FORWARD1_7		8
#define 	FORWARD1_8		9
#define 	FORWARD1_9		10
#define 	FORWARD2		200
#define 	FORWARD2_1		201
#define 	FORWARD2_2		202
#define 	FORWARD2_3		203
#define 	FORWARD2_4		204
#define 	FORWARD2_END	205
#define		FORWARD_ENCODER	210
#define		FORWARD_ENCODER_1	211
#define		FORWARD_ENCODER_2	212
#define		FORWARD_ENCODER_3	213


///////ADC////////////
#define	V_COMPARE_BLACK_MORE	10


////////////////////EEPRom//
#define	LEFT_ADJUST_POS		24 //gamepad 
#define	RIGHT_ADJUST_POS	25//gamepad


///////////////////////#define INPUT////////////////////////
#define LRButtons		input2
#define SWGifts			input3

////////Gamepad/////////////
// bit0 bit1 bit2 bit3 bit4 bit5  bit6 bit7
// slct joyr joyl strt up   right down left
// L2   R2    L1   R1  /\    O      X   []
//#ifdef _RES_

#define NO_BUTTON_1				0x0000
#define BUTTON_TRIANGLE_MASK_1 	0x0030
#define BUTTON_O_MASK_1 			0x0060
#define BUTTON_X_MASK_1 			0x00c0
#define BUTTON_SQUARE_MASK_1 		0x0180

#define BUTTON_L2_MASK_1	0x0003
#define BUTTON_R2_MASK_1	0x0006
#define BUTTON_L1_MASK_1	0x000c
#define BUTTON_R1_MASK_1	0x0018

#define BUTTON_UP_MASK_1 		0x3000
#define BUTTON_RIGHT_MASK_1 	0x6000
#define BUTTON_DOWN_MASK_1 	0xc000
#define BUTTON_LEFT_MASK_1	0x8001

#define BUTTON_START_MASK_1	0x1800
#define BUTTON_SELECT_MASK_1	0x0300
	
#define NO_BUTTON_2				0x0100

#define BUTTON_TRIANGLE_MASK_2 	0x0130
#define BUTTON_O_MASK_2 			0x0160
#define BUTTON_X_MASK_2 			0x01c0
#define BUTTON_SQUARE_MASK_2 		0x0180

#define BUTTON_L2_MASK_2	0x0103
#define BUTTON_R2_MASK_2	0x0106
#define BUTTON_L1_MASK_2	0x010c
#define BUTTON_R1_MASK_2	0x0118

#define BUTTON_UP_MASK_2 		0x3100
#define BUTTON_RIGHT_MASK_2 	0x6100
#define BUTTON_DOWN_MASK_2 	0xc100
#define BUTTON_LEFT_MASK_2	0x8101

#define BUTTON_START_MASK_2	0x1900
#define BUTTON_SELECT_MASK_2	0x0300

#define NO_LIFT		0
#define LIFT_DOWN	1
#define LIFT_UP		2

#define LIFT_UP_LEVEL 3
#define LIFT_DOWN_LEVEL 4 

#define LIFT_UP_LEVEL_1 5
#define LIFT_DOWN_LEVEL_1 6 

#define LIFT_UP_2LEVEL 7
#define LIFT_UP_2LEVEL_1 8
#define LIFT_UP_2LEVEL_2 9
#define LIFT_UP_2LEVEL_3 10

#define LIFT_DOWN_2LEVEL 11
#define LIFT_DOWN_2LEVEL_1 12
#define LIFT_DOWN_2LEVEL_2 13
#define LIFT_DOWN_2LEVEL_3 14

#define LIFT_SPEED	(-200)	//dong co nguoc
#define NO_HAND		0
#define HAND_UP		1
#define HAND_DOWN	2
#define HAND1_SPEED	255
#define HAND2_SPEED 100


#endif
