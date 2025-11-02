#pragma once

class Complex{
private:
    double real, imag;
public:
    //getters
    double getReal() const;
    double getImag() const;
    //setters
    void setReal(double value);
    void setImag(double value);
    //methods
    void print();

};
Complex Sum(const Complex& a, const Complex& b);
Complex Subtract(const Complex& a, const Complex& b);
Complex Multiply(const Complex& a, const Complex& b);
