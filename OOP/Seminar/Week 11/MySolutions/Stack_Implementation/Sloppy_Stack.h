#include <iostream>
#include <utility>
template <typename P>
struct Node{
    P data;
    Node* next;
    Node* prev;
    Node() : next(nullptr), prev(nullptr){}
    Node(const P& value) : data(value), next(nullptr), prev(nullptr) {}
    ~Node() = default;
};

template <typename P>
class Stack{
private:
    Node<P> node;
    unsigned size;
public:
    //big4
    Stack(){
        Node<P> el;
        this->node = el;
        size = 0;
    }

    //func
    void Push(P data){
        Node<P>* oldNode = new Node<P>(this->node);
        oldNode->next = &this->node;
        this->node.data = data;
        this->node.next = nullptr;
        this->node.prev = oldNode;
        size++;
    }
    P Peek(){
        return this->node.data;
    }
    P Pop(){
        P output = this->node.data;
        //std::cout << (*this->element.prev).data << "****" << this->size << "****";
        this->node = *(this->node.prev);
        size--;
        return output;
    }
    bool isEmpty() const{
        return size == 0;
    }
};