#include <iostream>

const size_t maxLen = 1024;

void SortArray(int *arr, int size){
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = i; j < size; j++)
        {
                if(arr[i] > arr[j]){
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
        }
    }
}

int FindMin(int a, int b){
    if(a < b)
        return a;
    else    
        return b;
}

int MaxSumOfPair(int *arr, int size){
    int sum = 0;
    for (size_t i = 0; i < size; i += 2)
    {
        sum += FindMin(arr[i], arr[i+1]);
    }
    return sum;
}

int main(){
    /*Задача 6: Да се напише програма, в която се въвежда цяло положително четно число n и след 
    това n на брой цели числа (елементи на масив). Напишете функция, която групира елементите на масива по двойки: (, ), (, ), ..., (, ), 
    така че сумата на min(, ) за всяко i да е максимална. Функцията да връща максималната сума.
    Функцията трябва да работи със сложност по време O(n^2) и сложност по памет O(1).*/
    int size;
    std::cout << "Enter n size of the array: ";
    std::cin >> size;
    if(size > maxLen || size % 2 == 1){
        std::cout << "Invalid SIZE!!!!";
        return 0;
    }
    
    int arr[maxLen];
    std::cout << "Enter " << size << " elements of the array: ";
    for (size_t i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }

    //we gotta sort the array and then we ball
    SortArray(arr, size);
    std::cout << "The maximum sum is: " << MaxSumOfPair(arr, size);
    
}