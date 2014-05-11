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


// ======================================================== Motion Sensor logic =================================================
boolean CheckMotion()
{
	if (digitalRead(MotionPin) == 1)
	{
		PrintText("Motion detected");
		return true;
	}

	PrintText("No motion detected");
	return false;
}