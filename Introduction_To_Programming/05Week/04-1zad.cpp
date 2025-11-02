#include <iostream>

using namespace std;

int Power(int a, int b){
    int result = 1;
    for (int i = 0; i < b; ++i)
    {
        result *= a;
    }
    return result;
    
}

int main(){
    cout << Power(4,2);
}