//
//  Func.h
//  hw_03_04
//
//  Created by Weiyi Chen on 7/7/14.
//  Copyright (c) 2014 Weiyi Chen. All rights reserved.
//

#ifndef hw_03_04_Func_h
#define hw_03_04_Func_h
#define Pi 3.141592653589793238462643
#define h 1e-5

#include <sstream>
#include <cmath>
using namespace std;

double CND(double X);

class Func {
    /*
     @summary: a abstract class that represents a mathematical function of one variable
     @operator (): pure virtual, takes a double and returns a double
     @method toString: pure virtual, returns a string representation of the mathematical function
     @method calc_first_derivative: calculate first derivative using central finite differences
     @method calc_second_derivative: calculate second derivative using central finite differences
     */
public:
    virtual double operator()(double x) = 0;
    virtual string toString() = 0;
    double calc_first_derivative(double x) {
        return ((*this)(x+0.5*h) - (*this)(x-0.5*h)) / h;
    }
    double calc_second_derivative(double x) {
        return ((*this)(x+h) - 2*(*this)(x) + (*this)(x-h)) / (h*h);
    }
};

class QuaFunc : public Func {
    /*
     @summary: a regular quadratic function
     @param a, b, c: coefficient of quadratic function
     @operator (): takes a double and returns a double
     @method toString: returns a string representation of the mathematical function
     */
private:
    double a, b, c;
public:
    QuaFunc(double aa, double bb, double cc): a(aa), b(bb), c(cc) {}
    double operator()(double x) {
        return a*x*x + b*x + c;
    }
    string toString() {
        ostringstream s;
        if (a == 0 && b == 0 && c == 0) return "0";
        if (a != 0) s << a << "x^2";
        if (b < 0) s << b << "x";
        else if (b > 0) s << "+" << b << "x";
        if (c < 0) s << c;
        else if (c > 0) s << "+" << c;
        return s.str();
    }
};

class EuropeanCall: public Func {
    /*
     @summary: an european call pricer using Black-Scholes-Merton formula
     @param S: spot price
     @param X: strike price
     @param T: duration
     @param r: risk-free rate
     @param v: volatility
     @operator (): takes a double and returns a double
     @method toString: returns a string representation of the mathematical function
     */
private:
    double X, T, r, v;
public:
    EuropeanCall(double XX, double TT, double rr, double vv): X(XX), T(TT), r(rr), v(vv) {}
    double operator()(double S) {
        double d1 = (log(S/X)+(r+v*v/2)*T) / (v*sqrt(T));
        double d2 = d1 - v*sqrt(T);
        return S * CND(d1) - X * exp(-r*T)*CND(d2);
    }
    string toString() {
        return "S*N(d1) - K*exp(-r*T)*N(d2)";
    }
};

double CND(double X) {
    /*
     @summary: The cumulative normal distribution function, copied online
     @ack: http://www.espenhaug.com/black_scholes.html
     @param X: random variable of cdf.
     @return: cdf of normal distribution
     */
    double L, K, w ;
    double const a1 = 0.31938153, a2 = -0.356563782, a3 = 1.781477937;
    double const a4 = -1.821255978, a5 = 1.330274429;
    L = fabs(X);
    K = 1.0 / (1.0 + 0.2316419 * L);
    w = 1.0 - 1.0 / sqrt(2 * Pi) * exp(-L *L / 2) * (a1 * K + a2 * K *K + a3 * pow(K,3) + a4 * pow(K,4) + a5 * pow(K,5));
    if (X < 0)
        w= 1.0 - w;
    return w;
}
#endif
