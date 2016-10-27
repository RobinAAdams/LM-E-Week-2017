/*******************************************************************************
*******************************************************************************/
#include "receiver.h"
#include "pwm.h"

Receiver Receiver::receiver_singleton;
Pin Receiver::channel_map[8];
PWM *Receiver::pwm_map[8];

Receiver::Receiver ()
{    
  channel_map[0] = RECEIVER_1;
  channel_map[1] = RECEIVER_2;
  channel_map[2] = RECEIVER_3;
  channel_map[3] = RECEIVER_4;
  channel_map[4] = RECEIVER_5;
  channel_map[5] = RECEIVER_6;
  channel_map[6] = RECEIVER_7;
  channel_map[7] = RECEIVER_8;

  for (int i = 0; i < 8; i++)
  {
    pwm_map[i] = new PWM(channel_map[i], INPUT);
  }
}

int Receiver::Read (Channel channel)
{
  return pwm_map[channel]->Read();
}

