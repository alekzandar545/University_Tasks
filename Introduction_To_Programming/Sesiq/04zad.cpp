#include <iostream>

void swap(int*arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void pivot(int* arr, unsigned size, int x){
    bool valid = true;
    
    for (size_t i = 0; i < size - 1; i++)
    {
        if(arr[i] > x){
            swap(arr, i, i+1);
            pivot(arr, size-1, x);
        }
    }
    return;
}

int main(){
    /*Задача 4. Да се дефинира функция pivot с подходящи параметри, която получава масив от числа (int) с произолна големина
    и число x от тип int. Функцията да пренареди елементите на масива така, че всички елементи, по-малки или равни на x да
    предшестват елементите, по-големи или равни на x. Например, за масива [1,6,3,9,5,12] и x=7, една възможна подредба на
    елементите на масива би била [1,6,3,5,9,12]*/
    unsigned size;
    std::cin >> size;
    int* arr = new(std::nothrow) int[size];
    if(!arr){
        std::cout << "Memory error";
        return 0;
    }
    for (size_t i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }
    pivot(arr, size, 0);
    for (size_t i = 0; i < size; i++)
    {
        std::cout << arr[i] << ' '; 
    }

    delete[] arr;
    return 0;
}