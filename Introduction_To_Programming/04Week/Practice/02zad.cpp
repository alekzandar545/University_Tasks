#include <iostream>

using namespace std;

int main(){
    //Да се прочете от конзолата цяло число n и да се намери стойността на n!.
    int n;
    int fact = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)    {
        fact *= i;
    }
    cout << n << "! = " << fact;
    
    return 0;    
}