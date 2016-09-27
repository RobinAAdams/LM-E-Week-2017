/*******************************************************************************
*******************************************************************************/
#ifndef PWM_H
#define PWM_H

#include <Arduino.h>
#include <Servo.h>

class PWM
{
public:
  PWM (Pin pin, int io);

  // Returns -500 to 500
  static int Read (Pin pin);
  int Read (void);

  // Expects value between -500 and 500
  static void Write (Pin pin, int value);
  void Write (int value);

  static bool Pin_Test (Pin pin);
  
protected:
private:
  static bool init;
  static bool pin_enabled[NUM_PINS];
  static bool pin_state[NUM_PINS];
  static unsigned long start_time[NUM_PINS];
  static unsigned int pin_micros[NUM_PINS];
  static Servo servo[NUM_PINS];

  Pin pin;
};

#endif /* PWM_H */
