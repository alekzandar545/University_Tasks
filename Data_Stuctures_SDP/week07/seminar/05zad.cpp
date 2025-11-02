#include <iostream>

struct State{
    int val;
    State *next, *prev, *down;
    State(int v) : val(v), next(nullptr), prev(nullptr), down(nullptr){}
};

State* flattenUntil(State* head){
    if(!head)
        return head;
    State* prev = nullptr;
    State* curr = head;
    State* downEnd;
    while(curr){
        if(curr->down){
            downEnd = flattenUntil(curr->down);
            downEnd->next = curr->next;
            if(curr->next)
                curr->next->prev = downEnd;
            curr->next = curr->down;
            curr->down->prev = curr;
            curr->down = nullptr;

            curr = downEnd->next;
            prev = downEnd;
        }
        prev = curr;
        curr = curr->next;
    }
    return prev;
}



State* flatten(State* head){
    if(!head) return head;
    flattenUntil(head);
    return head;
}

int main(){
    State* n1 = new State ({1});
    State* n2 = new State ({2});
    State* n3 = new State ({3});
    State* n4 = new State ({4});
    State* n5 = new State ({5});
    State* n6 = new State ({6});
    State* n7 = new State ({7});
    State* n8 = new State ({8});
    State* n9 = new State ({9});
    State* n10 = new State ({10});

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    
    n4->prev = n3;
    n3->prev = n2;
    n2->prev = n1;

    n2->down = n5;

    n5->next = n6;
    n6->next = n7;
    n7->next = n8;

    n8->prev = n7;
    n7->prev = n6;
    n6->prev = n5;

    n6->down = n9;

    n9->next = n10;
    n10->prev = n9;

    flatten(n1);
    State* curr = n4;
    while(curr){
        std::cout << curr->val << ' ' << '\n';
        curr = curr->prev;
    }

    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
    delete n6;
    delete n7;
    delete n8;
    delete n9;
    delete n10;    
}