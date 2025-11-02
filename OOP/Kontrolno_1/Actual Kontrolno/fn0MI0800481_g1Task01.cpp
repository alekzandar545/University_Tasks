#include <iostream>

class Statistics{
private: 
    unsigned count;
    int sum;
    int prod;
    int max;
    double average;
public:
    //base4
    Statistics();
    Statistics(const Statistics& other);
    Statistics& operator=(const Statistics& other);
    ~Statistics();
    //getters
    unsigned getCount() const;
    int getSum() const;
    int getProd() const;
    int getMax() const;
    double getAverage() const;
    //setters - not neededs
    //functionality
    void add(const int a);
    Statistics operator+(const int a) const;
    Statistics& operator+=(const int a);
};
//base4
Statistics::Statistics(){
    count = 0;
    sum = 0;
    prod = 1;
    max = 0; //can also just not set it
    average = 0; //same here, but 0 is convenient
}
Statistics::Statistics(const Statistics& other){
    count = other.count;
    sum = other.sum;
    prod = other.prod;
    max = other.max;
    average = other.average;

}
Statistics& Statistics::operator=(const Statistics& other){
    if(this != &other){
    count = other.count;
    sum = other.sum;
    prod = other.prod;
    max = other.max;
    average = other.average; 
    }
    return *this;
}
Statistics::~Statistics() = default;

//getters
unsigned Statistics::getCount() const{
    return count;
}
int Statistics::getSum() const{
    return sum;
}
int Statistics::getProd() const{
    return prod;
}
int Statistics::getMax() const{
    return max;
}
double Statistics::getAverage() const{
    return average;
}
//functionality
void Statistics::add(const int a){
    count++;
    sum+=a;
    prod*=a;
    if(a > max)
        max = a;
    average = (average*(count-1) + a)/count;
}
Statistics Statistics::operator+(const int a) const{
    Statistics output(*this);
    output.add(a);
    return output;
}
Statistics& Statistics::operator+=(const int a){
    this->add(a);
    return *this;
}

int main(){
    //testing
    int a;
    std::cout << a;
    Statistics seq1; 
    std::cout << seq1.getMax();

    return 0;
}