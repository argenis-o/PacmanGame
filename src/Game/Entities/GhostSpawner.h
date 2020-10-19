#pragma once
#include "Entity.h"
#include "Ghost.h"

class GhostSpawner: public Entity{
    private:

    public:
        GhostSpawner(int, int, int, int, ofImage);
        int count = 0;
        // int getCount(){return count;};
        // void sumCount();

};

