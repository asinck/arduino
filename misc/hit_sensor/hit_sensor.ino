//This is based on the provided example program

int led = 13;
int sensor = 12;

int value = 0;
int prevValue = 0;

void setup() {
    pinMode(led,OUTPUT);
    pinMode(sensor,INPUT);
}

void loop() {
    int value = digitalRead(sensor);
    digitalWrite(led,value);

    //pause if there was a change, because otherwise it'd have all of
    //a 1/4 second of output before resuming as usual
    if (value != prevValue) {
        delay(1000);
        prevValue = value;
    }
}
