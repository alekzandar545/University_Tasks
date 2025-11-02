#include <iostream>

const int SIZE = 100;

int FindSumLessThanK(int *arr, int size, int k){
    int counter = 0;
    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = i + 1; j < size; j++)
        {
            if(arr[i] + arr[j] < k)
                counter++;
        }
    }
    return counter;
}

int main(){
    /*Задача 7: Да се напише програма, в която се въвежда цяло положително число n и след
     това n на брой цели числа (елементи на масив). След което програмата да въвежда едно
      цяло число k. Напишете функция, която намира броя на всички двойки числа в масива
       (arr[i], arr[j]) имат сбор < k, където 0 <= i < j < n. Функцията трябва да работи
        със сложност по време O(n^2) и сложност по памет O(1).*/
    int size;
    std::cout << "Enter n size of the array: ";
    std::cin >> size;
    if(size > SIZE){
        std::cout << "Invalid SIZE!!!!";
        return 0;
    }
    
    int arr[SIZE];
    std::cout << "Enter " << size << " elements of the array: ";
    for (size_t i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }

    int k;
    std::cout << "Enter value for k: ";
    std::cin >> k;

    std::cout << FindSumLessThanK(arr, size, k);
}