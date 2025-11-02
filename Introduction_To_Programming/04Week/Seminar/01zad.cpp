#include <iostream>

using namespace std;

int main(){
    int input;
    cout << "enter input integer: " << endl;
    cin >> input;

    for(int i = 0; i <= 20 && i*i < input; i++){
        cout << i*i << " ";
    }
}