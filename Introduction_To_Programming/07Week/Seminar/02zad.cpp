#include <iostream>
const size_t maxLen = 1024;

//works for arrays with repeating values but the memory complexity is O(n)
void FindMissing(int *array, int size){
    int numbersCount[maxLen];
    for (size_t i = 0; i < size; i++)
    {
        numbersCount[array[i]] = 0;
        numbersCount[array[i]]++;
    }
    for (size_t i = 0; i < size + 1; i++)
    {
        //std::cout << i << ' ' << numbersCount[i] << '\n'; //check
        if(numbersCount[i] != 1)
            std::cout << i << ' ';
    }
}
//here we use the pesumption that all elements in the input array are uniue
int FindSingleMissing(int *array, int size){
    int sum = 0;
    for (size_t i = 0; i < size; i++)
    {
        sum += array[i];
    }
    return ((size*(size + 1))/2 - sum);
}

int main(){
    /*Задача 2: Да се напише програма, в която се въвежда цяло положително число n
     и след това n на брой уникални цели числа (елементи на масив) в интервала [0, n].
      Да се напише функция, която намира кой е елементът, който липсва.*/
    //сложност по време O(n) и сложност по памет O(1)
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
        if(input < 0 || input > n){
            std::cout << "Invalid value! Try again!";
            i--;
            continue;
        }
        array[i] = input;
    }
    std::cout << "The missing numbers are: ";
    FindMissing(array, n);
    std::cout << "The missing number is: " << FindSingleMissing(array, n);

}