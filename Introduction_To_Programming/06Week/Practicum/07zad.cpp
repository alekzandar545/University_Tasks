#include <iostream>
const size_t maxLen = 100;

void ShiftArrayRight(int *arr, int &size, int index){
    size++;
    for (int p = size - 1; p > index; p--)
    {
        arr[p] = arr[p-1];
    }
}

void PrintArray(int *arr, int size){
    std::cout << '\n';
    for (size_t i = 0; i < size; i++)
    {
        std::cout << arr[i] << ' ';
    }
}

int main(){
    /*Даден е сортиран масив sorted_arr с n елемента. Въведете число k и после k на брой елемента.
     Докато четете елементите ги вмъквайте в масива така, че той да остане сортиран. Изведете масива на екрана.*/
    int n;
    std::cout << "Enter size of the array: ";
    std::cin >> n;
    if(n > maxLen){
        std::cout << "Invalid size!";
        return 0;
    }
    int array[maxLen];
    std::cout << "Enter " << n << " elements of array: ";
    for (size_t i = 0; i < n; i++)
    {
        int input;
        std::cin >> input;
        array[i] = input;
    }

    std::cout << "Enter a number k to create a subArray: ";
    int k;
    std::cin >> k;
    if(k + n > 100){
        std::cout << "Invalid input!";
        return 0;
    }
    std::cout << "Enter " << k << " elements to array: ";
    for (size_t i = 0; i < k; i++)
    {
        int input;
        std::cin >> input;
        if(input < array[0]){
            ShiftArrayRight(array, n, 0);
            array[0] = input;
        }
        else if(input > array[n-1]){
            n++;
            array[n-1] = input;
        }
        else
            for (size_t i = 1; i < n; i++)
            {
                if(input < array[i] && input > array[i-1]){
                    ShiftArrayRight(array, n, i);
                    array[i] = input;
                    break;
                }

            }
    }
    PrintArray(array, n);
}