#include <iostream>
#include <cstring>

const size_t SIZE = 1024;

bool IsSaw(size_t size, int* arr){
    for (size_t i = 0; i < size - 1; i++)
    {
        if(i % 2 == 0 && arr[i] > arr[i+1])
            return false;
        else if(i % 2 != 0 && arr[i] < arr[i+1])
            return false;        
    }
    return true;
}

int main(){
    /*Задача 2. Да се напише булева функция, която получава цяло неотрицателно число n и масив от n цели числа. 
    Програмата да проверява дали въведените числа образуват редица „трион“. Редица „трион“ наричаме последователност, 
    за която е вярно, че a1 ≤ a2 ≥ a3 ≤ a4 ... или a1 ≥ a2 ≤ a3 ≥ a4 ...
    Използването на функцията да се демонстрира с извикване с примерен масив, стойностите 
    на чиито елементи се въвеждат от стандартния вход.*/
    int arr[SIZE];
    int size;
    std::cin >> size;
    for (size_t i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }
    std::cout << std::boolalpha << IsSaw(size, arr);
    
}