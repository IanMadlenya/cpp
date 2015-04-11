//
//  main.cpp
//  hw_03_04
//
//  Created by Weiyi Chen on 7/7/14.
//  Copyright (c) 2014 Weiyi Chen. All rights reserved.
//

#include <iostream>
#include "Func.h"

int main(int argc, const char * argv[])
{
    // Create an instance for f(x)=3x2+5x−20 and evaluate f(0),f′(0),f″(0)
    QuaFunc quafunc(3, 5, -20);
    cout << "---------- Quadratic Function ----------" << endl;
    cout << "f(x) is " << quafunc.toString() << endl;
    cout << "f(x) = " << quafunc(0) << endl;
    cout << "f'(x) = " << quafunc.calc_first_derivative(0) << endl;
    cout << "f\"(x) = " << quafunc.calc_second_derivative(0) << endl;
    
    // Create a concrete instance of a six month call with $40 strike, risk free rate of 10% and 20% vol
    EuropeanCall europeancall(40, 0.5, 0.1, 0.2);
    cout << "\n---------- European Call ----------" << endl;
    cout << "f(x) is " << europeancall.toString() << endl;
    // Calculate the call price when the underlying is $42. Calculate delta and gamma of the call
    cout << "Price: f(S) = " << europeancall(42) << endl;
    cout << "Delta: f'(S) = " << europeancall.calc_first_derivative(42) << endl;
    cout << "Gamma: f\"(S) = " << europeancall.calc_second_derivative(42) << endl;
    
    return 0;
}

