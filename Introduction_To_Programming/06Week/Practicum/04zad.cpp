#include <iostream>
const size_t maxLen = 100;

void PrintSubSequence(int *arr, int size){
    int current = arr[0];
    for (size_t i = 1; i < size; i++)
    {
        std:: cout << current << ' ';
        if(current >= arr[i])
            std::cout << '\n';
        current = arr[i];
    }
    std::cout << current;
}
int main(){
    //Напишете програма, която в даден масив намира и извежда растящите последователни подредици в него.
    int size;
    std::cout << "Enter size of the array: ";
    std::cin >> size;
    if(size > maxLen){
        std::cout << "Invalid size!";
        return 0;
    }

    int arr[maxLen];
    for (size_t i = 0; i < size; i++)
    {
        int input;
        std::cin >> input;
        arr[i] = input;
    }

    PrintSubSequence(arr, size);

    
    
    
}