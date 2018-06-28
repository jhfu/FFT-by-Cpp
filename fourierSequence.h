//
//  fourierSequence.h
//  FFT
//
//  Created by F on 14/11/2.
//  Copyright (c) 2014年 F. All rights reserved.
//

#ifndef __FFT__fourierSequence__
#define __FFT__fourierSequence__
#include "Complex.h"
class fourierSequence {
    Complex *data;
    Complex *wn;
    int length;
    int bitLength;
    
    int reverseNum(const int xx,const int bitLength)const;
    void reverseList();
    void nDIT_FFT(Complex *x,const int n);
    void nDIF_FFT(Complex *x,const int n);
    void conjugate();
    
public:
    fourierSequence();
    ~fourierSequence(){delete []data;delete []wn;}
    
    void DIT_FFT();
    void DIF_FFT();
    void IFFT();
    
    void print()const;
    
};

#endif /* defined(__FFT__fourierSequence__) */
