#include <iostream>

int main(){
    // /Да се прочете от конзолата int x и проверете дали броя на включените битове в него е четен или нечетен.
    int x;
    std::cout << "Enter an int x: ";
    std::cin >> x;

    int mask = 1;
    int bits;
    for (int i = 0; i < 32; i++)
    {
        if (x & mask == mask)
            bits++;
        x = x >> 1;
    }
    //std::cout << bits << std::endl;
    if(bits % 2 == 0)
        std::cout << "even";
    else
        std::cout << "odd";
    
}