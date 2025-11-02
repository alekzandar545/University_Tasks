#include <iostream>

struct int_array
{
    int* arr;
    unsigned int size;
};

int_array duplicate(int_array arr){
    int_array output;
    output.size = arr.size*2;
    int index = 0;
    for (size_t i = 0; i < arr.size; i++)
    {
        output.arr[index] = arr.arr[i];
        output.arr[index+1] = arr.arr[i];
        index+=2;
    }
    return output;   
}


int main(){
    /*Задача 2. Нека е дадена следната структура, описваща масив в динамичната памет:

    struct int_array { int *arr; unsigned int size; };

    Да се дефинира подходяща функция duplicate(a), която по масив от числа създава в динамичната памет и връща масив,
    в който всеки от елементите на a се среща два пъти последователно.
    Например, за масива [1,2,2,3], резултатът ще бъде [1,1,2,2,2,2,3,3].*/
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
    int_array newarr = duplicate(array);
    if(!newarr.arr){
        std::cout << "Memory error";
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