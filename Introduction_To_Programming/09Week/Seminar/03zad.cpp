#include <iostream>

int FindLefSum(int* arr, const int size, int index){
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
    /*Задача 3 Напишете функция, която при подаден масив с дължина n и n цели числа, намира най-малкият среден индекс.
    Ако не съществува среден индекс, който да удовлетворява условията върнете -1. Среден индекс е индекс, за който 
    е в сила следните зависимости:
    nums[0] + nums[1] + ... + nums[middleIndex - 1] == nums[middleIndex + 1] + nums[middleIndex + 2] + ... + nums[n - 1]
    Ако средният индекс е 0, то лявата сума се счита за 0.
    Ако средният индекс е n - 1, то дясната сума се счита за 0.*/
    int size;
    std::cin >> size;
    int* arr = new(std::nothrow) int[size];
    int middleIndex = -1;
    for (size_t i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }
    
    for (size_t i = 0; i < size; i++)
    {   
        if(FindLefSum(arr, size, i) == FindRightSum(arr, size, i)){
            middleIndex = i;
            break;
        }
            
    }
    std::cout << middleIndex;
    
}