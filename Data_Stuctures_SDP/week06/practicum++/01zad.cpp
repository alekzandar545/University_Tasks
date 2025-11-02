#include <iostream>
#include "Node.h"
/*Реализирайте функция void removeConsecutiveDuplicates(Node* lst), която премахва всички последователни 
повторения на елементи от двусвързания списък lst. Премахнатите елементи да се унищожават с delete.*/

void removeConsecutiveDuplicates(Node<int>* lst){
    Node<int>* nextNode = lst->next;
    while(nextNode){
        if(lst->value == nextNode->value){
            Node<int>* toDelete = nextNode;
            nextNode = nextNode->next;
            if(toDelete->next)
                toDelete->next->prev = toDelete->prev;
            if(toDelete->prev)
                toDelete->prev->next = toDelete->next;
            toDelete->next = nullptr;
            toDelete->prev = nullptr;
            delete toDelete;
            continue;
        }
        nextNode = nextNode->next;
        lst = lst->next;
    }
}

// /Да се дефинира функция mirror, която добавя към свързан списък неговото огледално копие.

void mirror(Node<int>* head){
    
}

int main(){
    Node<int>* head = new Node<int>(1);

    // Values to add
    int values[] = {1, 2, 2, 1, 1, 2, 2, 2, 2, 1, 2, 1, 2};
    int size = sizeof(values) / sizeof(values[0]);
    // Adding the values to the list
    for (int i = 0; i < size; ++i) {
        head->add(values[i]);
    }
    removeConsecutiveDuplicates(head);
    // Printing the list
    head->print();

    // Clean up
    delete head;

    return 0;
}