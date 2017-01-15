#include <math.h>

//pins for the colors; note there is no GND pin
int bluePin  = 11;
int redPin   = 12;
int greenPin = 13;

//how long to delay between iterations; ie, how fast to change color
int delayTime = 10;

int maxcolor = 360; //this is the color. in HSV color goes 0..360.

float H, S, V, R, G, B;

void setup() {
    pinMode(redPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    Serial.begin(9600);

    H = 0.0;
    S = 1.0;
    V = 1.0;
    
    R = 0.0;
    G = 0.0;
    B = 0.0;

}

void loop() {
    //I omit the maximum color, 360, because that's (0, 0, 0) in RGB
    for (int i = 1; i < maxcolor; i++) {
        printcolor();
        H = float(i);
        HSV2RGB();
        analogWrite(redPin, R);
        analogWrite(bluePin, G);
        analogWrite(greenPin, B);
        delay(delayTime);
    }
    for (int i = maxcolor - 2; i >= 0; i--) {
        printcolor();
        H = float(i);
        HSV2RGB();
        analogWrite(redPin, R);
        analogWrite(bluePin, G);
        analogWrite(greenPin, B);
        delay(delayTime);
    }
}

//this prints the color to the screen.
void printcolor() {
    Serial.print("H: ");
    Serial.print(H);
    Serial.print(". RGB = (");
    Serial.print(R);
    Serial.print(", ");
    Serial.print(G);
    Serial.print(", ");
    Serial.print(B);
    Serial.println(").");
}

//See
// http://www.rapidtables.com/convert/color/hsv-to-rgb.htm
//and
// http://www.rapidtables.com/convert/color/rgb-to-hsv.htm
void HSV2RGB() {
    //some vars we'll need
    float C, X, m;
    //R', G', B'
    float Rp, Gp, Bp;

    C = V * S;
    X = C * (1 - abs(mod((H / 60.0), 2) - 1));
    m = V - C;

    if      (H <  60) { Rp = C; Gp = X; Bp = 0; }
    else if (H < 120) { Rp = X; Gp = C; Bp = 0; }
    else if (H < 180) { Rp = 0; Gp = C; Bp = X; }
    else if (H < 240) { Rp = 0; Gp = X; Bp = C; }
    else if (H < 300) { Rp = X; Gp = 0; Bp = C; }
    else if (H < 360) { Rp = C; Gp = 0; Bp = X; }

    R = (Rp + m)*255;
    G = (Gp + m)*255;
    B = (Bp + m)*255;
}

//I made this function for use with floating point numbers. 
float mod(float num, int denom) {
    //      whole number  +    fractional
    return int(num)%denom + (num - int(num));
}
