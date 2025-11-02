#include <iostream>

bool IsPrime(unsigned n, unsigned counter){
    if(counter == n)
        return true;
    if(n % counter==0)
        return false;
    return IsPrime(n, counter+1);
}

int main(){
    //isPrime
    unsigned n;
    std::cin >> n;
    std::cout << std::boolalpha << IsPrime(n, 2);
}