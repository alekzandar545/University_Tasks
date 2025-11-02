#include <iostream>

int main(){
    std::string arr[2];
    std::string str1, str2;
    std::cin >> str1 >> str2;
    arr[0] = str1;
    arr[1] = str2;
    arr[0][3] = '!';
    std::cout << arr[0] << '\n' << arr[1];
}