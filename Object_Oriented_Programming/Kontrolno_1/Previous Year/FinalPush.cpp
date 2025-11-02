#include <iostream>
#include <cstring>
class Date{
private:
    uint8_t day, month, year;
    //validation
    bool isValid() const;
    bool isLeapYear() const{
        if(year % 4 != 0)
            return false;
        else if(year % 100 !=0)
            return true;
        else if(year % 400 !=0)
            return false;
        else
            return true;
    }
public:
    //constructor
    Date(unsigned int day, unsigned int month, unsigned int year);
    ~Date();
    //getters
    unsigned int getDay() const;
    unsigned int getMonth() const;
    unsigned int getYear() const;
    bool operator==(const Date& rhs) const;
    bool operator<(const Date& rhs) const;
};
//validation
bool Date::isValid() const{
    bool valid = month >= 1 && month <= 12 && day > 0;
    if(!valid)
        return false;
    switch (month)
    {
    case 1:
        valid = day <= 31;
        break;
    case 2:
        valid = (isLeapYear() && day<=29) || (!isLeapYear&& day<=28);
        break;
    case 3:
        valid = day <= 31;
        break;
    case 4:
        valid = day <= 30;
        break;
    case 5:
        valid = day <= 31;
        break;
    case 6:
        valid = day <= 30;
        break;
    case 7:
        valid = day <= 31;
        break;
    case 8:
        valid = day <= 31;
        break;
    case 9:
        valid = day <= 30;
        break;
    case 10:
        valid = day <= 31;
        break;
    case 11:
        valid = day <= 30;
        break;
    case 12:
        valid = day <= 31;
        break;
    }
}
Date::Date(unsigned int day, unsigned int month, unsigned int year){
    
    this->day = day;
    this->month = month;
    this->year = year;
    if(!isValid()){
        std::cout << "Error!";
        this->day = 1;
        this->month = 1;
        this->year = 1;
    }
}
Date::~Date() = default;
//getters
unsigned int Date::getDay() const{
    return day;
}
unsigned int Date::getMonth() const{
    return month;
}
unsigned int Date::getYear() const{
    return year;
}
bool Date::operator==(const Date& rhs) const{
    return day == rhs.day && month == rhs.month && year == rhs.year;
}
bool Date::operator<(const Date& rhs) const{
    return (year < rhs.year) || (year <=rhs.year && month < rhs.month) || (year <=rhs.year && month <= rhs.month && day < rhs.day);
}

class Registration{
private:
    std::string id;
    Date date;
public:
    //big2lol
    Registration(const std::string& id, const Date& date);
    ~Registration();
    //functionallity
    bool operator==(const Registration& rhs) const;
    bool operator<(const Registration& rhs) const;
};
//big2lol
Registration::Registration(const std::string& id, const Date& date){
    this->id = id;
    //need copy constructor for this sht
    //this->date(date);
}
Registration::~Registration() = default;
//functionallity
bool Registration::operator==(const Registration& rhs) const{

}
bool Registration::operator<(const Registration& rhs) const{

}

int main(){

}