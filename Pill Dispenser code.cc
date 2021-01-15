#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h> #include <DS1302.h>
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;
char hexaKeys[ROWS][COLS] = {
{'1','2','3','A'}, 
{'4','5','6','B'}, 
{'7','8','9','C'}, 
{'*','0','#','D'}
};
byte rowPins[ROWS] = {5, 6, 7, 8}; 
byte colPins[COLS] = {9, 10, 11, 12};
DS1302 rtc(2, 3, 4);

// LCD Setup
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

// Keypad Setup
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
Time t;
int H1, H11, H111;
int H2, H22, H222;
int M1, M11, M111;
int M2, M22, M222;
int Hor, Min, Sec;
int buzzer =13;


// User Interface Setup
void setup() { 
    Serial.begin(9600); 
    pinMode(buzzer, OUTPUT); 
    pinMode (A10 ,OUTPUT); digitalWrite(A10, 1); 
    digitalWrite(buzzer, 1);
    lcd.begin(16,2); rtc.halt(false); 
    rtc.writeProtect(false);
    lcd.print("Time:"); l
    cd.setCursor(0,1); 
    lcd.print("#:Dose Settings");
    
    //rtc.setDOW(MONDAY); 
    //rtc.setTime(02, 03, 00); 
    //rtc.setDate(27, 11, 2017);
    }

// Set Day-of-Week to FRIDAY
// Set the time to 12:00:00 (24hr format)
// Set the date to August 6th, 2010


