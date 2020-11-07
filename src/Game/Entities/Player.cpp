#include "Player.h"
#include "EntityManager.h"
#include "Dot.h"
#include "BigDot.h"
#include "SoundEffects.h"
#include "Ghost.h"
#include "GhostSpawner.h"
#include "Powerups.h"



Player::Player(int x, int y, int width, int height, EntityManager* em) : Entity(x, y, width, height){

    ghostdie = false;
    sprite.load("images/pacman.png");
    setSpeed(0);
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
    vector<ofImage> deadAnimation;
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
    if(ghostdie){
        if(timer<150){
            status = "InVulnerable"; // this means that the ghosts are in their vulnerable state, they can be eaten 
            timer++;
        }
        else{
            ghostdie = false;
            status = "Vulnerable";
            timer = 0;
        }
    }


    canMove = true;
    checkCollisions();
    if(canMove){
        if(facing == UP){
            y-= speed;
            walkUp->tick();
        }
        
        else if(facing == DOWN){
            y+=speed;
            walkDown->tick();
        }
        
        else if(facing == LEFT){
            x-=speed;
            walkLeft->tick();
        }
        
        else if(facing == RIGHT){
            x+=speed;
            walkRight->tick();
        }
    }
}

void Player::render(){
    ofSetColor(256,256,256);
    if(facing == UP){
        walkUp->getCurrentFrame().draw(x, y, width, height);
        
    }
    
    else if(facing == DOWN){
        walkDown->getCurrentFrame().draw(x, y, width, height);
    }
    
    else if(facing == LEFT){
        walkLeft->getCurrentFrame().draw(x, y, width, height);
    }
    
    else if(facing == RIGHT){
        walkRight->getCurrentFrame().draw(x, y, width, height);
    }
    
    ofDrawBitmapString("Score: "+to_string(this->getScore()),  0, 35); // display this info on screen
    ofDrawBitmapString("Lives : ", 0, 65);
    ofDrawBitmapString("Status: "+status, 0, 120);
    
    gapX = 55;
    for(int i=0;i < health; i++){
        livesIcon.draw(gapX, 55, 20, 20);
        gapX += 10;
    }
    
    if (oneupScore == 225){ // gain an extra life 
        oneup();
        oneupScore = 0;
    }
    
}

void Player::keyPressed(int key){
    switch(key){
        case 'w':
            setFacing(UP);
            setSpeed(2); // default speed is 2 so that the sound works appropietly. Can be changed to 4
            break;
        case 's':
            setFacing(DOWN);
            setSpeed(2);
            break;
        case 'a':
            setFacing(LEFT);
            setSpeed(2);
            break;
        case 'd':
            setFacing(RIGHT);
            setSpeed(2);
            break;
        case 'n':
            die();
            break;
        case 'm':
            oneup();
            break;
        
    }
}

void Player::keyReleased(int key){ //TODO: Add more key options for the movement
    if(key == 'w' || key =='s' || key == 'a' || key == 'd'){
        setSpeed(0);
        //canMove = false;
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
            if(dynamic_cast<Dot*>(entity)){ //PacMan eats a normal dot
                entity->remove = true;
                PacManEatsDots = SoundEffects::soundManager("PacManSoundEffects/PacManEatsDots2.mp3");
                score += 10;                
                oneupScore += 1;

            }
            else if(dynamic_cast<BigDot*>(entity)){ //PacMan eats a Big Dot
                entity->remove = true;
                PacManEatsDots = SoundEffects::soundManager("PacManSoundEffects/PacManEatsDots2.mp3");
                PacManEatsBigDot = SoundEffects::soundManager("PacManSoundEffects/PacManGhostsVulnerable.mp3");
                score +=50;
                oneupScore += 5;
                ghostdie = true; // Ghosts are vulnerable 
                timer = 0;
            }

            else if(dynamic_cast<Ghost*>(entity)){ // PacMan can eat Ghosts 
                if(ghostdie){
                    PacManEatsGhost = SoundEffects::soundManager("PacManSoundEffects/pacManEatsGhost.mp3");
                    entity->remove = true; // remove the Ghosts from the map 
                    score += 200;
                }
                if(!ghostdie){
                    die();
                }
                
            }
            else if(dynamic_cast<Powerups*>(entity)){ // PacMan eats a fruit 
                entity->remove = true;
                score += 500;
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
    if(score > highScore && health == 0){
        highScore = score;
    }
}

void Player::oneup(){
    if(health >=6){
        return;
    }
    
    health ++;
    PacManOneUp = SoundEffects::soundManager("PacManSoundEffects/PacManExtraLife.mp3");
}










