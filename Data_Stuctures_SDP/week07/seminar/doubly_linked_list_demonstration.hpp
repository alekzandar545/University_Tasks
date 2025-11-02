#pragma once

template <class T>
class DList{
    struct Node{
        T data;
        Node* next;
        Node* prev;
    };
    Node* tail;
    Node* head;
    size_t size;
    T pop_at (size_t pos){
        if(pos>= size)
            throw; //.......
        Node* temp = head;
        T x = temp.data;
        for (size_t i = 0; i < pos; i++)
            temp = temp->next;
        if(size == 1){}
            head = tail = nullptr;
        else if(temp == head){
            temp->next->prev = nullptr;
            temp->next = head;
            }
        else if(temp == tail){
            temp->prev->next = nullptr;
            temp->prev = tail;
        }
        else{
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
        } //eentualno moje dva cikula;
        size--;
        delete temp;
        return x;
    }
    void push_at(size_t pos, const T& el){
        if(pos > size)
            throw; //.....
        if(size == 0){
            head = tail = new Node(el, nullptr, nullptr);
        }
        else if(pos == 0){
            head = new Node(el, head, nullptr);
            head->next->prev = head;

        }
        else if(pos == size){
            tail = new Node(el,nullptr, tail);
            tail->prev->next = tail;
        }
        else{
            Node* temp = head;
            for (size_t i = 0; i < pos; i++)
                temp = temp->next;
            Node* newNode = new Node(el, temp, temp->next);
            temp->next = newNode;
            newNode->next->prev = newNode;
        }
        size++;
    }
};
