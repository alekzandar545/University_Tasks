#include <iostream>
const size_t maxLen = 1024;

void Swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void RemoveCommonElements(int arr[], size_t &n){
    int counter = 0;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = i + 1; j < n; j++)
        {
            if(arr[i] == arr[j]){
                Swap(arr[j], arr[maxLen - j]);
            }
        }
    }   
}

int CountCommonElements(const int *arr1, const int *arr2, const size_t n, const size_t m){
    int counter = 0;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            if(arr1[i] == arr2[j])
                counter++;
        }
    }
    return counter;  
}

int main(){
    size_t m, n;
    std::cout << "Enter m, n - size of arrays: ";
    std::cin >> n >> m;
    if(m <= 0 || n <= 0){
        std::cout << "invalid size!";
        return 0;
    }
    int arr1[maxLen], arr2[maxLen];
    std::cout << "Enter elements in arr1: ";
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> arr1[i];
    }
    std::cout << "Enter elements in arr2: ";
    for (size_t i = 0; i < m; i++)
    {
        std:: cin >> arr2[i];
    }

    RemoveCommonElements(arr1, n);
    RemoveCommonElements(arr2, m);
    std::cout << "Number of common elements: " << CountCommonElements(arr1, arr2, n, m);
    
    {}
}