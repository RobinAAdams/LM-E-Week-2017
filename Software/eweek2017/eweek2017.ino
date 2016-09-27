/*******************************************************************************
*******************************************************************************/
#include "printer.h"
#include "receiver.h"
#include "drive.h"

// Global variables
Drive *drive = new Arcade_Drive(CHANNEL_2, CHANNEL_3);
unsigned long start_time;
unsigned long curr_time;

// Code in this section only runs once
void setup ()
{
  start_time = micros();
}

// Code in this section runs continuously
void loop ()
{
  //TODO: Remove test code
  static int count = 0;
  if (count == 0)
  {
    for (int i = 0; i < Receiver::NUM_CHANNELS; i++)
    {
      Print(" ch" + (i + 1) + ": " + Receiver::Read((Channel)i) + "\n");
    }
    Print("\n");
  }
  count++;
  count%=60;

  drive->Process();

  // Process at ~60 Hz
  curr_time = micros();
  while (curr_time - start_time < 16000)
  {
    delay(1);
    curr_time = micros();
  }
  start_time = curr_time;
}
