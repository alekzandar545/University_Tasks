#include <iostream>

template <typename P>
class Sorted{
private:
    P arr[128];
    size_t size;
public:
    void Sort(){
        for (size_t i = 0; i < size; i++)
        {
            
            for (size_t j = 0; j < size-i; j++)
            {
                if(arr[j-1] > arr[j]){
                    P temp = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = temp;
                }
            }
            
        }
        
    }
    Sorted(){
        size = 0;
    }
    Sorted(size_t size){
        this->size = size;
    }
    Sorted(const P* arr, size_t size){
        this->size = size;
        for (size_t i = 0; i < size; i++)
        {
            this->arr[i] = arr[i];
        }
        this->Sort();
    }
    Sorted(const Sorted& other){
        copy(other);
    }
    Sorted& operator=(const Sorted& other) const{
        if(this != &other){
            copy(other);
        }
        return *this;
    }
    ~Sorted() = default;
    //setters
    void setArr(const P* arr, size_t size){
        Sorted sorted(arr, size);
        this->copy(sorted);
    }
    //getters
    P* getArr() const{
        return this->arr;
    }
    size_t getSize() const{
        return this->size;
    }
    //functionality
    void copy(const Sorted& other){
        this->size = other.size;
        for (size_t i = 0; i < size; i++)
        {
            this->arr[i] = other.arr[i];
        }
    }
    void add(P elem){
        if(size+1 == 128)
            return;
        arr[size+1] = elem;
        size++;
        this->Sort();
    }
    void remove(P elem){
        for (size_t i = 0; i < size; i++)
        {
            if (arr[i] == elem){
                P temp = arr[i];
                arr[i] = arr[size-1];
                arr[size-1] = temp;
                size--;
            }
        }
        this->Sort();
    }
    void print() const{
        for (size_t i = 0; i < size; i++)
        {
            std::cout << arr[i] << ' ';
        }
        
    }
};

int main(){
    int arr[]={1, 2, 4 ,5, 3};
    size_t size = 5;
    Sorted<int> sorted(arr, size);
    int a = 4;
    //std::cout << a;
    sorted.add(a);
    //std::cout << a;
    sorted.remove(a);
    sorted.add(a);
    sorted.add(a);
    sorted.add(a);
    sorted.add(a);
    sorted.add(a);
    sorted.print();
}