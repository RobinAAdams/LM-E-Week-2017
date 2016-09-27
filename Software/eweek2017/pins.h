/*******************************************************************************
* This file lists input and output pins and their functions for the ATmega328P
*******************************************************************************/
 #ifndef PINS_H
 #define PINS_H

 typedef byte Pin;
 
 typedef enum
 {
   CHANNEL_1 = 0,
   CHANNEL_2,
   CHANNEL_3,
   CHANNEL_4,
   CHANNEL_5,
   CHANNEL_6,
   CHANNEL_7,
   CHANNEL_8
 } Channel;

 static const byte NUM_PINS = A5 + 1;

/***********************************
 * MODIFYABLE SECTION START
 **********************************/

// User-Defined I/O
static const Pin CUSTOM_1 = 5;  // Pin 5 - Digital I/O, PWM Out
static const Pin CUSTOM_2 = 6;  // Pin 6 - Digital I/O, PWM Out
static const Pin CUSTOM_3 = A1; // Pin A1 - Digital I/O, Analog In
static const Pin CUSTOM_4 = A2; // Pin A2 - Digital I/O, Analog In
static const Pin CUSTOM_5 = A3; // Pin A3 - Digital I/O, Analog In
static const Pin CUSTOM_6 = A4; // Pin A4 - Digital I/O, Analog In
static const Pin CUSTOM_7 = A5; // Pin A5 - Digital I/O, Analog In

/***********************************
 * MODIFYABLE SECTION END
 **********************************/

// Reserved for serial I/O
static const Pin RESERVED_1 = 0;
static const Pin RESERVED_2 = 1;

// Inputs
static const Pin RECEIVER_1 = 7;
static const Pin RECEIVER_2 = 8;
static const Pin RECEIVER_3 = 9;
static const Pin RECEIVER_4 = 10;
static const Pin RECEIVER_5 = 11;
static const Pin RECEIVER_6 = 12;
static const Pin RECEIVER_7 = 13;
static const Pin RECEIVER_8 = A0;

// Outputs
static const Pin MOTOR_CONTROLLER_RIGHT = 2;
static const Pin MOTOR_CONTROLLER_LEFT  = 3;
static const Pin MOTOR_CONTROLLER_AUX   = 4;

#endif /* PINS_H */
