#include <iostream>
#include <list>

//По дадедо число К да се напише функция, която прави К ротации на спсъка.
//Една ротация преместа последния елемент на първо място

//time 0(n) memory 0(1)

//izpolzvame minalata zadacha da namerim noviq ni head
Node* FindLastK(Node* head, int k){
    Node* goal = head;
    int cnt = 0;
    for (size_t i = 0; (i < k) && head; i++) && head podsigurqva che ne izlizame
    {
        cnt++;
        head = head->next; //davame prednina na prednata chast na buffer
    }
    if(cnt > 0)//moje vmesto s counter da proverim dali i = k-1
        return nullptr;
    while(head){
        
        head = head->next; //dvijim celiq buffer
        goal = goal->next;
    }
    return goal;
    
}

void Rotate (Node*& head, int k){
    int size; //smqtame s 1 obhojdane
    k %= size;
    Node* newFirst = FindLastK(head,k);
    Node* curr = head;
    while(curr->next != newFirst){
        curr = curr->next;
    }
    curr->next = nullptr;
    curr = newFirst;
    while(curr->next){
        curr = curr->next;
    }
    curr->next = head;
    head = newFirst;
}
int main(){

}