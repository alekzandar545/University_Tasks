#include <iostream>
#include <stack>
#include <queue>

int main(){
    //Напишете програма, която проверява дали дадените елементи в опашка образуват палиндром.
    size_t size;
    std::cin >> size;
    std::queue<int> q;
    for (size_t i = 0; i < size; i++)
    {
        int el;
        std::cin >> el;
        q.push(el);
    }
    std::queue<int> copyq = q;
    std::stack<int> helper;
    for (size_t i = 0; i < size; i++)
    {
        int el = copyq.front();
        copyq.pop();
        helper.push(el);
    }
    bool palindrome = true;
    for (size_t i = 0; i < size; i++)
    {
        if(q.front() != helper.top()){
            palindrome = false;
            break;
        }
    }
    std::cout << std::boolalpha << palindrome;
    
    
}