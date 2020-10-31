#pragma once
#include "EntityManager.h"
#include "Animation.h"
#include "Player.h"
#include "ofSoundPlayer.h"


enum GHOSTFACING {
    GHOSTUP,
    GHOSTDOWN,
    GHOSTLEFT,
    GHOSTRIGHT
};


enum GHOSTNAMES{
    Pinky,
    Blinky,
    Inky,
    Clyde
};


class Ghost: public Entity{
    private:
        GHOSTFACING facing = GHOSTUP;
        GHOSTNAMES name;
        bool canMove;
        ofImage up, down, left, right, blueVulnerable, CyanVulnerable;
        Animation *walkUp;
        Animation *walkDown;
        Animation *walkLeft;
        Animation *walkRight;
        Animation *blue;
        Animation *white;
        EntityManager* em;
        int speed = 4;
        //bool isEatable = false;
        bool isDead;
        
        
        
    
    public:
        Ghost(int, int, int, int, ofImage, EntityManager*, GHOSTNAMES);
        void tick();
        void render();
        void setFacing(GHOSTFACING facing);
        void setName(GHOSTNAMES name);
        void setDirectionUp(ofImage image){this->up = image;}
        void setDirectionDown(ofImage image){this->down = image;}
        void setDirectionRight(ofImage image){this->right = image;}
        void setDirectionLeft(ofImage image){this->left = image;}
        ofImage getBlueSkin(){return blueVulnerable;}
        ofImage getWhiteSkin(){return CyanVulnerable;}
        //bool getIsEatable(){return this->isEatable;}
        void setIsEatable(bool eatable){isDead = eatable;}
        void checkGhostCollisions();
        //void setisDead(bool vulnerable){isDead = vulnerable;}
        int randomDir;
        //ofSoundPlayer GhostsMovement;
        
        


        


};



