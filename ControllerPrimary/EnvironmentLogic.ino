// ======================================================== Light logic =================================================

int CheckLight() {
  int sensorValue = HeadLight();
  return sensorValue;
}

// ======================================================== Distance's logic =================================================

int CheckDistance()
{
  return HeadPing();
}