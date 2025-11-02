#include <iostream>
#include <cstring>

#define IP_OCTETS 4

struct IpAdress{
    union{
        uint32_t hexadress;
        uint8_t octets[IP_OCTETS];
    };
};

void PrintAdress(uint32_t hexadress){
    //std::cout << "0x" << std::hex << hexadress;
    char symbols[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    std::string output;
    while(hexadress != 0){
        output += (symbols[hexadress % 16]);
        hexadress/=16;
    }
    for (size_t i = 0; i <= output.length(); i++)
    {
        std::cout << output[output.length() - i];
    }
}
void PrintAdress(uint8_t* octets){
    for (size_t i = 0; i < IP_OCTETS - 1; i++)
    {
        std::cout << (uint32_t)octets[i] << '.';
    }
    std::cout << (uint32_t)octets[IP_OCTETS-1] << '\n';
    
}

int main(){
    IpAdress ip;
    ip.hexadress = 0x0100007F;

    PrintAdress(ip.hexadress);
}