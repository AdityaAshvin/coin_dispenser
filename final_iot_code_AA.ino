#include <Servo.h>
Servo servoMain1;
Servo servoMain2;
Servo servoMain3;
Servo servoMain4;
int led = 13;
long int n = 0;
int a1 = 0;
int a2 = 0;
int a3 = 0;
int a4 = 0;
int d = 0;
int diff = 0;
int diff2 = 0;
int diff3 = 0;

void setup() {        
    Serial.begin(9600);
  pinMode(led, OUTPUT);
   servoMain1.attach(3);
   servoMain2.attach(5);
   servoMain3.attach(6);
   servoMain4.attach(9);
}
void loop(){
  while (Serial.available() > 0) {
    int n = Serial.parseInt();
    if(n>10){
      a1=n/10;
      d=n-(a1*10);
      }
    if(d>=5){
        a2=1;
        diff=d-5;
        }
      switch(diff){
        case 4:
        a3=2;
        break;
        case 3:
        a3=1;
        a4=1;
        break;
        case 2:
        a3=1;
        break;
        case 1:
        a4=1;
      }
    if(n>=5 && n<10){
      a2=1;
      diff2=n-5;
      switch (diff2){
        case 4:
        a3=2;
        break;    
        case 3:
        a3=1;
        a4=1;
        break;
        case 2:
        a3=1;
        break;
        case 1:
        a4=1;
      }
    }
    if(n>=2 && n<5){
    a3=1;
    diff3=n-2;
    }
    if(diff3>=1){
      a4=diff3;
    }
if(n>=1 && n<2){
  a4=n;
  }
  }
  Serial.println(a1);
  Serial.println(a2);
  Serial.println(a3);
  Serial.println(a4);
   while (a1>0) {
   servoMain1.write(40);
   delay(300);          
   servoMain1.write(120);  
   delay(300);          
a1--; }
 while (a2>0) {
   servoMain2.write(40);
   delay(300);          
   servoMain2.write(120);  
   delay(300);          
a2--;   }
 while (a3>0) {
   servoMain3.write(40);
   delay(300);          
   servoMain3.write(120);  
   delay(300);          
a3--; }
 while (a4>0) {
   servoMain4.write(40);
   delay(300);          
   servoMain4.write(120);  
   delay(300);          
a4--; }
}
