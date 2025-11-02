#include <iostream>
#include "listTest.hpp"
#include <stack>

//reverse a list taking only Node* head as argument
//fav na armqnov :3
//now try to do it for const memory
void ReverseList(State* head){
    std::stack<State*> s;
    State* temp = head;
    while(temp){
        s.push(temp);
        temp = temp->next;
    }
    head = s.top();
    s.pop();
    while(!s.empty()){
        head->next = s.top();
        head = head->next;
        s.pop();
    }
}
State* ReverseListConst(State* head){
    State* prev = nullptr;
    State* curr = head;
    State* next = nullptr;
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main(){
    std::list<int> list {1, 2 ,3 ,4, 5};
    ReverseList(list.begin());


}