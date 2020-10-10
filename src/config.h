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
#ifndef ARDUINO
#include "autoconf.h"
#endif

#define FALSE 0
#define TRUE  (!FALSE)

#define _DEF_REG(x,y) (x##y)
#define DEF_REG(x, y) _DEF_REG(x,y)

// Common definitions

#define RGB_LED_NUM 1

#if defined ARDUINO_AVR_UNO || defined ARDUINO_AVR_PRO || defined ARDUINO_AVR_NANO
// Arduino IDE does not allow us to create the autoconf.h file, so we have to add those things in here.
  #define CONFIG_HARDWARE_VARIANT   4
  #define CONFIG_SW_0_COLOR RED
  #define CONFIG_SW_1_COLOR WHITE
  #define CONFIG_SW_2_COLOR BLUE
  #define CONFIG_SW_3_COLOR GREEN
  #define CONFIG_SW_4_COLOR YELLOW
  #define CONFIG_SW_5_COLOR ORANGE
  #define CONFIG_SW_6_COLOR PURPLE
  #define CONFIG_SW_7_COLOR BLACK

  #define CONFIG_COLOR_DELAY 10
#endif

#if CONFIG_HARDWARE_VARIANT == 1

#define SAME_LED_PORT
#ifndef CONFIG_LED_REV_POL
#define LED_REV_POL
#endif

#define LED_R_PORT A
#define LED_G_PORT A
#define LED_B_PORT A

#define LED_R_PIN PIN0
#define LED_G_PIN PIN1
#define LED_B_PIN PIN2

#define SW_0_PORT   B
#define SW_0_PIN    PIN3

#define SW_1_PORT   B
#define SW_1_PIN    PIN6

#elif CONFIG_HARDWARE_VARIANT == 2
// 8 pin devices

#define SAME_LED_PORT
#ifndef CONFIG_LED_REV_POL
#define LED_REV_POL
#endif

#define LED_R_PORT B
#define LED_G_PORT B
#define LED_B_PORT B

#define LED_R_PIN PIN0
#define LED_G_PIN PIN1
#define LED_B_PIN PIN2

#define SW_0_PORT   B
#define SW_0_PIN    PIN3

#define SW_1_PORT   B
#define SW_1_PIN    PIN4

#elif CONFIG_HARDWARE_VARIANT == 3
// 14 pin devices

#define SAME_LED_PORT
#ifndef CONFIG_LED_REV_POL
#define LED_REV_POL
#endif

#define LED_R_PORT B
#define LED_G_PORT B
#define LED_B_PORT B

#define LED_R_PIN PIN0
#define LED_G_PIN PIN1
#define LED_B_PIN PIN2

#define SW_0_PORT   A
#define SW_0_PIN    PIN0

#define SW_1_PORT   A
#define SW_1_PIN    PIN1

#define SW_2_PORT   A
#define SW_2_PIN    PIN2

#define SW_3_PORT   A
#define SW_3_PIN    PIN3

#define SW_4_PORT   A
#define SW_4_PIN    PIN4

#define SW_5_PORT   A
#define SW_5_PIN    PIN5

#define SW_6_PORT   A
#define SW_6_PIN    PIN6

#define SW_7_PORT   A
#define SW_7_PIN    PIN7

#elif CONFIG_HARDWARE_VARIANT == 4
// 14 pin devices

#define SAME_LED_PORT
#ifndef CONFIG_LED_REV_POL
#define LED_REV_POL
#endif

#define LED_R_PORT D
#define LED_G_PORT D
#define LED_B_PORT D

#define LED_R_PIN PIN2
#define LED_G_PIN PIN3
#define LED_B_PIN PIN4

#define SW_0_PORT   B
#define SW_0_PIN    PIN0

#define SW_1_PORT   B
#define SW_1_PIN    PIN1

#define SW_2_PORT   B
#define SW_2_PIN    PIN2

#define SW_3_PORT   B
#define SW_3_PIN    PIN3

#define SW_4_PORT   C
#define SW_4_PIN    PIN0

