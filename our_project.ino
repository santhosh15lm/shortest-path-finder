void straight();
void right();
void left();
void turn_around();
void t_or_stop(); 
 int vSpeed = 110;        // MAX 255
  int turn_speed = 230;    // MAX 255 
  int turn_delay = 10;
#define leftCenterSensor 6
#define leftFarSensor 7
#define rightCenterSensor 5
#define rightFarSensor 4
  const int rm1      = 12;  
  const int rm2      = 11; 
  const int rmspeed  = 13;
  const int lm1      = 8; 
  const int lm2      = 9; 
  const int lmspeed  = 10;
  void straightl();
void read();
int s1,s2,s3,s4;

void setup() {
pinMode(leftCenterSensor, INPUT);

pinMode(leftFarSensor, INPUT);
pinMode(rightCenterSensor, INPUT);

pinMode(rightFarSensor, INPUT);
pinMode(lm1, OUTPUT);
pinMode(lm2, OUTPUT);
pinMode(rm1, OUTPUT);
pinMode(rm2, OUTPUT);
delay(3000);
}

void loop() {
  read();
  //LEFT
  if(s1 == 1)
  {
    left();
  }
  
  //straight
  if(s1 == 0 && (s2 == 1 || s3==1) && s4==0)
  {
    straight();  
  }
    //RIGHT
   else if(s1 == 0 && s2 == 1 && s3==1 && s4==1)
   {
    decide_right_or_straight();   
   }
    
  else if(s1 == 1 && s2 == 0 && s3==0 && s4==0 )
  {
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,HIGH);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  analogWrite (rmspeed, turn_speed);
  analogWrite (lmspeed, 0);
  delay(turn_delay);
    
    }
    //stop
   else if(s1 == 0 && s2 == 0 && s3==0 && s4==0)
   {
    turn_around();
   }
    //turn around

   else if( s1==1 && s2 == 1 && s3==1 && s4 == 1)
   {
    t_or_stop();
   }
}
void done()
{
  delay(1000000000);
}
void read()
{
  s2 = digitalRead(leftCenterSensor);
  s1 = digitalRead(leftFarSensor);
  s3 = digitalRead(rightCenterSensor);
  s4 = digitalRead(rightFarSensor); 
}
void left()
{
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  analogWrite (rmspeed, turn_speed);
  analogWrite (lmspeed, 0);
  delay(turn_delay);

}
void decide_right_or_straight()
{
  // move forward and check
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  analogWrite (rmspeed, vSpeed);
  analogWrite (lmspeed, vSpeed);
  delay(400);
  read();
  if(s1 == 0 && (s2 == 1 || s3==1) && s4==0)
  {
    straight();  
  }
 /* else if(s1 == 1 && (s2 == 1 || s3==1) && s4==1)
  {
    left();  
  }*/
  else if(s1 == 0 && s2 == 0 && s3==0 && s4==0)
  {
    // if no path is there except right
    digitalWrite(lm1,LOW);
    digitalWrite(lm2,HIGH);
    digitalWrite(rm1,LOW);
    digitalWrite(rm2,HIGH);
    analogWrite (rmspeed, vSpeed);
    analogWrite (lmspeed, vSpeed);
    delay(450);
  }  
  else if(s1==0 && s2==1 && s3==1 && s4==1)
  {
    right();
  }

}
void right()
{
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,HIGH);
  analogWrite (rmspeed, 0);
  analogWrite (lmspeed, turn_speed);
  delay(turn_delay);
}
void straight()  
{
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  analogWrite (rmspeed, vSpeed);
  analogWrite (lmspeed, vSpeed);
  delay(turn_delay);
}
void turn_around()
{
  delay(10);
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,HIGH);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  analogWrite (rmspeed, turn_speed);
  analogWrite (lmspeed, turn_speed);
  delay(turn_delay);

}
void t_or_stop()
{
    digitalWrite(lm1,HIGH);
    digitalWrite(lm2,LOW);
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
    analogWrite (rmspeed, vSpeed);
    analogWrite (lmspeed, vSpeed);
    delay(400);
    read();
    if( s1==0 && s2 == 1 && s3==1 && s4 == 0)
    {
      straight();
    }
    else if(s1==1 && s2 == 1 && s3==1 && s4 == 1)
    {
      digitalWrite(lm1,LOW);
      digitalWrite(lm2,LOW);
      digitalWrite(rm1,LOW);
      digitalWrite(rm2,LOW);
      done(); 
    }

}
