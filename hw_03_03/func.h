//
//  func.h
//  hw_03_03
//
//  Created by Weiyi Chen on 7/6/14.
//  Copyright (c) 2014 Weiyi Chen. All rights reserved.
//

#ifndef hw_03_03_func_h
#define hw_03_03_func_h
using namespace std;

// Type definition
typedef int* IntPtr;
const int NUMLABS = 100;


void createArrays(IntPtr labs[], int labsizes[]) {
    // Create Arrays:
    for (int i = 0; i < NUMLABS; i++) {
        labs[i] = new int[labsizes[i]];
        for (int j = 0; j< labsizes[i]; j++) {
            labs[i][j] = -1; // -1 means unused computer
        }
    }
}

void freeArrays(IntPtr labs[]) {
    // freeArrays: Release memory we allocated with "new"
    for (int i = 0; i < NUMLABS; i++) {
        delete [] labs[i];
    }
}

void showLabs(IntPtr labs[], int labsizes[], int i_numlabs) {
    // showLabs:
    cout << "LAB STATUS" << endl;
    for (int i = 0; i < i_numlabs; i++) {
        cout << i+1 << " ";
        for (int j = 0; j < labsizes[i]; j++) {
            cout << (j+1) << ": ";
            if (labs[i][j] == -1)
                cout << "empty ";
            else
                cout << labs[i][j] << " ";
        }
        cout<< endl;
    }
}

void login(IntPtr labs[], int labsizes[], int i_lab, int i_station, int i_id) {
    // Login: check to see if this station is free
    if (labs[i_lab-1][i_station-1] != -1) {
        cout << "Error: user " << labs[i_lab-1][i_station-1] << " has already logged into the station." << endl;
        return;
    }
    // Assign this station to the user
    labs[i_lab-1][i_station-1] = i_id;
    return;
}

void logoff(IntPtr labs[], int labsizes[], int i_lab, int i_station) {
    // Logoff
    labs[i_lab-1][i_station-1] = -1;
    return;
}

#endif
