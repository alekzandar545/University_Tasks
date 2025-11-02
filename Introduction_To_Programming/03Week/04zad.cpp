#include <iostream>

int main(){
    //Да се прочете число от конзолата и да се намери неговата абсолютна стойност с побитови операции.
    int x;
    std::cout << "Enter a number x: ";
    std::cin >> x;

    int mask = 1;
    mask = mask << 31;
    mask = ~mask;

    std:: cout << mask << std::endl;
    x = x & mask;
    
    std::cout << x;

    //why not working :(
}