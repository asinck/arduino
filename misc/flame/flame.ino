int digital_sensor = 13;
int analog_sensor = A0;

void setup() {
    pinMode(digital_sensor,INPUT);
    pinMode(analog_sensor,INPUT);
    Serial.begin(9600);
}

void loop() {
    int digital = digitalRead(digital_sensor);
    int analog = analogRead(analog_sensor);
    Serial.print("Digital: ");
    if (digital) {
        Serial.print("on");
    }
    else {
        Serial.print("off");
    }
    Serial.print("; Analog: ");
    Serial.println(analog);
    delay(300);
}
