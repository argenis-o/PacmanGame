#include "MapBuilder.h"


MapBuilder::MapBuilder(){
	entityManager = new EntityManager();
	pixelMultiplier = 16;
	boundBlock = ofColor(0,0,0);
	pacman = ofColor(255,255, 0);
	ghostC = ofColor(25, 255,0);
	dotC = ofColor(255, 10, 0);
	bigDotC = ofColor(167, 0, 150);
	powerups = ofColor(63,72,204);
	BossC = ofColor(195,195,195);
	pacmanSpriteSheet.load("images/Background.png");
	Darth.load("images/DarthVader.png");
	tempBound.cropFrom(pacmanSpriteSheet, 603,18,16,16);
	bound.push_back(tempBound);//single
	tempBound.cropFrom(pacmanSpriteSheet, 615,37,16,16);
	bound.push_back(tempBound);//single
	tempBound.cropFrom(pacmanSpriteSheet, 635,37,16,16);
	bound.push_back(tempBound);//single
	tempBound.cropFrom(pacmanSpriteSheet, 655,37,16,16);
	bound.push_back(tempBound);//single
	tempBound.cropFrom(pacmanSpriteSheet, 655,57,16,16);
	bound.push_back(tempBound);//single
	tempBound.cropFrom(pacmanSpriteSheet, 655,75,16,16);
	bound.push_back(tempBound);//single
	tempBound.cropFrom(pacmanSpriteSheet, 656,116,16,16);
	bound.push_back(tempBound);//single
	tempBound.cropFrom(pacmanSpriteSheet, 656,136,16,16);
	bound.push_back(tempBound);//single
	tempBound.cropFrom(pacmanSpriteSheet, 655,174,16,16);
	bound.push_back(tempBound);//single
	tempBound.cropFrom(pacmanSpriteSheet, 655,155,16,16);
	bound.push_back(tempBound);//single
	tempBound.cropFrom(pacmanSpriteSheet, 655,192,16,16);
	bound.push_back(tempBound);//single
	tempBound.cropFrom(pacmanSpriteSheet, 664,232,16,16);
	bound.push_back(tempBound);//single
	tempBound.cropFrom(pacmanSpriteSheet, 479,191,16,16);
	bound.push_back(tempBound);//single
	tempBound.cropFrom(pacmanSpriteSheet, 494,191,16,16);
	bound.push_back(tempBound);//single
	tempBound.cropFrom(pacmanSpriteSheet, 479,208,16,16);
	bound.push_back(tempBound);//single
	tempBound.cropFrom(pacmanSpriteSheet, 479,223,16,16);
	bound.push_back(tempBound);//single
}

Map* MapBuilder::createMap(ofImage mapImage){
	int xOffset = (ofGetWidth() - mapImage.getWidth()*pixelMultiplier)/2;
	int yOffset = (ofGetHeight() - mapImage.getHeight()*pixelMultiplier)/2;

	ofPixels pixels = mapImage.getPixels();
	Map* mapInCreation =  new Map(entityManager);
	mapInCreation->EntityReset();
    for (int i = 0; i < mapImage.getWidth(); i++) {
        for (int j = 0; j < mapImage.getHeight(); j++) {
            ofColor currentPixel = pixels.getColor(i, j);
            int xPos = i*pixelMultiplier + xOffset;
            int yPos = j*pixelMultiplier + yOffset;
            if(currentPixel == boundBlock){
                BlockEntity* BoundBlock = new BlockEntity(xPos,yPos,pixelMultiplier,pixelMultiplier,getSprite(mapImage,i,j));
                mapInCreation->addBlockEntity(BoundBlock);
            }
			
			else if(currentPixel == pacman){
                Player* PacMan = new Player(xPos,yPos,pixelMultiplier,pixelMultiplier, entityManager);
				mapInCreation->setPlayer(PacMan);
				// PowerupSpawner* Powerup = new PowerupSpawner(xPos, yPos,pixelMultiplier, pixelMultiplier, pacmanSpriteSheet, entityManager);
				// mapInCreation->setPowerups(Powerup);
				// DarthVader * SithLord = new DarthVader(xPos, yPos, pixelMultiplier, pixelMultiplier, Darth, entityManager);
            }
			
			else if(currentPixel == ghostC){
				GhostSpawner* ghost = new GhostSpawner(xPos,yPos,pixelMultiplier,pixelMultiplier,pacmanSpriteSheet,entityManager);
				mapInCreation->setSpawner(ghost);

            }
			
			else if(currentPixel == dotC){
                Dot* dot = new Dot(xPos,yPos,pixelMultiplier,pixelMultiplier, pacmanSpriteSheet);
                mapInCreation->addEntity(dot);
            }
			
			else if(currentPixel == bigDotC){
                BigDot* bigDot = new BigDot(xPos,yPos,pixelMultiplier,pixelMultiplier, pacmanSpriteSheet);
                mapInCreation->addEntity(bigDot);
            }

			else if(currentPixel == powerups){
				PowerupSpawner* Powerup = new PowerupSpawner(xPos, yPos,pixelMultiplier, pixelMultiplier, pacmanSpriteSheet, entityManager);
				mapInCreation->setPowerups(Powerup);

			}
			else if(currentPixel == BossC){
				DarthVader * SithLord = new DarthVader(xPos, yPos, 141, 141, Darth, entityManager);
				mapInCreation->addEntity(SithLord);
			}

			
        }

    }
    return mapInCreation;

}

