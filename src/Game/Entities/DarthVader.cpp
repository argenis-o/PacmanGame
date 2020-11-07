#include "DarthVader.h"
#include "SoundEffects.h"

DarthVader::DarthVader(int x,int y,int width,int height, ofImage sprite, EntityManager* em):Entity(x,y,width,height){
    DarthVaderImage.load("images/DarthVader.png");

    
    this->DarthVaderImage = sprite;
    this->em = em;
    Vader.cropFrom(sprite, 315, 238, 75, 123);
    
}




void DarthVader::tick(){
    
     
   if(timer < 3000){ // this timer is for the music to play after the timer reaches aprox 3 minutes.
       timer++;
   }

   else{
       PlayMusic(); 
       timer = 0;
       
       
       
   }

}

void DarthVader::render(){
    if(timer < 3000){ //draw Darth Vader after the timer reaches its goal, approx 3 minutes.
        timer++;
    }
    else{
       
        surprise = true;
    
    }
    
    if(surprise){   

        Vader.draw(x,y,width,height);
    }
    
    if(surprise){ // from this line onwards, we tried to make the abilities for Darth Vader, but we did not finished it
        if(ForceTimer < 360){
            ForceTimer++;
        }
        else{
            ForceTimer = 0;
            randomAttack = 2;//ofRandom(0,4)
            if(randomAttack == 2){forceChoke = true;}
        }
    }
    if(surprise){
        if(darkTimer<360){
            darkTimer++;
        }
        else{
            darkTimer = 0;
            randomAttack = 2;
             if(randomAttack == 2){feelThePowerOfTheDarkside = true;} // we plan to finish this on the future
        }
    }

}


void DarthVader::PlayMusic(){

    DarthVaderMessage = SoundEffects::soundManager("PacManSoundEffects/DarhVaderVoiceLine.mp3");
    ImperialMarch = SoundEffects::soundManager("PacManSoundEffects/ImperialMarch.mp3");
    
    
}