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
  
    //tmrpcm.play("BENHILL.WAV"); 

    // ok time to play! start playback
	PrintText("Playing: " + name);
	wave.play();
}

void playFileNoPriority(char *name)
{
   if (tmrpcm.isPlaying()==0) 
   {
     playcomplete(name);
   }
}
