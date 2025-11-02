#pragma once
#include <iostream>
#include "queue.hpp"
#include "vector.hpp"
#include "word.hpp"

class Tree {
private:
    struct Node {
        char ch;
        int value;
        bool isEndOfWord;
        Node* child;
        Node* sibling;

        Node(char ch, int value = 0, bool isEndOfWord = false, Node* child = nullptr, Node* sibling = nullptr)
            : ch(ch), value(value), isEndOfWord(isEndOfWord), child(child), sibling(sibling) {}
    } *root;

    unsigned size;

    //utility
    Node* copy(Node* otherCurr) {
        return otherCurr ? new Node(otherCurr->ch, otherCurr->value, otherCurr->isEndOfWord, copy(otherCurr->child), copy(otherCurr->sibling)) : nullptr;
    }

    void free(Node* curr) {
        if (curr) {
            free(curr->sibling);
            free(curr->child);
            delete curr;
        }
    }

    Node* traverseChildren(const std::string& word) const {
        Node* curr = root->child;
        for (char c : word) {
            Node* child = curr->child;
            while (child && child->ch != c) {
                child = child->sibling;
            }
            if (!child) return nullptr;
            curr = child;
        }
        return curr;
    }

    unsigned height(const Node* curr) const {
        if (!curr) return 0;
        return std::max(1 + height(curr->child), height(curr->sibling));
    }

    void insertWord(const std::string& word, int value, Node*& curr, int pos) {
        if (pos == word.length()) {
            curr->isEndOfWord = true;
            curr->value += value;
            return;
        }

        char c = word[pos];
        Node* child = curr->child;
        Node* prev = nullptr;

        while (child && child->ch != c) {
            prev = child;
            child = child->sibling;
        }

        if (!child) {
            child = new Node(c);
            if (prev) {
                prev->sibling = child;
            } else {
                curr->child = child;
            }
        }

        insertWord(word, value, child, pos + 1);
    }

    void getWords(const Node* curr, std::string& wordPrefix, MyVector<Word>& result) const {
        if (!curr) return;

        wordPrefix += curr->ch;
        if (curr->isEndOfWord) {
            result.push_back(Word(wordPrefix, curr->value));
        }

        getWords(curr->child, wordPrefix, result);
        wordPrefix.pop_back();
        getWords(curr->sibling, wordPrefix, result);
    }

    void print(const Node* curr, std::string& wordPrefix) const {
        if (!curr) return;

        wordPrefix += curr->ch;

        if (curr->isEndOfWord) {
            std::cout << wordPrefix << ' ' << curr->value << '\n';
        }

        print(curr->child, wordPrefix);
        wordPrefix.pop_back();
        print(curr->sibling, wordPrefix);
    }

    void printByLevels(const Node* curr) const {
        if (!curr) return;

        Queue<const Node*> queue;
        queue.push(curr);
        queue.push(nullptr);

        while (!queue.empty()) {
            const Node* curr = queue.front();
            queue.pop();
        
            if (!curr) {
                std::cout << '\n';
                if (!queue.empty()) queue.push(nullptr);
            } else {
                std::cout << curr->ch << ' ';
                for (const Node* it = curr->child; it; it = it->sibling) {
                    queue.push(it);
                }
            }
        }
    }

    bool removeChar(char ch, Node*& curr) {
        if (!curr) return false;
        if (curr->ch == ch) {
            Node* toDelete = curr;
            if (!curr->child) {
                curr = curr->sibling;
            } else if (curr->sibling) {
                Node* it = curr->child;
                while (it->sibling) {
                    it = it->sibling;
                }
                it->sibling = curr->sibling->child;
                curr->sibling->child = curr->child;
                curr = curr->sibling;
            } else {
                curr = curr->child;
            }
            delete toDelete;
            return true;
        } else {
            return removeChar(ch, curr->sibling) || removeChar(ch, curr->child);
        }
    }

    void evaluateWord(const std::string& word, const Tree& valuedWords) {
        if (valuedWords.containsWord(word)) {
            int value = valuedWords.getWordValue(word);
            insertWord(word, value);
        } else {
            insertWord(word, 1);
        }
    }

public:
    //life cycle
    Tree() : root(new Node(' ')), size(0) {}
    ~Tree() noexcept { free(root); }
    Tree(const Tree& other) : root(copy(other.root)), size(other.size) {}
    Tree(Tree&& other) noexcept : root(other.root), size(other.size) {
        other.root = nullptr;
        other.size = 0;
    }

    Tree& operator=(const Tree& other) {
        if (this != &other) {
            free(root);
            root = copy(other.root);
            size = other.size;
        }
        return *this;
    }

    Tree& operator=(Tree&& other) noexcept {
        if (this != &other) {
            std::swap(root, other.root);
            std::swap(size, other.size);
        }
        return *this;
    }

    //functionality
    bool insertWord(const std::string& word, int value) {
        insertWord(word, value, root, 0);
        ++size;
        return true;
    }

    bool removeChar(char ch) {
        if (removeChar(ch, root)) {
            --size;
            return true;
        }
        return false;
    }

    bool containsWord(const std::string& word) const {
        Node* curr = traverseChildren(word);
        return curr && curr->isEndOfWord;
    }

    int getWordValue(const std::string& word) const {
        Node* curr = traverseChildren(word);
        if (!curr || !curr->isEndOfWord) {
            throw std::invalid_argument("No such word!");
        }
        return curr->value;
    }

    void extractWordsFromText(std::istream& in, const Tree& valuedWords) {
        free(root);
        root = new Node(' ');
        size = 0;

        while (in.good()) {
            std::string word;
            in >> word;

            while (!word.empty() && (word.back() > 'z' || word.back() < 'a'))
                word.pop_back();
            while (!word.empty() && (word.front() > 'z' || word.front() < 'a'))
                word.erase(word.begin());

            evaluateWord(word, valuedWords);
        }
    }

    MyVector<Word> getWords() const {
        MyVector<Word> result;
        std::string word = "";
        getWords(root->child, word, result);
        return result;
    }

    //util
    unsigned getSize() const { return size; }
    unsigned getHeight() const { return height(root); }
    void print() const {
        std::string word = "";
        print(root->child, word);
    }

    void printByLevels() const { printByLevels(root); }

    void deserialize(std::istream& in) {
        free(root);
        root = new Node(' ');
        size = 0;

        int numWords;
        in >> numWords;
        for (int i = 0; i < numWords; ++i) {
            std::string word;
            int value;
            in >> word >> value;
            insertWord(word, value);
        }
    }
};
