#include <iostream>

int* CreateArray(const size_t size){
    int* arr = new(std::nothrow) int[size];
    if(!arr){
        std::cout << "Memory error!";
        return nullptr;
    }
    return arr;
}

int main(){
    /*Създайте функция int* CreateArray(const size_t size), която създава масив от цели
    числа по въведена от клавиатурата стойност n и връща указател към първия елемент.
    Ако заделянето на памет е неуспешно, върнете nullptr.*/
    int n;
    std::cin >> n;
    if(n <= 0){
        std::cout << "Invalid value";
        return 0;
    }
    int* arr = CreateArray(n);
    std::cout << arr;
    if(arr)
        delete[] arr;

}