/* Laser transmitter module test project
 * tutorial and circuit url http://osoyoo.com/?p=640
 */
char val;
const int LASER = 13;
void setup() {
    Serial.begin(9600); 
    pinMode(LASER, OUTPUT);
}
void loop() {
    val=Serial.read();
    if(val=='1') {
        digitalWrite(LASER, HIGH);  
    }
    if(val=='0') {
        digitalWrite(LASER, LOW);  
    }
}