void loop() {
             t = rtc.getTime();
             Hor = t.hour; Min = t.min; Sec = t.sec;
             lcd.setCursor(5,0); 
             lcd.print(rtc.getTimeStr());
             
             char Key = customKeypad.getKey();
             int a = b = c = d = e = f = g = h = i = j = k = l = m = n = o = p = 1;
             int A1, A2, A3, B, C, D, E, F, G, H, I,  J,  K,  L,  M;
             if (Key==35){
                 lcd.clear();
                 lcd.print("Doses Per Day:");}


while (a) {
    char Key = customKeypad.getKey(); 
    lcd.setCursor(14,0);
    if (Key){lcd.print(Key); 
             delay(1000); }
    
if (Key==49){ 
    lcd.clear();
    lcd.print("Dose Type:"); 
    lcd.setCursor(10,0);
    
while (b) {
    char Key = customKeypad.getKey(); 
    if (Key){ A1=Key;
        lcd.print(Key); 
        delay(1000); b=0; } 
    }


// SETTING HOUR  ******************************************************
lcd.clear(); 
lcd.print("Set Hour:");


lcd.setCursor(9,0);
while (c) {
    char Key = customKeypad.getKey(); 
    if (Key){ B=Key;
        lcd.print(Key);
        c=0; } } 
while (d) {
    char Key = customKeypad.getKey(); 
    if (Key){ C=Key;
    lcd.print(Key); delay(1000); d=0; } 
    }



// SETTING MINUTE *****************************************************
lcd.clear();
lcd.print("Set Minute:");
lcd.setCursor(11,0);
while (e) {
    char Key = customKeypad.getKey(); 
    if (Key){ D=Key;
        lcd.print(Key);
        e=0; } 
    } 
while (f) {
    char Key = customKeypad.getKey(); 
    if (Key){ E=Key;
    lcd.print(Key); 
    delay(1000); 
    f=0; } } a=0;}

// User Selects Dose Type 1
if (Key==50){ 
    lcd.clear();
    lcd.print("Dose 1 Type:"); 
    lcd.setCursor(12,0);
    
while (b) {
    char Key = customKeypad.getKey(); 
    if (Key){ A1=Key;
    lcd.print(Key); delay(1000); b=0; } }
lcd.clear(); 

// User Selects Dose Type 2
lcd.print("Dose 2 Type:"); 
lcd.setCursor(12,0);
while (c) {
    char Key = customKeypad.getKey(); 
    if (Key){ A2=Key;
        lcd.print(Key); 
        delay(1000); c=0; } 
    }


// Setting Doze 1 Alarm  ************************************************
lcd.clear(); 
lcd.print("Dose 1 Alarm"); 
delay (2000);
lcd.clear();
// Setting Hour
lcd.print("Set Hour:"); 
lcd.setCursor(9,0);
while (d) {
    char Key = customKeypad.getKey();


if (Key){ B=Key; 
    lcd.print(Key);
    d=0; } 
    } 
while (e) {
    char Key = customKeypad.getKey(); 
    if (Key){ 
        C=Key;
        lcd.print(Key); delay(1000); e=0; } 
    }

// Setting Minute *****************************************************
lcd.clear(); 
lcd.print("Set Minute:"); 
lcd.setCursor(11,0);
while (f) {
    char Key = customKeypad.getKey(); 
    if (Key){ D=Key;
        lcd.print(Key); f=0; } 
    }


while (g) {
    char Key = customKeypad.getKey(); 
    if (Key){ E=Key;
        lcd.print(Key); delay(1000); g=0; } 
    }

// Setting Doze 2 Alarm  ************************************************
lcd.clear(); 
lcd.print("Dose 2 Alarm"); 
delay (2000);
lcd.clear();
lcd.print("Set Hour:"); 
lcd.setCursor(9,0);
while (h) {
    char Key = customKeypad.getKey(); 
    if (Key){ 
        F=Key;
        lcd.print(Key);
        h=0; } 
    } 

while (i) {
    char Key = customKeypad.getKey(); 
    if (Key){ 
        G=Key; 
        lcd.print(Key);
        delay(1000); i=0; } 
    }

lcd.clear(); 
lcd.print("Set Minute:"); 
lcd.setCursor(11,0);
while (j) {
    char Key = customKeypad.getKey(); 
    if (Key){ H=Key;
        lcd.print(Key);
        j=0; } 
    } 
while (k) {
    char Key = customKeypad.getKey(); 
    if (Key){ I=Key;
        lcd.print(Key); delay(1000);
        k=0; } 
    } a=0;}



// Setting Dozes Types *****************************************************
if (Key==51){ 
    lcd.clear();
    lcd.print("Dose 1 Type:"); 
    lcd.setCursor(12,0);
while (b) {
    char Key = customKeypad.getKey(); 
    if (Key){ 
        A1=Key;
        lcd.print(Key); 
        delay(1000); 
        b=0; } 
    }

lcd.clear(); 
lcd.print("Dose 2 Type:"); 
lcd.setCursor(12,0);
while (c) {
    char Key = customKeypad.getKey(); 
    if (Key){ A2=Key;
    lcd.print(Key);
    delay(1000); 
    c=0; } 
    }

lcd.clear(); 
lcd.print("Dose 3 Type:"); 
lcd.setCursor(12,0);
while (d) {
    char Key = customKeypad.getKey(); 
    if (Key){ 
        A3=Key;
        lcd.print(Key); 
        delay(1000); d=0; } }


// Doze 1 Alarm  ******************************************************
lcd.clear(); 
lcd.print("Dose 1 Alarm"); 
delay (2000);
lcd.clear();
lcd.print("Set Hour:"); lcd.setCursor(9,0);

while (e) {
char Key = customKeypad.getKey(); 
if (Key){ B=Key;
lcd.print(Key);
e=0; } } 
while (f) {
    char Key = customKeypad.getKey(); 
    if (Key){ 
        C=Key;
        lcd.print(Key); delay(1000); f=0; } }


lcd.clear(); 
lcd.print("Set Minute:"); 
lcd.setCursor(11,0);
while (g) {
    char Key = customKeypad.getKey(); if (Key){ D=Key;
    lcd.print(Key);
    g=0; } 
    } 
while (h) {
    char Key = customKeypad.getKey(); 
    if (Key){ 
        E=Key;
        lcd.print(Key); 
        delay(1000); 
        h=0; } 
    }


// Doze 2 Alarm  ******************************************************
lcd.clear(); 
lcd.print("Dose 2 Alarm"); 
delay (2000);
lcd.clear();
lcd.print("Set Hour:"); 
lcd.setCursor(9,0);
while (i) {
    char Key = customKeypad.getKey(); 
    if (Key){ F=Key;
    lcd.print(Key); i=0; } 
    }


while (j) {
    char Key = customKeypad.getKey(); 
    if (Key){ 
        G=Key;
        lcd.print(Key); 
        delay(1000); j=0; } 
    }



lcd.clear(); 
lcd.print("Set Minute:"); 
lcd.setCursor(11,0);
while (k) {
    char Key = customKeypad.getKey(); 
    if (Key){ 
        H=Key;
        lcd.print(Key);
        k=0; } 
    } 
while (l) {
    char Key = customKeypad.getKey(); 
    if (Key){ I=Key;
        lcd.print(Key); 
        delay(1000); l=0; } 
    }

// Doze 3 Alarm  ******************************************************
lcd.clear(); 
lcd.print("Dose 3 Alarm"); 
delay (2000);
lcd.clear();
lcd.print("Set Hour:"); 
lcd.setCursor(9,0);
while (m) {
    char Key = customKeypad.getKey(); 
    if (Key){ 
        J=Key;
        lcd.print(Key);
        m=0; } 
    }
 
while (n) {
    char Key = customKeypad.getKey(); 
    if (Key){ K=Key;
        lcd.print(Key); 
        delay(1000);
        n=0; } 
    }



lcd.clear(); 
lcd.print("Set Minute:"); 
lcd.setCursor(11,0);
while (o) {
    char Key = customKeypad.getKey(); 
    if (Key){ 
        L=Key;
        lcd.print(Key);
        o=0; } 
    } 
while (p) {
    char Key = customKeypad.getKey(); 
    if (Key){ M=Key;
        lcd.clear();
        lcd.print(Key); 
        delay(1000); 
        p=0; } 
    } 
a=0;}
}



// LCD initiating
lcd.print("Time:"); 
lcd.setCursor(0,1); 
lcd.print("#:Dose Settings");
H1 = B - 48;
H2 = C - 48;
M1 = D - 48;
M2 = E - 48;
H11 = F - 48;
H22 = G - 48; 
M11 = H - 48; 
M22 = I - 48; 
H111 = J - 48; 
H222 = K - 48; 
M111 = L - 48; 
M222 = M - 48; }
int q=1;
//Check if set alarm matches time
if( (Hor == (H1*10)+H2 && Min == (M1*10)+M2) ){
if (A1==65) {

// initiating a servo motor called motor 1 // attach motor1 to pin 9

Servo motor1 ;
motor1.attach(A9); 
motor1.write(180);
int sensorValue = 500; 
digitalWrite (A10, 0); 
delay (500);


// set the order for the motor to rotate
// initiating the analog reading of the sensor


while( sensorValue > 200 ) {
    digitalWrite( A10 , 0 );
    
// set the power pin to high ( the relay must light up at this stage and
//the motor will start rotating)

    sensorValue = analogRead(A8); 


// the loop reads the sensor value Serial.println(sensorValue); 
// print Value 

    digitalWrite( A10 , 1 ); 
    Serial.println(sensorValue); 
    }
// once the loop is broken, the relay is switched off, therefore the motor will stop.


//if (A_1==66) 

lcd.clear();
lcd.print("Alarm ON");
lcd.setCursor(0,1);

// Stop Alarm **************************************************

lcd.print("Stop: Press Any");
while (q) { 
    Buzzer();
    char Key = customKeypad.getKey();
    if (Key){
        lcd.clear(); 
        lcd.print("Time:");
        lcd.setCursor(0,1); 
        lcd.print("#:Dose Settings"); 
        M2=M2-1;
        q=0;
        digitalWrite(buzzer, 1);}
        }
}

if( (Hor == (H11*10)+H22 && Min == (M11*10)+M22) ){
//if (A_2==65) { /*motor A*/}; //if (A_2==66) { /*motor B*/};
lcd.clear();


lcd.print("Alarm ON");
lcd.setCursor(0,1);
lcd.print("Stop: Press Any");
while (q) { 
    Buzzer();
    char Key = customKeypad.getKey();
    if (Key){
        lcd.clear(); 
        lcd.print("Time:");
        lcd.setCursor(0,1); 
        lcd.print("#:Dose Settings"); 
        M22=M22-1;
        q=0;
        digitalWrite(buzzer, 1);}
    }
}


if( (Hor == (H111*10)+H222 && Min == (M111*10)+M222) ){
        
//if (A_3==65) { /*motor A*/};
//if (A_3==66) { /*motor B*/};

    lcd.clear();
    lcd.print("Alarm ON");
    lcd.setCursor(0,1);
    lcd.print("Stop: Press Any");
    while (q) {
        Buzzer();
        char Key = customKeypad.getKey();
        if (Key){
            lcd.clear(); 
            lcd.print("Time:");
            lcd.setCursor(0,1); 
            lcd.print("#:Dose Settings"); 
            M222=M222-1;
            q=0;
            digitalWrite(buzzer, 1);}
        }
    }

}

void Buzzer()
{
digitalWrite(buzzer,HIGH);
delay(100);
digitalWrite(buzzer, LOW);

delay(100);
}
A9: Machine code