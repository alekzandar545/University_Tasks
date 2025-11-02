#include <iostream>


struct Interval
{
    unsigned from, to;
    Interval(unsigned from, unsigned to) : from(std::min(from,to)), to(std::max(from,to)){}
    Interval() : from(0), to(0){}

    friend std::ostream& operator<<(std::ostream& os, const Interval& interval) {
        os << "(" << interval.from << ", " << interval.to << ")";
        return os;
    }
};

template <class DataType>
class List{
private:
    struct Node
    {
        DataType val;
        Node* next;
        Node* prev;

        Node(DataType val, Node* next, Node* prev) : val(val), next(next), prev(prev){}
        Node(DataType val) : val(val), next(nullptr), prev(nullptr){}
    };

    Node* sentinel;
    unsigned length;

    void clear(){
        Node* curr = sentinel->next;
        while (curr != sentinel) {
            Node* toDelete = curr;
            curr = curr->next;
            delete toDelete;
        }
        delete sentinel;
    }

    void copy(const List& other){
        for(DataType curr : other)
            insertBack(curr);
    }
public:
    List() : length(0), sentinel(new Node(DataType())){
        sentinel->prev = sentinel;
        sentinel->next = sentinel;
    }
    ~List(){clear();}
    List(const List& other) : length (other.length), sentinel(new Node(DataType())) {
        sentinel->prev = sentinel;
        sentinel->next = sentinel;
        copy(other);
    }
    List(List&& other) noexcept{
        std::swap(sentinel, other.sentinel);
        std::swap(length, other.length);
    }
    List& operator=(const List& other){
        if(this != &other){
            *this = List(other);
        }
        return *this;
    }
    List& operator=(List&& other){
        if(this != &other){
            std::swap(sentinel, other.sentinel);
            std::swap(length, other.length);   
        }
        return *this;
    }

    class Iterator{
    private:
        friend class List;

        Node* ptr;
        const List& owner;

        Iterator(Node* ptr, const List& list) : ptr(ptr), owner(list){}
    public:
        bool valid() const {return ptr;}
        operator bool() const {return ptr && ptr != &(owner.sentinel); }

        DataType* operator->(){return &ptr->val;}
        DataType& operator*(){return ptr->val;}
                
        const DataType* operator->()const{return &ptr->val;}
        const DataType& operator*()const{return ptr->val;}

        Iterator& operator++(){
            if(valid()) ptr = ptr->next;
            return *this;
        }
        Iterator operator++(int){
            Iterator curr = *this;
            ++*this;
            return curr;
        }

        Iterator& operator--(){
            if(valid()) ptr = ptr->prev;
            return *this;
        }
        Iterator operator--(int){
            Iterator curr = *this;
            --*this;
            return curr;
        }
        
        bool operator==(const Iterator& other) const {
            return ptr == other.ptr;
        }

        bool operator!=(const Iterator& other) const {
            return !(*this == other);
        }
    };

    Iterator begin(){return Iterator(sentinel->next, *this);}
    Iterator end(){return Iterator(sentinel, *this);}
    
    Iterator begin()const{return Iterator(sentinel->next, *this);}
    Iterator end()const{return Iterator(sentinel, *this);}

    void insertFront(DataType value) {
        Node* newNode = new Node{value, sentinel->next, sentinel};
        sentinel->next->prev = newNode;
        sentinel->next = newNode;
        length++;
    }

    void insertBack(DataType value) {
        Node* newNode = new Node{value, sentinel, sentinel->prev};
        sentinel->prev->next = newNode;
        sentinel->prev = newNode;
        length++;
    }

    void print() const{
        for(DataType curr : *this){
            std:: cout << curr << " ";
        }
    }

    static void sumSublists(List<int>& nodes, const List<Interval>& Intervals){
        for (Interval interval : Intervals){
            nodes.sumSublist(interval);
        }
    }

    void sumSublist(const Interval& interval){
        if(interval.to >= length)
            throw std::out_of_range("Invalid interval!");
        
        unsigned from = interval.from;
        unsigned to = interval.to;

        Node* curr = sentinel->next;

        for (size_t i = 0; i < from; i++)
            curr = curr->next;

        //get next, sum and delete (to - from times)
        for (size_t i = 0; i < (to - from); i++)
        {
            if(curr->next == sentinel) break;
            curr->val += curr->next->val;
            removeNode(curr->next);
        }
    }

    void removeNode(Node* curr){
        if(curr == sentinel) return;

        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
        length--;
    }
    
};




int main(){
    unsigned intervalsCount, nodesCount;
    std::cout << "Enter number of intervals: ";
    std::cin >> intervalsCount;
    std::cout << "Enter number of nodes in list: ";
    std::cin >> nodesCount;
    
    //initiate intervalsList
    List<Interval> intervals;
    std::cout << "Type out the intervals: \n";
    for (size_t i = 0; i < intervalsCount; i++)
    {
        unsigned from, to;
        std::cin >> from >> to;
        Interval interval(from, to);
        intervals.insertBack(interval);
    }
    
    //initiate nodesList
    List<int> nodes;
        std::cout << "Type out the nodes: \n";
    for (size_t i = 0; i < nodesCount; i++)
    {
        int value;
        std::cin >> value;
        nodes.insertBack(value);
    }
    List<int> nodes2 = nodes;
    List<int>::sumSublists(nodes2, intervals);

    nodes2.print();
    std::cout << std::endl;
    intervals.print();
}