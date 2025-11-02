#include <iostream>

const size_t MAXSIZE = 255;

void ReadMessage(bool* arr, size_t size){
    //gotta read in in incremets of 8 bytes
    for (size_t i = 0; i < size; i+=8)
    {
        int start = i;
        char secretLetterUWU = 0;
        int increment = 1;
        for (size_t j = start; j < start + 8; j++)
        {
            secretLetterUWU += increment*arr[j];
            increment *= 2;
        }
        std::cout << secretLetterUWU;
    }
    
}

int main(){
    bool data[MAXSIZE];
    size_t n;
    std::cout << "Enter the number of rooms: ";
    std::cin >> n;
    //we need to ensure that n is a power of 2 and be a value that makes sense
    bool isValid = false;
    for (size_t i = 1; i <= 256; i*=2)
    {
        if(n == i){
            isValid = true;
            break;
        }
    }
    if(!isValid){
        std::cout << "Invalid number of rooms!";
        return 0;
    }
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> data[i];
    }
    
    //find which rooms are occupied (have 1s)
    int occupiedRooms[MAXSIZE];
    size_t occupiedIndex = 0;
    for (size_t i = 0; i < n; i++)
    {
        if(data[i] == 1){
            occupiedRooms[occupiedIndex] = i;
            occupiedIndex++;
        }
    }
    //With the XOR bitwise operator we find the parity of each
    //bit in the binary representation of the number of the occpied rooms

    //if the parity aint right somewhere the output bit changes to 1
    //at the place where we detected an error; all of those errors compose our output number
    int output = occupiedRooms[0];
    for (size_t i = 1; i < occupiedIndex; i++)
    {
        output = output ^ occupiedRooms[i];
        std::cout << output << std::endl;
    }
    std::cout << output << '\n';
    //P.S. God bless 3Blue1Brown for making a video on this type of solution
    ReadMessage(data, n);
}