#include <iostream>

int Factoriel(int n){
    if(n==1)
        return 1;
    return n*=Factoriel(n-1);
}

int main(){
    int n;
    std::cin >> n;
    std::cout << Factoriel(n);
}