# BatteryMonitor
Library for voltage divider based multi-cell battery voltage reader.

The library needs [LittleMaths](https://github.com/cubicap/LittleMaths) to work.

Voltage divider for 3 cell battery using 3.3V microcontroller should look something like this:

![Circuit diagram](circuit.png)

Where A1, A2 and A3 are output nodes connected to analog inputs on the microcontroller.