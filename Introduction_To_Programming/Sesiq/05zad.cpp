#include <iostream>

void swap(int* arr, unsigned const i, unsigned const j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void shift_left(int* arr, unsigned size, unsigned const n){
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = n - i - 1; j < size - 1; j++)
        {
            swap(arr, j, j+1);
        }
        size--;
    }
    
}

int main(){
    /*Задача 1. Да се дефинира функция shift_left с подходящи параметри, която получава масив от числа (int) с
    произолна големина и число n от тип unsigned int. Функцията да “премества” първите n елемента на масива в края му.
    Наприер, за масива [1,2,3,4,5,6,7] и n=3, резултатното подреждане на елементите ще е [4,5,6,7,1,2,3].*/
    unsigned size;
    std::cin >> size;
    int* arr = new(std::nothrow) int[size];
    if(!arr){
        std::cout << "Memory error!";
        return 0;
    }
    unsigned int n;
    std::cin >> n;
    for (size_t i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }
    
    if(n > size){
        std::cout << "Invalid input";
        return 0;
    }
    shift_left(arr, size, n);
    for (size_t i = 0; i < size; i++)
    {
        std::cout << arr[i] << ' ';
    }
    

    delete[] arr;
}