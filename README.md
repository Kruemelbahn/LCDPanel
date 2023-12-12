# LCDPanel

This is a simple library for LCD for usage with Arduino-platform.<br>

The class "LCDPanel" is derived from "Adafruit_RGBLCDShield" used in the original RGBLCDShield-library from [Adafruit](https://www.adafruit.com/).

Both libraries use a hardware in which the LCD and buttons are controlled by an MCP23017 via I<sup>2</sup>C-Bus.

The Adafruit-library was expanded to support the five buttons with debouncing (which is not supported directly with the original library).
In addition, controling and enabeling the backlight of LCD is possible.

"LCDPanel" is also used as a unit for controlling some of my devices and can
- show the status of the device
- change parameters (I call them CV = Configuration Variable)
Requested software for this is implemented inside the software for the device.

<img src=pics/LCD-Panel-Device.png><br>

PCB for LCDPanel is available.<br>
<img src=pics/LCD-Panel-PCB.png><br>
Tested on ATmega328.

### Necessary libraries
 - base-library https://github.com/adafruit/Adafruit-RGB-LCD-Shield-Library
 - accessory-library https://github.com/cosmikwolf/Bounce2mcp
 
### Usage
 - the basic usage of both libraries is well documented by [Adafruit](https://learn.adafruit.com/rgb-lcd-shield)
 - see also example [CheckLCDPanel.ino](examples/CheckLCDPanel/CheckLCDPanel.ino)
 
