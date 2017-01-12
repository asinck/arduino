int sensor = A0;
int max_value = 1023; //based on observation and intuition

void setup() {
    pinMode(sensor,INPUT);
    Serial.begin(9600);
}

void loop() {
    //value is how dark it is, actually
    int value = analogRead(sensor);
    Serial.print("Brightness: ");
    Serial.println(max_value - value);
    delay(300);
}
