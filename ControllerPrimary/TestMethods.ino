void Test()
{
  TestMusic();
  delay(2000);  
  TestHeadMoving();
  delay(2000);  
  TestEngine();
  delay(2000); 
  TestLight();
  delay(2000); 
  TestPing();
  delay(2000); 
  TestPingWithAction();
  delay(2000); 
}

void TestMusic()
{
     playcomplete("START.wav");
     delay(2000); 
}

void TestLight()
{
     delay(ServiceTimerFast); 
     Serial.print("HeadLight:");
     Serial.println(HeadLight());
}

void TestPing()
{
     delay(ServiceTimerFast);      
     Serial.print("HeadPingF: ");         
     Serial.println(HeadPingF());
}

void TestPingWithAction()
{
     delay(ServiceTimerFast);      
     Serial.print("HeadPingF: ");         
     Serial.println(HeadPingF());
     
     delay(ServiceTimerFast); 
     Serial.print("HeadPingR:");
     Serial.println(HeadPingR());
     
     delay(ServiceTimerFast); 
     Serial.print("HeadPingL:");
     Serial.println(HeadPingL());
}

void TestEngine()
{
     delay(ServiceTimerSlow); 
     Serial.println("MoveForvard");
     MoveForvard();
     
     delay(ServiceTimerSlow); 
     Serial.println("MoveBack");
     MoveBack();
    
     delay(ServiceTimerSlow); 
     Serial.println("MoveRight");
     MoveRight();
     
     delay(ServiceTimerSlow); 
     Serial.println("MoveLeft");
     MoveLeft();
     
     delay(ServiceTimerSlow); 
     Serial.println("MoveRightTurn");
     MoveRightTurn();
     
     delay(ServiceTimerSlow);           
     Serial.println("MoveLeftTurn");
     MoveLeftTurn();
     
     delay(ServiceTimerSlow); 
     Serial.println("MoveFullTurnLeft");
     MoveFullTurnLeft();
     
     delay(ServiceTimerSlow); 
     Serial.println("MoveFullTurnRight");
     MoveFullTurnRight();
     
     delay(ServiceTimerSlow); 
     Serial.println("MoveStop");
     MoveStop();
}

void TestHeadMoving()
{
     delay(ServiceTimerFast); 
     Serial.println("HeadMoveF");
     HeadMoveF();
     
     delay(ServiceTimerFast); 
     Serial.println("HeadMoveR");
     HeadMoveR();
     
     delay(ServiceTimerFast); 
     Serial.println("HeadMoveL");
     HeadMoveL();
}
