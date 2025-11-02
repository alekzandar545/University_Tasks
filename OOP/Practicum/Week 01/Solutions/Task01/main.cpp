#include <iostream>
#include <cstring>

unsigned const REG_ID_MAXLEN = 9;
unsigned const MAXLEN = 256;
const char* CAR_BRANDS[] = {"Mercedes", "BMW", "Volkswagen"};
const char* CAR_COLORS[] = {"Black", "Grey", "Red"};

struct Car
{
    enum Brand{
        UNKNOWN_BRAND,
        MERCEDES,
        BMW,
        VOLKSWAGEN,
        BRANDS_COUNT
    };
    enum Color{
        UNKNOWN_COLOR,
        BLACK,
        GREY,
        RED,
        COLORS_COUNT
    };
    Brand brand;
    Color color;
    char id[9];
    
};

Car InitCar(char* id, Car::Brand brand, Car::Color color){
    Car car;
    for (size_t i = 0; i < 9; i++)
        car.id[i] = id[i];
    car.color = color;
    car.brand = brand;
    return car;
}

Car CreateCar(){
    Car car;
    std::cout << "Enter reg num: ";
    std::cin.getline(car.id, REG_ID_MAXLEN);

    char brand[MAXLEN];
    char color[MAXLEN];
    std::cout << "Brand: ";
    std::cin.getline(brand, MAXLEN);
    std::cout << "Color: ";
    std::cin.getline(color, MAXLEN);
    //existBrand
    bool found = false;
    for (size_t i = 1; i < Car::BRANDS_COUNT; i++)
    {
        if(strcmp(brand, CAR_BRANDS[i-1]) == 0){
            found = true;
            car.brand = (Car::Brand) i;
            break;
        }
    }
    if(!found){
        car.brand = (Car::Brand) 0;
    }

    //existColor
    found = false;
    for (size_t i = 1; i < Car::COLORS_COUNT; i++)
    {
        if(strcmp(color, CAR_COLORS[i-1]) == 0){
            found = true;
            car.color = (Car::Color) i;
            break;
        }
    }
    if(!found){
        car.color = (Car::Color) 0;
    }
    
    return car;
}

void PrintCar(const Car& car){
    std::cout << "Registration id: " << car.id << '\n';

    std::cout << "Brand: ";
    switch (car.brand)
    {
    case Car::MERCEDES:
        std::cout << "Mercedes\n";
        break;
    case Car::BMW:
        std::cout << "BMW\n";
        break;
    case Car::VOLKSWAGEN:
        std::cout << "Volkswagen\n";
        break;    
    case Car::UNKNOWN_BRAND:
        std::cout << "Unknown\n";
        break;    
    }


    std::cout << "Color: ";
        switch (car.color)
    {
    case Car::BLACK:
        std::cout << "Black\n";
        break;
    case Car::RED:
        std::cout << "Red\n";
        break;
    case Car::GREY:
        std::cout << "Grey\n";
        break;       
    case Car::UNKNOWN_COLOR:
        std::cout << "Unknown\n";
        break;    
    }
}


int main(){
    Car car = CreateCar();
    //std::cout << car.id;
    PrintCar(car);
}