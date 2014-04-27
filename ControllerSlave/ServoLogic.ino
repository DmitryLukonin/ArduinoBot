    // ======================================================== Servo logic =================================================

void HeadMoving(int value)
{

  if(HeadCurrent!=value)
  {
    if(HeadCurrent<value)
    {
      for (int i=HeadCurrent; i <= value; i++){
        Head.write(i); 
        SoftwareServo::refresh();
        delay(10);
      } 
    }
    else
    {
      for (int i=HeadCurrent; i >= value; i--){
        Head.write(i); 
        SoftwareServo::refresh(); 
        delay(10);
      } 
    }      
  }   
  SoftwareServo::refresh();
  HeadCurrent=value; 
  
  if(value!=90) 
  {
    ConfigureTriger(1,5000);
  }
}
