int sensor = 13;

void setup() {
    pinMode(sensor, INPUT);
    Serial.begin(9600);
}

void loop() {
    int value = digitalRead(sensor);
    if (value)
        Serial.println("No magnet detected.");
    else
        Serial.println("Magnet detected.");
    delay(300);
}
