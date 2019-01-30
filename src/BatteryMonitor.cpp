#include "BatteryMonitor.h"

BatteryMonitor::BatteryMonitor(int8_t* pins, int numCells):
    pins(pins),
    numCells(numCells),
    multipliers(multipliers)
{}

void BatteryMonitor::getCellsVoltage(float* data) {
    if(++historyIndex >= historySize) {
        historyIndex = 0;
    }

    for(int i = 0; i < numCells; i++) {
        history[i][historyIndex] = (float)analogRead(pins[i]) * multipliers[i];
    }
    for(int i = numCells - 1; i > 0; i--) {
        history[i][historyIndex] -= history[i - 1][historyIndex];
        data[i] = LittleMaths::average(history[i], historySize);
    }
    data[0] = LittleMaths::average(history[0], historySize);
}
