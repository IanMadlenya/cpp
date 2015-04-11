//
//  main.cpp
//  hw_02_01
//
//  Created by Weiyi Chen on 6/27/14.
//  Copyright (c) 2014 Weiyi Chen. All rights reserved.
//

#define WIDTH 80+2
#define HEIGHT 40+2
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "World.h"
using namespace std;

int main ( int argc, char *argv[] ) {
    // Declaration
    string s_line;
    int i_GEN = atoi(argv[1]);
    string file_name = argv[2];
    World world;
    for (int i_height = 0; i_height < HEIGHT; i_height++) {
        for (int i_width = 0; i_width < WIDTH; i_width++) {
            world.c_world[i_width][i_height] = ' ';
        }
    }

    // Read file and parse contents
    ifstream in_file(file_name);
    for (int i_height = 1; i_height < HEIGHT-1; i_height++) {
        getline(in_file, s_line);
        for (int i_width = 1; i_width < WIDTH-1; i_width++) {
            world.c_world[i_width][i_height] = s_line[i_width-1];
        }
    }
    in_file.close();
    
    // World simulation
    for (int i_gen = 0; i_gen < i_GEN; i_gen++)
        world.generation(world.c_world);
    world.display(world.c_world);
    
    return 0;
}