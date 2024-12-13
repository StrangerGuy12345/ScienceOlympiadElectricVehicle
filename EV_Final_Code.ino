
#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Clcd.h> 

hd44780_I2Clcd lcd;

const int LCD_COLS = 16;
const int LCD_ROWS = 2;

const int encoderPinA = 2;  // Encoder A pin
const int encoderPinB = 3;  // Encoder B pin
const int motorDirectionPin = 4;  // Motor direction pin
const int motorPwmPin = 5;  // Motor PWM pin
const int motorDirection2Pin = 7; // Motor direction opposite
const int motorBrakePin = 6; // Motor Brake pin

volatile long encoderPulses = 0;  // Track the number of encoder pulses
const long targetPulses = 9450;  // Target Pulses
const int pulsesPerRevolution = 540;  // Pulses per revolution
const float wheelDiameter = 5.08;  // Wheel diameter in cm
const float wheelCircumference = wheelDiameter * 3.14159;  
const float distancePerPulse = wheelCircumference / pulsesPerRevolution;  

bool motorRunning = true;  
float totalDistance = 0.0;  
unsigned long startTime = 0;  

void setup() {
  Serial.begin(9600);

  int status = lcd.begin(LCD_COLS, LCD_ROWS);
  if (status) {
    hd44780::fatalError(status); 
  }

  pinMode(encoderPinA, INPUT_PULLUP);
  pinMode(encoderPinB, INPUT_PULLUP);
  pinMode(motorDirectionPin, OUTPUT);
  pinMode(motorPwmPin, OUTPUT);
  pinMode(motorBrakePin, OUTPUT);
  pinMode(motorDirection2Pin, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(encoderPinA), encoderISR, CHANGE);

  digitalWrite(motorDirectionPin, HIGH);  
  analogWrite(motorPwmPin, 255);  

  startTime = millis();  
}

void encoderISR() {
  if (digitalRead(encoderPinA) == digitalRead(encoderPinB)) {
    encoderPulses++;  
  } else {
    encoderPulses--;  
  }
}

void loop() {
  if (motorRunning) {
    float distanceTraveled = abs(encoderPulses) * distancePerPulse / 100.0 * 2.5362318841;  
    unsigned long currentTime = millis();
    float secondsElapsed = (currentTime - startTime) / 1000.0;

    lcd.setCursor(0, 0);
    lcd.print("Distance: ");
    lcd.print(distanceTraveled, 2);  
    lcd.print("m");
    lcd.setCursor(0, 1);
    lcd.print("Time: ");
    lcd.print(secondsElapsed, 1);
    lcd.print("s");

    float pulseProgress = float(abs(encoderPulses)) / targetPulses;

    if (pulseProgress >= 1.0) {
      digitalWrite(motorDirectionPin, LOW);  
      analogWrite(motorPwmPin, 0);           

      Serial.println("Target Reached");

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Reversing...");

      
      encoderPulses = 0;  
      digitalWrite(motorDirection2Pin, HIGH); 
      analogWrite(motorPwmPin, 255);          

      delay(200);



      while (abs(encoderPulses) < 80) {
        
      }

      
      analogWrite(motorPwmPin, 0);
      digitalWrite(motorDirection2Pin, LOW); 

      motorRunning = false;
      totalDistance = distanceTraveled;

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(" Target Reached ");
      lcd.setCursor(0, 1);
      lcd.print(totalDistance, 2);
      lcd.print("m in ");
      lcd.print(secondsElapsed, 1);
      lcd.print("s");
    } else if (pulseProgress >= 9.0 / 10.0) {
      analogWrite(motorPwmPin, 150);
    } else if (pulseProgress >= 9.3 / 10.0) {
      analogWrite(motorPwmPin, 125);
    } else if (pulseProgress >= 9.5 / 10.0) {
      analogWrite(motorPwmPin, 100);
    } else if (pulseProgress >= 9.7 / 10.0) {
      analogWrite(motorPwmPin, 50);
    } else if (pulseProgress >= 9.9 / 10.0) {
      analogWrite(motorPwmPin, 25);
    }
  }
}



