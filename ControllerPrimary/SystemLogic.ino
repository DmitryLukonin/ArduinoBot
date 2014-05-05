//======================================================== System logic =================================================

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

String FindCommandFromWifi()
{
    Serial.print("Looking for the command... ");

	String response = ReadDataFromWifi();
	if(response.length()==0) return false;
	
	String command = GetCommandFromString(response);
	if(command.length()==0) return false;

	return command;
}


String GetCommandFromString(String workZone)
{
	int firstWorkZone = workZone.indexOf(',Cm');
	int endWorkZone = workZone.indexOf(',Ty');
	return workZone.substring(firstWorkZone+5,endWorkZone-4);
}


String FindCommandFromIr(unsigned long command)
{
	if (command == IrCommandGoPause)  return "BotOnPause";
	if (command == IrCommandChM)  return "";
	if (command == IrCommandChP)  return "";
	if (command == IrCommandEq)  return "HeadLight";
	if (command == IrCommandVolM)  return "VolumeD";
	if (command == IrCommandVolP)  return "VolumeI";
	if (command == IrCommand0)  return "HeadPing";
	if (command == IrCommandPrev)  return "HeadPingL";
	if (command == IrCommandNext)  return "HeadPingR";
	if (command == IrCommand1)  return "";
	if (command == IrCommand2)  return "MoveForvard";
	if (command == IrCommand3)  return "";
	if (command == IrCommand4)  return "MoveLeft";
	if (command == IrCommand5)  return "MoveStop";
	if (command == IrCommand6)  return "MoveRight";
	if (command == IrCommand7)  return "";
	if (command == IrCommand8)  return "MoveBack";
	if (command == IrCommand9)  return "";
	if (command == IrCommandPS)  return "EnableWifi";
	if (command == IrCommandChSet)  return "EnableBrain";

	return "";
}



boolean ExecuteCommand(String command)
{
	PrintText(command);
	if(command.length()==0) return false;

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
		else if (Compare("BotOnPause", command)==0) {
			if(BotPause==true)
			{
				BotPause=false;
			}
			else
			{
				BotPause=true;
			}
        } 
		else if (Compare("EnableWifi", command)==0) {
			if(WifiEnabled==true)		// if wifi enabled
			{							// then disable wifi and do manual mode
				WifiEnabled=false;
				client.stop();
				controlType=3;
			}
			else
			{							// else enable wifi and do wifi only
				WifiEnabled=true;
				ConnectToWifi();
				ConnectToSite();
				controlType=2; 
			}
        }	
		else if (Compare("EnableBrain", command)==0) {
			if(controlType==1)			// if auto mode
			{							// disable auto and do ir only 
				controlType=3;
			}
			else
			{							// else do auto mode
				controlType=1; 
			}
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


void PrintText(String text)
{
	if(DEBUG>0) 
	{
		Serial.println(text);
		if(DEBUG>1 && WifiEnabled) {
			sendResponse(text); 
		}
	}	        
}