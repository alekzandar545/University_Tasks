#include <iostream>

int main(){
    /*Задача 7 Напишете функция, която при подаден масив от цели числа с дължина n и цяло число k, което е 
    елемент от масива, да пренареди елементите в масива, така че всички по-малки елемнти от k да са отляво на k, 
    а всички по-големи да са отдясно на него.*/
    int size, k;
    std::cin >> size >> k;
    int* arr = new(std::nothrow) int[size];
    int* outputArr = new(std::nothrow) int[size+1];
    if(!arr || !outputArr){
        std::cout << "Memory error!";
        return -1;
    }
    for (size_t i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }

    int outputIndex = 0;
    
    for (size_t i = 0; i < size; i++)
    {
        if(arr[i] < k){
            outputArr[outputIndex] = arr[i];
            outputIndex++;
        }
    }
    outputArr[outputIndex] = k;
    outputIndex++;
    for (size_t i = 0; i < size; i++)
    {
        if(arr[i] >= k){
            outputArr[outputIndex] = arr[i];
            outputIndex++;
        }
    }
    for (size_t i = 0; i < size + 1; i++)
    {
        std::cout << outputArr[i] << ' ';
    }
    
    delete[] arr;
    delete[] outputArr;
}