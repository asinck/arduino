/* This is a sample program for the DS18S20 Temperature Sensor
 * Module. Adapted from the provided code. 
 */

//See README for information about this library
#include <OneWire.h>

int inPin=13; // define D10 as input pin connecting to DS18S20 S pin
OneWire ds(inPin);

//for the data from the module
byte data[12];
float Ctemp = 0.0;
float Ftemp = 0.0;
byte addr[8];

void setup() {
    Serial.begin(9600);
}
 
void loop() {
    init_sensor();
    signal_ready();
    get_temp();
    Ftemp = (Ctemp * 9.0/5.0) + 32;
    
    Serial.print("Temperature: ");
    Serial.print(Ctemp);
    Serial.print("C, ");
    Serial.print(Ftemp);
    Serial.println("F");
}

//initialize the sensor
void init_sensor() {
    while (!ds.search(addr)) {
        ds.reset_search();
    }
}

//I'm assuming that this portion of the code signals that we want a
//reading. This was originally not in a separate function.
void signal_ready() {
    ds.reset();
    ds.select(addr);
    ds.write(0x44,1); 
 
    delay(1000);

    ds.reset();
    ds.select(addr);    
    ds.write(0xBE);  
}

//this reads data from the module
void get_temp() {
    for (byte i = 0; i < 9; i++) { 
        data[i] = ds.read();
    }
    
    //format the bytes
    int TReading = (data[1] << 8) + data[0];

    //find out if the reading was positive or negative. The first bit
    //will say. If so, convert the reading to a positive number and
    //deal with negativity later
    int SignBit = TReading & 0x8000;  
    if (SignBit) {
        TReading = (TReading ^ 0xffff) + 1;
    }

    //magic equation
    //original:  Ctemp = ((6 * TReading) + TReading / 4)/100.0;
    Ctemp = TReading / 16.0;

    if (SignBit) {
        Ctemp = -1 * Ctemp;
    }
}
