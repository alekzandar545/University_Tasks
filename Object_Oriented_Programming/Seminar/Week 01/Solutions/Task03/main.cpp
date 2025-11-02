#include <iostream>

struct Complex
{
    double real, imag;   
};

bool Validate(double a){
    return a >= -1000 && a <= 1000;
}

Complex AddComplex(const Complex& a, const Complex& b){
    Complex output;
    output.real = a.real + b.real;
    output.imag = a.imag + b.imag;
    return output;
}
Complex SubtractComplex(const Complex& a, const Complex& b){
    Complex output;
    output.real = a.real - b.real;
    output.imag = a.imag - b.imag;
    return output;
}
Complex MultiplyComplex(const Complex& a, const Complex& b){
    Complex output;
    output.real = a.real*b.real - a.imag*b.imag;
    output.imag = a.imag*b.real + b.imag*a.real;
    return output;
}
void PrintComplex(const Complex& a){
    if(a.real) std::cout << a.real;
    if(a.imag > 0) std::cout << '+';
    if(a.imag != 0) std::cout << a.imag << 'i';
    std::cout << '\n';
        
}
int main(){
    double a, b, c, d;
    std::cin >> a >> b >> c >> d;
    if(!(Validate(a)&&Validate(b)&&Validate(c)&&Validate(d))){
        std::cout << "Invalid input!";
        return -1;
    }
    Complex c1 = {a, b};
    Complex c2 = {c, d};
    PrintComplex(AddComplex(c1,c2));
    PrintComplex(SubtractComplex(c1,c2));
    PrintComplex(MultiplyComplex(c1,c2));
}