/*******************************************************************************
*******************************************************************************/
#ifndef DRIVE_H
#define DRIVE_H

#include <Arduino.h>
#include <Servo.h>
#include "pins.h"
#include "ppm.h"

class Drive
{
public:
  Drive();

  virtual void Process (void) = 0;
  
protected:
  PPM right_output;
  PPM left_output;
  
private:
};

// This drive type uses a single stick for drive and steering
class Arcade_Drive : public Drive
{
public:
  Arcade_Drive (Channel drive_in, Channel steering_in);

  void Process (void);
  
protected:
private:
  Channel drive_in;
  Channel steering_in;
};

#endif /* DRIVE_H */
