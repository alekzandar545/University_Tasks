//da se nameri purviqt element v koito dva converginh spisuka se slivat
//O(N1 + N2) / O(N1 . N2) slojnost
//minavame spisuk1 zallepen sus spisuk2
//paralelno minavame spisuk2 zalepen sus spisuk1
//kudeto convergenat, tam im e obshtiq element

...(Node* headA, Node* headB){
    Node* head1 = headA;
    Node* head2 = headB;
    while(head1 != head2){
        head1 = head1->next ? head1->next : headB; //butai headA i headB kato stignesh vtoroto uslovie
        head2 = head2->next ? head2->next : headA;
    }
    return head1;
}

int main(){

}