#define SW_5_PORT   C
#define SW_5_PIN    PIN1

#define SW_6_PORT   C
#define SW_6_PIN    PIN2

#define SW_7_PORT   C
#define SW_7_PIN    PIN3

#else
#  error Unknown hardware configuration in config.h. Please add information for this hardware.
#endif


#ifdef SW_0_PORT
  #define SW_0_DDR    DEF_REG(DDR,SW_0_PORT)
  #define SW_0_OUT    DEF_REG(PORT,SW_0_PORT)
  #define SW_0_IN     DEF_REG(PIN,SW_0_PORT)
  #define SW_0_VAL    _BV(SW_0_PIN)
#endif

#ifdef SW_1_PORT
  #define SW_1_DDR    DEF_REG(DDR,SW_1_PORT)
  #define SW_1_OUT    DEF_REG(PORT,SW_1_PORT)
  #define SW_1_IN     DEF_REG(PIN,SW_1_PORT)
  #define SW_1_VAL    _BV(SW_1_PIN)
#endif

#ifdef SW_2_PORT
  #define SW_2_DDR    DEF_REG(DDR,SW_2_PORT)
  #define SW_2_OUT    DEF_REG(PORT,SW_2_PORT)
  #define SW_2_IN     DEF_REG(PIN,SW_2_PORT)
  #define SW_2_VAL    _BV(SW_2_PIN)
#endif

#ifdef SW_3_PORT
  #define SW_3_DDR    DEF_REG(DDR,SW_3_PORT)
  #define SW_3_OUT    DEF_REG(PORT,SW_3_PORT)
  #define SW_3_IN     DEF_REG(PIN,SW_3_PORT)
  #define SW_3_VAL    _BV(SW_3_PIN)
#endif

#ifdef SW_4_PORT
  #define SW_4_DDR    DEF_REG(DDR,SW_4_PORT)
  #define SW_4_OUT    DEF_REG(PORT,SW_4_PORT)
  #define SW_4_IN     DEF_REG(PIN,SW_4_PORT)
  #define SW_4_VAL    _BV(SW_4_PIN)
#endif

#ifdef SW_5_PORT
  #define SW_5_DDR    DEF_REG(DDR,SW_5_PORT)
  #define SW_5_OUT    DEF_REG(PORT,SW_5_PORT)
  #define SW_5_IN     DEF_REG(PIN,SW_5_PORT)
  #define SW_5_VAL    _BV(SW_5_PIN)
#endif

#ifdef SW_6_PORT
  #define SW_6_DDR    DEF_REG(DDR,SW_6_PORT)
  #define SW_6_OUT    DEF_REG(PORT,SW_6_PORT)
  #define SW_6_IN     DEF_REG(PIN,SW_6_PORT)
  #define SW_6_VAL    _BV(SW_6_PIN)
#endif

#ifdef SW_7_PORT
  #define SW_7_DDR    DEF_REG(DDR,SW_7_PORT)
  #define SW_7_OUT    DEF_REG(PORT,SW_7_PORT)
  #define SW_7_IN     DEF_REG(PIN,SW_7_PORT)
  #define SW_7_VAL    _BV(SW_7_PIN)
#endif

static inline void sw_config(void) {
  // bring up pullup resistors.
#ifdef SW_0_PORT
  SW_0_OUT |= SW_0_VAL;
#endif
#ifdef SW_1_PORT
  SW_1_OUT |= SW_1_VAL;
#endif
#ifdef SW_2_PORT
  SW_2_OUT |= SW_2_VAL;
#endif
#ifdef SW_3_PORT
  SW_3_OUT |= SW_3_VAL;
#endif
#ifdef SW_4_PORT
  SW_4_OUT |= SW_4_VAL;
#endif
#ifdef SW_5_PORT
  SW_5_OUT |= SW_5_VAL;
#endif
#ifdef SW_6_PORT
  SW_6_OUT |= SW_6_VAL;
#endif
#ifdef SW_7_PORT
  SW_7_OUT |= SW_7_VAL;
#endif
}

