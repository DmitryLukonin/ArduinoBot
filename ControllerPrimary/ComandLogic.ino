void BotOnPauseOnOff()
{
			if(BotPause==true)
			{
				BotPause=false;
			}
			else
			{
				BotPause=true;
			}
}


void EnableWifiModeOnOff()
{
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

void EnableBrainModeOnOff()
{
			if(controlType==1)			// if auto mode
			{							// disable auto and do wifi(if enabled) and ir only 
				controlType=2;
			}
			else
			{							// else do auto mode
				controlType=1; 
			}
}

void MusicVolumeIncrease()
{
	tmrpcm.volume(1); 
}

void MusicVolumeDecrease()
{
	tmrpcm.volume(0); 
}

void MusicOnOff()
{
	if(MusicOn==true)
	{
		tmrpcm.disable();
		MusicOn=false;
	}
	else
	{
		configureMusic();
		MusicOn=true;
	}
}
