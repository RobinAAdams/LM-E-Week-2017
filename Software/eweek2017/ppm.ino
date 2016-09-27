/*******************************************************************************
*******************************************************************************/
#include "ppm.h"

#define PPM_MIN         800
#define PPM_LOW         1000
#define PPM_LOW_THRESH  1450
#define PPM_MID         1500
#define PPM_HIGH_THRESH 1550
#define PPM_HIGH        2000
#define PPM_MAX         2200

bool PPM::init = false;
bool PPM::pin_enabled[NUM_PINS];
bool PPM::pin_state[NUM_PINS];
unsigned long PPM::start_time[NUM_PINS];
unsigned int PPM::pin_micros[NUM_PINS];
Servo PPM::servo[NUM_PINS];

PPM::PPM (Pin pin, int io) : pin(pin)
{
  if (!init)
  {
    for (int i = 0; i < NUM_PINS; i++)
    {
      pin_enabled[i] = false;
    }
    
    init = true;
  }

  if (io == INPUT)
  {
    pinMode(pin, INPUT);

    // Enable pin interrupt
    *digitalPinToPCMSK(pin) |= bit (digitalPinToPCMSKbit(pin));  // enable pin
    PCIFR |= bit (digitalPinToPCICRbit(pin)); // clear any outstanding interrupt
    PCICR |= bit (digitalPinToPCICRbit(pin)); // enable interrupt for the group
  
    pin_enabled[pin] = true;
    pin_state[pin] = digitalRead(pin);
    start_time[pin] = micros();
    pin_micros[pin] = 0;
  }
  else if (io == OUTPUT)
  {
    servo[pin].attach(pin);
    Write(0);
  }
}

bool PPM::Pin_Test (Pin pin)
{
  if (pin_enabled[pin])
  {
    bool val = (digitalRead(pin) == HIGH);
    if (pin_state[pin] != val)
    {
      pin_state[pin] = val;

      if (val)
      {
        // Start timer
        start_time[pin] = micros();
      }
      else
      {
        // Stop timer
        pin_micros[pin] = micros() - start_time[pin];
      }

      return true;
    }
  }

  return false;
}
 
ISR (PCINT0_vect) // handle pin change interrupt for D8 to D13 here
{
  for (int i = 8; i <= 13; i++)
  {
    if (PPM::Pin_Test(i))
    {
      break;
    }
  }
}

ISR (PCINT1_vect) // handle pin change interrupt for A0 to A5 here
{
  for (int i = A0; i <= A5; i++)
  {
    if (PPM::Pin_Test(i))
    {
      break;
    }
  }
}  

ISR (PCINT2_vect) // handle pin change interrupt for D0 to D7 here
{
  for (int i = 0; i <= 7; i++)
  {
    if (PPM::Pin_Test(i))
    {
      break;
    }
  }
}

// Returns -100 to 100
int PPM::Read (Pin pin)
{
  if (pin_micros[pin] < PPM_MIN || pin_micros[pin] > PPM_MAX)
  {
    return 0;
  }
  else if (pin_micros[pin] <= PPM_LOW)
  {
    return -500;
  }
  else if (pin_micros[pin] >= PPM_HIGH)
  {
    return 500;
  }

  return pin_micros[pin] - PPM_MID;
}

// Returns -100 to 100
int PPM::Read ()
{
  return Read(pin);
}

// Expects value between -100 and 100
void PPM::Write (Pin pin, int value)
{
  if (value >= -500 && value <= 500)
  {
    servo[pin].write(PPM_MID + value);
  }
}

// Expects value between -100 and 100
void PPM::Write (int value)
{
  return Write(pin, value);
}

