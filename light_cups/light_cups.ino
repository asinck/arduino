//This is a sample program for the light cups. The concept is based on
//the provided code. The code is dramatically different. I'm using a
//class for the light cups because I got tired of keeping track of
//variables. 

//Is this a lot more complicated than it needs to be and complete
//overkill for the task? Definitely.
//Is it a lot cleaner and more expandable? Also definitely. I could
//follow the previous style of tracking all the pins, and collapse the
//code to maybe 25 lines, but I preferred encapsulation. The loop()
//function is *much* cleaner and clearer for it.


class light_cup {
public:
    int sensorPin;
    int LEDPin;
    int brightness;
    
    light_cup(int _sensorPin, int LEDPin);
    int getReading();
    void brighten();
    void dim();
};

//constructor
light_cup::light_cup(int _sensorPin, int _LEDPin) {
    //initialize the pins
    sensorPin = _sensorPin;
    LEDPin = _LEDPin;
    
    //set the pin modes
    pinMode(sensorPin, INPUT);
    pinMode(LEDPin, OUTPUT);

    //init the LED to off
    brightness = 0;
    analogWrite(LEDPin, brightness);
}

//this gets a reading from the module
int light_cup::getReading() {
    return digitalRead(sensorPin);
}

//this brightens the LED
void light_cup::brighten() {
    brightness++;
    //this is capped at 100 because it's hard to see the animation
    //between 100 and 255
    if (brightness > 100)
        brightness = 100;
    analogWrite(LEDPin, brightness);
}

//this dims to the LED
void light_cup::dim() {
    brightness--;
    if (brightness < 0)
        brightness = 0;
    analogWrite(LEDPin, brightness);
}

light_cup A(13, 12);
light_cup B(11, 10);

void setup() {}

void loop() {
    //using a not on the reading because it's HIGH if tilted backwards.
    if (!A.getReading())
        A.brighten();
    else
        A.dim();
    
    if (!B.getReading())
        B.brighten();
    else
        B.dim();

    delay(10);
}
