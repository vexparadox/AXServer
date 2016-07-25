#include "Server.hpp"

Server::Server(std::string address, int port, int maxClients, int numChannels, int incBandwidth, int outBandwidth) : maxClients(maxClients), numChannels(numChannels), incBandwidth(incBandwidth), outBandwidth(outBandwidth){
    //initlialise
	if (enet_initialize () != 0)
    { std::cout << "An error occurred while initializing ENet." << std::endl; }
    enet_address_set_host(&serverAddress, address.c_str());
    serverAddress.port = port;
    createHost();
}

Server::Server(){
    //initlialise
	if (enet_initialize () != 0)
    { std::cout << "An error occurred while initializing ENet." << std::endl; }
    enet_address_set_host(&serverAddress, "127.0.0.1");
    serverAddress.port = 1234;
    createHost();
}

void Server::createHost(){
    host = enet_host_create (&serverAddress, 32, 2, 0, 0);
    if (!host) { std::cout << "An error occurred while trying to create the server host." << std::endl; }
}

void Server::sendPacket(){
    std::cout << "Sending packet" << std::endl;
    ENetPacket* packet = enet_packet_create ("10", strlen ("10") + 1, ENET_PACKET_FLAG_RELIABLE);
    enet_host_broadcast (host, 0, packet);         
    enet_host_flush (host);
}

ENetHost* Server::getHost(){
    return host;
}