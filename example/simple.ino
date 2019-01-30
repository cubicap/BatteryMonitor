#include <BatteryMonitor.h>

/* 
* Each entry is equal to (base*correction*(r1+r2))/(res*r1), where:
*   base is base voltage of the microcontroller (read as maximum value)
*   res is maximum digital value which is read
*   r1 is the first resistor of the voltage divider
*   r2 is the second resistor of the voltage divider
*   correction is multiplier of the value to get more accurate measurement (calculate using multimeter), it is not necessary
* In my case (Teensy 3.2) the values were
*   base = 3.3
*   res = 1023
*/
float multipliers[4] = {
    (3.3f * 1.00505 * (390  + 994)) / (1023 * 994), 
    (3.3f * 1.00505 * (1796 + 993)) / (1023 * 993), 
    (3.3f * 1.00730 * (3284 + 996)) / (1023 * 996), 
    (3.3f * 1       * (4670 + 994)) / (1023 * 994)};

int8_t pins[4] = {15, 16, 17, 18};
float voltages[4];

BatteryMonitor monitor = BatteryMonitor(pins, 4, multipliers);

void setup() {
    Serial.begin(9600)
}

void loop() {
    battery.getCellsVoltage(voltages);
    Serial.print(voltages[0]);
    Serial.print("; ");
    Serial.print(voltages[1]);
    Serial.print("; ");
    Serial.print(voltages[2]);
    Serial.print("; ");
    Serial.print(voltages[3]);
    Serial.println("---------");
}