#include <iostream>

const size_t maxLen = 100;

void SortArray(double *arr, int size){
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = i; j < size; j++)
        {
            if(arr[i] > arr[j]){
                double temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }   
    }   
}

bool IsInArray(double *arr, int size, double k){
    double accuracy = 0.001;
    int start = 0;
    int end = size - 1;
    while (start <= end){
        int mid = (start + end) / 2;
        if(abs(arr[mid] - k) < accuracy){
            return true;
        }
        if(k < arr[mid]) 
            end = mid - 1;
        else 
            start = mid + 1;
        }
    return false;
}

int main(){
    /*Напишете функция, която приема сортиран масив от числа с плаваща точка и реално число k.
    Функцията да връща дали k се среща в масива. Точността на работа на програмата трябва да
    е три знака след десетичната запетая. Сложност по време: O(logn).*/

    int size;
    std::cout << "Enter the size of the arr: ";
    std::cin >> size;
    if(size > maxLen){
        std::cout << "Invalid size!";
        return 0;
    }

    double arr[maxLen];
    std::cout << "Enter " << size << " Elements of the arr: ";
    for (size_t i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }

    double k;
    std::cout << "Enter k: ";
    std::cin >> k;

    SortArray(arr, size); 
    std::cout << std::boolalpha << IsInArray(arr, size, k);
}