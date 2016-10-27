/*******************************************************************************
*******************************************************************************/
#ifndef RECEIVER_H
#define RECEIVER_H

#include "pins.h"
#include "pwm.h"

class Receiver
{
public:
  static const int NUM_CHANNELS = 8;

  static int Read (Channel channel);

protected:
private:
  static Receiver receiver_singleton;
  static Pin channel_map[NUM_CHANNELS];
  static PWM *pwm_map[NUM_CHANNELS];

  Receiver();
};

#endif /* RECEIVER_H */
