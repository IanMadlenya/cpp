/*
 * World.h
 *
 *  Created on: Jun 27, 2014
 *      Author: weiyi
 */

#ifndef WORLD_H_
#define WORLD_H_

#include <iostream>
using namespace std;

enum DrawSymbols {ALIVE = '*', DEAD = ' '};

class World {
public:
    char c_world[WIDTH][HEIGHT];
    void generation(char c_world[WIDTH][HEIGHT]);
    void display(char c_world[WIDTH][HEIGHT]);
};

void World::generation(char c_world[WIDTH][HEIGHT]) {
    char c_next[WIDTH][HEIGHT];
    for (int i_height = 1; i_height < HEIGHT-1; i_height++)
        for (int i_width = 1; i_width < WIDTH-1; i_width++) {
            int i_left = i_width-1;
            int i_right = i_width+1;
            int i_up = i_height-1;
            int i_down = i_height+1;
            
            int neighbors = (c_world[i_left][i_down] == ALIVE)+(c_world[i_width][i_down] == ALIVE)\
            +(c_world[i_right][i_down] == ALIVE)+(c_world[i_left][i_height] == ALIVE)\
            +(c_world[i_right][i_height] == ALIVE)+(c_world[i_left][i_up] == ALIVE)\
            +(c_world[i_width][i_up] == ALIVE)+(c_world[i_right][i_up] == ALIVE);
            
            c_next[i_width][i_height] = c_world[i_width][i_height];
            if (c_next[i_width][i_height] == ALIVE) {
                if (neighbors < 2 || neighbors > 3) c_next[i_width][i_height] = DEAD;
            } else {
                if (neighbors == 3) c_next[i_width][i_height] = ALIVE;
            }
        }
    
    for (int i_height = 0; i_height < HEIGHT; i_height++)
        for (int i_width = 0; i_width < WIDTH; i_width++)
            c_world[i_width][i_height] = c_next[i_width][i_height];
    
    return;
}

void World::display(char c_world[WIDTH][HEIGHT]) {
    for (int i_height = 1; i_height < HEIGHT-1; i_height++) {
        for (int i_width = 1; i_width < WIDTH-1; i_width++) {
            cout << c_world[i_width][i_height];
        }
        cout << endl;
    }
}


#endif /* WORLD_H_ */
