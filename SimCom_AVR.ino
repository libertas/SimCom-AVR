#include "SimCom.h"
#include "ServiceLayer.h"
#include "PhysicalLayer.h"

void callback0(char from, char to, const char* data, SIMCOM_LENGTH_TYPE length)
{
  sl_send(to, from, data, length);
}

void setup()
{
  Serial.begin(115200);
  sl_config(0, callback0);
  simcom_init();
}

void loop()
{
  ph_send_intr();
}

void serialEvent() {
  while(Serial.available()) {
    
    char c = (char)Serial.read(); 
    
    ph_receive_intr(c);
    sl_receive_intr();
  }
}

