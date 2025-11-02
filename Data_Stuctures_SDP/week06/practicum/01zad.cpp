#include <iostream>
#include <list>
#include <cassert>
/*Дадена е главата на сортиран свързан списък. 
Изтрийте всички дублиращи се елементи, така че всеки елемент 
да се появява само веднъж. Върнете списъка отново сортиран.
*/
struct State
{
    int data;
    State* next;

    State(int x) : data(x), next(nullptr){}
};
//alternatively do this implementation:
//Node n5(3,nullptr), n4(3,&n5), n3(2,&n4),.....
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
    //input
    List sortedList;
    size_t n;
    std::cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        int val;
        std::cin >> val;
        sortedList.push_front(val);
    }
    State* curr = sortedList.head;
    while(curr->next){
        if(curr->next->data == curr->data)
            sortedList.pop_right(curr);
        else
            curr = curr->next;
    }
    curr = sortedList.head;
    while(curr)
    {
        //std::cout << "test";
        std::cout << curr->data;
        curr = curr->next;
    }
    
    
    //sort
}