#include <iostream>

struct int_array{
    int* arr;
    unsigned int size;
};

int_array filter_evens(int* arr, unsigned size){
    int_array output;
    output.size = 0;
    for (size_t i = 0; i < size; i++)
    {
        if(arr[i] % 2 == 0)
            output.size++;
    }

    output.arr = new(std::nothrow) int[output.size];

    int index = 0;
    for (size_t i = 0; i < size; i++)
    {
        if(arr[i] % 2 == 0){
            output.arr[index] = arr[i];
            index++;
        }
    }
    return output;
}

int main(){
    /*Задача 2. Нека е дадена следната структура, описваща масив в динамичната памет:

    struct int_array { int *arr; unsigned int size; };

    Да се дефинира подходяща функция filter_evens, която по масив от числа създава в динамичната памет
    и връща масив само с тези от числата, които са четни.*/

    int_array array;
    std::cin >> array.size;
    array.arr = new(std::nothrow) int[array.size];
    if(!array.arr){
        std::cout << "Memory error!";
        return 0;
    }
    for (size_t i = 0; i < array.size; i++)
    {
        std::cin >> array.arr[i];
    }
    int_array newarr = filter_evens(array.arr, array.size);
    if(!newarr.arr){
        std::cout << "Memory error!";
        delete[] array.arr;
        return 0;
    }
    
    for (size_t i = 0; i < newarr.size; i++)
    {
        std::cout << newarr.arr[i] << ' ';
    }

    delete[] newarr.arr;
    delete[] array.arr;

    return 0;
}