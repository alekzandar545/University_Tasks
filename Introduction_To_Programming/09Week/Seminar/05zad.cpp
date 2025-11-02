#include <iostream>

/*Задача 5 Да се напише функция, която при подаден масив с дължина 2*n, намира дали масивът може да се раздели на n двойки,
за които са изпълнени следните условия:

Всеки елемент от масива може да участва само в една двойка.
Числата във всяка двойка да са равни.
Функцията да връща true ако такова разпределение е възможно и false в противен случай.*/

int main(){
    int size;
    std::cin >> size;
    if(size % 2 != 0)
        return 0;
    int* arr = new(std::nothrow) int[size];
    if(!arr){
        std::cout << "Memory error!";
        return -1;
    }
    for (size_t i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }
    //sort
    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = 0; j < size - 1 - i; j++)
        {
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    //check for pairs with equal elements
    bool output = true;
    for (size_t i = 1; i < size; i+=2)
    {
        if(arr[i] != arr[i-1]){
            output = false;
            break;
        }     
    }
    
    std::cout << std::boolalpha << output;
    
    delete[] arr;
}