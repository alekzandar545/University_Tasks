#include <iostream>

using namespace std;

int Logarithm(int a, int b){
    int result = 0;
    while (a >= b)
    {
        a /= b;
        result++;
    }
    return result;
}

int main(){
    cout << Logarithm(80, 2);
}