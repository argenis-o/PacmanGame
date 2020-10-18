#include "Player.h"
#include "EntityManager.h"
#include "Dot.h"
#include "BigDot.h"
#include "SoundEffects.h"
#include "Ghost.h"
#include "GhostSpawner.h"



Player::Player(int x, int y, int width, int height, EntityManager* em) : Entity(x, y, width, height){
    sprite.load("images/pacman.png");
    spawnX = this->x;
    spawnY = this->y;
    down.cropFrom(sprite, 0, 48, 16, 16);
    up.cropFrom(sprite, 0, 32, 16, 16);
    left.cropFrom(sprite, 0, 16, 16, 16);
    right.cropFrom(sprite, 0, 0, 16, 16);

    livesIcon.load("images/deadbody_amongus.png");
    
    vector<ofImage> downAnimframes;
    vector<ofImage> upAnimframes;
    vector<ofImage> leftAnimframes;
    vector<ofImage> rightAnimframes;
    ofImage temp;
    for(int i=0; i<3; i++){
        temp.cropFrom(sprite, i*16, 48, 16, 16);
        downAnimframes.push_back(temp);
    }
    for(int i=0; i<3; i++){
        temp.cropFrom(sprite, i*16, 32, 16, 16);
        upAnimframes.push_back(temp);
    }
    for(int i=0; i<3; i++){
        temp.cropFrom(sprite, i*16, 16, 16, 16);
        leftAnimframes.push_back(temp);
    }
    for(int i=0; i<3; i++){
        temp.cropFrom(sprite, i*16, 0, 16, 16);
        rightAnimframes.push_back(temp);
    }
    walkDown = new Animation(1,downAnimframes);
    walkUp = new Animation(1,upAnimframes);
    walkLeft = new Animation(1,leftAnimframes);
    walkRight = new Animation(1,rightAnimframes);

    this->em = em;
    
}

void Player::tick(){
    canMove = true;
    checkCollisions();
    if(canMove){
        if(facing == UP){
            y-= speed;
            walkUp->tick();
        }else if(facing == DOWN){
            y+=speed;
            walkDown->tick();
        }else if(facing == LEFT){
            x-=speed;
            walkLeft->tick();
        }else if(facing == RIGHT){
            x+=speed;
            walkRight->tick();
        }
    }
}

void Player::render(){
    ofSetColor(256,256,256);
    // ofDrawRectangle(getBounds());
    if(facing == UP){
        walkUp->getCurrentFrame().draw(x, y, width, height);
        
    }else if(facing == DOWN){
        walkDown->getCurrentFrame().draw(x, y, width, height);
    }else if(facing == LEFT){
        walkLeft->getCurrentFrame().draw(x, y, width, height);
    }else if(facing == RIGHT){
        walkRight->getCurrentFrame().draw(x, y, width, height);
    }ofDrawBitmapString("Score: "+to_string(this->getScore()),  0, 35);
    ofDrawBitmapString("Lives : ", 0, 65);
    gapX = 55;
    for(int i=0;i < health; i++){
        livesIcon.draw(gapX, 55, 20, 20);
        gapX += 10;
    }
    
    if (oneupScore == 225){
        oneup();
        oneupScore = 0;
    }
    
}

void Player::keyPressed(int key){
    switch(key){
        case 'w':
            setFacing(UP);
            break;
        case 's':
            setFacing(DOWN);
            break;
        case 'a':
            setFacing(LEFT);
            break;
        case 'd':
            setFacing(RIGHT);
            break;
        case 'n':
            die();
            break;
        case 'm':
            oneup();
            break;
        
    }
}

void Player::keyReleased(int key){
    if(key == 'w' || key =='s' || key == 'a' || key == 'd'){
        walking = false;
    }
}
void Player::mousePressed(int x, int y, int button){

}

void Player::setFacing(FACING facing){
    this->facing = facing;
}

void Player::checkCollisions(){
    for(BlockEntity* block: em->blocks){
        switch(facing){
            case UP:
                if(this->getBounds(x, y-speed).intersects(block->getBounds())){
                    canMove = false;
                }
                break;
            case DOWN:
                if(this->getBounds(x, y+speed).intersects(block->getBounds())){
                    canMove = false;
                }
                break;
            case LEFT:
                if(this->getBounds(x-speed, y).intersects(block->getBounds())){
                    canMove = false;
                }
                break;
            case RIGHT:
                if(this->getBounds(x+speed, y).intersects(block->getBounds())){
                    canMove = false;
                }
                break;
        }
    }
    for(Entity* entity:em->entities){
        if(collides(entity)){
            if(dynamic_cast<Dot*>(entity)){
                entity->remove = true;
                PacManEatsDots = SoundEffects::soundManager("PacManSoundEffects/PacManEatsDots2.mp3");
                score += 10;                
                oneupScore += 1;

            }
            else if(dynamic_cast<BigDot*>(entity)){
                entity->remove = true;
                PacManEatsDots = SoundEffects::soundManager("PacManSoundEffects/PacManEatsDots2.mp3");
                score +=50;
                oneupScore += 5;
            }

            else if(dynamic_cast<GhostSpawner*>(entity)){

                die();
                //this->remove = true;
                //this->setCoordX();
                //this->setCoordY();

            }
        }
    }
    
}

void Player::die(){
    if(health == 0){
        
        PacManDies = SoundEffects::soundManager("PacManSoundEffects/PacManDies.mp3");
        
        
        return;
    }
    
    PacManDies = SoundEffects::soundManager("PacManSoundEffects/PacManDies.mp3");
    this->remove = true;
    this->setCoordX();
    this->setCoordY();
    health --;
}

void Player::oneup(){
    if(health >=6){
        return;
    }
    health ++;
}

