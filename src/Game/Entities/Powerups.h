//Powerups.h
#pragma once
#include "EntityManager.h"
#include "Animation.h"
#include "Player.h"
#include "ofSoundPlayer.h"

enum POWER{
    CHERRY
};


class Powerups: public Entity{

    private:
        POWER current;
        ofImage power, cherry;
        EntityManager* em;

    public:
        Powerups(int, int, int, int, ofImage, EntityManager* em, POWER);

        void render();

        void setPower(POWER current){this->current = current;}

        bool spawn = false;

        


};