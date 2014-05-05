void TestHeadMoving()
{
  Serial.println("Test head moving");
  HeadMoving(90); 
  TestHeadPing();
  CheckLight();
  delay(20); 
  HeadMoving(40);
  TestHeadPing();
  CheckLight();
  delay(20);  
  HeadMoving(140); 
  TestHeadPing();
  CheckLight();
  delay(20); 
  HeadMoving(90); 
  TestHeadPing();
  CheckLight();
  delay(20); 

  delay(100); 
}
 
 
void TestHeadPing()
{
  int distance = CheckDistance();
  Serial.println(distance);
  delay(100); 
}