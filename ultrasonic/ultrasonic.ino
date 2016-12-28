/* use ultrasonic sensor to detect distances
 * adapted from code included with module
 */

int trig = 13; //trigger
int echo = 12; //echo
const int mach = 340; //M/S
int delay_time = 100; //usec to wait between pings

float calculateDistance(float time);
long ping();
float cmToIn(float len);

void setup() {
    Serial.begin(9600);
    pinMode(trig, OUTPUT);
    digitalWrite(trig, LOW);
    pinMode(echo, INPUT);
}

void loop() {
    long time /*no see*/ = ping();
    if (time < 0.000000001) {
        Serial.println("Unable to find object.");
    }
    else {
        float cm_distance = calculateDistance(time);
        float in_distance = cmToIn(cm_distance);
        Serial.print("Distance to object = ");
        Serial.print(cm_distance);
        Serial.print(" cm / ");
        Serial.print(in_distance/12.0);
        Serial.print(" ft / ");
        Serial.print(in_distance);
        Serial.print(" inches\n");
        delay(delay_time);
    }
}


//this does some pinging
//This triggers a ultrasonic ping, and then waits for the echo and
//returns the number of microseconds it took.
long ping() {
    //ping
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    //listen
    return pulseIn(echo, HIGH);
}


//Input: the time it took for the echo to come back
//Output: the distance of the object, in centimeters
float calculateDistance(float time) {
    //return (time / mach) / 2.0;
    // return (time / (10000.0/mach))/2.0;
/*
conversion:
                         (mach speed)
time (usec) | 1 sec     | 340 meters | 100 cm   |
------------|-----------|------------|----------|------
            | 1000 usec | 1 second   | 1 meter  |  2

= distance in cm

This is divided by two because the time recorded is the time it takes
for the ping to get to the object and back.

Simplifying,

time (usec) * 340
------------------- = time (usec) * 17
        20

*/
    //calibration is here for ... calibration
    //idk why the 1000 is necessary. Obviously my math would never
    //have an error
    float calibration = 1.125;
    return ((time * 17.0)/1000.0)*calibration;
}


//this converts centimeters to inches
float cmToIn(float len) {
    return len/2.54;
}
