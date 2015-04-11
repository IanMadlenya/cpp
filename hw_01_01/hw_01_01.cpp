//
//  main.cpp
//  greatest_puzzler
//
//  Created by Weiyi Chen on 6/19/14.
//  Copyright (c) 2014 Weiyi Chen. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

void shoot(bool& targetAlive, double accuracy) {
    /*
     @summary: part(a), simulate someone shooting with given accuracy by generating a random number between 0 and 1
     @targetAlive: target being shot
     @accuracy: if the random number is less than accuracy, the target is hit
     */
	double randomNum = double (rand())/RAND_MAX;
	if (randomNum < accuracy)
		targetAlive = false;
}

string startDuel() {
    /*
     @summary: part(b), each man to shoot at the most accurate shooter still alive
     @return: a variable that indicates who win the duel.
     */
	bool aaronAlive = true, bobAlive = true, charlieAlive = true;
	while (aaronAlive + bobAlive + charlieAlive > 1) {
		if (aaronAlive)
		{
			if (charlieAlive)
				shoot(charlieAlive, 1/3.0);
			else if (bobAlive)
				shoot(bobAlive, 1/3.0);
		}
		if (bobAlive)
		{
			if (charlieAlive)
				shoot(charlieAlive, 0.5);
			else if (aaronAlive)
				shoot(aaronAlive, 0.5);
		}
		if(charlieAlive)
		{
			if (bobAlive)
				shoot(bobAlive, 1.0);
			else if (aaronAlive)
				shoot(aaronAlive, 1.0);
		}
	}
	if (aaronAlive)
		return "Aaron";
	else if(bobAlive)
		return "Bob";
	else
		return "Charlie";
}

string startDuel_counter()
{
    /*
     @summary: part(d), a counter intuitive strategy for Aaron to intentionally miss on his first shot
     @return: a variable that indicates who won the duel
     */
	bool aaronAlive = true, bobAlive = true, charlieAlive = true;
	int round = 1;

	while (aaronAlive + bobAlive + charlieAlive > 1) {
		if (aaronAlive && round != 1) {
            if (charlieAlive)
                shoot(charlieAlive, 1/3.0);
            else if (bobAlive)
            shoot(bobAlive, 1/3.0);
		}
		if (bobAlive)
		{
			if (charlieAlive)
				shoot(charlieAlive, 0.5);
			else if (aaronAlive)
				shoot(aaronAlive, 0.5);
		}
		if(charlieAlive)
		{
			if (bobAlive)
				shoot(bobAlive, 1.0);
			else if (aaronAlive)
				shoot(aaronAlive, 1.0);
		}
		round++;
	}
	if (aaronAlive)
		return "Aaron";
	else if(bobAlive)
		return "Bob";
	else
		return "Charlie";
}

int main()
{
    // Part(c): everyone uses the strategy of shooting at the most accurate shooter left alive.
	int aaronWinTimes=0, bobWinTimes=0, charlieWinTimes=0;

    string winner = "";
    for (int numDuals = 0; numDuals < 1000; numDuals++) {
        winner = startDuel();
		if(winner == "Aaron")
			aaronWinTimes++;
		else if (winner == "Bob")
			bobWinTimes++;
		else
			charlieWinTimes++;
    }
	// Output the probability that each one will win
    cout << "First strategy:\n";
	cout << "Aaron's probability to win is " << aaronWinTimes/10.0 << "%.\n";
	cout << "Bob's probability to win is " << bobWinTimes/10.0 << "%.\n";
	cout << "Charlie's probability to win is " << charlieWinTimes/10.0 << "%.\n";

	// Part(d): Aaron intentionally miss on his first shot
	aaronWinTimes=0, bobWinTimes=0, charlieWinTimes=0;

    winner = "";
    for (int numDuals = 0; numDuals < 1000; numDuals++) {
		winner = startDuel_counter();
		if(winner == "Aaron")
			aaronWinTimes++;
		else if (winner == "Bob")
			bobWinTimes++;
		else
			charlieWinTimes++;
	}
	// Output the probability that each one will win
	cout << "\nSecond strategy:\n";
	cout << "Aaron's probability to win is " << aaronWinTimes/10.0 << "%.\n";
	cout << "Bob's probability to win is " << bobWinTimes/10.0 << "%.\n";
	cout << "Charlie's probability to win is " << charlieWinTimes/10.0 << "%.\n";
	return 0;
}




