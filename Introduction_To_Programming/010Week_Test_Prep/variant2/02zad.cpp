#include <iostream>

bool IsHill(int* arr, int size){
    //check for extremum
    int leftMaxIndex = 0;
    int rightMaxIndex = size - 1;
    for (size_t i = 0; i < size; i++)
    {
        if(arr[leftMaxIndex] <= arr[i]){
            leftMaxIndex = i;
        }
        else{
            break;
        }
    }
    for (int i = size - 1; i >= 0; i--)
    {
        if(arr[rightMaxIndex] <= arr[i]){
            rightMaxIndex = i;
        }
        else{
            break;
        }
    }
    std::cout << leftMaxIndex << ' ' << rightMaxIndex;
    if(leftMaxIndex == rightMaxIndex && arr[leftMaxIndex] <= size && arr[leftMaxIndex] >= 1 && leftMaxIndex != 0 && leftMaxIndex != size - 1)
        return true;
    return false;
    
    //see if extremum is in range (1, n)
}

int main(){
    /*Задача 2. Да се напише булева функция, която получава цяло неотрицателно число n и масив от n цели числа. 
    Програмата да проверява дали въведените числа образуват редица “хълм“. Редица “хълм” наричаме последователност, 
    за която е вярно, че съществува такъв елемент ai, 1 ≤ ai ≤ n такъв, че a1 ≤ a2 ≤ ... ≤ ai ≥ ai+1 ≥ ai-1 ≥ ... ≥ an

    Използването на функцията да се демонстрира с извикване с примерен масив, стойностите на чиито елементи се въвеждат от стандартния
    вход.*/
    int size;
    std::cin >> size;
    int* arr = new(std::nothrow) int[size];
    if(!arr){
        std::cout << "Memory leak!";
        return -1;
    }
    for (size_t i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }
    
    std::cout << std::boolalpha << IsHill (arr, size);

    delete[] arr;

}