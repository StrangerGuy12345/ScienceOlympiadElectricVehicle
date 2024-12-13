# ScienceOlympiadElectricVehicle
This repository gives the code files for programming your Electric Vehicle for the Science Olympiad utilizing the Arduino platform.
# Requirments
You will need an Arduino or ESP32 (I used the [Arduino Uno R4 Wifi](https://shorturl.at/gxt6B) due to the extra storage and faster download and upload rate), this [Motor with Encoder](https://shorturl.at/rNqjS), this [Motor Driver](https://shorturl.at/nulTf), these [Breadboard Wires](https://shorturl.at/aqRki) , this [Breadboard](https://shorturl.at/JkIDs) and this [LCD](https://shorturl.at/NttRC). You will also need to have [Arduino IDE](https://www.arduino.cc/en/software) installed with the board manager for the model of your microcontroller installed.
# Download Code
```
git clone https://github.com/StrangerGuy12345/ScienceOlympiadElectricVehicle.git ~/Documents/Arduino/
```
# Libraries
**HD44780**: 
```
git clone https://github.com/duinoWitchery/hd44780.git ~/Documents/Arduino/libraries/
```
**Wire**: Comes pre-installed with board manager. Included if for some reason you don't have it.
```
git clone https://github.com/arduino/ArduinoCore-avr.git ~/Documents/Arduino/libraries
```
# Getting Started
1. Wire the yellow wire of the encoder to pin 2 and white wire to pin 3 on your microcontroller.
2. Use your breadboard wires to wire pin 4 to the IN4 pin on the motor driver, pin 5 to the ENB pin next to the IN4 pin and not the one on the back (be sure to take off the cover), pin 6 to the back pin of the ENB pins, an pin 7 to the IN3 pin.
3. Wire the blue and yellow wires to pins SCL and SDA (A4 and A5 if you don't have them).






