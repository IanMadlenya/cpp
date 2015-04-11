//
//  main.cpp
//  give_change
//
//  Created by Weiyi Chen on 6/20/14.
//  Copyright (c) 2014 Weiyi Chen. All rights reserved.
//

#include <iostream>
using namespace std;

void compute_coins(int coin_value, int& num, int& amount_left) {
    /*
     @summary: compute number of coin_value and update amount_left
     @param coin_value: 0 < coin_value < 100
     @param num: num has been set equal to maximum number of coins of denomination coin_value cents that can be obtained from amount_left.
     @param amount_left: 0 <= amount_left < 100, change_left after former coin_value cents obtained
     */
    num = amount_left / coin_value;
    amount_left %= coin_value;
}

int main(int argc, const char * argv[])
{
    char end = 'N';
    while (end == 'N') {
        // Input the amount of change
        int amount_change;
        cout << "Please input the amount of change (in cents): ";
        cin >> amount_change;

        // Check the precondition
        while (amount_change < 1 || amount_change > 99) {
            cout << "Error: please enter an integer between 1 and 99.\n";
            cin >> amount_change;
        }

        // Calculate the number of different coins
        int quarter_value = 25, dime_value = 10, penny_value = 1;
        int quarter_num = 0, dime_num = 0, penny_num = 0;
        int amount_left = amount_change;
        compute_coins(quarter_value, quarter_num, amount_left);
        compute_coins(dime_value, dime_num, amount_left);
        compute_coins(penny_value, penny_num, amount_left);

        // Output the number of different coins
        cout << amount_change << " cents can be given as \n";
        cout << quarter_num << " quarter(s) " <<
        dime_num << " dime(s) and " <<
        penny_num << " penny(pennies)\n";

        // Query whether to end the program
        cout << "\nDo you wish to end the program? (Y/N)\n";
        cin >> end;
        while (end!='Y' && end!='N') {
            cout << "Please type Y or N." << endl;
            cin >> end;
        }
    }
    return 0;
}

