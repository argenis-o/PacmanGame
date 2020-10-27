#pragma once
#include "Player.h"
#include "GhostSpawner.h"

class Map{
    public:
      Map(EntityManager*);
      void addBlockEntity(BlockEntity*);
      void addEntity(Entity*);
      void setPlayer(Player*);
      void setSpawner(GhostSpawner*);
      void tick();
      void render();
      void keyPressed(int key);
		  void mousePressed(int x, int y, int button);
		  void keyReleased(int key);

      
      int getHealth();

      void setHealth();

      void EntityReset();

      void ResetMap();

    private:
      EntityManager *entityManager;
      Player *player;
      GhostSpawner *ghost;
};