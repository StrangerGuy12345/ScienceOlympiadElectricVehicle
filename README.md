# ScienceOlympiadElectricVehicle
This repository gives the code files for programming your Electric Vehicle for the Science Olympiad utilizing the Arduino platform.
# Requirments
You will need an Arduino or ESP32 (I used the [Arduino Uno R4 Wifi](https://shorturl.at/gxt6B) due to the extra storage and faster download and upload rate), this [Motor with Encoder](https://shorturl.at/rNqjS), this [Motor Driver](https://shorturl.at/nulTf), these [Breadboard Wires](https://shorturl.at/aqRki) , this [Breadboard](https://shorturl.at/JkIDs), a [Battery Holder](https://shorturl.at/r1iqW) that holds 8 [1.5V Batteries](https://shorturl.at/qhw5x), a [Switch](https://shorturl.at/7QrU3), and this [LCD](https://shorturl.at/NttRC). You will also need to have [Arduino IDE](https://www.arduino.cc/en/software) or [PlatformIO on Visual Studio Code](https://platformio.org/install/ide?install=vscode) installed with the board manager for the model of your microcontroller installed. Your operating system needs to be MacOS😎, Linux🐧, or Windows🤮. 
# Downloading the Code (Arduino IDE)
To download the program go to your termial and paste the following:
```
git clone https://github.com/StrangerGuy12345/ScienceOlympiadElectricVehicle.git ~/Documents/Arduino/ElectricVehicle
```
# Downloading the Code (PlatformIO)
```
git clone https://github.com/StrangerGuy12345/ScienceOlympiadElectricVehicle.git ~/Documents/PlatformIO/Projects/ElectricVehicle
```
# Libraries
[**HD44780**](https://github.com/duinoWitchery/hd44780.git): To download the HD44780 library go to your termial and paste the following:
**(Arduino)**
```
git clone https://github.com/duinoWitchery/hd44780.git ~/Documents/Arduino/libraries/hd44780-master
```
**(PlatformIO)**
```
git clone https://github.com/duinoWitchery/hd44780.git ~/Documents/PlatformIO/Projects/ElectricVehicle/lib/hd44780-master
```
[**Wire**](https://github.com/arduino/ArduinoCore-avr.git): Comes pre-installed with board manager. Included if for some reason you don't have it.
**(Arduino)**
```
git clone https://github.com/arduino/ArduinoCore-avr.git ~/Documents/Arduino/libraries/ArduinoCore-avr
```
**(PlatformIO)**
```
git clone https://github.com/duinoWitchery/hd44780.git ~/Documents/PlatformIO/Projects/ElectricVehicle/lib/ArduinoCore-avr
```
# Getting Started
1. Wire the yellow wire of the encoder to pin 2 and the white wire to pin 3 on your microcontroller.
2. Use your breadboard wires to wire pin 4 to the IN4 pin on the motor driver, pin 5 to the ENB pin next to the IN4 pin and not the one on the back (be sure to take off the cover), pin 6 to the back pin of the ENB pins, and pin 7 to the IN3 pin.
3. Wire the blue and yellow wires to pins SCL and SDA (A4 and A5 if you don't have them).
4. Wire the 5V pin on the microcontroller next to the red line on the breadboard (If you're using the ESP32 you will need a [Voltage Regulator](https://shorturl.at/k4l9B) since the ESP32 uses 3.3V) and the GND pin next to the blue line on the breadboard. Wire the VCC pin on the LCD next to the red line of the breadboard and GND to the 
   blue side and connect the blue wire of the encoder to the red side of the breadboard and green wire to blue side.
5. Connect the red wire of the battery holder to one wire on the switch and the seconed wire of the switch to a breadboard wire.
6. Unscrew the screw terminals on the motor driver.
7. Conncet the breadboard wire of the switch to the 12V supply on the Motor Driver (Pins of screw terminals listed under the motor driver), connect the black wire of battery to GND of Motor Driver, connect one end of a breadboard wire to the 5V supply on the Motor driver and the other end next to the red line on the breadboard, connect one end of another breadboard wire to the GND of the Motor Driver (More than one wire can be fit into a section of the screw terminal as long as you tighten it properly) and connect the other end to the blue side of the breadboard.
# Programming
1. To open the program go to your termial and paste the following:
   **(Arduino)**
   ```
   open Documents/Arduino/ElectricVehicle/
   ```
   **(PlatformIO)**
   ```
   open Documents/PlatformIO/Projects/ElectricVehicle/
   ```
3. Double Click on Meter_to_Pulses_Calc.java and run it if you have java installed or on your Java IDE. If you don't have a Java installed or and IDE for Java then use this online [IDE](https://www.online-java.com/). Cick on the folder button and go to your documents folder double click on Arduino, then double click on ElectricVehicle and then single click on Meter_to_Pulses_Calc.java and press Open. Then you will be taken back from Finder to the IDE. Press Run, then the scanner will give you the prompt "Enter the distance in meters:", enter the distance you want the encoder to travel in a positive integer, you can have decimals. It will then give you the pulses for the distance. Go back to the ElectricVehicle folder and double click on EV_Final_code.ino. It will then take you to Arduino IDE. Go to line 19 enter the pulses that you got from the Java IDE (The code is set to 7 meters by defualt). Then take the cable of that fits into your microcontroller and plug it in to your computer and select the port in the IDE. Click on the check mark to compile and then press the arrow button after it has finished compiling (For PlatformIO you click on the small arrow next to the run button and select upload). After it has finished uploading you can unplug the cable from your microcontroller and test to see if its working.
# Troubleshooting
**Make sure you downloaded the files properly and meet all the requirments and you downloaded everything in order of the README.** If you don't have access to a Terminal for any reason you can download the repositories manually.








