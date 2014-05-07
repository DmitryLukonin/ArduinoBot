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
    randomSeed(micros());	
}

void ConfigureTriger(unsigned char TrigerId, unsigned long TrigerStopTime)
{
  currentMillis = millis();

  //if (DEBUG) {Serial.println("Configure triger");}

  switch (TrigerId)
  {
	  case 1:        
	  	TimerTriger1=GetStopTimeForTriger(TrigerStopTime);
		break;
	  case 2:        
		TimerTriger2=GetStopTimeForTriger(TrigerStopTime);
		break;
	  default:
		//if (DEBUG) {Serial.println("hmm");}
		break;
  }
}

unsigned long GetStopTimeForTriger(unsigned long TrigerStopTime)
{
	currentMillis = millis();
	if(currentMillis+TrigerStopTime+1000<4294967295)
	{
		return currentMillis+TrigerStopTime;
	}
	else
	{
		unsigned long differences =  (currentMillis+TrigerStopTime+1000)-4294967295;
		return TrigerStopTime-differences;
	}
}