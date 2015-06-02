#import "TimerOne.h"
void setup()
{
  Serial.begin(9600);
  Timer1.initialize(10); 
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT); 
  //configMotor(10);
  //configMotor(9);
  Timer1.pwm(9, 90, 17000);
  delay(5000);
}

int  i = 90;
void loop()
{
  int tempo = 500;
  while (1)
  {
  Serial.println("frente");
  Timer1.pwm(9, 110, 17000);
  delay(3000);
  Serial.println("break");
  Timer1.pwm(9, 60, 17000);
  Serial.println(500);
  delay(150);
  //digitalWrite(10,HIGH);  
  Serial.println("zero");
  Serial.println(500);
  //digitalWrite(10,HIGH);
  Timer1.pwm(9, 90, 17000);
  delay(tempo);
  //digitalWrite(10,LOW);
  Serial.println("traz");
  Timer1.pwm(9, 70, 17000);
  delay(3000);
  //digitalWrite(10,HIGH);
  Serial.println("break");
   Timer1.pwm(9, 120, 17000);
  Serial.println(500);
  delay(100);
  Serial.println("zero");
  Serial.println(tempo);
  Timer1.pwm(9, 90, 17000);
  delay(tempo);
  //digitalWrite(10,LOW);
  //tempo -= 100;
  //if (tempo < 100) break;
  }
  ///
  ///
  
  
  /*while (i < 120)
  {
  if (i == 90) delay(1000);
  Timer1.pwm(9, i++, 17000);
  delay(100);
  }
  while (i > 60)
  {
  if (i == 90) delay(1000);
  Timer1.pwm(9, i--, 17000);
  delay(100);
  }*/
  /*if (i > -100)
    OnFwd(9, i);
  i--;
  delay(500);
  Serial.print(i);
  Serial.print("\t");*/
}
