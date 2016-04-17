
/*
 ADXL335 Direct Plug

 Reads an Analog Devices ADXL3xx accelerometer and communicates the
 acceleration to the computer.  The pins used are designed to be easily
 compatible with the breakout boards from SMAKN, available from:
 http://smile.amazon.com/dp/B00R7RCESK/ref=cm_sw_r_tw_dp_Jpscxb0G9R00F

 http://www.arduino.cc/en/Tutorial/ADXL3xx

 The circuit:
 analog 0: vcc
 analog 1: x-axis
 analog 2: y-axis
 analog 3: z-axis
 analog 4: ground

 created 2 Jul 2008
 by David A. Mellis
 modified 9 April 2016
 by Kyle King

 This example code is in the public domain.

*/

// these constants describe the pins. They won't change:
const int groundpin = 14;             // A0 -- GND
const int powerpin = 1;               // A4 -- VCC
const int xpin = A3;                  // x-axis of the accelerometer
const int ypin = A2;                  // y-axis
const int zpin = A1;                  // z-axis

void setup() {
  // initialize the serial communications:
  Serial.begin(115200);

  // Provide ground and power by using the analog inputs as normal
  // digital pins.  This makes it possible to directly connect the
  // breakout board to the Arduino.  If you use the normal 5V and
  // GND pins on the Arduino, you can remove these lines.
  pinMode(groundpin, OUTPUT);
  pinMode(powerpin, OUTPUT);
  digitalWrite(groundpin, LOW);
  digitalWrite(powerpin, HIGH);
}

void loop() {
  // print the sensor values:
  Serial.print(analogRead(xpin));
  // print a tab between values:
  Serial.print("\t");
  Serial.print(analogRead(ypin));
  // print a tab between values:
  Serial.print("\t");
  Serial.print(analogRead(zpin));
  Serial.println();
  // delay before next reading:
  delay(100);
}
