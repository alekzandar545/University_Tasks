#include <iostream>
const size_t maxLen = 1024;

void Swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
int GCD(int a, int b){
    if(a < b)
        Swap(a, b);
    int r = a % b;
    while(r > 0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}
int GCDofArray(const int *arr, const size_t size){
    int gcd = arr[0];
    for (size_t i = 1; i < size - 1; i++)
    {
        std::cout << gcd << std::endl;
        gcd = GCD(gcd, arr[i+1]);
    }
    return gcd;
}

//fix
int main(){
    size_t n = 4;
    int arr[maxLen];
    std::cout << "Enter " << n << " elements: ";
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    std::cout << "Greatest common divisor: " << GCD(*arr, maxLen);
}