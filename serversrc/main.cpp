//
//  main.cpp
//  CFServer
//
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//
#include "CFServerMain.h"
int main(int argc, char *argv[])
{
    //start a new runner a server
    //Servers will auto to 127.0.0.1:1234 with 12 max clients, 2 channels,  and unlimited incoming and outgoing bandwidth 
    //you can define a custom one new Server("x.x.x.x", 80, 3, 2, 0, 0);
    //Server(std::string& address, int port, int maxClients, int numChannels, int incBandwidth, int outBandwidth);
    Runner(new Server());
    return 0;
}
