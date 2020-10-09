/*
    ColorBandClock - Clock output using Resistor Color Band Colors
    Copyright Jim Brain and Brain Innovations, 2009

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

    led.h: RGB compatibility defines for multiple target chips
*/

#ifndef RGB_H
#define RGB_H

#if defined __AVR_ATtiny2313__

#  define RGB_IRQ_vect   TIMER0_COMPA_vect
#  define RGB_TCCRA      TCCR0A
#  define RGB_TCCRB      TCCR0B
#  define RGB_OCR        OCR0A
#  define RGB_TCNT       TCNT0
#  define RGB_TIMSK      TIMSK

#elif defined __AVR_ATtiny26__

#  define RGB_IRQ_vect   TIMER1_CMPA_vect
#  define RGB_OCR        OCR1A

static inline __attribute__((always_inline)) void rgb_timer_config(void) {
  TCNT1 = 0;
  OCR1A = (F_CPU/8/60/256/RGB_LED_NUM) - 1; // CPU/8, 60 times a sec, 256 steps per cycle, RGB_LED_NUM LEDs per RGB
  TCCR1B = _BV(CS10); // divide by 8
  TIMSK |= _BV(OCIE1A);
}

#endif

void rgb_set(uint8_t led, uint8_t red, uint8_t grn, uint8_t blu);
void rgb_init(void);

#endif /* RGB_H */
