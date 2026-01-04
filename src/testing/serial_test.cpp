#include "Arduino.h"


void setup() {
    Serial.begin(115200);
}

void loop() {
    bool got_data = false;
    while (Serial.available() > 0) {
        Serial.write(Serial.read());
        got_data = true;
    }

    if (got_data) {
        delay(100);
        Serial.println("HI");
    }
}
