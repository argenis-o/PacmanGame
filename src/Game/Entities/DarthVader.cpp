#include "DarthVader.h"

DarthVader::DarthVader(int x,int y,int width,int height, ofImage sprite, EntityManager* em):Entity(x,y,width,height){
    // DarthVaderImage.load("images/DarthVader.png");
    // DarthVaderImage.draw(0,200,16,16);
    this->DarthVaderImage = sprite;
    this->em = em;
    // this->x = 0;
    // this->y = 225;
    // this->width = 32;
    // this->height = 32;
    //159,87
    Vader.cropFrom(sprite, 315, 238, 75, 123);
    
}

void DarthVader::render(){
    if(timer < 3600){
        timer++;
    }
    else{surprise = true;}
    if(surprise){
        Vader.draw(x,y,width,height);
    }
    if(surprise){
        if(ForceTimer < 360){
            ForceTimer++;
        }
        else{
            ForceTimer = 0;
            randomAttack = 2;//ofRandom(0,4)
            if(randomAttack == 2){forceChoke = true;}
        }
    }
    if(surprise){
        if(darkTimer<360){
            darkTimer++;
        }
        else{
            darkTimer = 0;
            randomAttack = 2;
             if(randomAttack == 2){feelThePowerOfTheDarkside = true;}
        }
    }

}