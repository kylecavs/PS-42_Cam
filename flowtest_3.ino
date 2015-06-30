
#include <Wire.h>

int lcd_key     = 0;
int adc_key_in  = 0;

byte sensorInterrupt = 0;
byte sensorPin = 2;

// The hall-effect flow sensor outputs approximately 4.5 (Closer to 7.5-7.6) pulses per second per litre/minute of flow.
float calibrationFactor = 7.55;

volatile byte pulseCount;

float flowRate;
unsigned int flowMilliLitres;
unsigned long totalMilliLitresA;
unsigned long totalMilliLitresB;

unsigned long oldTime;

void setup()
{
 
  Serial.begin(38400);
 
  pinMode(sensorPin, INPUT);
  digitalWrite(sensorPin, HIGH);

  pulseCount = 0;
  flowRate = 0.0;
  flowMilliLitres = 0;
  totalMilliLitresA = 0;
  totalMilliLitresB = 0;
  oldTime = 0;

  attachInterrupt(sensorInterrupt, pulseCounter, FALLING);
}

void loop()
{
   
    if((millis() - oldTime) > 1000)
  {

    detachInterrupt(sensorInterrupt);
   
    flowRate = ((1000.0 / (millis() - oldTime)) * pulseCount) / calibrationFactor;
    
    oldTime = millis();
    
    flowMilliLitres = (flowRate / 60) * 1000;
    
    totalMilliLitresA += flowMilliLitres;
    totalMilliLitresB += flowMilliLitres;
 
    unsigned int frac;
 
    Serial.print("Flow: ");
    if(int(flowRate) < 10)
    {
    Serial.print(" ");
    }
    Serial.print((int)flowRate);
    Serial.print('.');
    frac = (flowRate - int(flowRate)) * 10;
    Serial.println(frac, DEC) ;
    Serial.print("SPEED in/sec: ");
    Serial.println(.19*flowRate);

    


    pulseCount = 0;
    
    attachInterrupt(sensorInterrupt, pulseCounter, FALLING);
  }
}

void pulseCounter()
{
  pulseCount++;
}
