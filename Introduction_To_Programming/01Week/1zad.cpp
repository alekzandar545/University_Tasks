#include <iostream>

using namespace std;

int main(){
    cout << "enter a lowercase latin letter: ";
    char input;
    cin >> input;
    int asciUppercase = 32;
    cout << endl << "capital letter: " << (char)(input - asciUppercase); 
    
    return 0;
}