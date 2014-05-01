// ======================================================== SC Play's logic =================================================

// Plays a full file from beginning to end with no pause.
void playcomplete(char *name) {
  // call our helper to find and play this name
  playfile(name);
}

void playfile(char *name) {

  // see if the wave object is currently doing something
   if (tmrpcm.isPlaying()==0) 
   {
     tmrpcm.stopPlayback();
   }
  
   //tmrpcm.play("BENHILL.WAV"); 

  // ok time to play! start playback
//  Serial.print("Playing: ");
//  Serial.println(name);
//  wave.play();
}

void playFileNoPriority(char *name)
{
   if (tmrpcm.isPlaying()==0) 
   {
     playcomplete(name);
   }
}
