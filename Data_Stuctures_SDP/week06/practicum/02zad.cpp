#include <iostream>
#include <list>
#include <cassert>

//merge 2 sorted lists

struct State
{
    int data;
    State* next;

    State(int x) : data(x), next(nullptr){}
};

class List{
    public:

    State* head;

    List() : head(nullptr){}

    void push_front(int data){
        State* newNode = new State(data);
        newNode->next = head;
        head = newNode;
    }
    
    int pop_front(){
        State* n = head;
        int x = head->data;
        assert(head);
        head = head->next;
        delete n;
        
        return x;
    }
    int pop_right(State* curr){
        State* n = curr->next;
        int x = curr->data;
        if(curr->next->next)
            curr->next = curr->next->next; 

        delete n;
        return x;
    }
};


int main(){
    //input1
    List sortedList1;
    size_t n;
    std::cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        int val;
        std::cin >> val;
        sortedList1.push_front(val);
    }
    List sortedList2;
    //input2
    std::cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        int val;
        std::cin >> val;
        sortedList2.push_front(val);
    }
    List outputList;
    while(sortedList1.head || sortedList2.head){
        if(!sortedList2.head || ((sortedList1.head && sortedList2.head) &&
         (sortedList1.head->data > sortedList2.head->data)))
            outputList.push_front(sortedList1.pop_front());
        else
            outputList.push_front(sortedList2.pop_front());
    }

    State* curr = outputList.head;
    while(curr)
    {
        //std::cout << "test";
        std::cout << curr->data;
        curr = curr->next;
    }
}