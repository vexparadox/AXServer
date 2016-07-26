#include "myController.hpp"

void myController::setup(){
    std::cout << "Server is running, type help for more options." << std::endl;
}

void myController::takeInput(std::string s){
    //if the string the user has entered "exit" we should stop the server
    if(s == "exit"){
        //the runner object is in charge of the server
        runner->stopServer();
    }else if(s == "help"){
        std::cout << "exit - to stop the server safely" << std::endl;
    }
}