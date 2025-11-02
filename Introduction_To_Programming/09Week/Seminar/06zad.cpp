#include <iostream>

int FindLeftSum(int* arr, const int size, int index){
    int sum = 0;
    if(index == 0)
        return 0;
    for (size_t i = 0; i < index; i++)
    {
        sum += arr[i];
    }
    return sum;
}
int FindRightSum(int* arr, const int size, int index){
    int sum = 0;
    if(index == size)
        return 0;
    for (size_t i = index + 1; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}
int main(){
    /*Задача 6 Да се напише функция, която при подаден масив от n цели числа, връща нов масив от вида: 
    answer[i] = |leftSum[i] - rightSum[i]|.

    Размерът на answer е същият като на оригиналният масив.
    leftSum[i] е сумата на числата в интервала [0, i). Ако i = 0, считаме сумата за 0.
    rightSum[i] е сумата на числата в интервала (i, n - 1]. Ако i = n - 1, считаме сумата за 0.*/
    int size;
    std::cin >> size;
    int* arr = new(std::nothrow) int[size];
    if(!arr){
        std::cout << "Memory error!";
        return -1;
    }
    for (size_t i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }
    
    for (size_t i = 0; i < size; i++)
    {
        std:: cout << abs(FindLeftSum(arr, size, i) - FindRightSum(arr, size, i)) << ' ';
    }
    
    delete[] arr;
}