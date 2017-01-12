/* use relay module to turn on/off LEDs
 * circuit and tutorial url http://osoyoo.com/?p=615
 */

int relay = 13;
void setup() {
    Serial.begin(9600); 
    pinMode(relay, OUTPUT);
}

void loop() {
    char val;
    val = Serial.read();
    
    if (val=='1') {
        digitalWrite(relay,HIGH); 
    }
    
    if(val=='0') {
        digitalWrite(relay,LOW);
    }
}
