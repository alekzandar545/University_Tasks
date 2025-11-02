#include <iostream>

int main(){
    /*Задача 2 Да се напише програма, която при въведени масив от n цели числа и ги сортира в нарастващ
    ред спрямо броя на включените им битове. Ако има 2 числа с еднакъв брой включени битове да се подредят
    в нарастващ ред.*/
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
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            int currFirst = arr[j];
            int bitsFirst = 1;
            while(currFirst >= 2){
                if(currFirst % 2 == 1)
                    bitsFirst++;
                currFirst /= 2;
            }
            int currSecond = arr[j+1];
            int bitsSecond = 1;
            while(currSecond >= 2){
                if(currSecond % 2 == 1)
                    bitsSecond++;
                currSecond /= 2;
            }
            if(bitsFirst > bitsSecond || (bitsFirst == bitsSecond) && (arr[j] > arr[j+1])){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (size_t i = 0; i < size; i++)
    {
        std::cout << arr[i] << ' ';
    }
    
    

    delete[] arr;
    
}