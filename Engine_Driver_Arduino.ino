
#define p1 2
#define p2 3
#define p3 4
#define p4 5
#define p5 8
#define p6 9
#define p7 10
#define p8 11
#define button 12
#define OUTPUT_LENGTH 8

char read_value, way;
int sensivity = 1001;
int outputs[OUTPUT_LENGTH] = {p1, p2, p3, p4, p5, p6, p7, p8};

void setup() 
{
  for(int i = 0; i < OUTPUT_LENGTH; i++)
  {
    pinMode(outputs[i], OUTPUT);
  }
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

  
  while(sensivity > 1000 || sensivity < 0)
  {
  Serial.println("Choose sensivity (0 - 1000)\n");
  while (Serial.available()==0) {} //wait until serial input
  sensivity = Serial.read();
  }

  delay(10);//for bugs

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
  sensivity = 1001;
}

void forward()
{

 first_step();
 delay(sensivity);
 second_step();
 delay(sensivity);
 third_step();
 delay(sensivity);
 fourth_step();
 delay(sensivity);
 
  }
void backward()
{
   fourth_step();
   delay(sensivity);
   third_step();
   delay(sensivity);
   second_step();
   delay(sensivity);
   first_step();
   delay(sensivity);
 
  }
void first_step()
{
  digitalWrite(p1,HIGH);
  digitalWrite(p2,LOW);
  digitalWrite(p3,LOW);
  digitalWrite(p4,HIGH);
  delay(sensivity);
  for(int i = 0; i < OUTPUT_LENGTH; i++)
  {
    digitalWrite(outputs[i], LOW);
  }
}
void second_step()
{
  digitalWrite(p5,LOW);
  digitalWrite(p6,HIGH);
  digitalWrite(p7,HIGH);
  digitalWrite(p8,LOW);
  delay(sensivity);
  for(int i = 0; i < OUTPUT_LENGTH; i++)
  {
    digitalWrite(outputs[i], LOW);
  }
}
void third_step(){
  digitalWrite(p1,LOW);
  digitalWrite(p2,HIGH);
  digitalWrite(p3,HIGH);
  digitalWrite(p4,LOW);
  delay(sensivity);
  for(int i = 0; i < OUTPUT_LENGTH; i++)
  {
    digitalWrite(outputs[i], LOW);
  }
}
void fourth_step(){
  digitalWrite(p5,HIGH);
  digitalWrite(p6,LOW);
  digitalWrite(p7,LOW);
  digitalWrite(p8,HIGH);
  delay(sensivity);
  for(int i = 0; i < OUTPUT_LENGTH; i++)
  {
    digitalWrite(outputs[i], LOW);
  }
}