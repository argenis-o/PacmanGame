#pragma once
#include "EntityManager.h"
#include "Animation.h"

enum GHOSTFACING {
    GHOSTUP,
    GHOSTDOWN,
    GHOSTLEFT,
    GHOSTRIGHT
};


class Ghost: public Entity{
    private:
        GHOSTFACING facing = GHOSTUP;
        bool canMove;
        ofImage up, down, left, right;
        Animation *walkUp;
        Animation *walkDown;
        Animation *walkLeft;
        Animation *walkRight;
        EntityManager* em;
        int speed = 4;
        bool isEatable;
        bool isDead;
        
        
    
    public:
        Ghost(int, int, int, int, ofImage, EntityManager*);
        void tick();
        void render();
        void setFacing(GHOSTFACING facing);
        void checkGhostCollisions();
        int randomDir;
        


        


};



