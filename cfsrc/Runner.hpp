//
//  Runner.hpp
//  CFServer
//
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#ifndef Runner_hpp
#define Runner_hpp
#include "Server.hpp"
#include <iostream>
class Runner{
    Server* server = 0;
    public:
    Runner(Server* s);
    
};
#endif
