//based on https://github.com/asinck/arduino/tree/master/misc/joystick

#include <Servo.h>

//servos and their pins
Servo elbow, wrist, hand;
int elbowPin = 2;
int wristPin = 3;
int handPin = 4;

//how far from 0 deg each way
double servoMax = 180.0;
double servoMin = 0.0;

//This is for the hand. The range of motion is about 60deg, and these
//measurements reflect that based on observation. It may be different
//for other arms.
//Note: handMax is all the way closed; handMin is all the way open.
double handMax = 120;
double handMin = 60;

//analog x and y for the joystick
int pinx = 0;
int piny = 1;

//digital z for the joystick
int pinz = 13;

//midpoints for the joystick
int midx = 0;
int midy = 0;

void setup() {
    //set the pins to input mode
    pinMode(pinx, INPUT);
    pinMode(piny, INPUT);
    pinMode(pinz, INPUT);

    //Set the midpoint of the readings. This will be subtracted from
    //the readings, to make a 0 on the number line.
    midx = analogRead(pinx);
    midy = analogRead(piny);
    
    //attach the servos to their pins
    elbow.attach(elbowPin);
    wrist.attach(wristPin);
    hand.attach(handPin);

    Serial.begin(9600);
} 

void loop() { 
    //read the values
    int x = analogRead(pinx) - midx;
    int y = analogRead(piny) - midy; //the y axis is inverted, imho
    int z = digitalRead(pinz);

    //filter out the noise from off-by-one readings at 0
    if ((2 > x) && (x > -2))
        x = 0;
    if ((2 > y) && (y > -2))
        y = 0;

    //scale the measurements for output
    x = scale(x);
    y = scale(y);
    
    //output to the joints
    elbow.write(x);
    wrist.write(y);

    //adjust the hand as needed
    if (z == 1) {
        hand.write(handMax);
    }
    else {
        hand.write(handMin);
    }

    //do all the converting now instead of printing each part
    //separately, because printing slows the arduino down noticeably.
    String strX = String(x);
    String strY = String(y);
    String strZ = String(z);
    String output = "(" + strX + ", " + strY + ", " + strZ + ")";
    Serial.println(output);

    delay(100);
} 

int scale(int input) {
    /*
      max analog input is 1023, but this program uses half that
      because the midpoint is 512. Thus, the range is [-512, 512]. 
      However, the joint servos are in the range [0, 180]. Because of
      this, the input range must be made positive: add 512 to it.

      The ratio is as follows:
      ((input+512) / 1024) = (output / servoMax)
      Solving,
      output = servoMax * ((input+512) / 1024)
      
     */
    int output = servoMax * ((input+512.0) / 1024.0);
    return output;
}