static inline uint8_t is_switch(uint8_t sw) {
  switch(sw) {
#ifdef SW_0_PORT
  case 0:
    return !(SW_0_IN & SW_0_VAL);
#endif
#ifdef SW_1_PORT
    case 1:
    return !(SW_1_IN & SW_1_VAL);
#endif
#ifdef SW_2_PORT
    case 2:
    return !(SW_2_IN & SW_2_VAL);
#endif
#ifdef SW_3_PORT
    case 3:
    return !(SW_3_IN & SW_3_VAL);
#endif
#ifdef SW_4_PORT
    case 4:
    return !(SW_4_IN & SW_4_VAL);
#endif
#ifdef SW_5_PORT
    case 5:
    return !(SW_5_IN & SW_5_VAL);
#endif
#ifdef SW_6_PORT
    case 6:
    return !(SW_6_IN & SW_6_VAL);
#endif
#ifdef SW_7_PORT
    case 7:
    return !(SW_7_IN & SW_7_VAL);
#endif
  }
  return 0;
}

#define LED_R_DDR    DEF_REG(DDR,  LED_R_PORT)
#define LED_R_OUT    DEF_REG(PORT, LED_R_PORT)
#define LED_R_IN     DEF_REG(PIN,  LED_R_PORT)
#define LED_R_VAL    _BV(LED_R_PIN)

#define LED_G_DDR    DEF_REG(DDR,  LED_G_PORT)
#define LED_G_OUT    DEF_REG(PORT, LED_G_PORT)
#define LED_G_IN     DEF_REG(PIN,  LED_G_PORT)
#define LED_G_VAL    _BV(LED_G_PIN)

#define LED_B_DDR    DEF_REG(DDR,  LED_B_PORT)
#define LED_B_OUT    DEF_REG(PORT, LED_B_PORT)
#define LED_B_IN     DEF_REG(PIN,  LED_B_PORT)
#define LED_B_VAL    _BV(LED_B_PIN)

// easy defines for the simple single LED options
#if defined(LED_R_PORT) && defined(LED_G_PORT) && defined (LED_B_PORT)
static inline __attribute__((always_inline)) void rgb_led_init(void) {
#ifdef SAME_LED_PORT
  LED_R_DDR |= (LED_R_VAL | LED_G_VAL | LED_B_VAL);
#else
  LED_R_DDR |= LED_R_VAL;
  LED_G_DDR |= LED_G_VAL;
  LED_B_DDR |= LED_B_VAL;
#endif
}

#if defined(CONFIG_LED_REV_POL) && CONFIG_LED_REV_POL==y
#define LED_REV_POL
#endif

#ifdef LED_REV_POL
#define REV(x) (!x)
#else
#define REV(x) (x)
#endif

static inline __attribute__((always_inline)) void rgb_led_set(uint8_t pos __attribute__((unused)), uint8_t r, uint8_t g, uint8_t b) {
  //PORTA = (_BV(4 + pos) | (r ? _BV(0) : 0) | (g ? _BV(1) : 0) | (b ? _BV(2) : 0));
  LED_R_OUT = (REV(r) ? LED_R_OUT |= LED_R_VAL : LED_R_OUT & ~LED_R_VAL);
  LED_G_OUT = (REV(g) ? LED_G_OUT |= LED_G_VAL : LED_G_OUT & ~LED_G_VAL);
  LED_B_OUT = (REV(b) ? LED_B_OUT |= LED_B_VAL : LED_B_OUT & ~LED_B_VAL);
}
#endif

#define BLACK   0,0,0
#define BROWN   102,51,0
#define RED     255,0,0
#define ORANGE  255,128,0
#define YELLOW  255,255,0
#define GREEN   0,255,0
#define BLUE    0,0,255
#define GRAY    128,128,128
#define GOLD    153,153,0

#define LT_GRAY 192,192,192
#define WHITE   255,255,255
#define PURPLE  127,0,255
#define PLUM    255,0,255



#endif  /*CONFIG_H*/
