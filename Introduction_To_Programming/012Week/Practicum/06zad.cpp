#include <iostream>


bool IsPalindrome(int n, int aux){
    if(n == aux || n / 10 == aux)
        return true;
    if(n == 0)
        return false;
    return IsPalindrome(n/10, 10*aux + n%10);
}


int main(){
    //find palindrome
    int n;
    std::cin >> n;
    std::cout << std::boolalpha << IsPalindrome(n, 0);
}