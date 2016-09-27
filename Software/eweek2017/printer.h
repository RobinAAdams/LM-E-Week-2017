/*******************************************************************************
* Printer simplifies program console output over the serial terminal.
* 
* To use:
*   1) Include this file in the one you want to print in
*        #include "printer.h"
*   2) Verify "#define DEBUG_OUTPUT" is not commented out
*   3) Print to the console
*        Println("Hello, World!");
*******************************************************************************/
#ifndef PRINTER_H
#define PRINTER_H

/***********************************
 * MODIFYABLE SECTION START
 **********************************/

// Comment out to disable prints
#define DEBUG_OUTPUT

// This is the speed of data over your serial terminal (default = 9600)
#define BAUD_RATE 9600

/***********************************
 * MODIFYABLE SECTION END
 **********************************/

class Printer
{
public:
  static void _Print (String str);
  static String _Scan (unsigned int max_bytes);
  
protected:
private:
#ifdef DEBUG_PRINT
  static Printer printer_singleton;
#endif /* DEBUG_PRINT */

  Printer ();
};

extern String blank_string;

#define Print(a) Printer::_Print(blank_string + a)
#define Scan(a) Printer::_Scan(a)

#endif /* PRINTER_H */
