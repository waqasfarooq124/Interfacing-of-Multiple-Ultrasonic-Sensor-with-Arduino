#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,10,11,12,13);
#define trigPin1 A1
#define echoPin1 A0
#define trigPin2 A3
#define echoPin2 A2
#define trigPin3 A5
#define echoPin3 A4
int ALARM = 7;
long duration, distance, FIRSTSensor,SECONDSensor,THIRDSensor;
void setup()
{
lcd.begin(16,2);
Serial.begin (9600);
lcd.clear(); 
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
pinMode(trigPin3, OUTPUT);
pinMode(echoPin3, INPUT);
pinMode(ALARM, OUTPUT);
digitalWrite(ALARM, LOW);
 lcd.setCursor(0,0);lcd.print("Interfacing ");
lcd.setCursor(0,1);lcd.print("of Multiple ");
delay(3000);lcd.clear();  
lcd.setCursor(0,0);lcd.print("3 HC - SR04 ");
lcd.setCursor(0,1);lcd.print("Ultrasonic  ");
delay(3000);lcd.clear();
lcd.setCursor(0,0);lcd.print("SensorS With ");
lcd.setCursor(0,1);lcd.print("Arduino ");
delay(3000);lcd.clear();
}

void loop() 
{
/////////////////////////////////////////////////////// 
SonarSensor(trigPin1, echoPin1);
FIRSTSensor = distance;
SonarSensor(trigPin2, echoPin2);
SECONDSensor = distance;
SonarSensor(trigPin3, echoPin3);
THIRDSensor = distance;
/////////////////////////////////////////////////////////////
digitalWrite(ALARM, LOW);
//////////////////////////////////////////////////////////////////////////////////////
Serial.print("S1:");Serial.println(FIRSTSensor); delayMicroseconds(10);
Serial.print("S2:");Serial.println(SECONDSensor);delayMicroseconds(10);
Serial.print("S3:");Serial.println(THIRDSensor); delayMicroseconds(10);
///////////////////////////////////////////////////////////////////////////////////////
lcd.setCursor(0,0);lcd.print("S1:");lcd.setCursor(4,0);lcd.print(FIRSTSensor);
lcd.setCursor(9,0);lcd.print("S2:");lcd.setCursor(12,0);lcd.print(SECONDSensor);
lcd.setCursor(0,1);lcd.print("S3:");lcd.setCursor(4,1);lcd.print(THIRDSensor);
delay(1000);lcd.clear();
///////////////////////////////////////////////////////
if((FIRSTSensor >= 10) & (FIRSTSensor <= 50)) 
{digitalWrite(ALARM, HIGH);delay(500);}
///////////////////////////////////////////////////////
if((SECONDSensor >= 10) & (SECONDSensor <= 50)) 
{digitalWrite(ALARM, HIGH);delay(500);}
///////////////////////////////////////////////////////
if((THIRDSensor >= 10) & (THIRDSensor <= 50)) 
{digitalWrite(ALARM, HIGH);delay(500);}
///////////////////////////////////////////////////////
}
/////////////////////////////////////////////////////////////////////////////////
void SonarSensor(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
}
