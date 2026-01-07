//
// Created by redredmaple on 2025/11/6.
//

#ifndef MAIEV_SPATIALTRIGGERSYSTEM_H
#define MAIEV_SPATIALTRIGGERSYSTEM_H
#include "Entity.h"
#include "Event.h"
#include <vector>
#include <memory>


class SpatialTriggerSystem{
public:
    float triggerRadius = 1.0f;

    std::vector<std::shared_ptr<Event>> detectEvent(const std::vector<std::shared_ptr<Entity>>& entities){
        std::vector<std::shared_ptr<Event>> events;
        for(auto &a: entities){
            for(auto &b : entities){
                if (a == b) continue;
                if (isCharacter(a) && isNpc(b)){
                    if (a->position.distanceTo(b->position) < triggerRadius){
                        events.push_back(std::make_shared<ChatEvent>(a.get(), b.get()));
                    }
                }
            }
        }
    }
private:
    bool isCharacter(const std::shared_ptr<Entity>& e){
        return dynamic_cast<Role*>(e.get()) != nullptr;
    }

    bool isNpc(const std::shared_ptr<Entity>& e){
        return dynamic_cast<Npc*>(e.get()) != nullptr;
    }
};

#endif //MAIEV_SPATIALTRIGGERSYSTEM_H
