int ledPin = 13;
int buttonPin = 12;
int val = 0;

void setup() {
    pinMode(ledPin, OUTPUT);
    pinMode(buttonPin, INPUT);
}

void loop() {
    val = digitalRead(buttonPin);
    digitalWrite(ledPin, val);
}
