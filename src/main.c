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

static inline void set_color(uint8_t sw) {

  switch(sw) {
#ifdef SW_0_PORT
  case 0:
    rgb_set(0,CONFIG_SW_1_COLOR);
    break;
#endif
#ifdef SW_1_PORT
  case 1:
    rgb_set(0,CONFIG_SW_1_COLOR);
    break;
#endif
#ifdef SW_2_PORT
  case 2:
    rgb_set(0,CONFIG_SW_2_COLOR);
    break;
#endif
#ifdef SW_3_PORT
  case 3:
    rgb_set(0,CONFIG_SW_3_COLOR);
    break;
#endif
#ifdef SW_4_PORT
  case 4:
    rgb_set(0,CONFIG_SW_4_COLOR);
    break;
#endif
#ifdef SW_5_PORT
  case 5:
    rgb_set(0,CONFIG_SW_5_COLOR);
    break;
#endif
#ifdef SW_6_PORT
  case 6:
    rgb_set(0,CONFIG_SW_6_COLOR);
    break;
#endif
#ifdef SW_7_PORT
  case 7:
    rgb_set(0,CONFIG_SW_7_COLOR);
    break;
#endif
  }
}


int main(void) {
  uint8_t color[3];
  uint8_t j;

  rgb_init();
  sw_config();

  sei();

  while(TRUE) {


   // Start off with red.
   color[0] = 255;
   color[1] = 0;
   color[2] = 0;

   // Choose the colours to increment and decrement.
   for (uint8_t dec_clr = 0; dec_clr < 3; dec_clr++) {
     int inc_clr = dec_clr == 2 ? 0 : dec_clr + 1;

     // cross-fade the two colours.
     for(uint8_t i = 0; i < 255; i++) {
       color[dec_clr] --;
       color[inc_clr] ++;
       j = 8;
       while(j-- && !is_switch(j)) {
       }
       if(is_switch(j)) {
         set_color(j);
       } else {
         rgb_set(0, color[0], color[1], color[2]);
         rgb_set(0, color[0], color[1], color[2]);
         _delay_ms(CONFIG_COLOR_DELAY);
       }
     }
   }
  }
}
