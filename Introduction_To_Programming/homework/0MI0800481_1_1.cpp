#include <iostream>
#include <cstring>

const int days = 5;
const int productiveHours = 13;
const size_t MAXLENGTH = productiveHours * 2 + 1; //each activity is 2 characters (+ 1 for '\0')

double CheckDay(char* day){
    double hourSum = 0;
    for (size_t i = 0; i < productiveHours * 2; i+=2)
    {
        char substring[3];
        substring[0] = day[i];
        substring[1] = day[i+1];
        substring[2] = '\0';
        //std::cout << substring << '\n';
        if(strcmp(substring, "hw") == 0)
            hourSum++;
        else if(strcmp(substring, "hf") == 0 || strcmp(substring, "hm") == 0){}
        else if(strcmp(substring,"st") == 0)
            hourSum += 0.5;
        else{
            return -1;
        }
    }
    return hourSum;
}

int main(){
    double homeworkHours;
    std::cin >> homeworkHours;
    std::cin.ignore();
    if(homeworkHours > days * productiveHours || homeworkHours < 0){
        std::cout << "Daite po lesno domashno ;c";
        return 0;
    }
    int investedHours = 0;
    char day1[MAXLENGTH], day2[MAXLENGTH], day3[MAXLENGTH], day4[MAXLENGTH], day5[MAXLENGTH];
    char* allDays[5] = {day1, day2, day3, day4, day5};
    for (size_t i = 0; i < days; i++)
    {
        std::cin.getline(allDays[i], MAXLENGTH);
    }
    for (size_t i = 0; i < days; i++)
    {
        double hours = CheckDay(allDays[i]);
        if(hours == -1){
            std::cout << "Invalid input";
            return 0;
        }
        investedHours += hours;
    }
    if(investedHours >= homeworkHours)
        std::cout << "You got it!";
    else
        std::cout << "You ain't got it...";
}