#include <string>

using std::string;

class Trie{
    private:
    struct Node{
        int word = 0;
        Node* next[26]{nullptr,};
    }*head;
    bool hasChildren(Node*) const;
    void copy(Node*& curr,Node* other);
    void free(Node* curr);
    void insertRec(const string& word, int index, Node* curr);
    void removeRec(const string& word, int index, Node* curr);
    void printRec(Node*, std::string&)const;
    
    public:
    Trie();
    Trie(const Trie& other);
    Trie(Trie&& other);
    Trie& operator=(const Trie& other);
    Trie& operator=(Trie&& other);
    ~Trie();
    void insert(const string& word);
    bool search(const string& word)const;
    void remove(const string& word);
    void print()const;
};