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

void swap(State* start, State* end){
    State temp(0);
    swapOutside(start, &temp);
    swapOutside(end, start);
    swapOutside(&temp, end);
}

void CheckSides(State* n, int k){
    State* curr = n;
    State* old = curr;
    int counter = 0;
    // //check back and swap?
    while(curr->prev && counter < k){
        if(curr->val < curr->prev->val){
            swap(curr, curr->prev);
            counter++;
            continue;
        }
        counter++;
        curr = curr->prev;
    }
    //check forward and swap?
    curr = old;
    counter = 0;
    while(curr->next && counter < k){
        if(curr->val > curr->next->val){
            swap(curr, curr->next);
            counter++;
            continue;
        }
        counter++;
        curr = curr->next;
    }
}

void SortOffset(State* n1, int k){
    State* curr = n1;
    while(curr){
        CheckSides(curr, k);
        curr = curr->next;
    }
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
    int k;
    std::cin >> k;

    //constructing the list
    State *n1 = new State(2);
    State *n2 = new State(5);
    State *n3 = new State(15);
    State *n4 = new State(3);
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
    
    SortOffset(n1, k);

    print(n1);

    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
}