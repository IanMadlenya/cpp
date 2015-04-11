//
//  main.cpp
//  word_counter
//
//  Created by Weiyi Chen on 6/23/14.
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
    cout << "Please input the name of the file: ";
    string s_file;
    cin >> s_file;
    ifstream in_stream(s_file.c_str());

    // Read file and calculate number of words and lines
    int i_word = 0, i_line = 0;
    string s_line, s_word = "";
    getline(in_stream, s_line);
    while (in_stream) {
        i_line++;
        for(int i=0; s_line[i]!='\0'; i++) {
            if(!isspace(s_line[i]))
                s_word = s_word + s_line[i];
            else {
                i_word++;
                s_word = "";
            }
        }
        s_word="";
        getline(in_stream, s_line);
    }

    // Output number of words and lines
    cout << "The number of words in the file: " << i_word << endl;
    cout << "The number of lines in the file: " << i_line << endl;
    in_stream.close();
    return 0;
}
