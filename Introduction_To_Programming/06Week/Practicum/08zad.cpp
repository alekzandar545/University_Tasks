#include <iostream>

const int SIZE = 100;

void PrintSumElements(int *arr, int size, int m){
    for (size_t i = 0; i < size / 2; i++)
    {
        for (size_t j = i; j < size; j++)
        {
            if(arr[i] + arr[j] == m)
                std::cout << arr[i] << ' ' << arr[j] << '\n';
        }
    }
}

int main(){
    /*Въведете в конзолата размер на масив n [0,100], число m и след това n на брой 
    елементи в масива. Да се напише функция, която извежда всички двойки числа, които
    се сумират до m.*/

    int size, m;
    std::cout << "Enter the size of the array n: ";
    std::cin >> size;
    if(size > SIZE){
        std::cout << "Invalid input!";
    }
    std::cout << "Enter m: ";
    std::cin >> m;

    int array[SIZE];
    std::cout << "Enter " << size << " elements of array: ";
    for (size_t i = 0; i < size; i++)
    {
        int input;
        std::cin >> input;
        array[i] = input;
    }
    PrintSumElements(array, size, m);
}