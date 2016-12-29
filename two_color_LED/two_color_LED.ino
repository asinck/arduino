//this code is adapted from the provided code. 

//pins for the colors; note there is no GND pin
int greenPin = 12;
int redPin   = 13;

//this is an iterator variable
int i;

//how long to delay between iterations; ie, how fast to change color
int delayTime = 10;

//the bounds on the brightness. This goes 0..255, because it's RGB
int minBright = 0;
int maxBright = 255;

void setup() {
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    Serial.begin(9600);
    
    //gradually raise it to red
    for (i = minBright; i <= maxBright; i++) {
        analogWrite(redPin, i);
        delay(delayTime);
    }
}

//go in a loop, initialized with red:
//yellow  (red + green)
//green   (yellow - red)
//red     (yellow - green, + red)

//I am *not* going to put orange in this. If you know computer color
//codes, you'll understand why. If not, this would be a fun problem
//for you.

void loop() {
    Serial.println("Started yellow");
    //yellow
    //add green to red
    for (i = minBright; i <= maxBright; i++) {
        analogWrite(greenPin, i);
        delay(delayTime);
    }

    Serial.println("Started green");
    //green
    //subtract red from yellow
    for (i = maxBright; i >= minBright; i--) {
        analogWrite(redPin, i);
        delay(delayTime);
    }

    Serial.println("Started red");
    //red
    //add red, subtract green
    for (i = minBright; i <= maxBright; i++) {
        analogWrite(redPin, i);
        analogWrite(greenPin, maxBright - i);
        delay(delayTime);
    }
}
