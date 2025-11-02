#include <iostream>
#include <cassert>
#include "list.hpp"
//priority list
//3 priorities according to a num


int main(){
    int n, k;
    std::cin >> n >> k;
    List<std::pair<std::string,int>> list;
    for (size_t i = 0; i < n; i++)
    {
        std::string str;
        int val;
        std::cin >> str >> val;
        std::pair<std::string, int> entry {str, val};
        list.push_back(entry);
    }
    //creating 3 lists that ill later concatenate
    List<std::pair<std::string,int>> l1,l2,l3;
    List<std::pair<std::string,int>>::Node* curr = list.head;
    std::pair<std::string, int> dummyPair {"Dummy", 0};
    l1.push_front(dummyPair);
    l2.push_front(dummyPair);
    l3.push_front(dummyPair);
    while(curr)
    {
        
        if(curr->data.second > k)
            l1.push_back(curr->data);
        else if(curr->data.second < k)
            l3.push_back(curr->data);
        else
            l2.push_back(curr->data);

        curr = curr->next;
    }
    List<std::pair<std::string,int>> result;
    result.head = l1.head->next;
    result.tail = l1.tail;
    result.tail->next = l2.head->next;
    result.tail = l2.tail;
    result.tail->next = l3.head->next;
    result.tail = l3.tail;
    //printing
    curr = result.head;
    std::cout << '\n' << "======================" << '\n';
    while(curr)
    {
        std::cout << curr->data.first << ' ' << curr->data.second << '\n';
        curr = curr->next;
    }
}