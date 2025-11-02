#include <iostream>
const size_t maxLen = 100;

void ReverseElementsNoCopy(int *array, int size){
    for (size_t i = 0; i < size / 2; i++)
    {
        int copy;
        copy = array[size - i - 1];
        array[size - i - 1] = array[i];
        array[i] = copy;
    }

}
void ReverseElementsCopy(int *array, int size){
    int copy[maxLen];
    for (size_t i = 0; i < size; i++)
    {
        copy[i] = array[size - i - 1];
    }
    for (size_t i = 0; i < size; i++)
    {
        array[i] = copy[i];
    }
}

void PrintElements(int *array, int size){
    for (size_t i = 0; i < size; i++)
    {
        std::cout << array[i] << ' ';
    }
    
}

int main(){
    /*Въведете в конзолата число k - елементи в масив и след това k на брой елементи в този масив.
     Капацитетът на масива е 100 (не забравяйте валидацията за k). Напишете две функции,
      които да обръщат входния масив наобратно, като:

        използвате втори масив;
        не използвате втори масив. Изведете елементите на новия масив на екрана.*/
    int k;
    std::cout << "Enter size of the array: ";
    std::cin >> k;
    if(k > maxLen){
        std::cout << "Invalid size!";
        return 0;
    }

    int array[maxLen];
    for (size_t i = 0; i < k; i++)
    {
        int input;
        std::cin >> input;
        array[i] = input;
    }
    
    ReverseElementsCopy(array, k);
    PrintElements(array, k);
    std::cout << '\n';
    ReverseElementsNoCopy(array, k);
    PrintElements(array, k);
}