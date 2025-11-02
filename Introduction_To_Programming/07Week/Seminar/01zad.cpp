#include <iostream>
const size_t maxLen = 1024;

int FindLessOrEqual(int *array, int size, int k){
    int start = array[0];
    int end = array[end - 1];
    while(end > start){
        int mid = (start + end) / 2;
        if (mid <= k)
            return k;
        end = mid;
    } 
    return INT32_MIN;
}

int main(){
    /*Задача 1: Да се напише програма, в която се въвежда цяло положително число n и след това n 
    на брой цели числа (елементи на масив). След което програмата да въвежда едно цяло положително число k.
     Да се напише функция, която да намери най-големия елемент, по-малък или равен на k. Ако няма такъв елемент
      в масива, функцията да върне INT32_MIN. За вход приемаме, че въведените масиви ще са сортирани. Функцията
       трябва да работи със сложност по време O(log(n)) и сложност по памет O(1).*/
    int n;
    std::cout << "Enter the size of the array n: ";
    std:: cin >> n;
    int array[maxLen];
    if(n <= 0){
        std::cout << "Invalid value!";
        return 0;
    }
    std::cout << "Enter " << n << " elements of array: ";
    for (size_t i = 0; i < n; i++)
    {
        int input;
        std::cin >> input;
        array[i] = input;
    }
    int k;
    std::cout << "Enter k: ";
    std::cin >> k;
    std::cout << FindLessOrEqual(array, n, k) << " is less than " << k;
    
}