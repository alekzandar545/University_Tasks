#include <iostream>

#define DEFAULT_MAXLEN 16

size_t nextPow(size_t a){
    size_t output = 1;
    while(output < a){
        output *= 2;
    }
    return output;
}

class String{
private:
    char* str;
    size_t capacity;
    void Resize(const size_t size);
public:
    
    //base
    String();
    String(const size_t size);
    String(const char* str, size_t size);
    String(const String& str);
    String& operator=(const String& str);
    ~String();
    //getters
    char* getStr() const;
    size_t getSize() const;
    //functionality
    size_t Length() const;
    void Copy(const String& str);
    void Append(const String& str);
    String Combine(const String& str);
    void Clear();
    bool Empty() const;
    char At(unsigned index)const;
    void Print() const;
};
//resize
void String::Resize(const size_t size){
    this->capacity = nextPow(size);
    char* newstr = new(std::nothrow) char[capacity];
    for (size_t i = 0; i < this->Length(); i++)
    {
        newstr[i] = str[i];
    }
    newstr[this->Length()] = '\0';
    Clear();
    str = newstr;
    
}
//basics
String::String(){
    capacity = DEFAULT_MAXLEN;
    str = new(std::nothrow) char[capacity];
    if(!str){
        std::cout << "Error";
        return;
    }
}

String::String(const size_t size){
    capacity = size;
    str = new(std::nothrow) char[size];
    if(!str){
        std::cout << "Error";
        return;
    }
}
String::String(const char* str, const size_t size){
    capacity = size;
    this->str = new(std::nothrow) char[size];
    if(!str){
        std::cout << "Error";
        return;
    }
    for (size_t i = 0; i < size; i++)
    {
        this->str[i] = str[i];
    }   
}
String::String(const String& str){
    Copy(str);
}

String& String::operator=(const String& str){
    if(this != &str){
        this->Clear();
        Copy(str);
    }
    return *this;
}
String::~String(){
    delete[] str;
}
//getters
char* String::getStr() const{
    return this->str;
}
size_t String::getSize() const{
    return this->capacity;
}
//functionality
size_t String::Length() const{
    size_t counter = 0;
    for (size_t i = 0; i < capacity; i++)
    {
        if(str[i] == '\0')
            return counter;
        counter++;
    }
    return counter;
}

void String::Copy(const String& other){
    this->capacity = other.Length() + 1;
    this->str = new(std::nothrow) char[this->capacity];
    if(!str){
        std::cout << "Error!";
        return;
    }
    for (size_t i = 0; i < capacity; i++)
    {
        this->str[i] = other.str[i];
    }
    this->str[other.Length()] = '\0';
}
void String::Append(const String& str){
    size_t oldLen = this->Length();
    if(oldLen + str.Length() + 1 > this->capacity){
        Resize(oldLen + str.Length() + 1);
    }
    for (size_t i = oldLen; i < oldLen + str.Length(); i++)
    {
        this->str[i] = str.str[i-oldLen];
    }
    this->str[oldLen+str.Length()] = '\0';
}
String String::Combine(const String& str){
    String newstr(*this);
    newstr.Append(str);
    return newstr;
}

bool String::Empty() const{
    return this->Length() == 0;
}
char String::At(unsigned index)const{
    if(index < 0 || index >= this->Length()){
        std::cout << "Invalid index!";
    }
    return this->str[index];
}

void String::Clear(){
    delete[] str;
}

void String::Print() const{
    std::cout << str;
}


std::ostream& operator<<(std::ostream& out, const String& str){
    out << str.getStr();
    return out;
}

int main(){
    String str1("sosko", 6);
    String str2("georgi", 7);
    //str.Print();
    //std::cout << str.Length();
    String newstr;
    newstr = str1.Combine(str2);
    //::cout << newstr.getSize();
    std::cout << newstr;
    return 0;
}
