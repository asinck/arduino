/*
This is for the DHT11 temperature and humidity sensor, based on the
provided code. Significant readability changes were made, although the
logic is still similar.
*/

#define dht_dpin A0

//error codes
#define OK 0
#define ACTIVATION_FAIL 1
#define NOT_READY 2
#define CHECKSUM_ERROR 3


byte dht_data[5];

//we'll need these
float humidity = 0.0;
float Ctemp = 0.0;
float Ftemp = 0.0;

void setup() {
    pinMode(dht_dpin,OUTPUT);
    digitalWrite(dht_dpin,HIGH);

    Serial.begin(9600);
    delay(300);
    Serial.println("Humidity and temperature\n\n");
    delay(700);
}

void loop() {
    byte code = ReadDHT();
    switch (code) {
    case OK:
        humidity = dht_data[0] + (dht_data[1]/10.0);
        Ctemp = dht_data[2] + (dht_data[3]/10.0);
        Ftemp = (Ctemp * 9.0/5.0) + 32;
        Serial.print(Ctemp);
        Serial.print(" C / ");
        Serial.print(Ftemp);
        Serial.print(" F. ");
        Serial.print(humidity);
        Serial.println("% humidity.");
        break;

    case ACTIVATION_FAIL:
        Serial.println("Error: Could not signal module.");
        break;
    case NOT_READY:
        Serial.println("Error: Module not ready to read.");
        break;
    case CHECKSUM_ERROR:
        Serial.println("Error: Invalid reading.");
        break;
    default:
        Serial.println("Error: Something unknown went wrong.");
        break;
    }
    delay(800);
}

//This gets a reading from the sensor, for temp and humidity. Not to
//be confused with read_dht_dataa(), which does the actual data
//reading, or take_reading(), which grabs that reading.
byte ReadDHT() {
    // http://www.uugear.com/portfolio/dht11-humidity-temperature-sensor-module/

    //code is for errors, if any
    int code = 0;

    //signal that we want a reading
    code = signal_ready();
    if (code != OK)
        return code;

    //see if the module is ready
    code = check_ready();
    if (code != OK)
        return code;

    //Get a reading. Note that the reading is stored in a global
    //variable, and the return value from the function is the error
    //code (0 if no errors)
    code = take_reading();
    if (code != OK)
        return code;

    return OK;
}

//This function signals to the module that we're ready to take a
//reading from it. 
int signal_ready() {
    //signal that we want to take a reading
    digitalWrite(dht_dpin, LOW);
    delay(20);
    digitalWrite(dht_dpin, HIGH);
    delayMicroseconds(40);

    //if it gave something back, that's an issue because it shouldn't
    //right here
    pinMode(dht_dpin, INPUT);
    byte dht_in = digitalRead(dht_dpin);

    if (dht_in) {
        return ACTIVATION_FAIL;
    }
    return OK;
}

//This function gets a "go ahead" from the module to make sure it's
//ready to send data.
int check_ready() {
    delayMicroseconds(80);
    byte dht_in = digitalRead(dht_dpin);

    //if it didn't give a signal, it's not ready
    if (!dht_in) {
        return NOT_READY;
    }
    return OK;
}

//This function collects data from the module and does error checking.
int take_reading() {
    //ok, take a reading
    delayMicroseconds(80);
    for (byte i=0; i<5; i++)
        dht_data[i] = read_dht_data();

    //signal that we're done here
    pinMode(dht_dpin, OUTPUT);
    digitalWrite(dht_dpin, HIGH);

    //make sure the result is correct
    byte dht_check_sum = dht_data[0] + dht_data[1] +
        dht_data[2] + dht_data[3];
    if (dht_data[4] != dht_check_sum)
        return CHECKSUM_ERROR;
    return OK;
}

//This is the interface between the software and the module. This
//reads at the bit level.
byte read_dht_data() {
    byte result = 0;
    for (byte i = 0; i < 8; i++) {
        while (digitalRead(dht_dpin) == LOW) {}
        delayMicroseconds(30);

        if (digitalRead(dht_dpin) == HIGH) {
            result |= (1 << (7-i)); //bitwise or on the equals, like +=
        }

        while (digitalRead(dht_dpin) == HIGH) {}
    }
    return result;
}
