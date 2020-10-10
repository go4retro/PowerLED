# PowerLED

This is a simple Atmela AVR-based uC project that allows a single LED to signal 
different types of events to the end user.

## History

The initial commit of this codebase was designed around an ATTiny26, because I had
a spare one in the parts box, and I was trying to solve a problem with a project
design for a friend. Gabriella wanted to paint a Commodore VIC-20 green like the 
"station wagon" automobiles of the 1970's, make it self contained with an SD-based
CBM drive, and use a "rear view mirror" LCD screen and wooden side panels to finish 
the look.  I offered to help, and the design came together well, though I was loathe
to wire in additional LEDs for the uIEC/SD power and activity/error indicators.  
This project allowed me to both re-use the already existing power LED spot in the 
VIC-20 case to show all 3 conditions (uIEC power not on, error, and normal operation)
while also providing a neat visible draw for the show audience with the color cycling
LED effect.

![VIC SW Int](https://github.com/go4retro/PowerLED/blob/master/pics/VIC%20SW%20Int.JPG)

![VIC SW](https://github.com/go4retro/PowerLED/blob/master/pics/VIC%20SW.JPG)

I've removed some of the uIEC/SD specific stuff in the codebase and generalized the
rest of the code, but the main idea is still the same.  (And yes, the ATTINY26 was
also overkill for the project, but you use what you have on hand).

## Operation

In normal operation, a single RGB slowly and continually cycles across a large 
set of colors, giving off a pleasing cool power LED vibe.  However, when one of the 
various I/O pins is triggered, the color "snaps" to a predetermined hue for as long
as that trigger is present.  The triggers are priority encoded, so if there are 2 
triggers and both are present, the highest priority trigger's color will override.
Triggers are defined according to the size of the AVR microcontroller in use.  The
ATTiny13 is the smallest uC supported, with 8 pins (5 IO lines, RESET, Vcc, and Gnd)
and 2 triggers supported. ATTiny24 (with 14 pins), supports 8 triggers.  Not all
triggers need be used, unused triggers will float high and not display.

## Technical Details

There's nothing particularly technologically impressive about the uC code, but it
does use a IRQ-based LED PWM cycling system to free the main code having to manage
the RGB LED colors.  Simply set the led values (0-255 for each color) and let the 
IRQ handle the rest.  The code is borrowed from an unreleased multi-LED project, so
the system can handle more than 1 LED, though only 1 is supported in the curret
code base.

## Configuration

Most configuration changes can be made from the config-* files.  Pick one that fits
your uC of choice, and then edit a few fields.  

The obvious ones are the colors to
be used per trigger, defined **CONFIG_SW_X_COLOR**, where X is the switch number (0-MAX).
You can use the predefined color names (RED, GREEN, etc.), or just use a 3-tuple of
color values "255,255,255" (don't put the quotes in, though...)  

The cycling speed can be set via the **CONFIG_COLOR_DELAY** value, which is in ms.  10 
seems mellow, but 2 is OK, and 0 is hectic.

## Building

Make sure you have a working avr-gcc, avrdude and a copy of make and awk (GNU awk is
in cygwin or I think there is a Windows native version).

On the command line of the directory, type in (replace config-t13 with config you
are using):

`make CONFIG=config-t13 fuses program`

This will set the fuses to 8MHz RC oscillator, no clock division, and everything else
off (no watchdog timer, etc.).  Pretty basic.  It will then compile and flash the 
code onto the uC.

The system will use the default avrdude programmer settings, which are normally set 
in avrdude.rc, but you can override by passing AVRDUDE_PROGRAMMER=<the value you'd 
normally place after -c for avrdude directly> and/or  AVRDUDE_PORT=<the value you'd
normally place after the -P for avrdude directly.  So, if you are using the arduino
programming algorithm on COM1, you'd do:

`make CONFIG=config-t13 AVRDUDE_PROGRAMMER=arduino AVRDUDE_PORT=COM1: fuses program`

You need only use the "fuses" target once.  Afterwards, you can omit it.

## Improvements  

If there is interest, I can add more features:

* more AVR uC support (assuming I have the uC here to test)
* options for active high switch/trigger signals (all are active low right now)
* Different normal LED operational modes (cycling from red to black and then to green
  to black and then to blue to black, or something else...
* A version for the Arduino (the Arduino ATMEGA328 is aboslutely overkill for this 
  project, but I realize some may want to try it out first on a UNO)

Feel free to hack the code, but I would appreciate folks fork the project and
contribute the ideas back into the main codebase.

*Jim Brain*<br>
*RETRO Innovations*
