//
//  fourierSequence.cpp
//  FFT
//
//  Created by F on 14/11/2.
//  Copyright (c) 2014年 F. All rights reserved.
//

#include "fourierSequence.h"
#include <iostream>
#include <cmath>
const double pi=M_PI;
using namespace std;

fourierSequence::fourierSequence(){
    length=8;
    data=new Complex[length];
    data[0].value(1,5);
    data[1].value(9,2);
    data[2].value(9,0);
    data[3].value(4,1);
    data[4].value(0,3);
    data[5].value(4,1);
    data[6].value(1,4);
    data[7].value(1,0);
    
    bitLength=log(length)/log(2);
    
    wn=new Complex[length];
    for (int i=0; i<length; i++) {
        wn[i]=expj(-2*pi/length*i);
    }
}


int fourierSequence::reverseNum(const int xx, const int bitLength)const{
    int x=xx;
    int result=0;
    for (int i=0; i<bitLength-1; i++) {
        result=result*2+x%2;
        x/=2;
    }
    return result*2+x%2;
}
void fourierSequence::reverseList(){
    int newAddress;
    Complex temp;
    for (int i=1; i<length/2; i++) {
        newAddress=reverseNum(i, bitLength);
        if (i!=newAddress) {
            temp=data[newAddress];
            data[newAddress]=data[i];
            data[i]=temp;
        }
    }
}

void fourierSequence::print()const{
    for (int i=0; i<length; i++) {
        cout<<data[i]<<"\t\t";
    }
    cout<<endl;
}


void fourierSequence::nDIT_FFT(Complex *x,const int n){
    Complex temp1,temp2;
    int k=length/n;
    for (int i=0; i<n/2; i++) {
        temp1=*(x+i)+(*(x+i+n/2))*(wn[i*k]);
        temp2=*(x+i)-(*(x+i+n/2))*(wn[i*k]);
        *(x+i)=temp1;
        *(x+i+n/2)=temp2;
    }
}

void fourierSequence::nDIF_FFT(Complex *x, const int n){
    Complex temp1,temp2;
    int k=length/n;
    for (int i=0; i<n/2; i++) {
        temp1=*(x+i)+(*(x+i+n/2));
        temp2=(*(x+i)-(*(x+i+n/2)))*(wn[i*k]);
        *(x+i)=temp1;
        *(x+i+n/2)=temp2;
    }
}

void fourierSequence::DIT_FFT(){
    reverseList();
    for (int i=1; i<=bitLength; i++) {
        int time=pow(2, bitLength-i);
        for (int j=0; j<time; j++) {
            nDIT_FFT(data+int(j*pow(2, i)), pow(2, i));
        }
    }
}

void fourierSequence::DIF_FFT(){
    for (int i=bitLength; i>0; i--) {
        int time=pow(2, bitLength-i);
        for (int j=0; j<time; j++) {
            nDIF_FFT(data+int(j*pow(2, i)), pow(2, i));
        }
    }
    reverseList();
}
void fourierSequence::conjugate(){
    for (int i=0; i<length; i++) {
        data[i].conjugate();
    }
}

void fourierSequence::IFFT(){
    conjugate();
    DIF_FFT();
    conjugate();
    for (int i=0; i<length; i++) {
        data[i]=data[i]/length;
    }
}
