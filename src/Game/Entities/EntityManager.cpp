#include "EntityManager.h"
#include "Ghost.h"

void EntityManager::tick(){
    std::vector<int> toRemove;
    for(int i = 0;i<entities.size();i++){
        if(!entities[i]->remove){
            entities[i]->tick();

        }
        
        else{
            toRemove.push_back(i);
        }
    }
    for(BlockEntity* block: blocks){
        block->tick();
    }
    for(unsigned int removable: toRemove){
        entities.erase(entities.begin() + removable);
    }
}

void EntityManager::render(){ // draw the ghosts first and then all other entities
    for(Entity* entity: entities){
        if(dynamic_cast<Ghost*>(entity) == NULL){
            entity->render();
        }
    }
    
    for(BlockEntity* block: blocks){
        block->render();
    }

    for(Entity* entity: entities){
        if(dynamic_cast<Ghost*>(entity) != NULL){
            entity->render();
        }
    }   
}