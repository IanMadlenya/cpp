//
//  main.cpp
//  hw_01_04
//
//  Created by Weiyi Chen on 6/26/14.
//  Copyright (c) 2014 Weiyi Chen. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
using namespace std;

int main(int argc, const char * argv[])
{
    // Open file
    ifstream in_stream("babynames2004.txt");
    if (!in_stream) {
    	cout << "Failed to open the file." << endl;
    	return 0;
    }
    string s_search;
    cout << "Please input the searching name: ";
    cin >> s_search;

    // Search name
    int i_word = 0, i_line = 0;
    bool b_boy = false, b_girl = false;
    string s_line, s_word = "";
    getline(in_stream, s_line);
    while (in_stream) {
        i_line++;
        for(int i=0; s_line[i]!='\0'; i++) {
            if(!isspace(s_line[i]))
                s_word = s_word + s_line[i];
            else {
                i_word++;
                if(s_word == s_search && i_word % 3 == 2) {
                    cout << s_search << " is ranked " << i_line << " in popularity among boys." << endl;
                    b_boy = true;
                }
                if (s_word == s_search && i_word % 3 == 0) {
                    cout << s_search << " is ranked " << i_line << " in popularity among girls." << endl;
                    b_girl = true;
                }
                s_word = "";
            }
        }
        s_word="";
        getline(in_stream, s_line);
    }
    if (b_boy == false)
        cout << s_search << " is not ranked among the top 1000 boy names." << endl;
    if (b_girl == false)
        cout << s_search << " is not ranked among the top 1000 girl names." << endl;

    return 0;
}

