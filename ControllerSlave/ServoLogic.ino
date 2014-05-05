// ======================================================== Servo logic =================================================

void HeadMoving(int value)
{
  if(HeadCurrent!=value)
  {
    if(HeadCurrent<value)
    {
      for (int i=HeadCurrent; i <= value; i++){
        Head.write(i); 
        delay(5);
      } 
    }
    else
    {
      for (int i=HeadCurrent; i >= value; i--){
        Head.write(i); 
        delay(5);
      } 
    }      
  }   
  HeadCurrent=value; 
  
  if(value!=90) 
  {
    ConfigureTriger(1,5000);
  }
}
