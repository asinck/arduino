//this code is adapted from the provided code. 

//pins for the colors; note there is no GND pin
int bluePin  = 11;
int redPin   = 12;
int greenPin = 13;

//this is an iterator variable
int i;

//how long to delay between iterations; ie, how fast to change color
int delayTime = 10;

//this is if white should be in the loop
bool white = false;

//the bounds on the brightness. This goes 0..255, because it's RGB
int minBright = 0;
int maxBright = 255;

void setup() {
    pinMode(redPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    Serial.begin(9600);
    
    //gradually raise it to red
    for (i = minBright; i <= maxBright; i++) {
        analogWrite(redPin, i);
        delay(delayTime);
    }
}

//go in a loop, initialized with red:
//purple  (red + blue)
//blue    (purple - red)
//aqua    (blue + green)
//green   (aqua - blue)
//yellow  (green + red)
//red     (yellow - green)

//I am *not* going to put orange in this. If you know computer color
//codes, you'll understand why. If not, this would be a fun problem
//for you.

void loop() {
    //purple
    //add blue to red
    Serial.println("Started purple");
    for (i = minBright; i <= maxBright; i++) {
        analogWrite(bluePin, i);
        delay(delayTime);
    }
    
    Serial.println("Started blue");
    //blue
    //subtract red from purple
    for (i = maxBright; i >= minBright; i--) {
        analogWrite(redPin, i);
        delay(delayTime);
    }

    Serial.println("Started aqua");
    //aqua
    //add green to blue
    for (i = minBright; i <= maxBright; i++) {
        analogWrite(greenPin, i);
        delay(delayTime);
    }

    Serial.println("Started green");
    //green
    //subtract blue from aqua
    for (i = maxBright; i >= minBright; i--) {
        analogWrite(bluePin, i);
        delay(delayTime);
    }

    Serial.println("Started yellow");
    //yellow
    //add red to green
    for (i = minBright; i <= maxBright; i++) {
        analogWrite(redPin, i);
        delay(delayTime);
    }

    //if we want to include white, do so
    if (white) {
        Serial.println("Started white");
        //white
        //add blue to yellow
        for (i = minBright; i <= maxBright; i++) {
            analogWrite(bluePin, i);
            delay(delayTime);
        }

        Serial.println("Started red");
        //fade back to red
        for (i = maxBright; i >= minBright; i--) {
            analogWrite(bluePin, i);
            analogWrite(greenPin, i);
            delay(delayTime);
        }
    }
    else {
        Serial.println("Started red");
        //green
        //subtract green from yellow
        for (i = maxBright; i >= minBright; i--) {
            analogWrite(greenPin, i);
            delay(delayTime);
        }
    }
}
