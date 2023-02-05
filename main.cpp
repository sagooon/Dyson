#include <Servo.h>

Servo X;
int x = 0;
int xHigh = 0;
int xLow = 0;

Servo Y;
int y = 0;
int yHigh = 0;
int yLow = 0;

void setup()
{
  X.attach(0);
  X.write(0);

  X.attach(0);
  X.write(0);

  delay(0);
}

void loop()
{
  x = X.read();
  y = y.read();
  
  int R00 = analogRead(0);
  int R01 = analogRead(0);
  int R10 = analogRead(0);
  int R11 = analogRead(0);

  int avgt = ()/2;
  int avgb = ()/2;
  int avgr = ()/2;
  int avgl = ()/2;

  if(avgt>avgb)
  {
    X.write(x+1);
    if(x>xHigh)
    {
      x = xHigh;
    }
  }
  else if(avgt<avgb)
  {
    X.write(x-1);
    if(x<xLow)
    {
      x = xLow;
    }
  }
  else
  {
    servo.write(x);
  }

  if(avgr>avgl)
  {
    Y.write(y+1);
    if(y>yHigh)
    {
      y = yHigh;
    }
  }
  else if(avgr<avgl)
  {
    Y.write(y-1);
    if(y<yLow)
    {
      y = yLow;
    }
  }
  else
  {
    servo.write(y);
  }

  delay(0);

}

# Coded with ❤️ by sagooon: Github
