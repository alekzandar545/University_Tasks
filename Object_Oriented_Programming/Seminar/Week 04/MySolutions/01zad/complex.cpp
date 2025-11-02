#include <iostream>
#include "complex.h"


//getters
double Complex::getReal() const{
    return this->real;
}
double Complex::getImag() const{
    return this->imag;
}
//setters
void Complex::setReal(double value){
    this->real = value;
}
void Complex::setImag(double value){
    this->imag = value;
}
//methods
void Complex::print(){
    std::cout << "Real: " << this->real << "\nImag: " << this->imag; 
}

Complex Sum(const Complex& a, const Complex& b){
    Complex output;
    output.setImag(a.getImag() + b.getImag());
    output.setReal(a.getReal() + b.getReal());
    return output;
}
Complex Subtract(const Complex& a, const Complex& b){
    Complex output;
    output.setImag(a.getImag() - b.getImag());
    output.setReal(a.getReal() - b.getReal());
    return output;
}
Complex Multiply(const Complex& a, const Complex& b){
    Complex output;
    output.setImag(a.getReal()*b.getImag() + a.getImag()*b.getReal());
    output.setReal(a.getReal()*b.getReal() - a.getImag()*b.getImag());
    return output;
}
