#pragma once

#include <stdint.h>
#include <Arduino.h>
#include <LittleMaths.h>

class BatteryMonitor {
    public:
        BatteryMonitor(int8_t* pins, int numCells, float * multipliers);
        void getBatteryVoltage();
        void getCellsVoltage(float * data);
    private:
        int8_t* pins;
        int numCells;
        //(3,3*correction*(r1+r2))/(1023*r1)
        float * multipliers;
        float history[4][20] = {};
        int historySize = 20;
        int historyIndex = 0;
};