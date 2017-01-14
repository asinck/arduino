int sensor = 13;

void setup() {
    pinMode(sensor, INPUT);
    Serial.begin(9600);
}

void loop() {
    int value = digitalRead(sensor);
    if (value)
        Serial.println("Interrupted.");
    else
        Serial.println("No interrupt.");
    delay(30);
}
