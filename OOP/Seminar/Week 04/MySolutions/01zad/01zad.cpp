#include <iostream>
#include "complex.h"


int main(){
    Complex a, b;
    a.setReal(2);
    a.setImag(3);
    b.setReal(1);
    b.setImag(5);
    Multiply(a,b).print();
}