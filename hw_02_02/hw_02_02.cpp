//
//  main.cpp
//  hw_02_02
//
//  Created by Weiyi Chen on 6/27/14.
//  Copyright (c) 2014 Weiyi Chen. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Voter.h"
using namespace std;

int main ( int argc, char *argv[] ) {
    // Declaration
    vector<Voter> voters;
    int id;
    int count[] = {0,0,0,0,0,0,0,0,0};
    string vote_string;

    // Read each vote from the file
    ifstream vote_file("sample.csv");
    if (vote_file.fail()) {
        cout << "Could not open the file." << endl;
        return 0;
    }
    while(!vote_file.eof()) {
        vote_file >> id;
        vote_file >> vote_string;
        Voter v(id, vote_string);
        voters.push_back(v);
    }
    vote_file.close();

    // iterate over the vector to compute the percent of votes cast
    for (vector<Voter>::iterator it = voters.begin(); it != voters.end(); it++) {
        count[it->get_mayor_vote()-65]++;
        count[it->get_prop_17_vote()-65]++;
        count[it->get_measure_1_vote()-65]++;
        count[it->get_measure_2_vote()-65]++;
    }

    // Output the percent of votes cast
    unsigned long total_votes = voters.size();
    cout << "Vote for Mayor: " << "Pincher Penny " << count[0]/(total_votes/100.0) << "%, "
    << "Dover Skip " << count[1]/(total_votes/100.0) << "%, "
    << "Perman Sue " << count[2]/(total_votes/100.0) << "%.\n";
    cout << "Proposition 17: " << "YES " << count[3]/(total_votes/100.0) << "%, "
    << "NO " << count[4]/(total_votes/100.0) << "%.\n";
    cout << "MEASURE 1: " << "YES " << count[5]/(total_votes/100.0) << "%, "
    << "NO " << count[6]/(total_votes/100.0) << "%.\n";
    cout << "MEASURE 2: " << "YES " << count[7]/(total_votes/100.0) << "%, "
    << "NO " << count[8]/(total_votes/100.0) << "%.\n";

    return 0;
}
