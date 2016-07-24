//
//  Server.hpp
//  CFServer
//
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#ifndef Server_hpp
#define Server_hpp
#include "enet/enet.h"
#include <string>
class Server{
    ENetAddress serverAddress;
    public:
    Server(std::string& address, int port);
    Server();

};
#endif /* CoreMain_h */
