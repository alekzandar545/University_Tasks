#include <iostream>

const size_t maxLen = 1024;

int FindKBiggestElement(int *arr, int size, int k){
    int biggestPlace = 1;
    for (size_t i = 0; i < size - 1; i++)
    {
        if(biggestPlace == k)
            return arr[i];
        else if(arr[i] == arr[i+1])
            continue;
        else
            biggestPlace++;
    }
    return arr[size - 1];
}

void SortArray(int *arr, int size){
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = i; j < size; j++)
        {
            if(arr[i] < arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }   
    }   
}

int main(){
    /*Напишете функция, която приема масив от числа и цяло неотрицателно число k (k < size).
    Функцията да връща на k-тия по големина елемент. O(n^2)*/

    int size;
    std::cout << "Enter the size of the arr: ";
    std::cin >> size;
    if(size > maxLen){
        std::cout << "Invalid size!";
        return 0;
    }

    int arr[maxLen];
    std::cout << "Enter " << size << " Elements of the arr: ";
    for (size_t i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }

    int k;
    std::cout << "Enter k for values [1,n]: ";
    std::cin >> k;
    if(k < 1 || k > size){
        std::cout << "Invalid input!";
        return 0;
    }

    SortArray(arr, size);
    
    std::cout << FindKBiggestElement(arr, size, k);
    

    
}