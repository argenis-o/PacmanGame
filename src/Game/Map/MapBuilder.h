#pragma once
#include "ofMain.h" 
#include "Map.h"
#include "Dot.h"
#include "BigDot.h"
#include "Ghost.h"
#include "GhostSpawner.h"
#include "DarthVader.h"

class MapBuilder {
    public:
        MapBuilder();
	Map* createMap(ofImage);
        int xCount=0;

	private:
        vector<ofImage> bound;
        int pixelMultiplier;
        ofColor boundBlock;
        ofColor pacman;
        ofColor ghostC;
	ofColor dotC;
	ofColor bigDotC;
        ofColor powerups;
        ofColor BossC;
        ofImage pacmanSpriteSheet;
        ofImage tempBound;
        ofImage Darth;
        ofImage getSprite(ofImage, int, int);
        EntityManager* entityManager;
        
};