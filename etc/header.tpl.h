/*
 *  {FILENAME}.h
 *  Generated by lcd128x64.generate plugin for Adobe Generator™
 *
 *  C header file exporting bitmap sprites from Photoshop™ as byte array.
 *  Usage and docs at https://github.com/kilianc/lcd128x64.generate
 *
 *  For 128x64 LCD by Sparkfun with custom firmware.
 *   - LCD https://www.sparkfun.com/products/710
 *   - Serial Backpack https://www.sparkfun.com/products/9352
 *   - Custom Firmware http://serialglcd.sourceforge.net
 *   - Atmega* driver https://github.com/kilianc/arduino-lib
 *
 *  Created by Kilian Ciuffolo on {DATE}.
 *  This software is released under the MIT license cited below.
 *
 *  Copyright (c) 2010 Kilian Ciuffolo, me@nailik.org. All Rights Reserved.
 *
 *  Permission is hereby granted, free of charge, to any person
 *  obtaining a copy of this software and associated documentation
 *  files (the 'Software'), to deal in the Software without
 *  restriction, including without limitation the rights to use,
 *  copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the
 *  Software is furnished to do so, subject to the following
 *  conditions:
 *
 *  The above copyright notice and this permission notice shall be
 *  included in all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND,
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 *  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 *  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 *  OTHER DEALINGS IN THE SOFTWARE.
 */

#include <avr/pgmspace.h>

#define DIGITS_W {DIGITS_W}
#define DIGITS_H {DIGITS_H}

static const char digit_ba_0[] PROGMEM = { {DIGIT_0} };
static const char digit_ba_1[] PROGMEM = { {DIGIT_1} };
static const char digit_ba_2[] PROGMEM = { {DIGIT_2} };
static const char digit_ba_3[] PROGMEM = { {DIGIT_3} };
static const char digit_ba_4[] PROGMEM = { {DIGIT_4} };
static const char digit_ba_5[] PROGMEM = { {DIGIT_5} };
static const char digit_ba_6[] PROGMEM = { {DIGIT_6} };
static const char digit_ba_7[] PROGMEM = { {DIGIT_7} };
static const char digit_ba_8[] PROGMEM = { {DIGIT_8} };
static const char digit_ba_9[] PROGMEM = { {DIGIT_9} };

static const char *digit_ba_list[] PROGMEM = {
  digit_ba_0,
  digit_ba_1,
  digit_ba_2,
  digit_ba_3,
  digit_ba_4,
  digit_ba_5,
  digit_ba_6,
  digit_ba_7,
  digit_ba_8,
  digit_ba_9
};

const char * get_digit(char digit) {
  return digit_ba_list[digit];
}

void load_digit_ba_P(char digit, char digit_ba[]) {
  memcpy_P(digit_ba, (char *)pgm_read_word(&(digit_ba_list[digit])), 122);
}