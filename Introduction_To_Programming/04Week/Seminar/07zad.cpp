#include <iostream>

using namespace std;

int main(){
    int input;
    cin >> input;
    for (int i = 1; i <= input; i++)
    {
        
        for (int j = input; j >= i; j--)
        {
            cout << " ";
        }
        for (int j = 1; j < 2*i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    
}