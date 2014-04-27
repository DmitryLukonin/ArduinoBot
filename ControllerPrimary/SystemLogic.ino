//======================================================== System logic =================================================


void Rest(int time)
{
	if(time>99 && controlType>0)
	{
		FindAndExecuteCommandFromWifi();
	}
	delay(time-99);
}

void ConfigureRnd()
{
	randomSeed(micros());	
}

void CleanSerial()
{
    while (Serial1.available() > 0) 
    {
      oldSerialData = Serial1.read(); 
    }
   
    if(Serial1.available() > 0) 
    {
      Serial.println("Data on serial!");
    }
}

boolean FindAndExecuteCommandFromWifi()
{
  
  Serial.print("Looking for the command... ");
	String response = ReadDataFromWifi();
	if(response.length()==0) return false;
	
	String command = GetCommandFromString(response);
	if(command.length()==0) return false;
	Serial.println(command);
	
	boolean result = ExecuteCommandFromWifi(command);
	return result;
	
}

String GetCommandFromString(String workZone)
{
	int firstWorkZone = workZone.indexOf(',Cm');
	int endWorkZone = workZone.indexOf(',Ty');
	return workZone.substring(firstWorkZone+5,endWorkZone-4);
}


boolean ExecuteCommandFromWifi(String command)
{

        if (Compare("HeadLight", command)==0) {
          HeadLight();
        }
        else if (Compare("HeadPing", command)==0) {
			HeadPing();
        }
        else if (Compare("HeadPingF", command)==0) {
			HeadPingF();
        }
        else if (Compare("HeadPingR", command)==0) {
			HeadPingR();
        }
        else if (Compare("HeadPingL", command)==0) {
			HeadPingL();
        }      
        else if (Compare("MoveForvard", command)==0) {
			MoveForvard();
        }  
        else if (Compare("MoveBack", command)==0) {
			MoveBack();
        }  
        else if (Compare("MoveRight", command)==0) {
			MoveRight();
        }  
        else if (Compare("MoveLeft", command)==0) {
			MoveLeft();
        } 
        else if (Compare("MoveRightTurn", command)==0) {
			MoveRightTurn();
        }
        else if (Compare("MoveLeftTurn", command)==0) {
			MoveLeftTurn();
        }
        else if (Compare("HeadMoveR", command)==0) {
			MoveFullTurnLeft();
        }
        else if (Compare("HeadMoveL", command)==0) {
			MoveFullTurnRight();
        }
        else if (Compare("MoveStop", command)==0) {
			MoveStop();
        }
        else if (Compare("HeadMoveF", command)==0) {
			HeadMoveF();
        } 
        else if (Compare("HeadPingR", command)==0) {
			HeadMoveR();
        }         
        else if (Compare("HeadPingL", command)==0) {
			HeadMoveL();
        } 
		else
		{
			return false;
		}
		return true;
}

char Compare(char* This, String command)
{             
         char inData[20]; 
         command.toCharArray(inData,20);
                  if (strcmp(inData,This)  == 0) 
                  {
                    return(0);
                  }
                  else 
                  {
                    return(1);
                  }     
}




