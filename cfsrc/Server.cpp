#include "Server.hpp"

Server::Server(std::string& address, int port, int maxClients, int numChannels, int incBandwidth, int outBandwidth) : maxClients(maxClients), numChannels(numChannels), incBandwidth(incBandwidth), outBandwidth(outBandwidth){
    enet_address_set_host(&serverAddress, address.c_str());
    serverAddress.port = port;
    createHost();
}

Server::Server(){
    enet_address_set_host(&serverAddress, "127.0.0.1");
    serverAddress.port = 1234;
    createHost();
}

void Server::createHost(){
    host = enet_host_create (&serverAddress, maxClients, numChannels, incBandwidth, outBandwidth);
    if (!host) { std::cout << "An error occurred while trying to create the server host." << std::endl; }
}

ENetHost* Server::getHost(){
    return host;
}