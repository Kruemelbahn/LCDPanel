/*************************************************** 
 *  LCDPanel.h v1.0 - LCD/I2C communication for Arduino
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

#ifndef _KS_LCDPanel_h
#define _KS_LCDPanel_h

#include <inttypes.h>
#include "Adafruit_RGBLCDShield.h"
#include "Bounce2mcp.h"

#define BUTTON_FCT_BACK (BUTTON_LEFT | BUTTON_UP | BUTTON_DOWN)
#define BUTTON_A5 0x20

#define BUTTON_BACKLIGHT 5
#define LCD_BACKLIGHT 6

#define DEBOUNCE_TIME 5

class LCDPanel : public Adafruit_RGBLCDShield {
public:
	LCDPanel() {};
  void begin(uint8_t cols, uint8_t rows, uint8_t charsize = LCD_5x8DOTS);

	Adafruit_MCP23017* getMCP() { return &i2c; }

	uint8_t detect_i2c(uint8_t ui8_LcdAddr);

  uint8_t readButtonA5();

	void	updateDebounce();

	// Instantiate the Bounce objects
	BounceMcp debouncer_Left; 
	BounceMcp debouncer_Right; 
	BounceMcp debouncer_Up; 
	BounceMcp debouncer_Down; 
	BounceMcp debouncer_OK; 

protected:
	Adafruit_MCP23017 i2c;

private:
  // just a comment for variable used in Adafruit_RGBLCDShield:
	//   uint8_t _i2cAddr;	==> 0 = i2c is used; 255 = wired connection instead use of i2c
};

#endif
