//
//  main.cpp
//  hw_03_02
//
//  Created by Weiyi Chen on 7/5/14.
//  Copyright (c) 2014 Weiyi Chen. All rights reserved.
//

#include <iostream>
#include "Rational.h"
using namespace std;

int main(int argc, const char * argv[])
{
    // Test constructors
    Rational R_rational;
    R_rational = Rational();
    cout << "Result of Rational() constructor: " << R_rational << endl;
    R_rational = Rational(2);
    cout << "Result of Rational(int) constructor: " << R_rational << endl;
    R_rational = Rational(-2, -4);
    cout << "Result of Rational(int, int) constructor: " << R_rational << endl;
    
    // Test << and >> operators
    cout << "Enter a fraction (numerator/denominator): ";
    cin >> R_rational;
    cout << "The equivalent fraction is " << R_rational << endl;
    
    // Test ==, <, <=, >, >= operators
    Rational R_rational1 = Rational(1,2);
    Rational R_rational2 = Rational(2,3);
    cout << "(" << R_rational1 << " = " << R_rational2 << "): " << (R_rational1 == R_rational2) << endl;
    cout << "(" << R_rational1 << " < " << R_rational2 << "): " << (R_rational1 < R_rational2) << endl;
    cout << "(" << R_rational1 << " <= " << R_rational2 << "): " << (R_rational1 <= R_rational2) << endl;
    cout << "(" << R_rational1 << " > " << R_rational2 << "): " << (R_rational1 > R_rational2) << endl;
    cout << "(" << R_rational1 << " >= " << R_rational2 << "): " << (R_rational1 >= R_rational2) << endl;
    
    // Test +, -, *, / operators
    cout << R_rational1 << " + " << R_rational2 << " = " << (R_rational1 + R_rational2) << endl;
    cout << R_rational1 << " - " << R_rational2 << " = " <<(R_rational1 - R_rational2) << endl;
    cout << R_rational1 << " * " << R_rational2 << " = " <<(R_rational1 * R_rational2) << endl;
    cout << R_rational1 << " / " << R_rational2 << " = " <<(R_rational1 / R_rational2) << endl;

    return 0;
}

