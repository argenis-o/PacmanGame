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
        int oneupScore = 0;
        bool canMove;
        int speed = 4;
        bool walking = false;
        FACING facing = DOWN;
        ofImage up, down, left, right;
        Animation *walkUp;
        Animation *walkDown;
        Animation *walkLeft;
        Animation *walkRight;
        EntityManager* em;

    public:
        Player(int, int, int , int, EntityManager*);
        int getHealth();
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

        bool BeginningHealth = true;
        vector <int> lives;
        int gapX;

        
        ofImage livesIcon;
        ofSoundPlayer PacManEatsDots;


};