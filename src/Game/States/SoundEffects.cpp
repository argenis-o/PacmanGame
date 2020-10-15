#include "SoundEffects.h"

 ofSoundPlayer SoundEffects::soundManager(string SoundPath){
    ofSoundPlayer SoundEffect;
    SoundEffect.load(SoundPath);
    SoundEffect.setVolume(0.6);
    //SoundEffect.play();
    return SoundEffect;
    
}
