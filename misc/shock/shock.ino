int sensor = 13;

void setup() {
    pinMode(sensor,INPUT);
    Serial.begin(9600);
}

void loop() {
    if (!digitalRead(sensor)) {
        Serial.println("I am unfazed.");
    }
    else {
        Serial.println("Woah, stirred, not shaken please.");
    }
}
