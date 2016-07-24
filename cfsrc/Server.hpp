//
//  Server.hpp
//  CFServer
//
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#ifndef Server_hpp
#define Server_hpp
#include "enet/enet.h"
#include <iostream>
class Server{

    ENetAddress serverAddress;
    int maxClients = 12;
    int incBandwidth = 0;
    int outBandwidth = 0;
    int numChannels = 2;
    ENetHost* host = 0;

    void createHost();
    public:
    //create a server with custom settings
    Server(std::string& address, int port, int maxClients, int numChannels, int incBandwidth, int outBandwidth);
    Server();
    ENetHost* getHost();

};
#endif /* CoreMain_h */
