#include <Servo.h>
Servo servoX;
Servo servoY;
const int but1 = 1;
const int but2 = 2;
const int but3 = 3;
const int but4 = 4;
const int but5 = 5;
const int laser = 6;
int butval1 = 0;
int butval2 = 0;
int butval3 = 0;
int butval4 = 0;
int butval5 = 0;
int x = 0;
int y = 0;


void setup() {
  // put your setup code here, to run once:
servoX.attach(9);
servoY.attach(10);
pinMode(but1, INPUT);
pinMode(but2, INPUT);
pinMode(but3, INPUT);
pinMode(but4, INPUT);
pinMode(but5, INPUT);
pinMode(laser, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 butval1 = digitalRead(but1);
  butval2 = digitalRead(but2);
  if(butval1 == HIGH && x <= 179){
    delay(100);
    x++;
    delay(15);
  } /* Scaderea axei X */
  else if(butval2 == HIGH && x > 0){
    delay(100);
    x--;
    delay(15);
  }
  // Cresterea axei Y
  butval3 = digitalRead(but3);
  butval4 = digitalRead(but4);
  if(butval3 == HIGH && y <= 179){
    delay(100);
    y++;
    delay(15);
  } /* Scaderea axei Y */
  else if(butval4 == HIGH && y > 0){
    delay(100);
    y--;
    delay(15);
  }

delay(125);
servoX.write(x);
delay(125);
servoY.write(y);
delay(15);
//Chestii pentru a porni si opri laser-ul
butval5 = digitalRead(but5);
if(butval5 == HIGH) {
  delay(80);
  digitalWrite(laser, HIGH);
}else{
  delay(80);
  digitalWrite(laser, LOW);}
}
