/*
    PowerLED - Multi-purpose Power LED
    Copyright Jim Brain and RETRO Innovations, 2008-2011

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

    config.h: User-configurable options to simplify hardware changes and/or
              reduce the code/ram requirements of the code.
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "config.h"
#include "rgb.h"

int main(void) {
  uint8_t uiec_on = FALSE;
  //uint8_t count = 0;
  unsigned int rgbColour[3];

  rgb_init();

  sei();

  while(TRUE) {


   // Start off with red.
   rgbColour[0] = 255;
   rgbColour[1] = 0;
   rgbColour[2] = 0;

   // Choose the colours to increment and decrement.
   for (int decColour = 0; decColour < 3; decColour += 1) {
     int incColour = decColour == 2 ? 0 : decColour + 1;

     // cross-fade the two colours.
     for(int i = 0; i < 255; i += 1) {
       rgbColour[decColour] -= 1;
       rgbColour[incColour] += 1;
       if((PINB & _BV(PB3)) && !uiec_on) {
         // power to uIEC has come on...
         uiec_on = TRUE;
       } else if(!(PINB & _BV(PB3)) && !uiec_on) {
           // power to uIEC has yet to come on...
         rgb_set(0,255, 255, 255);
         //uiec_on = TRUE;
       } else if((PINB & _BV(PB6))) {
           // activity or error
         rgb_set(0,255, 0, 0);  // red
       } else {
         rgb_set(0,rgbColour[0], rgbColour[1], rgbColour[2]);
         rgb_set(0,rgbColour[0], rgbColour[1], rgbColour[2]);
         _delay_ms(2);
       }
     }
   }
  }
}
