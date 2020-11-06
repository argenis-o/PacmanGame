#pragma once
#include "EntityManager.h"
#include "Animation.h"
#include "Player.h"
#include "ofSoundPlayer.h"

class DarthVader:public Entity{ 

    private:
        bool forceChoke=false;
        bool feelThePowerOfTheDarkside=false;
        //bool lackoFaith=false;
        bool surprise = false;
    
        

    public: 
        DarthVader(int ,int ,int,int, ofImage, EntityManager*em);
        EntityManager*em;
        ofImage DarthVaderImage, Vader;
        bool getForceChoke(){return forceChoke;}
        bool getFeelThePowerOfTheDarkSide(){return feelThePowerOfTheDarkside;}
        // bool getLackOfFaith(){return lackoFaith;}
        void setForceChoke(bool isChoke){forceChoke = isChoke;}
        void setFeelThePowerOfTheDarkSide(bool Power){feelThePowerOfTheDarkside = Power;}
        // void setLackOfFaith(bool faith){lackoFaith = faith;}
        void tick();
        void render();
        void PlayMusic();

        int timer = 0;
        int ForceTimer = 0;
        int darkTimer = 0;
        int randomAttack;
        ofSoundPlayer DarthVaderIntro;
        ofSoundPlayer DarthVaderMessage;
        ofSoundPlayer ImperialMarch;
};