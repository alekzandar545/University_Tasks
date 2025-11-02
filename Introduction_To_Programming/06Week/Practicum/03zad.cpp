#include <iostream>
const size_t maxLen = 10;

int main(){
    /*Въведете k на брой цифри от конзолата (без да ги вкарвате в масив) и изведете колко пъти се среща
    всяка цифра (0 до 9). Записвайте бройката в масив, като индекса на масива отговаря на съответната цифра.*/

    unsigned int k;
    std::cout << "Enter k numbers: ";
    std::cin >> k;
    int array[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < k; i++)
    {
        int input;
        std::cin >> input;
        if(input < 10 && input >= 0)
            array[input]++;
        else{
            std::cout << "Invalid input!" << '\n';
            continue;
        }
    }
    
    for (size_t i = 0; i < maxLen; i++)
    {
        std::cout << i << ": " << array[i] << ' ' << '\n';
    }
    
}