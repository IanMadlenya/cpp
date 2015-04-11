/*
 * Voter.h
 *
 *  Created on: Jun 28, 2014
 *      Author: weiyi
 */

#ifndef VOTER_H_
#define VOTER_H_

using namespace std;

class Voter {
public:
    Voter();
    Voter(int newID, string newVotes);
    char get_mayor_vote();
    char get_prop_17_vote();
    char get_measure_1_vote();
    char get_measure_2_vote();
    int get_voter_id();
private:
    int id;
    string votes;
};

Voter::Voter():id(0), votes(""){

}

Voter::Voter(int newID, string newVotes):id(newID), votes(newVotes){

}

char Voter::get_mayor_vote() {
    return votes[1];
}

char Voter::get_prop_17_vote() {
    return votes[2];
}

char Voter::get_measure_1_vote() {
    return votes[3];
}

char Voter::get_measure_2_vote() {
    return votes[4];
}

int Voter::get_voter_id() {
    return id;
}

#endif /* VOTER_H_ */
