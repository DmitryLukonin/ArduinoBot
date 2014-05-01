//======================================================== Sleep logic =================================================
void SleepStart()
{
  
  PrintText("It's dark outside... will go to sleep");
  
  MoveStop();
  priorityMoving=false;
  sleep=true;   
  playFileNoPriority("crystal.wav");  
  
}

void SleepEnd()
{
   
  PrintText("Sunny! Walk, walk!");
  
  sleep=false;
  playcomplete("DROP.wav");  
}
