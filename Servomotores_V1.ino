#include <Adafruit_PWMServoDriver.h>

#define SERVOMIN  150 
#define SERVOMAX  600 
 
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

 int A_0,A_1;
 
void setup() 
{
  
    Serial.begin(9600);
    pwm.begin();
    pwm.setPWMFreq(50); //FRECUENCIA DE SERVO MH995=20MS
    yield();
    
}
 
void loop() {
    
  Servo_control_2(150, 600, 150, 550, "A1");
  Servo_control_2(600, 150, 550, 150, "A1");
  
 /* int Speed;
        A_0 = analogRead(A0); 
        A_1 = analogRead(A1);// realizar la lectura analógica raw
        
        Speed = map(A_1, 0, 1023, 10, 50);
        Serial.println(Speed);
        
        
      for(uint16_t Pos=SERVOMAX; Pos>SERVOMIN; Pos=Pos - Speed){
          pwm.setPWM(1, 0, Pos);
          uint16_t Pos2 = map(Pos, SERVOMAX, SERVOMIN, SERVOMIN, SERVOMAX);
          pwm.setPWM(2, 0, Pos2);
          
          delay(20);
          
          A_1 = analogRead(A1);// realizar la lectura analógica raw
          Speed = map(A_1, 0, 1023, 10, 50);
          Serial.println(Speed);

       while(Speed <= 11){
            pwm.setPWM(1, 0, Pos);
            pwm.setPWM(2, 0, Pos2);
            delay(20);
            
            A_1 = analogRead(A1);// realizar la lectura analógica raw
            Speed = map(A_1, 0, 1023, 10, 50);
            Serial.println(Speed);
          }
         }

     for(uint16_t Pos=SERVOMIN; Pos<SERVOMAX; Pos=Pos + Speed){
          pwm.setPWM(1, 0, Pos);
          uint16_t Pos2 = map(Pos, SERVOMIN, SERVOMAX, SERVOMAX, SERVOMIN);
          pwm.setPWM(2, 0, Pos2);
       
          delay(20);
          
          A_1 = analogRead(A1);// realizar la lectura analógica raw
          Speed = map(A_1, 0, 1023, 10, 50);
          Serial.println(Speed);

          while (Speed <= 11){
            pwm.setPWM(1, 0, Pos);
            pwm.setPWM(2, 0, Pos2);
            delay(20);
            
            A_1 = analogRead(A1);// realizar la lectura analógica raw
            Speed = map(A_1, 0, 1023, 10, 50);
            Serial.println(Speed);
          }
          
         }*/
}

/////////////////////////////////////////////funciones////////////////////////////////////////////////

void Servo_control_2(uint16_t pi1, uint16_t pf1, uint16_t pi2,uint16_t pf2, unsigned char analog[3]) {
  
  uint16_t pos1, pos2;
  uint16_t val = analogRead(analog);
  uint8_t Speed = map(val, 0, 1023, 10, 50);
  Serial.println(Speed);
  
//      if (Speed <= 11){
//              pwm.setPWM(1, 0, pos1);
//              pwm.setPWM(2, 0, pos2);
//              delay(20);
//      }
  
  if (pi1<pf1 && abs(pf1-pi1)>=abs(pf2-pi2)){//--------------------------------------arriba-mayor1
    
      for(pos1=pi1; pos1>pf1; pos1=pos1 + Speed){
              pwm.setPWM(1, 0, pos1);
              pos2 = map(pos1, pi1, pf1, pi2, pf2);
              pwm.setPWM(2, 0, pos2);
              delay(20);
              
              val = analogRead(analog);// realizar la lectura analógica raw
              Speed = map(val, 0, 1023, 10, 50);
              Serial.println(Speed);
       }
    break;
  }
  
  else if (pi2<pf2 && abs(pf1-pi1)<=abs(pf2-pi2)){//----------------------------------------arriba-mayor2        
    
      for(pos2=pi2; pos2>pf2; pos2=pos2 + Speed){
              pwm.setPWM(2, 0, pos2);
              pos1 = map(pos2, pi2, pf2, pi1, pf1);
              pwm.setPWM(1, 0, pos1);
              delay(20);
              
              val = analogRead(analog);// realizar la lectura analógica raw
              Speed = map(val, 0, 1023, 10, 50);
              Serial.println(Speed);
       }

       break;
  }

  else if (pi1>pf1 && abs(pf1-pi1)>=abs(pf2-pi2)){//-----------------------------------------abajo-mayor1
      
        for(pos1=pi1; pos1<pf1; pos1=pos1 - Speed){
                pwm.setPWM(1, 0, pos1);
                pos2 = map(pos1, pi1, pf1, pi2, pf2);
                pwm.setPWM(2, 0, pos2);
                delay(20);
                
                val = analogRead(analog);// realizar la lectura analógica raw
                Speed = map(val, 0, 1023, 10, 50);
                Serial.println(Speed);
          }

      break;
   }
    
  
  else if (pi2>pf2 && abs(pf1-pi1)<=abs(pf2-pi2)){//------------------------------------------abajo-mayor2        
    
      for(pos2=pi2; pos2<pf2; pos2=pos2 - Speed){
              pwm.setPWM(2, 0, pos2);
              pos1 = map(pos2, pi2, pf2, pi1, pf1);
              pwm.setPWM(1, 0, pos1);
              delay(20);
              
              val = analogRead(analog);// realizar la lectura analógica raw
              Speed = map(val, 0, 1023, 10, 50);
              Serial.println(Speed);
              
       }
      break;
  }
}


