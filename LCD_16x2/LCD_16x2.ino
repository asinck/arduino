//This is a sample program for the sainsmart I2C 16x2 LCD
//screen. Adapted from
//https://bitbucket.org/celem/sainsmart-i2c-lcd/src/3adf8e0d2443/sainlcdtest.ino?fileviewer=file-view-default

//Note: the LCD characters are 0-based, so the first character square
//is at (0, 0).

#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

//Set up the LCD screen
#define I2C_ADDR    0x3F  // Define I2C Address where the PCF8574A is
#define BACKLIGHT_PIN     3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7

LiquidCrystal_I2C lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);


int row = 0;
int col = 0;
int screen_width = 16;
int screen_height = 2;

void setup() {
    //Make a random seed. This requires that analog port 0 be open.
    //This is done because if not, the random numbers will always be
    //the same, and that means that when it makes a "random" choice
    //about which demo to run, it'll *always* choose the same one if
    //not for this seed.
    randomSeed(analogRead(0));

    //tell the screen how big it is
    lcd.begin(screen_width, screen_height);
  
    // turn the backlight on
    lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
    lcd.setBacklight(HIGH);    
}


void loop() {
    //flip a coin for which demo program
    if (random(2)) { //random int, 0 or 1
        /*  http://www.ascii-art.de/ascii/t/tank.txt
          __
         |"""\-=
         (____)
         
        */

        //draw a tank
        lcd.setCursor(0,0);
        lcd.print("|\"\"\"\-=");
        lcd.setCursor(0,1);
        lcd.print("(____)");

        //start shooting
        while (1) {
            for (int i = 6; i < screen_width+1; i++) {
                if (i > 6) {
                    lcd.setCursor(i-1, 0);
                    lcd.print(" ");
                }
                lcd.setCursor(i, 0);
                lcd.print("o");
                delay(250);
            }
            lcd.print(" ");
        }
    }

    //this prints a dot moving around the screen
    else {
        while (1) {
            //erase the previous dot
            lcd.setCursor(col,row);
            lcd.print(" ");

            //move the cursor

            //flip a coin to change line
            if (random(2)) { //random int, 0 or 1
                row = row ? 0 : 1; //toggle line
            }

            col += random(-1, 2); //move over, maybe

            //check out of bounds
            if (col < 0) {
                col = 0;
            }
            else if (col > screen_width - 1) { //b/c 0-based
                col = 15;
            }
            
            lcd.setCursor(col,row);
            lcd.print(".");
    
            delay(250);
        }
    }
}
