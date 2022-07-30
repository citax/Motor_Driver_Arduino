
#define p1 2
#define p2 3
#define p3 4
#define p4 5
#define p5 8
#define p6 9
#define p7 10
#define p8 11
#define button 12
int way = 1;
int x , y;

void setup() 
{
pinMode(p1,OUTPUT);
pinMode(p2,OUTPUT);
pinMode(p3,OUTPUT);
pinMode(p4,OUTPUT);
pinMode(p5,OUTPUT);
pinMode(p6,OUTPUT);
pinMode(p7,OUTPUT);
pinMode(p8,OUTPUT);
pinMode(button,INPUT);
Serial.begin(9600);
Serial.println("Start");
Serial.println(way);
}

void loop() 
{
 way = digitalRead(button);
 if (way == 1) // 1/forward 0/backward
 {
  x == 0;
  y == 1; 
 }
 else if (way == 0)
 {
  x == 1;
  y == 0;
 }
 Serial.println(way);
 first_step();
 delay(10);
 second_step();
 delay(10);
 third_step();
 delay(10);
 fourth_step();
 delay(10);
}

void first_step()
{
  digitalWrite(p1,y);
  digitalWrite(p2,x);
  digitalWrite(p3,x);
  digitalWrite(p4,y);
  delay(10);
  digitalWrite(p1,LOW);
  digitalWrite(p2,LOW);
  digitalWrite(p3,LOW);
  digitalWrite(p4,LOW);
  
}

void second_step()
{
  digitalWrite(p1,x);
  digitalWrite(p2,y);
  digitalWrite(p3,y);
  digitalWrite(p4,x);
  delay(10);
  digitalWrite(p1,LOW);
  digitalWrite(p2,LOW);
  digitalWrite(p3,LOW);
  digitalWrite(p4,LOW);
  
}

void third_step(){
  digitalWrite(p5,x);
  digitalWrite(p6,y);
  digitalWrite(p7,y);
  digitalWrite(p8,x);
  delay(10);
  digitalWrite(p5,LOW);
  digitalWrite(p6,LOW);
  digitalWrite(p7,LOW);
  digitalWrite(p8,LOW);
  
}

void fourth_step(){
  digitalWrite(p5,y);
  digitalWrite(p6,x);
  digitalWrite(p7,x);
  digitalWrite(p8,y);
  delay(10);
  digitalWrite(p5,LOW);
  digitalWrite(p6,LOW);
  digitalWrite(p7,LOW);
  digitalWrite(p8,LOW);
  
}
