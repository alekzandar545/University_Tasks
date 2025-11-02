#include <iostream>
#include <cmath>
#include "fraction.h"

int gcd(int a, int b) 
{ 
  if (b == 0) 
    return a; 
  return gcd(b, a % b); 
} 
  
// Function to return LCM of two numbers  
int lcm(int a, int b) 
{ 
    return (a / gcd(a, b)) * b; 
} 
//getters
int Fraction::getNumerator() const{
    return this->numerator;
}
int Fraction::getDenomenator() const{
    return this->denominator;
}
//setters
void Fraction::setNumerator(int const value){
    this->numerator = value;
}
void Fraction::setDenomerator(int const value){
    if(value <= 0){
        std::cout << "Error!";
        return;
    }
    this->denominator = value;
}
//reduce
void Fraction::reduce(){
    while(gcd(this->numerator, this->denominator) != 1){
        int greatestCommonDivisor = gcd(this->numerator, this->denominator);
        this->numerator /= greatestCommonDivisor;
        this->denominator /= greatestCommonDivisor;
    }
}
//methods
double Fraction::value() const{
    double output = numerator;
    return output / this->denominator;
};
void Fraction::add(const Fraction &other){
    if(this->denominator == other.denominator){
        this->numerator += other.numerator;
    }
    //find least common multiple
    else{
        int newDivisor = lcm(this->denominator, other.denominator);
        int firstMultiple = newDivisor/this->denominator;
        int secondMultiple = newDivisor/other.denominator;
        this->denominator = newDivisor;
        //std::cout << this->denominator;
        this->numerator = this->numerator*firstMultiple + other.numerator*secondMultiple;
        //std::cout << this ->numerator;
    }
    reduce();
};
void Fraction::subtract(const Fraction &other){
    if(this->denominator == other.denominator){
        this->numerator -= other.numerator;
    }
    //find least common multiple
    else{
        int newDivisor = lcm(this->denominator, other.denominator);
        int firstMultiple = newDivisor/this->denominator;
        int secondMultiple = newDivisor/other.denominator;
        this->denominator = newDivisor;
        this->numerator = this->numerator*firstMultiple - other.numerator*secondMultiple;
    }
    reduce();
}
void Fraction::divide(const Fraction &other){
    this->numerator *= other.denominator;
    this->denominator *= other.numerator;
    Fraction::reduce();
}
void Fraction::mult(const Fraction &other){
    this->numerator *= other.numerator;
    this->denominator *= other.denominator;
    Fraction::reduce();
}
void Fraction::reverse(){
    int temp = this->numerator;
    this->numerator = this->denominator;
    this->denominator = temp;
    if(this->denominator < 0){
        this->denominator = -this->denominator;
        this->numerator = - this->numerator;
    }
}
bool Fraction::compare(const Fraction &other) const{
    int newDivisor = lcm(this->denominator, other.denominator);
    int firstMultiple = newDivisor/this->denominator;
    int secondMultiple = newDivisor/other.denominator;
    return this->numerator*firstMultiple > other.numerator*secondMultiple;
}
void Fraction::print() const{
    std::cout << this->numerator << '/' << this->denominator << '\n';
} // Принтира дробта с дробна черта в конзолата
