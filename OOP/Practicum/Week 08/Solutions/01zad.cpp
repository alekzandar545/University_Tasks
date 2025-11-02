#include <iostream>
#include <utility>
#include <cmath>

class Complex{
private:
    double real, imag;
public:
    //big 4
    Complex();
    Complex(const double real, const double imag);
    Complex(const Complex & other);
    Complex(Complex && other); //add const or no?
    Complex& operator=(const Complex & other);
    Complex& operator=(Complex && other);
    ~Complex();
    //move
    void Move(Complex && other);
    //getters
    double getReal() const;
    double getImag() const;
    //setters
    void setReal(const double real);
    void setImag(const double imag);
    //operators
    bool operator!() const;
    Complex operator+(const Complex & other) const;
    Complex operator+(const double other) const;
    Complex operator+(const Complex & other) const;
    Complex& operator+=(const Complex & other);
    Complex operator-(const Complex & other) const;
    Complex& operator-=(const Complex & other); 
    Complex operator*(const Complex & other) const;
    Complex& operator*=(const Complex & other);
    //methods
    double AbsComplex() const;
};
//big4
Complex::Complex(){
    real = 0;
    imag = 0;
}
Complex::Complex(double real, double imag){
    this->real = real;
    this ->imag = imag;
}
Complex::Complex(const Complex& other){
    real = other.real;
    imag = other.imag;
}
Complex::Complex(Complex && other){
    Move(std::move(other));
}
Complex& Complex::operator=(const Complex & other){
    if(this == &other) return *this;
    *this = Complex(other);
    return *this;
}
Complex& Complex::operator=(Complex && other){
    if(this == &other) return *this;
    Move(std::move(other));
    return *this;
}
Complex::~Complex() = default;
//move
void Complex::Move(Complex && other){
    real = std::exchange(other.real, 0);
    imag = std::exchange(other.imag, 0);
}
//getters
double Complex::getReal() const{
    return real;
}
double Complex::getImag() const{
    return imag;
}
//setters
void Complex::setReal(const double real){
    this->real = real;
}
void Complex::setImag(const double imag){
    this->imag = imag;
}
//operators
bool Complex::operator!() const{
    return !((real == 0) && (imag == 0));
}
Complex Complex::operator+(const Complex & other) const{
    Complex output = *this;//maybe change this idunno if it will break cus no copy constructor
    output.setReal(output.real + other.real);
    output.setImag(output.imag + other.imag);
    return output;
}
Complex& Complex::operator+=(const Complex & other){
    this->real += other.real;
    this->imag += other.imag;
    return *this;
}
Complex Complex::operator-(const Complex & other) const{
    Complex output = *this;
    output.setReal(output.real - other.real);
    output.setImag(output.imag - other.imag);
    return output;
}
Complex& Complex::operator-=(const Complex & other){
    this->real -= other.real;
    this->imag -= other.imag;
    return *this;
}
Complex Complex::operator*(const Complex & other) const{
    Complex output = *this;
    output.setReal(output.real*other.real - output.imag*other.imag);
    output.setImag(output.real*other.imag + output.imag*other.real);
    return output;
}
Complex& Complex::operator*=(const Complex & other){
    this->real = real*other.real - imag*other.imag;
    this->imag = real*other.imag + imag*other.real;
    return *this;
}
//methods
double Complex::AbsComplex() const{
    return sqrt(real*real + imag*imag);
}
//streams
std::ostream& operator<<(std::ostream & stream, const Complex & other){
    stream << "Real: " << other.getReal() << " Imag: " << other.getImag() << '\n';
    return stream;
}
std::istream& operator>>(std::istream & stream, Complex & other){
    double real, imag;
    std::cin >> real >> imag;
    other.setReal(real);
    other.setImag(imag);
    return stream;
}
//TODO: FIX COMUTATIVNOSTTA NA +-*
// <= with friend modifier
int main(){

    Complex a(1, 2), b;
    std::cin >> a >> a;
    std::cout << a << b;

}