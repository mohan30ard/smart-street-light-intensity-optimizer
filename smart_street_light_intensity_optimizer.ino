const int ledPin1 = 9;
const int ledPin2 = 10;
const int ledPin3 = 11;
const int ledPin4 = 5;
int obstaclePin1 = 4;// This is our input pin
int obstaclePin2 = 2;
int obstaclePin3 = 6;
int obstaclePin4 = 7;
int hasObstacle1 = LOW; 
int hasObstacle2 = LOW; 
int hasObstacle3 = LOW; 
int hasObstacle4 = LOW; // HIGH MEANS NO OBSTACLE
const int ldrPin = A0;
int RELAY1 = A1;
int RELAY2 = A2;
int RELAY3 = A3;
int RELAY4 = A4;
int fadeAmount = 3;
int brightness = 50;
int delayValue = 500;
void setup() {
 
Serial.begin(9600);
 
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);
  pinMode(RELAY4, OUTPUT);
  digitalWrite(RELAY1, HIGH);
  digitalWrite(RELAY2, HIGH);
  digitalWrite(RELAY3, HIGH);
  digitalWrite(RELAY4, HIGH);
  pinMode(ledPin1, OUTPUT); 
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(obstaclePin1, INPUT);
  pinMode(obstaclePin2, INPUT);
  pinMode(obstaclePin3, INPUT);
  pinMode(obstaclePin4, INPUT);
 
  pinMode(ldrPin, INPUT);
 
 
}
 
void loop() {
 
int ldrStatus = analogRead(ldrPin);
 
if (ldrStatus >= 200) {
 
digitalWrite(ledPin1, LOW);
digitalWrite(ledPin2, LOW);
digitalWrite(ledPin3, LOW);
digitalWrite(ledPin4, LOW);
digitalWrite(RELAY1, HIGH);
digitalWrite(RELAY2, HIGH);
digitalWrite(RELAY3, HIGH);
digitalWrite(RELAY4, HIGH);
 
 
} else {
 
 
 
if (hasObstacle1 == HIGH )
{
  digitalWrite(RELAY1, LOW);
  digitalWrite(ledPin1, HIGH);
}
else
{
  digitalWrite(RELAY1, HIGH);
  analogWrite(ledPin1, brightness);
}
 
if (hasObstacle2 == HIGH )
{
  digitalWrite(RELAY2, LOW);
}
else
{
  digitalWrite(RELAY2, HIGH);
}
 
hasObstacle1 = digitalRead(obstaclePin1);
  if (hasObstacle1 == HIGH) 
  {
    //Serial.println("Stop something is ahead!!");
    digitalWrite(RELAY1, LOW);
    digitalWrite(ledPin1, HIGH);
    
  }
  else
  {
    //Serial.println("Path is clear");
    digitalWrite(RELAY1, HIGH);
    //digitalWrite(ledPin1, LOW);
    analogWrite(ledPin1, brightness);
  }
  //delay(200);
  hasObstacle2 = digitalRead(obstaclePin2); 
  if (hasObstacle2 == HIGH) 
  {
    //Serial.println("Stop something is ahead!!");
    digitalWrite(RELAY2, LOW);
    digitalWrite(ledPin2, HIGH);
  }
  else
  {
    //Serial.println("Path is clear");
    digitalWrite(RELAY2, HIGH);
    analogWrite(ledPin2, brightness);
  }
  //delay(200);
  hasObstacle3 = digitalRead(obstaclePin3);
  if (hasObstacle3 == HIGH) 
  {
    //Serial.println("Stop something is ahead!!");
    digitalWrite(RELAY3, LOW);
    digitalWrite(ledPin3, HIGH);
  }
  else
  {
    //Serial.println("Path is clear");
    digitalWrite(RELAY3, HIGH);
    analogWrite(ledPin3, brightness);
  }
  //delay(200);
  hasObstacle4 = digitalRead(obstaclePin4);
  if (hasObstacle4 == HIGH) 
  {
    //Serial.println("Stop something is ahead!!");
    digitalWrite(RELAY4, LOW);
    digitalWrite(ledPin4, HIGH);
  }
  else
  {
    //Serial.println("Path is clear");
    digitalWrite(RELAY4, HIGH);
    analogWrite(ledPin4, brightness);
  }
  //delay(200);
}  
 
}
