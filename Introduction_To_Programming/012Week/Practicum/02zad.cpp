#include <iostream>

unsigned Fibonacci(unsigned n){
    if (n==0){
        return 0;
    }
    if(n==2){
        return 1;
    }
    if(n==1){
        return 1;
    }
    return Fibonacci(n-1) + Fibonacci(n-2);
}

int main(){
    //Nth fibonaci number
    unsigned n;
    std::cin >> n;
    std::cout << Fibonacci(n);
}