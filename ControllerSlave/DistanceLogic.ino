// ======================================================== Distance's logic =================================================

int CheckDistance()
{
  long distance=0;
  unsigned char x=0;
  bool toobig=0;

  for (unsigned char i=0; i <= HeadTrigersCount; i++)
  {
    long tempDist=PingDistance();                   

    if (tempDist<3000 && tempDist>0)
    {
      distance=distance+tempDist;
      x++;
      toobig=false;                        
    }
    else
    {
      toobig=true;
    }

    delay(1);
  }

  int averegeDistance = distance/x;    

  if (DEBUG) 
  {
    Serial.print("Ping distance: ");
    Serial.println(averegeDistance);
  }

  return averegeDistance;      
}

long PingDistance()
{
  digitalWrite(TRIGPIN, LOW);                   // Set the trigger pin to low for 2uS
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);                  // Send a 10uS high to trigger ranging
  delayMicroseconds(5);
  digitalWrite(TRIGPIN, LOW);                   // Send pin low again
  return microsecondsToCentimeters(pulseIn(ECHOPIN, HIGH));
}

int microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
} 
