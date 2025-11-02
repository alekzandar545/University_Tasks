#include <iostream>

struct State
{
    int val;
    State *next, *other;
    State(int v, State* n = nullptr, State* p = nullptr) : val(v), next(n), other(p) {}
};

void print(State* head){
    State* curr = head;
    while(curr){
        if(curr->other)
            std::cout << curr->val << ' ' << curr->other->val << '\n';
        else    
            std::cout << curr->val << '\n';
        curr = curr->next;
    }
    std::cout << '\n';
}
//gonna go over thrice
//1. create intermediate elements
//2. connect the random pointers
//3. disconnect the 2 lists
void CreateIntermediates(State* start){
    
    while(start){
        State* temp = new State(start->val + 5);
        temp->next = start->next;
        start->next = temp;
        start = start->next->next;
    }
}
void ConnectRandoms(State* start){
    while(start){
        if(start->other)
            start->next->other = start->other->next;
        start = start->next->next;
    }
}

State* DisconnectLists(State* start) {
    if (!start)
        return nullptr;
    //trick is to do this simoltaniously
    State* newStart = start->next;
    State* currOld = start;
    State* currNew = newStart;

    while (currOld) {
        currOld->next = currNew->next;
        currOld = currOld->next;
        if (currOld) {
            currNew->next = currOld->next;
            currNew = currNew->next;
        }
    }
    return newStart;
}

State* CopyList(State* start){
    CreateIntermediates(start);
    ConnectRandoms(start);
    return DisconnectLists(start);
    return start;
}

int main(){
    //constructing the list
    State *n1 = new State(1);
    State *n2 = new State(2);
    State *n3 = new State(3);
    State *n4 = new State(4);
    State *n5 = new State(5);
    n1->next = n2;
    n1->other = n5;
    n2->next = n3;
    n2->other = n4;
    n3->next = n4;
    n3->other = n1;
    n4->next = n5;
    n4->other = n1;
    print(n1);
    
    print(CopyList(n1));

    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
}