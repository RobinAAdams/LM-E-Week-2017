/*******************************************************************************
*******************************************************************************/
#include "drive.h"
#include "receiver.h"

Drive::Drive ()
  : right_output(MOTOR_CONTROLLER_RIGHT, OUTPUT)
  , left_output(MOTOR_CONTROLLER_LEFT, OUTPUT)
{
}

Arcade_Drive::Arcade_Drive (Channel drive_in, Channel steering_in)
  : drive_in(drive_in)
  , steering_in(steering_in)
{
}

void Arcade_Drive::Process ()
{
  int drive_val = Receiver::Read(drive_in);
  int steering_val = Receiver::Read(steering_in);

  right_output.Write(((drive_val - steering_val) / 2) * -1);
  left_output.Write((drive_val + steering_val) / 2);
}