ofImage MapBuilder::getSprite(ofImage mapImage, int i, int j){
	ofColor currentPixel = boundBlock;
	ofPixels pixels = mapImage.getPixels();
	ofColor leftPixel;
	ofColor rightPixel;
	ofColor upPixel;
	ofColor downPixel;
	if (i>0) {
		leftPixel = pixels.getColor(i - 1, j);
	}else{
		leftPixel = pacman;

	}
	if (i<mapImage.getWidth()-1) {
		rightPixel = pixels.getColor(i + 1, j);
	}else{
		rightPixel= pacman;

	}
	if (j>0) {
		upPixel = pixels.getColor(i, j - 1);
	}else{
		upPixel = pacman;

	}
	if (j<mapImage.getHeight()-1) {
		downPixel = pixels.getColor(i, j + 1);
	}else{
		downPixel = pacman;

	}

	if (currentPixel != leftPixel && currentPixel != upPixel && currentPixel != downPixel && currentPixel == rightPixel){

		return bound[1];
	}else if (currentPixel != leftPixel && currentPixel != upPixel && currentPixel == downPixel && currentPixel != rightPixel){

		return bound[2];
	}else if (currentPixel == leftPixel && currentPixel != upPixel && currentPixel != downPixel && currentPixel != rightPixel){

		return bound[3];
	}else if (currentPixel != leftPixel && currentPixel == upPixel && currentPixel != downPixel && currentPixel != rightPixel){

		return bound[4];
	}else if (currentPixel != leftPixel && currentPixel == upPixel && currentPixel == downPixel && currentPixel != rightPixel){

		return bound[5];
	}else if (currentPixel == leftPixel && currentPixel != upPixel && currentPixel != downPixel && currentPixel == rightPixel){

		return bound[6];
	}else if (currentPixel != leftPixel && currentPixel == upPixel && currentPixel != downPixel && currentPixel == rightPixel){

		return bound[7];
	}else if (currentPixel == leftPixel && currentPixel == upPixel && currentPixel != downPixel && currentPixel != rightPixel){

		return bound[8];
	}else if (currentPixel != leftPixel && currentPixel != upPixel && currentPixel == downPixel && currentPixel == rightPixel){

		return bound[9];
	}else if (currentPixel == leftPixel && currentPixel != upPixel && currentPixel == downPixel && currentPixel != rightPixel){

		return bound[10];
	}else if (currentPixel == leftPixel && currentPixel == upPixel && currentPixel == downPixel && currentPixel == rightPixel){

		return  bound[11];
	}else if (currentPixel != leftPixel && currentPixel == upPixel && currentPixel == downPixel && currentPixel == rightPixel){

		return bound[12];
	}else if (currentPixel == leftPixel && currentPixel == upPixel && currentPixel == downPixel && currentPixel != rightPixel){

		return bound[13];
	}else if (currentPixel == leftPixel && currentPixel != upPixel && currentPixel == downPixel && currentPixel == rightPixel){

		return bound[14];
	}else if (currentPixel == leftPixel && currentPixel == upPixel && currentPixel != downPixel && currentPixel == rightPixel){

		return bound[15];
	}else{

		return  bound[0];
	}
}