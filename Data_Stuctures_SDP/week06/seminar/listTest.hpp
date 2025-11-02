#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>

/*steps when writing implementation
1. Validation
2. Logic
3. Integrity /CQLOST
4. Memory leaks*/

    struct State{
        State* next;
        int val;
        State(int v, State* n = nullptr): val(v), next(n){};
    };

class List{

    State* head; //we can replace this with sentinel which lets us use iterator from beginning
    State* tail;
    size_t size;

    void push_front(int el){
        head = new State(el, head);
        if(!tail)
            tail = head;
        size++;
    }
    void push_back(int el){
        if(!tail){
            tail = new State(el, nullptr);
            head = tail;
        }
        else{
            tail->next = new State(el, nullptr);
            tail = tail->next;
        }
        size++;
    }
    void push_at(int el, size_t pos){
        if(pos > size)
            throw std::invalid_argument("rip");
        if(pos == 0){
            push_front(el); //adds size
            return;
        }
        else if (pos == size){
            push_back(el); //adds size
            return;
        }
        else{
            State* curr = head;
            for (size_t i = 0; i < pos-1; i++)
                curr = curr->next;
            curr->next = new State(el, curr->next);
            size++;
        }
    }
    int pop_front(){
        if(empty())
            throw std::underflow_error("poop");
        State* temp = head;
        head = head->next;
        if(!head)
            tail = head;
        size--;
        int result = temp->val;
        delete temp;
        return result; //can void it too just remove this line and one above
    }
    void pop_back(){
        if(empty())
            throw std::overflow_error("poop");
        State* temp = head;
        while(temp->next != tail){ //problem when only 1 element

        }
    }
    void pop_at(size_t pos){
        if(empty())
            throw std::underflow_error("ript");
        if(pos >= size)
            throw std::overflow_error("ript");
        State* temp;
        if(pos == 0){
            temp = head;
            head = head->next;
            if(!head)
                tail = head;
        }
        else if(pos == size-1){
            State* curr = head;
            while(curr->next != tail)
                curr = curr->next;
            curr->next = nullptr;
            temp = tail;
            tail = curr;
        }
        else{
            State* curr = head;
            for (size_t i = 0; i < pos-1; i++)
                curr= curr ->next;
            temp = curr->next;
            curr->next = curr->next->next;
        }
        delete temp;
        size--;
    }
    int front(){
        if(empty())
            throw std::underflow_error("s");
        return head->val;
    };
    int back(){
        if(empty())
            throw std::overflow_error("s");
        return tail->val;
    };
    int at(size_t pos){};
    bool empty(){return !size;};

    class Iterator{
        State* ptr;
        List& owner; //pozvolqva push_After i da proverqvame dali rabotim v same spisuk
        friend class List;
    };

    Iterator begin(){
        return Iterator(head, *this);
    }
    Iterator end(){
        return Iterator(nullptr, *this); //nullptr za da mojem da obhodim i tail
    }
    void push_After(int el, Iterator it){
        if(&it.owner != this)
            throw std::invalid_argument("sdasd");
        if(it == end())
            throw std::invalid_argument("sdasd");
        it.ptr->next = new State(el, it.ptr->next);
        if(tail == it.ptr)
            tail = it.ptr->next;
        size++;
    }
    void popAfter(int el, Iterator it){
        if(&it.owner != this)
            throw std::invalid_argument("sdasd");
        if(it == end() || it.ptr == tail)
            throw std::invalid_argument("sdasd");
        State* temp = it.ptr->next;
        it.ptr->next = temp->next;
        it.ptr->next = new State(el, it.ptr->next);
        if(temp == tail)
            tail = it.ptr->next;
        delete temp;
        size--;
    }
};