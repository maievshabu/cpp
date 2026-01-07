//
// Created by redredmaple on 2025/11/6.
//

#ifndef MAIEV_EVENT_H
#define MAIEV_EVENT_H
#include <iostream>
#include "Entity.h"

enum class EventType{
    Chat,
    Trade,
    Combat
};

class Event {
public:
    EventType eventType;
    Entity* initiator;
    Entity* receiver;

    virtual void execute() = 0;
    virtual ~Event() = default;
};

class ChatEvent : public Event{
public:
    ChatEvent(Entity* i, Entity* r){
        initiator = i;
        receiver = r;
        eventType = EventType::Chat;
    }
    void execute() override{
        std::cout << initiator->name << "chat with" << receiver->name << std::endl;
    }
};

class TradeEvent : public Event{
public:
    TradeEvent(Entity* i, Entity* r){
        initiator = i;
        receiver = r;
        eventType = EventType::Trade;
    }
    void execute() override{
        std::cout << initiator->name << "trade with" << receiver->name << std::endl;
    }
};

class CombatEvent : public Event{
public:
    CombatEvent(Entity* i, Entity* r){
        initiator = i;
        receiver = r;
        eventType = EventType::Combat;
    }
    void execute() override{
        std::cout << initiator->name << "combat with" << receiver->name << std::endl;
    }
};

#endif //MAIEV_EVENT_H
