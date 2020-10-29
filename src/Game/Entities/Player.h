#pragma once
#include "Animation.h"

#include "EntityManager.h"
#include "ofSoundPlayer.h"
#include "SoundEffects.h"

enum FACING {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Player: public Entity{

    private:
    
        int health = 3;
        int score = 0;
        int highScore = 0;
        int oneupScore = 0;
        bool canMove;
        int speed;
        bool walking = false;
        FACING facing = DOWN;
        ofImage up, down, left, right;
        Animation *walkUp;
        Animation *walkDown;
        Animation *walkLeft;
        Animation *walkRight;
        EntityManager* em;
        int spawnX, spawnY;

    public:
        Player(int, int, int , int, EntityManager*);
        int getHealth(){return health;};
        int getScore(){return score;};
        void tick();
        void render();
        void keyPressed(int);
        void keyReleased(int);
        void damage(Entity* damageSource);
        void mousePressed(int, int, int);
        void reset();
        void setFacing(FACING facing);
        void checkCollisions();

        void StartingH();
        void die();
        void oneup();
        void setCoordX(){this->x = spawnX;};
        void setCoordY(){this->y = spawnY;};
        void setSpeed(int speed){this->speed = speed;};
        int getHighScore(){return highScore;}

        void ResetPlayer();
        //static bool getGhostDie();
        //static void setGhostDie(bool isVulneable);


        bool BeginningHealth = true;
        vector <int> lives;
        int gapX;
        int timer = 0;
        string status = "Vulnerable";
         bool ghostdie;
        
        void setHealth(int h){this->health = h;};

        
        ofImage livesIcon;
        ofImage ghost;
        ofSoundPlayer PacManEatsDots;
        ofSoundPlayer PacManDies;
        ofSoundPlayer PacManEatsBigDot;
        ofSoundPlayer PacManOneUp;
        ofSoundPlayer PacManEatsGhost;

};
