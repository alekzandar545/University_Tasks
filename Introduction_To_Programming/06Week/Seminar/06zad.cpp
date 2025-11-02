#include <iostream>
const size_t maxLen = 1024;

int FindMinDiff(int *arr, int size){
    int minDiff = abs(arr[0] - arr[1]);

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {   
            int currentDiff = arr[i] - arr[j];
            if(abs(currentDiff) < minDiff)
                minDiff = abs(currentDiff);
        }
    }
    return minDiff;
    
}

int main(){
    //Задача 6: Да се напише функция, която приема масив и намира коя е най-малката разлика между два елемента.
    int size;
    std::cout << "Enter the size of the array n: ";
    std:: cin >> size;
    int array[maxLen];
    if(size <= 1){
        std::cout << "Invalid value!";
        return 0;
    }   

    std::cout << "Enter " << size << " elements of array: ";
    for (size_t i = 0; i < size; i++)
    {
        int input;
        std::cin >> input;
        array[i] = input;
    }
    std::cout << "Minimum difference between 2 numbers of the array is: "
    << FindMinDiff(array, size);
}