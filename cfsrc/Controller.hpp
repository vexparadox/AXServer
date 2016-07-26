//
//  Controller.hpp
//  CFServer
//
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#ifndef Controller_hpp
#define Controller_hpp
class Controller{
    public:
    Controller();
    virtual void clientConnected(){};
    virtual void clientDisconnected(){};
    virtual void packetRecieve(){};
    virtual void takeInput(std::string s){};
};
#endif