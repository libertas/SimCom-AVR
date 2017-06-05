#include "SimCom.h"
#include "ServiceLayer.h"
#include "PhysicalLayer.h"

void callback0(char from, char to, const char* data, SIMCOM_LENGTH_TYPE length)
{
  //sl_send(to, from, data, length);
  if(length == 1) {
    switch(data[0]) {
      case '0':
        digitalWrite(13, LOW);
        break;
      default:
        digitalWrite(13, HIGH);
        break;
    }
  }
}

void setup()
{
  pinMode(13, OUTPUT);
  Serial.begin(115200);
  sl_config(0, callback0);
  simcom_init();
}

void loop()
{
  static unsigned int t = 0;
  if(millis() - t > 1000) {
    t = millis();
    sl_send(0, 0, "Test\r\n", 6);
  }
  ph_send_intr();
}

void serialEvent() {
  while(Serial.available()) {
    
    char c = (char)Serial.read(); 
    
    noInterrupts();
    ph_receive_intr(c);
    sl_receive_intr();
    interrupts();
  }
}

