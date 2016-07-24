#include "Server.hpp"

Server::Server(std::string& address, int port){
    enet_address_set_host(&serverAddress, address.c_str());
    serverAddress.port = port;
}

Server::Server(){
    enet_address_set_host(&serverAddress, "127.0.01");
    serverAddress.port = 1234;
}