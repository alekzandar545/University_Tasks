#include <iostream>
#include <cstring>

#define MAXLEN 128

class Beer{
private:
    //can try this with an enum and bitwise magic
    char name[MAXLEN];
    unsigned quantity;
public:
    //constructor
    Beer(char* name, unsigned quantity){
        strcpy(this->name, name);
        this->quantity = quantity;
    }
    //getters
    char* GetName(){
        return this->name;
    }
    unsigned GetQuantity(){
        return this->quantity;
    }
    //Напишете метод, който добавя една бира към друга.
    Beer MixBeers(const Beer& other){
        char name[MAXLEN];
        name[0] = '\0';
        strcat(name, this->name);
        strcat(name, "&");
        strcat(name, other.name);
        unsigned quantity = this->quantity + other.quantity;
        Beer beer(name, quantity);
        return beer;
    }
    //Напишете метод, който допълва бирата с дадени милилитри.
    void Fill(unsigned const value){
        this->quantity += value;
    }
    //Напишете метод, който проверява дали дадена бира съдържа каквото и да е количество от дадена марка.
    bool CheckName(const char* brand){
        for (size_t i = 0; i < strlen(this->name); i++)
        {
            char substr[strlen(brand)];
            for (size_t j = i; j < i+strlen(brand); j++)
            {
                substr[j-i] = this->name[j];
            }
            if(strcmp(substr,brand) == 0)
                return true;
        }
        return false;
    }
};
int main(){
    char name1[] = "Korona";
    char name2[] = "Kristina";
    Beer a = {name1, 500};
    Beer b = {name2, 250};
    Beer c = a.MixBeers(b);
    std::cout << c.GetName();
    //std::cout << std::boolalpha << c.CheckName(a.GetName());
}