#include <iostream>

const size_t maxLen = 1024;

void SortArray(int *array, int size){
    for (int i = 0; i < size; i++)
    {
        bool swapped = 0;
        for (int j = 0; j < size - i - 1; j++)
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

void RemoveRepeatingElement(int *arr, int &size){
    int outputsArray[maxLen];
    if(size == 0 || size == 1)
        return;
    int outputIndex = 0;
    //checks if the first element is unique
    if(arr[0] != arr[1]){
        outputsArray[0] = arr[0];
        outputIndex++;
    }
    //checks if all the elements in the middle are uniue
    for (int i = 1; i < size - 1; i++)
    {
        if((arr[i] != arr[i-1]) && (arr[i] != arr[i+1])){
            outputsArray[outputIndex] = arr[i];
            outputIndex++;
        }
    }
    //checks if last element is uniue
    if(arr[size - 2] != arr[size - 1]){
        outputsArray[outputIndex] = arr[size-1];
        outputIndex++;        
    }

    size = outputIndex;

    for (int i = 0; i < size; i++)
    {   
        std::cout << outputsArray[i] << ' ';
        arr[i] = outputsArray[i];
    }
}

//more compact code
void RemoveRepeatingElements2(int *arr, int &size){
    int badNum = 0;
    for (size_t i = 0; i < size - 1; i++)
    {
        if(arr[i] == arr[i+1] || arr[i] == badNum){
            badNum = arr[i];
            for (size_t j = i; j < size - 1; j++)
            {
                arr[j] = arr[j + 1];
            }
            size--;
            i--;
        }
    }
    if(arr[size - 1] == badNum)
        size--;
        
    

}

int main(){
    //Задача 5: Да се напише функция, която приема сортиран масив и изтрива всички повтарящи се елементи в него.
    int size;
    std::cout << "Enter the size of the array n: ";
    std:: cin >> size;
    int array[maxLen];
    if(size <= 0){
        std::cout << "Invalid value!";
        return 0;
    }   

    std::cout << "Enter " << size << " elements of array: ";
    for (size_t i = 0; i < size; i++)
    {
        int input;
        std::cin >> input;
        array[i] = input;
    }
    
    SortArray(array, size);
    for (size_t i = 0; i < size; i++)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << '\n';
    RemoveRepeatingElements2(array, size);

    for (size_t i = 0; i < size; i++)
    {
        std::cout << array[i] << ' ';
    }
    
}