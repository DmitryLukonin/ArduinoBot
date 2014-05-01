//======================================================== System logic =================================================

void CheckTrigers()
{
  currentMillis = millis();
  if(TimerTriger1==0 && TimerTriger2==0) return;

  if(currentMillis>TimerTriger1 && TimerTriger1>0)
  {
    HeadMoving(HeadForward);
    TimerTriger1=0;
  }
  
  if(currentMillis>TimerTriger2 && TimerTriger2>0)
  {
    MoveStop();
    TimerTriger2=0;
  }
}

void ConfigureRnd()
{
  //if (DEBUG) {Serial.print("Setup distance: "); Serial.println(temp);}
    randomSeed(micros());	
  //if (DEBUG) {Serial.println("Setup is done");}

}

void ConfigureTriger(unsigned char TrigerId, unsigned long TrigerStopTime)
{
  currentMillis = millis();

  //if (DEBUG) {Serial.println("Configure triger");}

  switch (TrigerId)
  {
  case 1:        
    if(currentMillis+TrigerStopTime+1000<4294967295)
    {
      TimerTriger1=currentMillis+TrigerStopTime;
    }
    else
    {
      unsigned long differences =  (currentMillis+TrigerStopTime+1000)-4294967295;
      TimerTriger1=TrigerStopTime-differences;
    }
    break;
  case 2:        
    if(currentMillis+TrigerStopTime+1000<4294967295)
    {
      TimerTriger2=currentMillis+TrigerStopTime;
    }
    else
    {
      unsigned long differences =  (currentMillis+TrigerStopTime+1000)-4294967295;
      TimerTriger2=TrigerStopTime-differences;
    }
    break;
  default:
    //if (DEBUG) {Serial.println("hmm");}
    break;
  }
}
