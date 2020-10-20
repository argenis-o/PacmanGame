#include "Ghost.h"
#include "EntityManager.h"


Ghost::Ghost(int x, int y, int width, int height, ofImage spriteSheet, EntityManager *em): Entity(x, y, width, height){
    sprite.load("images/background.png");
    //sprite.cropFrom(spriteSheet,456,64,16,16);
    down.cropFrom(sprite, 552, 64, 16, 16);
    up.cropFrom(sprite, 520, 64, 16, 16);
    left.cropFrom(sprite, 456, 64, 16, 16);
    right.cropFrom(sprite, 488, 64, 16, 16);
    setFacing(GHOSTUP);

   
    vector<ofImage> downAnimframes;
    vector<ofImage> upAnimframes;
    vector<ofImage> leftAnimframes;
    vector<ofImage> rightAnimframes;
    ofImage temp;
    for(int i=0; i<3; i++){
        temp.cropFrom(sprite, 552, 64, 16, 16);
        downAnimframes.push_back(temp);
    }
    for(int i=0; i<3; i++){
        temp.cropFrom(sprite, 520, 64, 16, 16);
        upAnimframes.push_back(temp);
    }
    for(int i=0; i<3; i++){
        temp.cropFrom(sprite, 456, 64, 16, 16);
        leftAnimframes.push_back(temp);
    }
    for(int i=0; i<3; i++){
        temp.cropFrom(sprite, 488, 64, 16, 16);
        rightAnimframes.push_back(temp);
    }
    walkDown = new Animation(1,downAnimframes);
    walkUp = new Animation(1,upAnimframes);
    walkLeft = new Animation(1,leftAnimframes);
    walkRight = new Animation(1,rightAnimframes);
    this->em = em;

    
    
}



void Ghost::tick(){  //Basic Idea
    canMove = true;
    checkGhostCollisions();
    if(canMove){
        if(facing == GHOSTUP){
            y-= speed;
            walkUp->tick();
        }else if(facing == GHOSTDOWN){
            y+=speed;
            walkDown->tick();
        }else if(facing == GHOSTLEFT){
            x-=speed;
            walkLeft->tick();
        }else if(facing == GHOSTRIGHT){
            x+=speed;
            walkRight->tick();
        }
    }

   
}  


void Ghost::render(){
    ofSetColor(256,256,256);
    // ofDrawRectangle(getBounds());
    if(facing == GHOSTUP){
        walkUp->getCurrentFrame().draw(x, y, width, height);
        
    }
    
    else if(facing == GHOSTDOWN){
        walkDown->getCurrentFrame().draw(x, y, width, height);
    }
    
    else if(facing == GHOSTLEFT){
        walkLeft->getCurrentFrame().draw(x, y, width, height);
    }
    
    else if(facing == GHOSTRIGHT){
        walkRight->getCurrentFrame().draw(x, y, width, height);
    }

}
  






void Ghost::setFacing(GHOSTFACING facing){
    this->facing = facing;
}


void Ghost::checkGhostCollisions(){
    for(BlockEntity* block: em->blocks){
        switch(facing){
            case GHOSTUP:
                if(this->getBounds(x, y-speed).intersects(block->getBounds())){
                    canMove = false;
                }
                break;
            case GHOSTDOWN:
                if(this->getBounds(x, y+speed).intersects(block->getBounds())){
                    canMove = false;
                }
                break;
            case GHOSTLEFT:
                if(this->getBounds(x-speed, y).intersects(block->getBounds())){
                    canMove = false;
                }
                break;
            case GHOSTRIGHT:
                if(this->getBounds(x+speed, y).intersects(block->getBounds())){
                    canMove = false;
                }
                break;
        }
    }

}



