#include "Arduino.h"
#include "pcb1.h"
#include "allocateMem.h"
#include "commandmessenger.h"
#include <U8x8lib.h>

/* **********************************************************************************
    This is just the basic code to set up your custom device.
    Change/add your code as needed.
********************************************************************************** */

U8X8_SSD1309_128X64_NONAME0_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);

pcb1::pcb1(uint8_t Pin1, uint8_t Pin2)
{
    _pin1 = Pin1;
    _pin2 = Pin2;
}

void pcb1::begin()
{
  u8x8.begin();
  u8x8.setFlipMode(3); // Falls es wieder auf dem Kopf steht
  u8x8.setFont(u8x8_font_chroma48medium8_r);
    u8x8.setCursor(0, 0);
    u8x8.print( F("Motherfucker 2!"));
 _initialised=true;
}

void pcb1::attach(uint16_t Pin3, char *init)
{
    _pin3 = Pin3;
}

void pcb1::detach()
{
    if (!_initialised)
        return;
    _initialised = false;
}

void pcb1::set(int16_t messageID, char *setPoint)
{
    // 1. Zeile explizit löschen, damit der alte, lange Text verschwindet
    u8x8.clearLine(0); 
    
    // 2. Neuen Text schreiben
    u8x8.setCursor(0, 0);
    u8x8.print(F("set()"));

    if(true) return; // Bricht hier ab für deinen Test
    /* **********************************************************************************
        Each messageID has it's own value
        check for the messageID and define what to do.
        Important Remark!
        MessageID == -2 will be send from the board when PowerSavingMode is set
            Message will be "0" for leaving and "1" for entering PowerSavingMode
        MessageID == -1 will be send from the connector when Connector stops running
        Put in your code to enter this mode (e.g. clear a display)

    ********************************************************************************** */
    int32_t  data = atoi(setPoint);
    uint16_t output;

    // do something according your messageID
    switch (messageID) {
    case -1:
        // tbd., get's called when Mobiflight shuts down
    case -2:
        // tbd., get's called when PowerSavingMode is entered
    case 0:
        output = (uint16_t)data;
        data   = output;
        break;
    case 1:
        /* code */
        break;
    case 2:
        /* code */
        break;
    default:
        break;
    }
}

void pcb1::update()
{ 
    // Do something which is required regulary
    //u8x8.setCursor(0, 0);
    //u8x8.print( F("update()"));
}
