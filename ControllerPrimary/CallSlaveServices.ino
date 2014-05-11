int HeadLight()
{
  CleanSerial();
  Serial1.println(";HeadLight;");
  int value = Serial1.parseInt();
  PrintText("Light: " + String(value));
  return value;
}
int HeadPing()
{
  CleanSerial();
  Serial1.println(";HeadPing;");
  int value = Serial1.parseInt();
  PrintText("Distance: " + String(value));
  return value;
}
int HeadPingF()
{
  CleanSerial();
  Serial1.println(";HeadPingF;");
  int value = Serial1.parseInt();
  PrintText("Distance ahead: " + String(value));
  return value;
}
int HeadPingR()
{
  CleanSerial();
  Serial1.println(";HeadPingR;");
  int value = Serial1.parseInt();
  PrintText("Distance right: " + String(value));
  return value;
}
int HeadPingL()
{
  CleanSerial();
  Serial1.println(";HeadPingL;");
  int value = Serial1.parseInt();
  PrintText("Distance left: " + String(value));
  return value;
}
void MoveForvard(){  
	Serial1.println(";MoveForvard;");
	PrintText("Go forward.");
	playFileNoPriority("BENHILL.WAV");
}
void MoveBack(){ 
	Serial1.println(";MoveBack;");
	PrintText("Go back...");
	playFileNoPriority("BENHILL.WAV");
}
void MoveRight(){  
	Serial1.println(";MoveRight;"); 
	PrintText("Carefully go to the right");
	playFileNoPriority("BENHILL.WAV");
}
void MoveLeft(){  
	Serial1.println(";MoveLeft;"); 
	PrintText("Carefully go to the left");
	playFileNoPriority("BENHILL.WAV");
}
void MoveRightTurn(){  
	Serial1.println(";MoveRightTurn;"); 
	PrintText("Turning right");
	playFileNoPriority("BENHILL.WAV");
}
void MoveLeftTurn(){  
	Serial1.println(";MoveLeftTurn;"); 
	PrintText("Turning left");
	playFileNoPriority("BENHILL.WAV");
}
void MoveFullTurnLeft(){  
	Serial1.println(";MoveFullTurnLeft;"); 
	PrintText("U turn left");
	playFileNoPriority("BENHILL.WAV");
}
void MoveFullTurnRight(){  
	Serial1.println(";MoveFullTurnRight;"); 
	PrintText("U turn right");
	playFileNoPriority("BENHILL.WAV");
}
void MoveStop(){  
	Serial1.println(";MoveStop;");
	PrintText("Stop!");
	tmrpcm.stopPlayback();
}
void HeadMoveF(){  
	Serial1.println(";HeadMoveF;"); 
	PrintText("Head directs forward");
	playFileNoPriority("BENHILL.WAV");
}
void HeadMoveR(){  
	Serial1.println(";HeadMoveR;"); 
	PrintText("Head directs to the right");
	playFileNoPriority("BENHILL.WAV");
}
void HeadMoveL(){  
	Serial1.println(";HeadMoveL;");
	PrintText("Head directs to the left");
	playFileNoPriority("BENHILL.WAV");
}
