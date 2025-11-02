#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>

int main() {
    // Map Latin characters to Cyrillic (UTF-8 encoded)
    std::unordered_map<char, std::string> translitMap = {
        {'Ç', "\xD0\xA6"},  // Ц
        {'à', "\xD0\xB0"},  // а
        {'ä', "\xD0\xB4"},  // д
        {'ñ', "\xD1\x81"},  // с
        {'ú', "\xD1\x8A"},  // ъ
        {'ò', "\xD1\x82"},  // т
        {'ð', "\xD1\x80"},  // р
        {'â', "\xD0\xB2"},  // в
        {'ï', "\xD0\xBF"},  // п
        {'î', "\xD0\xBE"},  // о
        {'ù', "\xD1\x89"},  // щ
        {'ã', "\xD0\xB3"},  // г
        {'é', "\xD0\xB5"},  // е
        {'å', "\xD1\x8F"},  // я
        {'ê', "\xD0\xBA"},  // к
        {'è', "\xD0\xB8"},  // и
        // Add more mappings if needed
    };

    // Open input and output files
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open input.txt\n";
        return 1;
    }

    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not create output.txt\n";
        return 1;
    }

    // Process each character
    char c;
    while (inputFile.get(c)) {
        auto it = translitMap.find(c);
        if (it != translitMap.end()) {
            outputFile << it->second;  // Write Cyrillic character
        } else {
            outputFile << c;          // Write original character
        }
    }

    // Cleanup
    inputFile.close();
    outputFile.close();
    std::cout << "Transliteration completed successfully!\n";
    return 0;
}