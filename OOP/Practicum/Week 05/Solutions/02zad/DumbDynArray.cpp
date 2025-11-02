#include "DumbDynArray.hpp"
#include <iostream>
#include <cstring>

bool DumbDynArray::IsDigit(char const a) const{
    return a >='0' && a <= '9';
}
unsigned DumbDynArray::FindDigits(char* const arr) const{
    unsigned output = 0;
    for (size_t i = 0; i < strlen(arr); i++)
        if(IsDigit(arr[i]))
            output++;
    return output;
}
void DumbDynArray::AssignDigits(char* const arr){
    unsigned index = 0;
    for (size_t i = 0; i < strlen(arr); i++)
    {
        if(IsDigit(arr[i])){
            this->array[index] = arr[i]; 
            index++;
        }
    }
}

DumbDynArray::DumbDynArray(char* const arr){
    this->size = FindDigits(arr);
    this->array = new(std::nothrow) char[size];
    AssignDigits(arr);
}
DumbDynArray::~DumbDynArray(){
    if(array)
        delete[] array;
}
void DumbDynArray::Print(){
    for (size_t i = 0; i < this->size; i++)
        std::cout << this->array[i];
}


