#include <iostream>
#include <bitset>

int findMask(int n){
    int mask = 1;
    for (int i = 0; i < n; i++)
    {
        mask *= 2;
    }
    return mask;
}

int changeToOne(int x, int n){
    //Да се смени бита с индекс n в числото x с единица;
    x |= findMask(n);
    return x;
}
int changeToZero(int x, int n){
    //Да се смени бита с индекс n в числото x с нула, с помощта на операторите ~ и &;
    int mask = findMask(n);
    mask = ~mask;
    x &= mask;
    return x;
}
int main(){

    /*Да се прочете от конзолата цяло число x в интервала [ 0 , 255 ] и цяло число n в интервала [ 0 , 7 ].   */
    int x;
    int n;
    std::cout << "Enter an int n and a number n between [0, 31]";
    std::cin >> x >> n;
    if(n > 31 || n < 0){
        std::cout << "invalid input";
        return 0;
    }

    std::cout << changeToOne(x, n) << std::endl;

    std::cout << changeToZero(x, n) << std::endl;
    
    //Да се обърне бита на позиция n в числото x.
    if (x == changeToOne(x, n))
        std::cout << changeToZero(x, n) << std::endl;
    else
        std::cout << changeToOne(x, n) << std::endl; 
}