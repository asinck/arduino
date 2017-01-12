//This is based on the provided sample program.

//analog x and y
int pinx = 0;
int piny = 1;

//digital z
int pinz = 13;

int midx = 0;
int midy = 0;

void setup() {
    //set the pins to input mode
    pinMode(pinx, INPUT);
    pinMode(piny, INPUT);
    pinMode(pinz, INPUT);

    //Set the midpoint of the readings. This will be subtracted from
    //the readings, to make a 0 on the number line.
    midx = analogRead(pinx);
    midy = analogRead(piny);

    Serial.begin(9600); 
} 

void loop() { 
    //read the values
    int x = analogRead(pinx) - midx;
    int y = midy - analogRead(piny); //the y axis is inverted, imho
    int z = digitalRead(pinz);

    //filter out the noise from off-by-one readings at 0
    if ((2 > x) && (x > -2))
        x = 0;
    if ((2 > y) && (y > -2))
        y = 0;
    
    Serial.print("(");
    Serial.print(x);
    Serial.print(", ");
    Serial.print(y);
    Serial.print(", ");
    Serial.print(z);
    Serial.println(")");

    delay(100);
} 
