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
        bool isDead;

        bool invisable = false;
        
        
        
    
    public:
        Ghost(int, int, int, int, ofImage, EntityManager*, GHOSTNAMES);
        void tick();
        void render();
        void setFacing(GHOSTFACING facing);
        void setName(GHOSTNAMES name);

        ofImage getBlueSkin(){return blueVulnerable;}
        ofImage getWhiteSkin(){return CyanVulnerable;}
        void setIsEatable(bool eatable){isDead = eatable;}
        void checkGhostCollisions();

        void setInvisable(bool f){invisable = f;};

        int randomDir;


        int deadTU =0, deadTD =0, deadTL = 0, deadTR = 0;

        
        
        


        


};



