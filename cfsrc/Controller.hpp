//
//  Controller.hpp
//  CFServer
//
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#ifndef Controller_hpp
#define Controller_hpp
#include "enet/enet.h"
#include <iostream>
class Runner;
class Controller{
    public:
    Controller(){};
    Runner* runner = 0;
    virtual void setup(){};
    virtual void clientConnected(const ENetEvent& e){};
    virtual void clientDisconnected(const ENetEvent& e){};
    virtual void packetRecieve(const ENetEvent& e){};
    virtual void takeInput(std::string s){};
};
#endif