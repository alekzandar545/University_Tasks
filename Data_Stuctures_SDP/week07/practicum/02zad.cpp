#include <iostream>

struct State
{
    int val;
    State *next, *prev;
    State(int v, State* n = nullptr, State* p = nullptr) : val(v), next(n), prev(p) {}
};

void swapOutside(State* inside, State* outside){
    if(inside->next)
        inside->next->prev = outside;
    if(inside->prev)
        inside->prev->next = outside;
    outside->prev = inside->prev;
    outside->next = inside->next;
}

State* Mirror( State *head, int k ){
    //validate later
    State* start = head;
    State* end = head;
    while (end && end->next)
    {
        end = end->next;
    }
    for (size_t i = 0; i < k-1; i++)
    {
        end = end->prev;
        start = start->next;
    }
    //works up until k/2t
    std::cout << "---" << start->val << ' ' << end->val << "---" << '\n';
    State temp(0);
    swapOutside(start, &temp);
    swapOutside(end, start);
    swapOutside(&temp, end);
    return k==1? end : head;
}

void print(State* head){
    State* curr = head;
    while(curr){
        std::cout << curr->val << ' ';
        curr = curr->next;
    }
    std::cout << '\n';
}

int main(){
    //constructing the list
    State *n1 = new State(5);
    State *n2 = new State(2);
    State *n3 = new State(15);
    State *n4 = new State(30);
    State *n5 = new State(4);
    n1->next = n2;
    n2->next = n3;
    n2->prev = n1;
    n3->next = n4;
    n3->prev = n2;
    n4->next = n5;
    n4->prev = n3;
    n5->prev = n4;
    print(n1);
    
    print(Mirror(n1, 4));

    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
}