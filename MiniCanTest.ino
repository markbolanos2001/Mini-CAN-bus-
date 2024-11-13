/* 
Basic Code to initialise the can bus of the car and the arduino and hopefully get them working together
 
!!!!Code has not been tested yet!!!!

https://github.com/DFRobot/DFRobot_MCP2515/tree/master -- LINK TO LIBRARY
*/


#include <SPI.h>
#include <DFRobot_MCP2515.h>

const int SPI_CS_PIN = 10;         // Pin for the shield
DFRobot_MCP2515 CAN(SPI_CS_PIN);   // Instantiate


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  while (CAN.begin(CAN_500KBPS)){  // Baudrate for the can bus , might need to change it
    Serial.println("CAN Init failed!, retrying in 3 seconds...");
    delay(3000);

  }
  Serial.println("CAN Init OK!");
    



}

void loop() {
  // put your main code here, to run repeatedly:

  unsigned char len = 0;
  unsigned char buf[8];

  if (CAN_MSGAVAIL == CAN.checkReceive()){ // Check if messages are coming in
    CAN.readMsgBuf(&len, buf);

    for  (int i = 0; i < len; i++){
      Serial.write(buf[i]);
      Serial.print("\t");

    }
    Serial.println();
  }

}
