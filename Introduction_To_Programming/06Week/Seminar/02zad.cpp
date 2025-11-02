#include <iostream>

const size_t maxLen = 5;

int SumElements(const int *arr, const size_t SIZE){
    int sum = 0;
    for (size_t i = 0; i < SIZE; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main(){
    int arr[maxLen];
    std::cout << "Enter " << maxLen << " elements: ";
    for (size_t i = 0; i < maxLen; i++)
    {
        std::cin >> arr[i];
    }
    std::cout << "Sum of elements: " << SumElements(arr, maxLen);
}