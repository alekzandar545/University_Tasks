#include <iostream>
#include <fstream>
#include "heap.hpp"
#include "trie.hpp"

int main(){
    unsigned M,K;
    std::string values, text;
    std::cout << "Enter the name of the file with the values list: ";
    std::cin >> values;
    std::cout << "Enter the name of the file with the main text: ";
    std::cin >> text;
    std::cout << "Enter number of words you want to extract from the heap: ";
    std::cin >> M;
    std::cout << "Enter what K you want for the KHeap: ";
    std::cin >> K;
    std::ifstream wordValues(values);
    std::ifstream rawText(text);

    Tree valuedWords;
    valuedWords.deserialize(wordValues);

    Tree allWords;
    allWords.extractWordsFromText(rawText,valuedWords);

    MyVector<Word> wordList = allWords.getWords();

    KHeap<Word> heap(K);
    for (size_t i = 0; i < wordList.size(); i++)
        heap.insert(wordList[i]);
        
    while(!heap.empty() && M > 0){
        Word word = heap.extract();
        std::cout << word.word << ' ' << word.value << '\n';
        M--;
    }
}