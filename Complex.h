//
//  Complex.h
//  Complex
//
//  Created by F on 13-5-10.
//  Copyright (c) 2013年 F. All rights reserved.
//

#ifndef __Complex__Complex__
#define __Complex__Complex__

#include <iostream>
#include <cmath>
using namespace std;
class Complex{
    friend Complex operator+(const Complex &c1,const Complex &c2);
    friend Complex operator-(const Complex &c1,const Complex &c2);
    friend Complex operator*(const Complex &c1,const Complex &c2);
    friend Complex operator/(const Complex &c1,const Complex &c2);
    friend ostream& operator<<(ostream & os,const Complex &c);
private:
    double a,b;
public:
    Complex(double A=0,double B=0):a(A),b(B){
        if (abs(a)<10e-6) a=0;
        if (abs(b)<10e-6) b=0;
    };
    void value(double A=0,double B=0);
    void conjugate();
    
};
Complex expj(double x);
#endif /* defined(__Complex__Complex__) */
