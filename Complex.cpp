//
//  Complex.cpp
//  Complex
//
//  Created by F on 13-5-10.
//  Copyright (c) 2013年 F. All rights reserved.
//

#include "Complex.h"

Complex operator+(const Complex &c1,const Complex &c2)
{
    return Complex(c1.a+c2.a,c1.b+c2.b);
}
Complex operator-(const Complex &c1,const Complex &c2)
{
    return Complex(c1.a-c2.a,c1.b-c2.b);
}
Complex operator*(const Complex &c1,const Complex &c2)
{
    return Complex(c1.a*c2.a-c1.b*c2.b,c1.a*c2.b+c1.b*c2.a);
}
Complex operator/(const Complex &c1,const Complex &c2)
{
    return Complex((c1.a*c2.a+c1.b*c2.b)/(c2.a*c2.a+c2.b*c2.b),(c1.b*c2.a-c1.a*c2.b)/(c2.a*c2.a+c2.b*c2.b));
}
Complex expj(double x){
    return Complex(cos(x),sin(x));
}
void Complex::conjugate(){
    b=-b;
}
void Complex::value(double A,double B){
    a=A;b=B;
    if (abs(a)<10e-6) {
        a=0;
    }
    if (abs(b)<10e-6) {
        b=0;
    }
};

ostream& operator<<(ostream & os,const Complex &c)
{
    if(c.a!=0)
    {
        os<<c.a;
        if(c.b==-1)
        {
            os<<"-i";
        }
        else if (c.b==1)
        {
            os<<"+i";
        }
        else if (c.b<0) 
        {
            os<<c.b<<'i';
        }
        else if (c.b>0)
        {
            os<<'+'<<c.b<<'i';
        }
        return os;
    }
    else
    {
        if (c.b==0) {
            os<<0;
        }
        else if(c.b==1)
            os<<'i';
        else if(c.b==-1)
            os<<"-i";
        else
        {
            os<<c.b<<'i';
        }
        return os;
    }
    
}
