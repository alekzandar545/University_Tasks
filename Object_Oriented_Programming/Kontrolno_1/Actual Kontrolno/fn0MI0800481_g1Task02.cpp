#include <iostream>

#define DEFAULT_CAPACITY 10

//not pretty because no header part :(
template <typename P>
class BoundSet{
private:
    P* arr;
    size_t capacity;
    size_t size;

    void Copy(const BoundSet& other){
        capacity = other.capacity;
        size = other.size; 
        arr = new(std::nothrow) P[capacity];
        if(!arr){
            std::cout << "Memory error!";
            return;
        }
        for (size_t i = 0; i < size; i++)
        {
            arr[i] = other.arr[i];
        }
    }
    void Swap(size_t i1, size_t i2){
        P temp = arr[i1];
        arr[i1] = arr[i2];
        arr[i2] = temp;
    }

public:
    //basics
    BoundSet(){
        capacity = DEFAULT_CAPACITY;
        size = 0;
        arr = new(std::nothrow) P[capacity];
        if(!arr){
            std::cout << "Memory error!";
            return;
        }
    }
    BoundSet(const size_t capacity){
        this->capacity = capacity;
        size = 0;
        arr = new(std::nothrow) P[this->capacity];
        if(!arr){
            std::cout << "Memory error!";
            return;
        }
    }
    BoundSet(const P* arr, const size_t size){
        //add some breathing room
        capacity = size + 10;
        this->size = 0;
        this->arr = new(std::nothrow) P[capacity];
        if(!arr){
            std::cout << "Memory error!";
            return;
        }
        for (size_t i = 0; i < size; i++)
        {   
            this->add(arr[i]);
        }
    }
    BoundSet(const BoundSet& other){
        Copy(other);
    }
    BoundSet& operator=(const BoundSet& other){
        if(this != &other){
            delete[] arr;
            Copy(other);
        }
        return *this;
    }
    ~BoundSet(){
        delete[] arr;
    }
    //getters/setters
    size_t getSize() const{
        return size;
    }
    size_t getCapacity() const{
        return capacity;
    }
    //functionality
    BoundSet operator+(const BoundSet& other) const{
        BoundSet<P> output(size + other.size);
        for (size_t i = 0; i < size; i++)
        {
            output.add(arr[i]);
        }
        for (size_t i = 0; i < other.size; i++)
        {
            output.add(other.arr[i]);
        }
        return output;
    }
    BoundSet& operator+=(const BoundSet& other){
        if(size + other.size > capacity){
            //resizing not allowed
            std::cout << "Not enough memory!";
            return *this;
        }
        for (size_t i = 0; i < other.size; i++)
        {
            this->add(other.arr[i]);
        }
        return *this;
    }
    void add(const P element){
        if(size == capacity){
            //resizing not allowed
            std::cout << "No more capacity!";
        }
        if(!this->member(element)){
            arr[size++] = element;
        }
    }
    void remove(const P element){
        for (size_t i = 0; i < size; i++)
        {
            if(arr[i] == element){
                Swap(i, size);
                size--;
                i--;
            }
        }
    }
    bool member(const P element) const{
        for (size_t i = 0; i < size; i++)
        {
            if(arr[i] == element)
                return true;
        }
        return false;
    }
    void print() const{
        for (size_t i = 0; i < size; i++)
        {
            std::cout << arr[i] << ' ';
        }
    }
};

int main(){
    //testing
    int arr[] = {1, 2, 2, 4, 4};
    BoundSet<int> set(arr, 5);
    set.add(3);std::cout << "///" << set.getSize() <<"///\n";
    set.add(3); std::cout << "///" << set.getSize() <<"///\n";
    set.print();
    set.remove(3);std::cout << "///" << set.getSize() <<"///\n";
    BoundSet<int> bonus;
    bonus.add(2);
    (set+bonus).print();
    set.add(5);
    set.add(6);
    set.print();

    return 0;
}