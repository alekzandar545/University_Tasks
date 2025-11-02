#pragma once
#include <iostream>
#include <cassert>


template <class T>

class List{
    public:
    struct Node
    {
        T data;
        Node* next;

        Node(T val) : data(val), next(nullptr){}
        Node() : next(nullptr){}
    };

    Node* head;
    Node* tail;

    List() : head(nullptr), tail(nullptr){}

    ~List(){
        if(head){
        while(head->next){
                Node* old = head;
                head = head->next;
                delete old;
            }
        delete head;
        }

    }

    void push_front(T data){
        Node* newNode = new Node(data);
        if(!head)
            tail = newNode;
        newNode->next = head;
        head = newNode;
    }
    
    void push_back(T data){
        Node* newNode = new Node(data);
        if(!tail){
            head = newNode;
        }
        else
            tail->next = newNode;
        tail = newNode;
    }

    T pop_front(){
        Node* n = head;
        T x = head->data;
        assert(head);
        head = head->next;
        delete n;
        
        return x;
    }
    T pop_right(Node* curr){
        Node* n = curr->next;
        T x = curr->data;
        if(curr->next->next)
            curr->next = curr->next->next; 

        delete n;
        return x;
    }
    //Iterator testin
    class iterator{
        friend class List<T>;
        private:
        List<T>::Node* ptr;
        const List<T>& owner;
        iterator(List<T>::Node* ptr, const List<T>& creator) : ptr(ptr), owner(creator) {}

        public:
        bool valid() const { return ptr; }
        operator bool() const { return ptr; }

        T& operator*() { return ptr->data; }
        T* operator->() { return &ptr->data; }
        const T& operator*() const { return ptr->data; }
        const T* operator->() const { return &ptr->data; }

        iterator& operator++()
        {
            ptr = ptr->next;
            return *this;
        }
        iterator operator++(int)
        {
            iterator res = *this;
            ++*this;
            return res;
        }

        bool operator == (const iterator& rhs) const
        {
            return ptr == rhs.ptr;
        }
        bool operator != (const iterator& rhs) const
        {
            return !(*this == rhs);
        }
    };
    iterator begin(){return iterator(this->head, *this);}
    iterator end()const{return iterator(nullptr, *this);}
};
