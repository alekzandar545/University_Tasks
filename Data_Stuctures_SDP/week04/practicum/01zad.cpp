#include <iostream>
#include <stack>
#include <queue>

//Напишете програма, която обръща всички елементи в дадена опашка.

int main(){
    std::queue<int> queue;
    size_t size;
    std::cin >> size;
    for (size_t i = 0; i < size; i++)
    {
        int el;
        std::cin >> el;
        queue.push(el);
    }
    std::stack<int> results;
    for (size_t i = 0; i < size; i++)
    {
        int curr = queue.front();
        results.push(curr);
        queue.pop();
    }
    for (size_t i = 0; i < size; i++)
    {
        std::cout << results.top() << ' ';
        results.pop();
    }
    
    
}