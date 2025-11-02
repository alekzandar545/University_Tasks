#include <iostream>

int main(){
    /*Задача 1 Да се напише програма, която при въведен масив от n цели числа да намира кой
     от всички елементи преобладава. Ако има еднакъв брой преобладаващи числа да се извади първото срещнато.*/
    int n;
    std::cin >> n;
    int* arr = new(std::nothrow) int[n];
    if(!arr){
        std::cout << "Memory error!";
        return -1;
    }
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    int result;
    int bestStreak = 0;
    int currentStreak = 0;
    for (size_t i = 0; i < n - bestStreak; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if(arr[i] == arr[j])
                currentStreak++;
        }
        if(currentStreak > bestStreak){
            bestStreak = currentStreak;
            result = arr[i];
        }

        currentStreak = 0;
    }
    
    std::cout << result;
    
    delete[] arr;
}