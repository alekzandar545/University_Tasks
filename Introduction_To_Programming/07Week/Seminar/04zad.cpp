#include <iostream>

const size_t maxLen = 100;

int FindPeakIndex(int *arr, int size){
    int start = 0;
    int end = size - 1;
    while(start < end){
        int mid = (start + end) / 2;
        if (arr[mid-1] > arr[mid])
            end = mid;
        else if (arr[mid] < arr[mid + 1])
            start = mid;
        else
            return mid;
    }
}

int main(){
    /*Задача 4: Да се напише програма, в която се въвежда цяло положително число n, което е >= 3 и след това n
     на брой цели числа (елементи на масив). Масивът ще има видът на планина. Това означава, че за някое i важи
    следното твърдение:

    arr[0] < arr[1] < ... < arr[i - 1] < arr[i]

    arr[i] > arr[i + 1] > ... > arr[n - 1] Напишете функция, която по подадени arr и n, намира този индекс i.
    Тази функция трябва да работи със сложност по време O(log(n)) и сложност по памет O(1).*/
    int size;
    std::cout << "Enter n >= 3 size of the array: ";
    std::cin >> size;
    if(size < 3 || size > maxLen){
        std::cout << "Invalid SIZE!!!!";
        return 0;
    }
    
    int arr[maxLen];
    std::cout << "Enter " << size << " elements of the array: ";
    for (size_t i = 0; i < size; i++)
    {
        int input;
        std::cin >> input;
        arr[i] = input;
    }

    std::cout << "The peak index is: " << FindPeakIndex(arr, size);
}