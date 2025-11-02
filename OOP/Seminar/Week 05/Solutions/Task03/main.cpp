#include <iostream>
#include <cmath>
#define DEFAULF_MAXSIZE 10
class Polynomial{
private:
    int* values;
    size_t capacity;
    size_t size;
    //not adding resize as it is not required
public:
    //fundaments
    Polynomial();
    Polynomial(const size_t size);
    Polynomial(const Polynomial& other);
    Polynomial& operator=(const Polynomial& other);
    ~Polynomial();
    //setters
    void setValues(int* arr, size_t size);
    //funtionallity
    void copy(const Polynomial& other);
    void add(const int a);
    int getSum() const;
    void removeLast();
    void changeAt(const int value, const size_t pos);
};
//fundaments
Polynomial::Polynomial(){
    size = 0;
    capacity = DEFAULF_MAXSIZE;
    values = new(std::nothrow) int[capacity];
    if(!values){
        std::cout << "Memory error!";
        return;
    }
}
Polynomial::Polynomial(const size_t size){
    this->size = 0;
    this->capacity = size;
    values = new(std::nothrow) int[this->capacity];
    if(!values){
        std::cout << "Memory error!";
        return;
    }
}
Polynomial::Polynomial(const Polynomial& other){
    copy(other);
}
Polynomial& Polynomial::operator=(const Polynomial& other){
    if(this != &other){
        if(values)
            delete[] values;
        copy(other);
    }
    return *this;
}
Polynomial::~Polynomial(){
    delete[] values;
}

//setters
void Polynomial::setValues(int* arr, size_t size){
    if(size > this->capacity){
        std::cout << "Error!";
        return;
    }
    this->size = size;
    for (size_t i = 0; i < size; i++)
    {
        values[i] = arr[i];
    }
}
//funtionallity
void Polynomial::copy(const Polynomial& other){
    delete[] values;
    capacity = other.capacity;
    values = new(std::nothrow) int[capacity];
    for (size_t i = 0; i < capacity; i++)
    {
        values[i] = other.values[i];
    }
}
void Polynomial::add(const int a){
    if(size == capacity){
        std::cout << "Cannot add more!";
        return;
    }
    values[size++] = a;
}
int Polynomial::getSum() const{
    int sum = 0;
    for (size_t i = 0; i < size; i++)
    {
        sum += pow(values[i],i); 
    }
    return sum;
}
void Polynomial::removeLast(){
    values[size--] = 0;
}
void Polynomial::changeAt(const int value, const size_t pos){
    if(pos < 0 || pos >= size){
        std::cout << "Error index!";
        return;
    }
    values[pos] = value;
}
int main(){
Polynomial sumator;
sumator.add(4);
sumator.add(2);

std::cout << sumator.getSum(); //- 3

sumator.add(5);

std::cout << sumator.getSum(); //- 28

sumator.removeLast();

std::cout << sumator.getSum(); //- 3

sumator.changeAt(5, 1);

std::cout << sumator.getSum(); //- 6
}