#include <iostream>
const size_t maxLen = 100;

void AddElements(int *array, int size){
    for (size_t i = 0; i < size; i++)
    {
        int element;
        std::cin >> element;
        array[i] = element;
    }
}

//без да искам направих второто условие на 5зад тук
void ReverseElements(int *array, int size){
    for (size_t i = 0; i < size / 2; i++)
    {
        int copy;
        copy = array[size - i - 1];
        array[size - i - 1] = array[i];
        array[i] = copy;
    }
}

void PrintReversed(int *array, int size){
    for (int i = size - 1; i >= 0; i--)
    {
        std::cout << array[i] << ' ';
    }
    
}

int main(){
    /*Въведете в конзолата число n, отговарящо на брой елементи в едномерен масив
     (за да не се объркате може да го именувате size). Напишете функция, която прочита n (или size)
      на брой елементи и ги вкарва в масива. Напишете функция, която изкарва на екрана елементите
       на масива в обратен ред. Валидирайте числото n (или size) да не надвишава максималния размер на масива
        (нека максималния размер е 100).*/
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;
    if(size > maxLen){
        std::cout << "Invalid size!";
        return 0;
    }
    int array[maxLen];
    AddElements(array, size);
    ReverseElements(array, size);
    for (size_t i = 0; i < size; i++)
    {
        std::cout << array[i] << ' ';
    }
    std::cout<< '\n';
    PrintReversed(array, size);
}