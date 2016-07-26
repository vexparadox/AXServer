//
//  myController.hpp
//  CFServer
//
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#ifndef myController_hpp
#define myController_hpp
#include "CFServerMain.h"
class myController : public Controller{
    public:
    myController(){};
    void setup();
    void takeInput(std::string s);
};
#endif