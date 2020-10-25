#pragma once
#include "Entity.h"
#include "Ghost.h"

class GhostSpawner: public Entity{
    private:

    public:
        GhostSpawner(int, int, int, int, ofImage, EntityManager* entityManager);
        //void tick();
        EntityManager* entityManager;

};

