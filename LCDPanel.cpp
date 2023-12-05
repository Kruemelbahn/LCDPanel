/*************************************************** 
 *  LCDPanel.cpp v1.0 - LCD/I2C communication for Arduino
 *
 *  Copyright (c) 2018 Michael Zimmermann <http://www.kruemelsoft.privat.t-online.de>
 *  All rights reserved.
 *
 *  Derived class from Adafruit_RGBLCDShield
 *  Original source (Adafruit_RGBLCDShield) written by Limor Fried/Ladyada for Adafruit Industries
 *       <http://http://www.adafruit.com/products/714>
 *
 *  LICENSE
 *  -------
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 ****************************************************/

#include "LCDPanel.h"

#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <Wire.h>

#ifdef __AVR__
 #define WIRE Wire
#else // Arduino Due
 #define WIRE Wire1
#endif

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

uint8_t LCDPanel::detect_i2c(uint8_t ui8_LcdAddr)
{
	Wire.begin();
	Wire.beginTransmission(ui8_LcdAddr);
	return Wire.endTransmission();
}

void LCDPanel::begin(uint8_t cols, uint8_t rows, uint8_t charsize)
{
	// init of MCP28017 before initializing from Adafruit_RGBLCDShield:
	i2c.begin();
	Adafruit_RGBLCDShield::begin(cols, rows, charsize);
  i2c.pinMode(BUTTON_BACKLIGHT, INPUT);
  i2c.pullUp(BUTTON_BACKLIGHT, HIGH);

	// After setting up the button, setup the Bounce instances :
	debouncer_Left.attach	(i2c, 4, DEBOUNCE_TIME);
	debouncer_Up.attach		(i2c, 3, DEBOUNCE_TIME);
	debouncer_Down.attach	(i2c, 2, DEBOUNCE_TIME);
	debouncer_Right.attach(i2c, 1, DEBOUNCE_TIME);
	debouncer_OK.attach		(i2c, 0, DEBOUNCE_TIME);
}

void	LCDPanel::updateDebounce()
{
	// Update the Bounce instances :
	debouncer_Left.update();
	debouncer_Up.update();
	debouncer_Down.update();
	debouncer_Right.update();
	debouncer_OK.update();
}

uint8_t LCDPanel::readButtonA5(void)
{
  uint8_t reply(BUTTON_A5);
  reply &= ~((i2c.digitalRead(BUTTON_BACKLIGHT)) << 5);
  return reply;
}