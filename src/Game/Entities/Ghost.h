#pragma once
#include "EntityManager.h"
#include "Animation.h"
#include "Player.h"

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
        EntityManager* em;
        int speed = 4;
        static bool isEatable;
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
        bool getIsEatable(){return this->isEatable;}
        static void setIsEatable(bool eatable);


        void checkGhostCollisions();
        int randomDir;
        


        


};



