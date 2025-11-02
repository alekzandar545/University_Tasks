#include <iostream>
#include <list>

//Да се напише функция, която получава начало на едносвързан сисък и число К, и 
//връща стойността на възела, който се наимра на к-тата позиция отзад напред
//O(n) time O(1) memory

//pravim s buffer ot k elementa i kato kraq mu stigne nullptr, znachi sme stignali
//va nachaloto na buffera do nashiq element

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

int main(){


}