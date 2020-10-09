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

#ifndef CONFIG_H
#define CONFIG_H

#include <avr/io.h>
#include "autoconf.h"

#define FALSE 0
#define TRUE  (!FALSE)

#if CONFIG_HARDWARE_VARIANT == 1

#define RGB_LED_NUM 1

static inline __attribute__((always_inline)) void rgb_led_init(void) {
  DDRA = 0xff;
}

static inline __attribute__((always_inline)) void rgb_led_set(uint8_t pos, uint8_t r, uint8_t g, uint8_t b) {
  //PORTA = 0;  // TODO: NOT SURE I NEED THIS.
  PORTA = (_BV(4 + pos) | (r ? _BV(0) : 0) | (g ? _BV(1) : 0) | (b ? _BV(2) : 0));
}


#endif
#endif  /*CONFIG_H*/
