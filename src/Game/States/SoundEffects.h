#pragma once
#include "ofSoundPlayer.h"
#include "ofMain.h"

// This class has the job of handling the music
class SoundEffects{
    SoundEffects(){};

    public:
      static ofSoundPlayer soundManager(string SoundPath); // this method receives a string representing the path for the song, it loades it and play its.
  



};