#pragma once
#include "Entity.h"
#include "Ghost.h"

class GhostSpawner: public Entity{
    private:

    public:
        GhostSpawner(int, int, int, int, ofImage, EntityManager* entityManager);
        EntityManager* entityManager;
        void tick();
        void keyPressed(int);
        bool viewGhostCount();
        int randomColor;
        int gCount = 0; // counts how many ghosts are active on the map
        int timer = 0;

        

};

