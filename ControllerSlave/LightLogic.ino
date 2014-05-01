// ======================================================== Light logic =================================================

int CheckLight() {
  sensorValue = analogRead(sensorPin);
  if (DEBUG) 
  {
    Serial.print("Test light: ");
    Serial.println(sensorValue);
  }
  
  return sensorValue;
}
