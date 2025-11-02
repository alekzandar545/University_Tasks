#include <iostream>

double Power(double n, int pow, int nowPow){
    if(pow == nowPow)
        return n;
    else if(pow<nowPow){
        return Power(n, pow, nowPow - 1) / n;
    }
    else{
        return n * Power(n, pow, nowPow + 1); 
    }
}

int main(){
    //pow
    double n;
    int pow;
    std::cin >> n >> pow;
    std::cout << Power(n, pow, 1);
}