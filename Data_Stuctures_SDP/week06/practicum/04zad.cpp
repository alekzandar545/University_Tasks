#include <iostream>
#include "list.hpp"

std::pair<List<int>, List<int>> SplitList(const List<int>& list){
    List<int>::Node* slow = list.head;
    List<int>::Node* fast = list.head;
    List<int> first, second;
    bool slowWrite = 1;
    while(fast){
        if(slowWrite){
            first.push_back(slow->data);
            slow = slow->next;
        }
        slowWrite = !slowWrite;
        fast = fast->next;
    }
    if(!slow->next) //1 element only in other case
        return {first,second};

    slow = slow->next;
    while(slow){
        second.push_back(slow->data);
        slow = slow->next;
    } 
    for (const int& val : first){
        std::cout << val << ' ';
    }
    std::cout << '\n';
    for (const int& val : second){
        std::cout << val << ' ';
    }
    return {first, second};
}

int main(){
    int n;
    std::cin >> n;
    List<int> list;
    for (size_t i = 0; i < n; i++)
    {
        int val;
        std::cin >> val;
        list.push_back(val);
    }
    for (const int& val : list){
        std::cout << val << ' ';
    }
    std::pair<List<int>, List<int>> splitList;
    splitList = SplitList(list);
    for (const int& val : splitList.first){
        std::cout << val << ' ';
    }
    std::cout << '\n';
    for (const int& val : splitList.second){
        std::cout << val << ' ';
    }
}