//======================================================== Brain logic =================================================

void BrainLoop()
{
	if(CheckLight()<SleepLimitValue)
	{    
		if(sleep==false) SleepStart(); 
	}
	else
	{  
		if(sleep==true) SleepEnd();    
		Brain();
	}
}


void Brain()
{    
    int distance = CheckDistance();
    if(distance<DistanceToBreakLimit)
    {
    
      if(distance<DistanceToBreakLimit/2)
      {
        PrintText("Danger! Something is really close!");
        BrainMovBre(true);
      }
      else
      {               
        PrintText("Something ahead");
        BrainMovBre(false);
      }
    }
    else
    {
	  PrintText("No breaks found");
      playFileNoPriority("BENHILL.wav");
      BrainMov();
    }
}

void BrainMov()
{
  int pattern=random(10);

  if(pattern<6)
  {
    MoveForvard();
  }  
  else if(pattern=6)
  {
    BrainMoveCarefullLeRight();
  }
  else if(pattern=7)
  {
    BrainMoveCarefullLeLeft();
  }
  else if(pattern=8)
  {
    MoveLeft();
  }
  else if(pattern=9)
  {
    MoveRight();
  }
  else
  {
    PrintText("Too tired... "); 
    MoveStop();
  }
}

void BrainMovBre(boolean danger)
{
  int pattern=random(6);
  if (danger) pattern = 0;


  if(pattern==0)
  {       
    MoveStop();
    PrintText("Analize situation");
    playcomplete("DROP.wav");
    BrainMovBreAnalize(false);
  }
  else if(pattern==1)
  {
    MoveLeft();
  }
  else if(pattern==2)
  {
    MoveRight();
  }
  else if(pattern==3)
  {
    BrainMovBreTurn();
  }
  else if(pattern>3)
  {
    MoveForvard();
  }
}

void BrainMoveCarefullLeLeft()
{
	MoveForvard();
  DistanceLeft = HeadPingL();
  Rest(100);

  if(DistanceLeft>DistanceToBreakLimit)  
  {
    MoveLeft();
  }
}

void BrainMoveCarefullLeRight()
{
	MoveForvard();
  DistanceRight = HeadPingR();
  Rest(100);

  if(DistanceRight>DistanceToBreakLimit)  
  {
    MoveRight();
  }
}

void BrainMovBreAnalize(boolean enclosed)
{
  DistanceFront = HeadPingF();
  Rest(100);

  DistanceLeft = HeadPingL();
  Rest(100);

  DistanceRight = HeadPingR();
  Rest(100);  

  MoveStop();
  
  //PrintText("Free distance ahead: " + String(DistanceFront) + ", left: " + String(DistanceLeft) + ", right: " + String(DistanceRight));
  
  if(DistanceFront==0 || DistanceLeft==0 || DistanceRight==0)  
  {
    if(DistanceFront==DistanceLeft && DistanceLeft==DistanceRight)
    {
      PrintText("I'm blind!");
      detectorWorks=false;
      return;
    }
    else
    {
      if(DistanceFront==0) DistanceFront==9999;
      if(DistanceLeft==0) DistanceLeft==9999;
      if(DistanceRight==0) DistanceRight==9999;
    }
  }


  if(DistanceFront>=DistanceLeft && DistanceFront>=DistanceRight && DistanceFront>=10)
  {
    MoveForvard();
  }
  else if(DistanceLeft>=DistanceFront && DistanceLeft>=DistanceRight && DistanceLeft>=10)
  {
    MoveLeft();     
  }
  else if(DistanceRight>=DistanceFront && DistanceRight>=DistanceLeft && DistanceRight>=10)
  {
    MoveRight();
  }
  else
  {
    priorityMoving=true;
    MoveBack();
    delay(50);
    MoveBack();
    //Serial.println("Closed? Try to go back...");
    BrainMovBreAnalize(true);
  }
  
  HeadMoveF();
}



void BrainMovBreTurn()
{
  priorityMoving=true;
  //Serial.println("Full Turn!");
  if(random(1)==1)
  {
    MoveFullTurnLeft();
  }
  else
  {
    MoveFullTurnRight();
  }
}

