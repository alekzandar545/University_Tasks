#include <iostream>

void PrintArray(int* arr, const size_t size){
    for (size_t i = 0; i < size; i++)
    {
        int* currentAdress = arr + i;
        std::cout << *currentAdress;
    }
    
}

int main(){
    /*Създайте функция void PrintArray(const int* arr, const size_t size),
    която отпечатва масив от цели числа. Използвайте указателна аритметика.*/
    int size;
    std::cin >> size;
    int* arr = new(std::nothrow) int[size];
    if(!arr){
        std::cout << "Memory error!";
        return -1;
    }
    for (size_t i = 0; i < size; i++)
    {
        int* currentAdress = arr + i;
        std::cin >> *currentAdress;
    }
    
    PrintArray(arr, size);

    delete[] arr;
    
}