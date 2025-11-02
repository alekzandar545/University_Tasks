#include <iostream>

int main(){
    /*Да се състави програма, в която се въвеждат естествени цели числа от клавиатурата.
    Размерът на масива да се въвежда от клавиатурата и да се заделя динамично памет за него.
    Програмата да разменя симетричните елементи спрямо средата, като по-малкото число остава
    в началото на масива, а по-голямото в края.*/
    int size;
    std::cin >> size;
    int* arr = new(std::nothrow) int[size];
    if(!arr){
        std::cout << "Memory error!";
        return -1;
    }

    for (size_t i = 0; i < size; i++)
    {   
        int input;
        std::cin >> input;
        if(input >= 0)
            arr[i] = input;
        else{
            std::cout << "Natural numbers only!";
            i--;
        }
    }
    for (size_t i = 0; i < size / 2; i++)
    {
        if(arr[i] > arr[size - i - 1]){
            int temp = arr[i];
            arr[i] = arr[size - i - 1];
            arr[size - i - 1] = temp;
        }
    }
    for (size_t i = 0; i < size; i++)
    {
        std::cout << *(arr + i) << ' ';
    }
    
    

    

    delete[] arr;
}