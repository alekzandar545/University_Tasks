#include <iostream>

unsigned NaturalSum(unsigned n){
    if(n==0)
        return 0;
    return n + NaturalSum(n-1);
}

int main(){
    //natural num sum
    unsigned n;
    std::cin >> n;
    std::cout << NaturalSum(n);
}