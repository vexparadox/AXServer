//
//  Runner.hpp
//  CFServer
//
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#ifndef Runner_hpp
#define Runner_hpp
#include "Server.hpp"
#include "Controller.hpp"
#include <atomic>
#include <thread>
#include <iostream>
class Runner{
    Server* server = 0;
    Controller* controller = 0;
    std::atomic<bool> run;
    void takeInput();
    public:
    Runner(Server* s, Controller* c);
    ~Runner();
    void stopServer();
};
#endif
