#include <Wire.h>
#include <LCDPanel.h>

//=== declaration of var's =======================================
LCDPanel displayPanel = LCDPanel();

uint8_t ui8_DisplayPanelPresent = 0;  // ui8_DisplayPanelPresent: 1 if I2C-LCD-Panel is found

uint8_t ui8CountFallingEdge(0), ui8CountRisingEdge(0);

void setup()
{
  // Debugging output
  Serial.begin(9600);

  if (displayPanel.detect_i2c(MCP23017_ADDRESS) == 0)
  {
    // LCD found:
    // set up the LCD's number of columns and rows: 
    displayPanel.begin(16, 2);
    displayPanel.print("LCD-Panel found");
    delay(2000);

    Serial.println("LCD-Panel found");
	ui8_DisplayPanelPresent = 1;
  }	  
  else
    Serial.println("no LCD-Panel found");
}

void loop()
{
  if(!ui8_DisplayPanelPresent)
	  return;
  
  // control the backlight
  uint8_t ui8_backlight_state(1);
  if(displayPanel.readButtonA5() == BUTTON_A5)
    ui8_backlight_state = 0;
  displayPanel.setBacklight(ui8_backlight_state);

  displayPanel.clear();
  displayPanel.setCursor(0, 0);

  // read all buttons:
  uint8_t ui8_buttons(displayPanel.readButtons());  // reads only five buttons (A0...A4)
  if (ui8_buttons)
  {
    if (ui8_buttons & BUTTON_UP)
      displayPanel.print("UP ");
    if (ui8_buttons & BUTTON_DOWN)
      displayPanel.print("DOWN ");
    if (ui8_buttons & BUTTON_LEFT)
      displayPanel.print("LEFT ");
    if (ui8_buttons & BUTTON_RIGHT)
      displayPanel.print("RIGHT ");
    if (ui8_buttons & BUTTON_SELECT)
      displayPanel.print("OK ");
  }

  // if debouncing is used, update debouncing cyclic:
  displayPanel.updateDebounce();
  
  // Returns the falling pin state
  if(displayPanel.debouncer_OK.fell())
  {
    ++ui8CountFallingEdge;
    Serial.println("OK fell");
  }
  // Returns the rising pin state
  if(displayPanel.debouncer_OK.rose())
  {
    ++ui8CountRisingEdge;
    Serial.println("OK rise");
  }

  displayPanel.setCursor(0,1);
  displayPanel.print("rise:");
  displayPanel.print(ui8CountRisingEdge, DEC);

  displayPanel.setCursor(8,1);
  displayPanel.print("fell:");
  displayPanel.print(ui8CountFallingEdge, DEC);

}
