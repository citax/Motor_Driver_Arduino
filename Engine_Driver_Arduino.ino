
#define p1 2
#define p2 3
#define p3 4
#define p4 5
#define p5 8
#define p6 9
#define p7 10
#define p8 11
#define button 12

char read_value, way, sensivity;

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
  Serial.begin(115200);
  Serial.println("Hello World!");

}

void loop() 
{
  while(way != 'b' && way != 'f')
  {
  Serial.println("which way do you want to go? (f -> forward || b -> backward )\n");
  while (Serial.available()==0) {} //wait until serial input
  way = Serial.read();
  }

  
  while(sensivity > 1000 && sensivity < 0)
  {
  Serial.println("Choose sensivity: ");
  while (Serial.available()==0) {} //wait until serial input
  sensivity = Serial.read();
  }

  while(read_value != 'y')
  {
  Serial.println("Start? (y/n)");
  while (Serial.available()==0) {} //wait until serial input
  read_value = Serial.read();
  }

  if( read_value == 'y' || read_value == 'Y')
  {
      switch (way)
      {
        case  'f':
          for(int i=0; i<=75; i++)
            {
              forward();
              Serial.println(i);
            }
        break;

        case  'b':
          for(int i=0; i<=75; i++)
            {
              backward();
              Serial.println(i);
            }
        break;
      }
  }
  way = '0';
  read_value = '0';
  
}

void forward()
{

 first_step();
 delay(10);
 second_step();
 delay(10);
 third_step();
 delay(10);
 fourth_step();
 delay(10);
 
  }
void backward()
{
   fourth_step();
   delay(10);
   third_step();
   delay(10);
   second_step();
   delay(10);
   first_step();
   delay(10);
 
  }
void first_step()
{
  digitalWrite(p1,HIGH);
  digitalWrite(p2,LOW);
  digitalWrite(p3,LOW);
  digitalWrite(p4,HIGH);
  delay(10);
  digitalWrite(p1,LOW);
  digitalWrite(p2,LOW);
  digitalWrite(p3,LOW);
  digitalWrite(p4,LOW);
  digitalWrite(p5,LOW);
  digitalWrite(p6,LOW);
  digitalWrite(p7,LOW);
  digitalWrite(p8,LOW);
  
}
void second_step()
{
  digitalWrite(p5,LOW);
  digitalWrite(p6,HIGH);
  digitalWrite(p7,HIGH);
  digitalWrite(p8,LOW);
  delay(10);
  digitalWrite(p1,LOW);
  digitalWrite(p2,LOW);
  digitalWrite(p3,LOW);
  digitalWrite(p4,LOW);
  digitalWrite(p5,LOW);
  digitalWrite(p6,LOW);
  digitalWrite(p7,LOW);
  digitalWrite(p8,LOW);
  
}
void third_step(){
  digitalWrite(p1,LOW);
  digitalWrite(p2,HIGH);
  digitalWrite(p3,HIGH);
  digitalWrite(p4,LOW);
  delay(10);
  digitalWrite(p1,LOW);
  digitalWrite(p2,LOW);
  digitalWrite(p3,LOW);
  digitalWrite(p4,LOW);
  digitalWrite(p5,LOW);
  digitalWrite(p6,LOW);
  digitalWrite(p7,LOW);
  digitalWrite(p8,LOW);
  
}
void fourth_step(){
  digitalWrite(p5,HIGH);
  digitalWrite(p6,LOW);
  digitalWrite(p7,LOW);
  digitalWrite(p8,HIGH);
  delay(10);
  digitalWrite(p1,LOW);
  digitalWrite(p2,LOW);
  digitalWrite(p3,LOW);
  digitalWrite(p4,LOW);
  digitalWrite(p5,LOW);
  digitalWrite(p6,LOW);
  digitalWrite(p7,LOW);
  digitalWrite(p8,LOW);
  
}
