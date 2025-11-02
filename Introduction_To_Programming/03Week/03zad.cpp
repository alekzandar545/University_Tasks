#include <iostream>

int main(){
    //Да се прочетат две цели числа от конзолата и с побитови операции проверете дали те са с противоположни знаци.
    int x;
    int y;
    std::cout << "Enter x, y: ";
    std::cin >> x >> y;

    x = x >> 31;
    y = y >> 31;

    //std::cout << x << std::endl << y << std::endl;
    if(x == ~y)
        std::cout << "true";
    else
        std::cout << "false";
    
}