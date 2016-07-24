//
//  main.cpp
//  CFServer
//
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//
#include "CFServerMain.h"
int main(int argc, char *argv[])
{
    //start a new runner with the constructor
    //Runner(int width, int height, int frameRate, const char* title, new Core);
    Runner(new Server()m);
    return 0;
}
