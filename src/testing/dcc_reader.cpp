/**
 * First pass test script to read DCC data
 */

#include "Arduino.h"

#include <NmraDcc.h>


NmraDcc Dcc;

// This call-back function is called whenever we receive a DCC Speed packet for our address
void notifyDccSpeed(uint16_t Addr, DCC_ADDR_TYPE AddrType, uint8_t Speed, DCC_DIRECTION Dir, DCC_SPEED_STEPS SpeedSteps) {
    Serial.print("notifyDccSpeed: Addr: ");
    Serial.print(Addr,DEC);
    Serial.print((AddrType == DCC_ADDR_SHORT) ? "-S" : "-L");
    Serial.print(" Speed: ");
    Serial.print(Speed,DEC);
    Serial.print(" Steps: ");
    Serial.print(SpeedSteps,DEC);
    Serial.print(" Dir: ");
    Serial.println((Dir == DCC_DIR_FWD) ? "Forward" : "Reverse");
};

void setup() {
    Serial.begin(115200);

    // Set up the DCC library
    Dcc.pin(2, false);
    Dcc.init(MAN_ID_DIY, 10, FLAGS_MY_ADDRESS_ONLY | FLAGS_AUTO_FACTORY_DEFAULT, 0);
}

void loop() {
    Dcc.process();
}
