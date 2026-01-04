#include "Arduino.h"


void setup() {
    Serial.begin(115200);
    pinMode(PIN_PA4, INPUT_PULLUP);

}

void loop() {
    Serial.println(digitalRead(PIN_PA4));
}
