#pragma once
#include "Player.h"
#include "GhostSpawner.h"
#include "PowerupSpawner.h"

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


      int HighScore;

      int getHighScore();

      bool dotC = true;

      int getDotCount(){return dotCount;};

      int dotCount = 0;

      int timer = 0;

      void setPowerups(PowerupSpawner*);


    private:
      EntityManager *entityManager;
      Player *player;
      GhostSpawner *ghost;
      PowerupSpawner *power;
};