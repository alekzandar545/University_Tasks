#include <iostream>
const size_t maxLen = 1024;


void PrintIndex(int *array, int size, int k){
    bool contains = 0;
    for (size_t i = k - 1; i < size; i++)
    {
        if(array[i] == k){
            std::cout << i << ' ';
            contains = 1;
        }
        else if (array[i] > k)
            break;
    }
    if(!contains)
        std::cout << "No such elements!";

}

void SortArray(int *array, int size){
    for (size_t i = 0; i < size; i++)
    {
        bool swapped = 0;
        for (size_t j = 0; j < size - i - 1; j++)
        {
            if(array[j] > array[j + 1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j + 1] = temp;
                swapped = 1;
            }
        }
        if(swapped == 0)
            break;
    } 
}



int main(){
    /*Задача 3: Да се напише програма, в която се въвежда цяло положително число n и след това n на брой
     цели числа (елементи на масив). След което програмата да въвежда едно цяло положително число k.
      Да се напише функция, която принтира всички индекси на които arr[index] == k, след като сортирате масива.
       Функцията трябва да работи със сложност по време O(n^2) и сложност по памет O(1).*/

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
    if(k <= 0){
        std::cout << "Invalid value!";
        return 0;
    }       
    SortArray(array, n);
    PrintIndex(array, n, k);
}