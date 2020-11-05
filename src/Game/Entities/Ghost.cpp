#include "Ghost.h"
#include "EntityManager.h"
#include "Player.h"
#include "SoundEffects.h"





Ghost::Ghost(int x, int y, int width, int height, ofImage spriteSheet, EntityManager *em, GHOSTNAMES name): Entity(x, y, width, height){
    this->sprite = spriteSheet;
    blueVulnerable.cropFrom(sprite,584,64,16,16);
    CyanVulnerable.cropFrom(sprite,616,64,16,16);
    isDead = false;
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
    vector<ofImage> blueAnimframes;
    vector<ofImage> whiteAnimframes;
    
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

    blueAnimframes.push_back(blueVulnerable);
    whiteAnimframes.push_back(CyanVulnerable);
    
    
    walkDown = new Animation(1,downAnimframes);
    walkUp = new Animation(1,upAnimframes);
    walkLeft = new Animation(1,leftAnimframes);
    walkRight = new Animation(1,rightAnimframes);
    blue = new Animation(1,blueAnimframes);
    white = new Animation(1, whiteAnimframes);
    this->em = em;

    
    
}






void Ghost::tick(){
    canMove = true;
    checkGhostCollisions();
    if(canMove){
        if(facing == GHOSTUP){
            y-= speed;
            checkSurroundingUP.push_back(GHOSTLEFT);
            checkSurroundingUP.push_back(GHOSTRIGHT);
            checkSurroundingUP.push_back(GHOSTUP);
            
            if(isDead){
                blue->tick();
                white->tick();
            }
        }
        
        else if(facing == GHOSTDOWN){
            y+=speed;
            checkSurroundingDOWN.push_back(GHOSTLEFT);
            checkSurroundingDOWN.push_back(GHOSTRIGHT);
            checkSurroundingDOWN.push_back(GHOSTDOWN);
           

            if(isDead){
                blue->tick();
                white->tick();
            }
        }
        
        else if(facing == GHOSTLEFT){
            x-=speed;
            checkSurroundingLEFT.push_back(GHOSTDOWN);
            checkSurroundingLEFT.push_back(GHOSTUP);
            checkSurroundingLEFT.push_back(GHOSTRIGHT);

            if(isDead){
                blue->tick();
                white->tick();
            }
        }
        
        else if(facing == GHOSTRIGHT){
            x+=speed;
            checkSurroundingRIGHT.push_back(GHOSTDOWN);
            checkSurroundingRIGHT.push_back(GHOSTUP);
            checkSurroundingRIGHT.push_back(GHOSTLEFT);
            if(isDead){
                blue->tick();
                white->tick();
            }
        }
    }

    else{
        if(facing == GHOSTUP){
            setFacing(checkSurroundingUP[int(ofRandom(checkSurroundingUP.size()-1))]);

        }

        else if(facing == GHOSTDOWN){
            setFacing(checkSurroundingDOWN[int(ofRandom(checkSurroundingDOWN.size()-1))]);
            

        }

        else if(facing == GHOSTRIGHT){
            setFacing(checkSurroundingRIGHT[int(ofRandom(checkSurroundingRIGHT.size()-1))]);

        }


        else if(facing == GHOSTLEFT){
            setFacing(checkSurroundingLEFT[int(ofRandom(checkSurroundingLEFT.size()-1))]);

        }

    }


}






void Ghost::render(){
    ofSetColor(256,256,256);
    // ofDrawRectangle(getBounds())
    if(facing == GHOSTUP){
        if(isDead){
            if(deadTU<30){
                deadTU++;
                blue->getCurrentFrame().draw(x,y,width,height);
            }
            else if(deadTU<60){
                deadTU++;
                white->getCurrentFrame().draw(x,y,width,height);     
            }
            else{deadTU = 0;}
        }
        
        else{
            walkUp->getCurrentFrame().draw(x, y, width, height);
        }
        
    }
    
    else if(facing == GHOSTDOWN){
        //walkDown->getCurrentFrame().draw(x, y, width, height);
        if(isDead){
            if(deadTD<30){
                deadTD++;
                blue->getCurrentFrame().draw(x,y,width,height);
            }
            else if(deadTD<60){
                deadTD++;
                white->getCurrentFrame().draw(x,y,width,height);     
            }
            else{deadTD = 0;}
        }

        else{
            walkDown->getCurrentFrame().draw(x, y, width, height);
        }
        
    }
    
    else if(facing == GHOSTLEFT){
        //walkLeft->getCurrentFrame().draw(x, y, width, height);
        if(isDead){
            if(deadTL<30){
                deadTL;
                blue->getCurrentFrame().draw(x,y,width,height);
            }
            else if(deadTL<60){
                deadTL++;
                white->getCurrentFrame().draw(x,y,width,height);     
            }
            else{deadTL = 0;}
        }

        else{
            walkLeft->getCurrentFrame().draw(x, y, width, height);
        }
    }
    
    else if(facing == GHOSTRIGHT){

        //walkRight->getCurrentFrame().draw(x, y, width, height);
        if(isDead){
            if(deadTR<30){
                deadTR++;
                blue->getCurrentFrame().draw(x,y,width,height);
            }
            else if(deadTR<60){
                deadTR++;
                white->getCurrentFrame().draw(x,y,width,height);     
            }
            else{deadTR = 0;}
        }

        else{
            walkRight->getCurrentFrame().draw(x, y, width, height);
        }

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







