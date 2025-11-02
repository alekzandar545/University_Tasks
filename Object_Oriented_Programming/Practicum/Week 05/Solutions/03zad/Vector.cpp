#include <iostream>
#include "Vector.hpp"

size_t nextPow(size_t a){
    size_t output = 1;
    while(output < a){
        output *= 2;
    }
    return output;
}

void Vector::Resize(size_t size){
    if(size <= this->capacity){
        std::cout << "Cant shrink!";
        return;
    }
    int* newArr = new(std::nothrow) int[nextPow(size)];
    for (size_t i = 0; i < this->size; i++)
    {
        newArr[i] = this->arr[i];
    }
    delete[] this->arr;
    this->arr = newArr;
}
void Vector::Clear(){
    delete[] arr;
}
Vector::Vector(){
    this->size = 0;
    this->capacity = 0;
    this->arr = nullptr;
}
Vector::Vector(size_t capacity){
    this->size = 0;
    if(capacity == 0){
        this->capacity = 0;
        this->arr = nullptr; 
        return;
    }
    this->capacity = nextPow(capacity);
    this->arr = new(std::nothrow) int[capacity];
}
Vector::Vector(size_t capacity, int a){
    this->size = 0;
    if(capacity == 0){
        this->capacity = 0;
        this->arr = nullptr; 
        return;
    }
    this->capacity = nextPow(capacity);
    this->arr = new(std::nothrow) int[capacity];
    for (size_t i = 0; i < this->capacity; i++)
        arr[i] = a;
}
Vector::~Vector(){
    this->Clear();
}
//functionality
int Vector::At(size_t index) const{
    if(index > this->size + 1){
        std::cout << "Invalid index!";
        return;
    }
    return this->arr[index];
}
void Vector::SetAt(size_t index, int value){
    if(index > this->size + 1){
        std::cout << "Invalid index!";
        return;
    } 
    //if index is too big create more room or nah>?
}
void Vector::RemoveAt(size_t index){

}
void Vector::PushBack(int value){

}
bool Vector::Empty() const{

}
size_t Vector::Size() const{
    return this->size;
}
size_t Vector::Capacity() const{
    return this->size;
}
