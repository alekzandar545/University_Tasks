#include <iostream>
#include <iomanip>

int main(){
    double atk, elementalPrBase;
    double atkTrincket = 0.432;
    double elementalTrinket = 0.388;
    std::cin >> atk >> elementalPrBase; 
    std::cout << "DMG using dmg trinket: " << std::fixed << std::setprecision(2) << (atkTrincket+1 + (atkTrincket+1)*elementalPrBase)*atk << "dmg" << std::endl;
    std::cout << "DMG using the elemental trinket: " << std::fixed << std::setprecision(2) << (elementalPrBase + 1 + elementalTrinket)* atk << "dmg" << std::endl;

    return 0;
}