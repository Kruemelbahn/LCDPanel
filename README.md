# LCDPanel

This is a simple library for LCD for usage with Arduino-platform.<br>

The library is based on the original RGBLCDShield-library from [Adafruit](https://www.adafruit.com/).<br>
This library uses a hardware in which the LCD is controlled by an MCP23017 via I<sup>2</sup>C-Bus.
Additionally, the library will also control the operating buttons connected to the MCP23017; debouncing for the buttons is also integrated.<br>

Necessary base-library can be found on https://github.com/adafruit/Adafruit-RGB-LCD-Shield-Library

PCB for LCDPanel is available.<br>
Tested on ATmega328.
