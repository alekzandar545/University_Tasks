#include <iostream>

struct String {
    char* str;

};
std::ostream& operator<<(std::ostream& out, const String& string) {
    out << string.str;
    return out;
}
int main() {
    char str[] = "sosko";
    String string;
    string.str = str; // Initialize the String struct with str
    std::cout << string << string << "georgi" << string;
}