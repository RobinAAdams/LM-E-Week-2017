/*******************************************************************************
* Printer simplifies program console output over the serial terminal.
* 
* See printer.h for usage.
*******************************************************************************/
#include "printer.h"

#ifdef DEBUG_PRINT
Printer Printer::printer_singleton;
#endif /* DEBUG_PRINT */

String blank_string = "";

Printer::Printer ()
{
#ifdef DEBUG_PRINT
  Serial.begin(BAUD_RATE);
#endif /* DEBUG_PRINT */
}

void Printer::_Print (String str)
{
#ifdef DEBUG_PRINT
  Serial.print(str.c_str());
#endif /* DEBUG_PRINT */
}

String Printer::_Scan (unsigned int max_bytes)
{
  String str = "";

#ifdef DEBUG_PRINT
  for (unsigned int i = 0; i < max_bytes; i++)
  {
    if (Serial.available() > 0)
    {
      str += Serial.read();
    }
    else
    {
      break;
    }
  }
#endif /* DEBUG_PRINT */

  return str;
}

