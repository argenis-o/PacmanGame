#include "Ghost.h"
#include "EntityManager.h"
#include "Player.h"



Ghost::Ghost(int x, int y, int width, int height, ofImage spriteSheet, EntityManager *em, GHOSTNAMES name): Entity(x, y, width, height){
    this->sprite = spriteSheet;
    blueVulnerable.cropFrom(sprite,584,64,16,16);
    CyanVulnerable.cropFrom(sprite,616,64,16,16);
    // sprite.load("images/background.png");
    //sprite.cropFrom(spriteSheet,456,64,16,16);
    this->name = name;
    switch(name){
        case Blinky:
            down.cropFrom(sprite, 552, 64, 16, 16);
            up.cropFrom(sprite, 520, 64, 16, 16);
            left.cropFrom(sprite, 488, 64, 16, 16);
            right.cropFrom(sprite, 456, 64, 16, 16);
            break;
            
        
        case Pinky:
            down.cropFrom(sprite, 552, 80, 16, 16);
            up.cropFrom(sprite, 520, 80, 16, 16);
            left.cropFrom(sprite, 488, 80, 16, 16);
            right.cropFrom(sprite, 456, 80, 16, 16);
            break;

        case Clyde:
            down.cropFrom(sprite, 552, 96, 16, 16);
            up.cropFrom(sprite, 520, 96, 16, 16);
            left.cropFrom(sprite, 488, 96, 16, 16);
            right.cropFrom(sprite, 456, 96, 16, 16);
            break;
            

        case Inky:
            down.cropFrom(sprite, 552, 112, 16, 16);
            up.cropFrom(sprite, 520, 112, 16, 16);
            left.cropFrom(sprite, 488, 112, 16, 16);
            right.cropFrom(sprite, 456, 112, 16, 16);
            break;
            
    }
    
    /*down.cropFrom(sprite, 552, 64, 16, 16);
    up.cropFrom(sprite, 520, 64, 16, 16);
    left.cropFrom(sprite, 456, 64, 16, 16);
    right.cropFrom(sprite, 488, 64, 16, 16);
    setFacing(GHOSTUP);*/

   
    vector<ofImage> downAnimframes;
    vector<ofImage> upAnimframes;
    vector<ofImage> leftAnimframes;
    vector<ofImage> rightAnimframes;
    ofImage temp;
    for(int i=0; i<3; i++){
        downAnimframes.push_back(down);
    }
    for(int i=0; i<3; i++){
        upAnimframes.push_back(up);
    }
    for(int i=0; i<3; i++){
        leftAnimframes.push_back(left);
    }
    for(int i=0; i<3; i++){
        rightAnimframes.push_back(right);
    }
    walkDown = new Animation(1,downAnimframes);
    walkUp = new Animation(1,upAnimframes);
    walkLeft = new Animation(1,leftAnimframes);
    walkRight = new Animation(1,rightAnimframes);
    this->em = em;

    
    
}






void Ghost::tick(){
    canMove = true;
    checkGhostCollisions();
    if(canMove){
        if(facing == GHOSTUP){
            y-= speed;
            walkUp->tick();
        }
        
        else if(facing == GHOSTDOWN){
            y+=speed;
            walkDown->tick();
        }
        
        else if(facing == GHOSTLEFT){
            x-=speed;
            walkLeft->tick();
        }
        
        else if(facing == GHOSTRIGHT){
            x+=speed;
            walkRight->tick();
        }
    }

    else{
        if(facing == GHOSTUP){
            randomDir = ofRandom(0,3);
            switch(randomDir){
                case 0:
                    setFacing(GHOSTRIGHT);
                    break;
                case 1:
                    setFacing(GHOSTLEFT);
                    break;
                case 2:
                    setFacing(GHOSTUP);
                    break;
            }

        }

        else if(facing == GHOSTDOWN){
            randomDir = ofRandom(0,3);
            switch(randomDir){
                case 0:
                    setFacing(GHOSTRIGHT);
                    break;
                case 1:
                    setFacing(GHOSTLEFT);
                    break;
                case 2:
                    setFacing(GHOSTUP);
                    break;
            }

        }

        else if(facing == GHOSTRIGHT){
            randomDir = ofRandom(0,3);
            switch(randomDir){
                case 0:
                    setFacing(GHOSTDOWN);
                    break;
                case 1:
                    setFacing(GHOSTLEFT);
                    break;
                case 2:
                    setFacing(GHOSTUP);
                    break;
            }

        }


            else if(facing == GHOSTLEFT){
            randomDir = ofRandom(0,3);
            switch(randomDir){
                case 0:
                    setFacing(GHOSTDOWN);
                    break;
                case 1:
                    setFacing(GHOSTRIGHT);
                    break;
                case 2:
                    setFacing(GHOSTUP);
                    break;
            }

        }

    }


}






void Ghost::render(){
    ofSetColor(256,256,256);
    // ofDrawRectangle(getBounds());

    if(true){
        switch(name){
            case Blinky:
                setDirectionUp(blueVulnerable);
                setDirectionDown(CyanVulnerable);
                setDirectionRight(blueVulnerable);
                setDirectionLeft(CyanVulnerable);
                /*down.cropFrom(sprite, 552, 64, 16, 16);
                up.cropFrom(sprite, 520, 64, 16, 16);
                left.cropFrom(sprite, 488, 64, 16, 16);
                right.cropFrom(sprite, 456, 64, 16, 16);*/
                break;
            
        
            case Pinky:
                setDirectionUp(blueVulnerable);
                setDirectionDown(CyanVulnerable);
                setDirectionRight(blueVulnerable);
                setDirectionLeft(CyanVulnerable);
               /* down.cropFrom(sprite, 552, 80, 16, 16);
                up.cropFrom(sprite, 520, 80, 16, 16);
                left.cropFrom(sprite, 488, 80, 16, 16);
                right.cropFrom(sprite, 456, 80, 16, 16);
                break;*/

            case Clyde:

                setDirectionUp(blueVulnerable);
                setDirectionDown(CyanVulnerable);
                setDirectionRight(blueVulnerable);
                setDirectionLeft(CyanVulnerable);
                /*down.cropFrom(sprite, 552, 96, 16, 16);
                up.cropFrom(sprite, 520, 96, 16, 16);
                left.cropFrom(sprite, 488, 96, 16, 16);
                right.cropFrom(sprite, 456, 96, 16, 16);*/
                break;
                

            case Inky:

                setDirectionUp(blueVulnerable);
                setDirectionDown(CyanVulnerable);
                setDirectionRight(blueVulnerable);
                setDirectionLeft(CyanVulnerable);
                /*down.cropFrom(sprite, 552, 112, 16, 16);
                up.cropFrom(sprite, 520, 112, 16, 16);
                left.cropFrom(sprite, 488, 112, 16, 16);
                right.cropFrom(sprite, 456, 112, 16, 16);
                break;*/
                
        }
        
    }
    
    
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



