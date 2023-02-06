#define sensorPower 7
#define sensorPin A0
#include <Servo.h>

Servo X;
int x = 0;
int xHigh = 160;
int xLow = 20;
int serX = 0;

Servo Y;
int y = 0;
int yHigh = 160;
int yLow = 20;
int serY = 0;

void setup() {
  pinMode(sensorPower, OUTPUT);
  digitalWrite(sensorPower, LOW);

  X.attach(10);
  X.write(0);

  X.attach(11);
  X.write(0);
  
  Serial.begin(9600);
  delay(500);
}

void loop() {
  
  Serial.print("Analog output: ");
  Serial.println(readSensor());

  x = X.read();
  y = Y.read();

  Serial.println(x);
  Serial.println(y);
  
  int R00 = analogRead(0);
  int R01 = analogRead(1);
  int R10 = analogRead(2);
  int R11 = analogRead(3);

Serial.println(R00);
Serial.println(R01);
Serial.println(R10);
Serial.println(R11);
  
  int avgt = (R00+R01)/2;
  int avgb = (R10+R11)/2;
  int avgr = (R01+R11)/2;
  int avgl = (R00+R10)/2;

Serial.println(avgt);
Serial.println(avgb);
Serial.println(avgr);
Serial.println(avgl);

  if(avgt>avgb)
  {
    serX = x+1;  
    X.write(serX);
    if(x>xHigh)
    {
      x = xHigh;
    }
    delay(10);
  }
  else if(avgt<avgb)
  {
    serX = x-1;
    X.write(serX);
    if(x<xLow)
    {
      x = xLow;
    }
    delay(10);
  }
  else
  {
    X.write(x);
  }

  if(avgr>avgl)
  { 
    serY = y+1;
    Y.write(serY);
    if(y>yHigh)
    {
      y = yHigh;
    }
    delay(10);
  }
  else if(avgr<avgl)
  { 
    serY = y-1;
    Y.write(serY);
    if(y<yLow)
    {
      y = yLow;
    }
    delay(10);
  }
  else
  {
    Y.write(y);
  }

  delay(50);

  Serial.println(" ");
}


int readSensor() {
  digitalWrite(sensorPower, HIGH);  
  delay(10);              
  int val = analogRead(sensorPin);  
  digitalWrite(sensorPower, LOW);   
  return val;             
}

# Coded with ❤️ by sagooon: Github
