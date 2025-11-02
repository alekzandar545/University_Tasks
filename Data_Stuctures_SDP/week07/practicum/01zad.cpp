#include <iostream>

struct State
{
    int val;
    State *next, *prev;
    State(int v, State* n = nullptr, State* p = nullptr) : val(v), next(n), prev(p) {}
};


void print(State* head){
    State* curr = head;
    while(curr){
        std::cout << curr->val << ' ';
        curr = curr->next;
    }
    std::cout << '\n';
}

State* RemoveDuplicatesRec(State* originalStart, State* newStart){
    if(!newStart){
        return originalStart;
    }
    State* curr = newStart->next;
    while(curr){
        if(curr->val == newStart->val){
            //deleting curr
            State* temp = curr;
            if(curr->prev)
                curr->prev->next = curr->next;
            if(curr->next)
                curr->next->prev = curr->prev;
            curr = curr->next;
            delete temp;
        }
        else

            curr = curr->next;
    }
    return RemoveDuplicatesRec(originalStart, newStart->next);
}

State* RemoveDuplicates(State* start){
    return RemoveDuplicatesRec(start, start);
}

void deleteList(State* head) {
    while (head) {
        State* temp = head;
        head = head->next;
        delete temp;
    }
}

int main(){
    //constructing the list
    State *n1 = new State(1);
    State *n2 = new State(2);
    State *n3 = new State(3);
    State *n4 = new State(2);
    State *n5 = new State(1);
    n1->next = n2;
    n2->next = n3;
    n2->prev = n1;
    n3->next = n4;
    n3->prev = n2;
    n4->next = n5;
    n4->prev = n3;
    n5->prev = n4;
    print(n1);

    n1 = RemoveDuplicates(n1);
    
    print(n1);

    deleteList(n1);
}