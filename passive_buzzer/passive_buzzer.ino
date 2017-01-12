int buzzer = 13;
int buzz_duration = 50; //how long to buzz a frequency

void setup() {
    pinMode(buzzer,OUTPUT);
    Serial.begin(9600);
}

void loop() {
    //go from high tones to low tones
    for (int i = 1; i < 1000; i++) {
        buzz(i, buzz_duration);
    }
    //go from low tones to high tones
    for (int i = 1000; i > 0; i--) {
        buzz(i, buzz_duration);
    }
}

//frequency is the delay between on and off signals to the speaker. I
//have no clue if that's the right term, but I'm saying it is.
void buzz(int frequency, int duration) {
    //scale the time for the frequency, because higher frequencies
    //mean longer delays
    duration = (duration * 100) / frequency;
    
    for (int i = 0; i < duration; i++) {
        digitalWrite(buzzer,HIGH);
        delayMicroseconds(frequency);
        digitalWrite(buzzer,LOW);
        delayMicroseconds(frequency);
    }
}
