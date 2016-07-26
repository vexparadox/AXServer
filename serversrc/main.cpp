//
//  main.cpp
//  CFServer
//
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//
#include "CFServerMain.h"
#include "myController.hpp"
int main(int argc, char *argv[])
{
    //start a new runner a server
    //Servers will auto to 127.0.0.1:1234 with 12 max clients, 2 channels,  and unlimited incoming and outgoing bandwidth 
    //you can define a custom one new Server("192.168.0.1", 80, 3, 2, 256, 512);
    //Server(std::string& address, int port, int maxClients, int numChannels, int incBandwidth, int outBandwidth);
    Runner(new Server(), new myController());
    return 0;
}
