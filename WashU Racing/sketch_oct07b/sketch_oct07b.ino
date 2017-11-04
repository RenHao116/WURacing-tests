#include <Wire.h>
#include <SD.h>
#include <SPI.h>
#include <SoftwareSerial.h>
#include "Canbus.h"  // don't forget to include these
#include "defaults.h"
#include "global.h"
#include "mcp2515.h"
#include "mcp2515_defs.h"
#include "stdlib.h"
#include "PacketSender.h"
void setup() {
  // put your setup code here, to run once:
  Serial. begin(9600);
    if (Canbus.init(CANSPEED_500)) {
    Serial.println("CAN Init ok");
  }
  else {
    Serial.println("Couldn't Init CAN");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  tCAN message;
  if(mcp2515_check_message()){
    if(mcp2515_get_message(&message)){
      Serial.println(message.id);
    }
  }

}
     
