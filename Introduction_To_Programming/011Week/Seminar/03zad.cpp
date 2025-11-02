#include <iostream>

int sumNeighbours(int* arr, int size, int index){
    if(size == 2)
        return arr[0];

    if(index == size - 1){
        size--;
        index = 0;
    }
    arr[index] += arr[index + 1];
    
    return sumNeighbours(arr, size, index + 1);
}

int main(){
    //Задача 3 Да се напише рекурсивна функция, която приема масив и събира всеки две съседни числа, докато не получи 1 число.
    int arr[] = {1, 2, 3, 4, 4};
    std::cout << sumNeighbours(arr, 5, 0);
}