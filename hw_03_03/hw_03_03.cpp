//
//  main.cpp
//  hw_03_03
//
//  Created by Weiyi Chen on 7/5/14.
//  Copyright (c) 2014 Weiyi Chen. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include "func.h"
using namespace std;

int main(int argc, const char * argv[])
{
    IntPtr ipp_labs[NUMLABS];
    int ip_labsizes[NUMLABS];
    int i_numlabs = 0;
    char c_comma;
    string s_line;
    
    // Initialize labsizes to those given from file
    ifstream if_labs("labs.txt");
    if (!if_labs.is_open()) {
        cout << "Unable to open file." << endl;
        exit(1);
    }
    else {
        getline(if_labs, s_line);
        while (!if_labs.eof())
            if_labs >> i_numlabs >> c_comma >> ip_labsizes[i_numlabs-1];
    }
    
    // Create ragged array structure
    createArrays(ipp_labs, ip_labsizes);
    
    // Login and Logoff
    ifstream if_users("users.txt");
    if (!if_users.is_open()) {
        cout << "Unable to open file." << endl;
        exit(1);
    }
    else {
        getline(if_users, s_line);
        while (!if_users.eof()) {
            char c_log;
            int i_lab, i_station, i_id;
            if_users >> c_log;
            if (c_log == 'I') {
                if_users >> c_comma >> i_station >> c_comma >> i_lab >> c_comma >> i_id;
                login(ipp_labs, ip_labsizes, i_lab, i_station, i_id);
            }
            else if (c_log == 'O') {
                if_users >> c_comma >> i_station >> c_comma >> i_lab;
                logoff(ipp_labs, ip_labsizes, i_lab, i_station);
            }
            else {
                cout << "Invalid Entry: " << c_log << endl;
                exit(1);
            }
        }
    }
    
    // Show labs and free arrays
    showLabs(ipp_labs, ip_labsizes, i_numlabs);
    freeArrays(ipp_labs);
    return 0;
}

