#include <iostream>
const size_t maxLen = 1024;

void ShiftAndRemoveEvenIndexes(int *arr, int &size){
    for (size_t i = 1; i < size; i++)
    {   
        for (size_t j = i; j < size - 1; j++)
        {
            arr[j] = arr[j+1];
        }
        size--;
    }
}

void ShiftAndRemoveEven(int *arr, int &size){
    for (size_t i = 0; i < size; i++)
    {   
        if(arr[i] % 2 == 0){
            for (size_t j = i; j < size - 1; j++)
            {
                arr[j] = arr[j+1];
            }
            size--;
        }

    }
}

//the elements won't be in order here but i don't think it is required
void SwapAndRemoveEven(int *arr, int &size){
    for (size_t i = 0; i < size; i++)
    {
        if(arr[i] % 2 == 0){
            arr[i] = arr[size -1];
            i--;
            size--;
        }
    }
    
}

int main(){
    /*Да се напише функция, която премахва всички четни елементи от масив. Да се направи по два начина:

        чрез отместване на всички следващи елементи;
        чрез размяна на съответния елемент за премахване и последния и намаляване на размера.*/
    int size;
    std::cout << "Enter size of the array: ";
    std::cin >> size;
    if(size > maxLen){
        std::cout << "Invalid size!";
        return 0;
    }

    int array[maxLen];
    std::cout << "Enter " << size << " elements of array: ";
    for (size_t i = 0; i < size; i++)
    {
        int input;
        std::cin >> input;
        array[i] = input;
    }
    
    SwapAndRemoveEven(array, size);
    for (size_t i = 0; i < size; i++)
    {
        std::cout << array[i] << ' ';
    }
    
}