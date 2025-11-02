#include <iostream>
#include <cmath>

struct quadratic{
    double a,b,c;

    void Solve() const{
        double discriminant = b*b - 4*a*c;
        if(discriminant < 0){
            std::cout << "The equation does not have real solutions!\n";
        }
        else if(discriminant == 0){
            std::cout << "x1 = x2 = " << -b/2*a << '\n';
        }
        else{
            std::cout << "x1 = " << (-b + sqrt(discriminant))/2*a << '\n';
            std::cout << "x2 = " << (-b - sqrt(discriminant))/2*a << '\n';
        }
    }
};

bool Validate(double a){
    return a >= -100 && a <= 100;
}

int main(){
    double a,b,c;
    std::cin >> a >> b >> c;
    if(!(Validate(a)&&Validate(b)&&Validate(c))){
        std::cout << "Inalid inputs!";
        return -1;
    }
    quadratic quad = {a, b, c};
    quad.Solve();
}