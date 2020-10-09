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

    rgb.c: RGB LED matrix routines
*/

#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "config.h"
#include "rgb.h"

static uint8_t RGB[RGB_LED_NUM * 3];
static volatile uint8_t _count;
static volatile uint8_t _led;

ISR(RGB_IRQ_vect) {
  uint8_t r,g,b;
  uint8_t* p;


  if(_led >= RGB_LED_NUM) {
    _led = 0;
    _count++;
  }

  p = &RGB[_led * 3];

  r = (*p++ > _count ? TRUE : FALSE);
  g = (*p++ > _count ? TRUE : FALSE);
  b = (*p++ > _count ? TRUE : FALSE);

  rgb_led_set(_led, r, g, b);
  _led++;
}

void rgb_set(uint8_t led, uint8_t red, uint8_t grn, uint8_t blu ) {
  uint8_t* p = &RGB[led * 3];

  if(led < RGB_LED_NUM) {
    *p++ = red;
    *p++ = grn;
    *p++ = blu;
  }
}

void rgb_init(void) {
  rgb_timer_config();
  rgb_led_init();
}
