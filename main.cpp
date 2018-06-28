#include <iostream>
#include "fourierSequence.h"
using namespace std;

int main(){
    fourierSequence test,test2;
    
    cout<<"The original sequence: "<<endl;
    test.print();
    cout<<endl;
    
    cout<<"After DIT_FFT: "<<endl;
    test.DIT_FFT();
    test.print();
    cout<<endl;
    
    cout<<"After DIF_FFT: "<<endl;
    test2.DIF_FFT();
    test2.print();
    cout<<endl;
    
    cout<<"After IFFT: "<<endl;
    test.IFFT();
    test.print();
    
    return 0;
}