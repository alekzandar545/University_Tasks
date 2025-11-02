#include <iostream>
#include <cmath>

const size_t maxLen = 100;

//Единствено се сещам за алгоритъм със сложност по време O(n^2) 
int FindDuplicateON2(int *arr, int size){
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = i + 1; j < size; j++)
        {
            if(arr[i] == arr[j])
                return arr[i];
        }
    }  
    return -1; 
}
//друг начин е да се сортира масива с алгоритъм, който да има сложност O(logn)
//и после да се търсят съседни повтарящи се стойности

//този алгоритъм работи с желаната сложност, но само за стойност на масива единствено естествени числа
int FindDuplicateON(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        int index = abs(arr[i]) - 1;
        if (arr[index] < 0) {
            return abs(arr[i]);
        } else {
            arr[index] = -arr[index];
        }
    }
    return -1;
}

int main(){
    /*Задача 5: Да се напише програма, в която се въвежда цяло положително число n и след
    това n на брой цели числа (елементи на масив). Да се напише функция, която намира, кой
    от елементите в този масив се повтаря. Функцията трябва да работи със сложност по време O(n) и сложност по памет O(1).*/
    int size;
    std::cout << "Enter n size of the array: ";
    std::cin >> size;
    if(size > maxLen){
        std::cout << "Invalid SIZE!!!!";
        return 0;
    }
    
    int arr[maxLen];
    std::cout << "Enter " << size << " elements of the array: ";
    for (size_t i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }
    
    std::cout << "The duplicate element is: " << FindDuplicateON2(arr, size) << std::endl;
    std::cout << "The duplicate element is: " << FindDuplicateON(arr, size) << std::endl;
}