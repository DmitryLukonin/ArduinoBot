// ======================================================== SC Play's logic =================================================

// Plays a full file from beginning to end with no pause.
void playcomplete(char *name) {
	playfile(name);
}

void playfile(char *name) {
    if (tmrpcm.isPlaying()==0) 
    {
      tmrpcm.stopPlayback();
    }
  
	tmrpcm.play(name);
	PrintText("Playing " + String(name));
   // tmrpcm.play("BENHILL.WAV"); 

    // ok time to play! start playback
	//PrintText("Playing: " + name);
	//wave.play();
}

void playFileNoPriority(char *name)
{
   if (tmrpcm.isPlaying()==0) 
   {
     playcomplete(name);
   }
}


void CheckAndPlayNextMusicInLine()
{
	unsigned int tempValue = musicCurrent+1;

	while (tempValue != musicCurrent)
	{
		if (tempValue > 9) tempValue = 0;

		if (MusicList[tempValue] != "")
		{
			playcomplete(MusicList[tempValue]);
			musicCurrent = tempValue;
			break;
		}


		tempValue++;
	}
}

void AddMusicToLine(char* name)
{
	unsigned int tempValue = musicCurrent + 1;

	while (tempValue != musicCurrent)
	{
		if (tempValue > 9) tempValue = 0;

		if (MusicList[tempValue] == "")
		{
			MusicList[tempValue] = name;
			break;
		}
		
		tempValue++;
	}
}