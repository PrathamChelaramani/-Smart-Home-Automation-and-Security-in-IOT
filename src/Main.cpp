#include <LiquidCrystal.h>

const int rs = 12,en =11,d4 = 4 ,d5 = 5, d6 = 6, d7 = 7 ;
LiquidCrystal lcd (rs, en, d4, d5, d6, d7);

int temp = A1;
float value;
int pir = 8;
int pvalue = 0;
int light = 13;
int pirIntruder = 10;
int pirIntruderValue = 0;

void setup()
{
    pinMode(temp, INPUT);
    pinMode(pir,INPUT);
    pinMode(light,OUTPUT);
    lcd.begin(16,2);
}

void loop()
{
    value = analogRead(temp)*0.004882814;
    value = (value - 0.5)* 100.0;
    lcd.setCursor (0,0);
    lcd.print ("Temp: ");
    lcd.print (value);
    lcd.print (" C ");
    lightonoff();
    intruderDetector();
    delay(1000);
    lcd.clear();
}

void lightonoff()
{
    pvalue = digitalRead(pir);
    if (pvalue == HIGH){
    digitalWrite(light,HIGH);
    lcd.setCursor (0,1);
    lcd.print("LIGHTS ON");
}

else {
    digitalWrite (light, LOW); 
}

delay(10);
}

void intruderDetector(){
    pirIntruderValue = digitalRead(pirIntruder);
    
    if (pirIntruderValue == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Intruder ");
        lcd.setCursor(0,1);
        lcd.print("detected"); 
    }
}