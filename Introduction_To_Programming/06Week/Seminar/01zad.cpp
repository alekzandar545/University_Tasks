#include <iostream>

int MinElement(const int *arr, const size_t SIZE){
    int min = arr[0];
    for (size_t i = 1; i < SIZE; i++)
    {
        if(arr[i] < min)
            min = arr[i];
    }
    return min;
}

int main(){
    const size_t SIZE = 4;
    int arr[SIZE];
    std::cout << "Enter " << SIZE << " elements: ";
    for (size_t i = 0; i < SIZE; i++)
    {
        std::cin >> arr[i];
    }
    std::cout << "Minimum element: " << MinElement(arr, SIZE);
}