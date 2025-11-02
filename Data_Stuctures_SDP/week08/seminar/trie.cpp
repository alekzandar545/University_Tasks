
#include "trie.hpp"
#include <iostream>

void Trie::copy(Node*& curr,Node* other){
    curr = new Node();
    for(int i = 0; i< 26;i++){
        if(other->next[i]){
            copy(curr->next[i],other->next[i]);
        }
    }
}
void Trie::free(Node* curr){
    if(!curr)return;
    for(int i = 0; i<26;i++ )
        free(curr->next[i]);
    delete curr;
}

Trie::Trie(){
    head = new Node();
}
Trie::Trie(const Trie& other){
    copy(head,other.head);
}
Trie::Trie(Trie&& other){
    std::swap(head,other.head);
}
Trie& Trie::operator=(const Trie& other){
    if(&other == this)return *this;
    free(head);
    copy(head,other.head);
    return *this;
}
Trie& Trie::operator=(Trie&& other){
    if(&other == this)return *this;
    std::swap(head,other.head);
    return *this;
}
Trie::~Trie(){
    free(head);
}

void Trie::insertRec(const string& word, int index, Node* curr){//do this iteratively at home
    if(index == word.size()){
        curr->word++;
        return;
    }
    if(!curr->next[word[index] - 'a']){
        curr->next[word[index] - 'a'] = new Node();
    }
    insertRec(word, index+1,curr->next[word[index] - 'a']);
    
}

void Trie::insert(const string& word){
    insertRec(word, 0, head);
}
bool Trie::search(const string& word)const{
    Node* curr = head;
    for (size_t i = 0; i < word.size(); i++)
    {
        curr = curr->next[word[i]-'a'];
    }
    if(!curr || !curr->word)
        return false;
    return true;
}
void Trie::removeRec(const string& word, int index, Node* curr){
    if(index == word.size())
        curr->word--;
    if(!curr) 
        return;
    Node* next = curr->next[word[index] - 'a'];
    removeRec(word, index+1, next);
    if(next && !hasChildren(next) && next->word){
        delete[] next;
        curr->next[word[index] - 'a'] = nullptr;
    }
}

bool Trie::hasChildren(Node* curr) const{
    if(!curr)
        return false;
    for (size_t i = 0; i < 26; i++)
    {
        if(curr->next[i]) return true;
    }
    return false;
    
}

void Trie::remove(const string& word){
    removeRec(word,0,head);
}
void Trie::print()const{
    string s = "";
    printRec(head,s);
}
void Trie::printRec(Node* curr, std::string& word)const{
    if(!curr) return;
    if(curr->word) //ako if-a e dolu shte se printirat dulgite s prioritet
        for (size_t i = 0; i < curr->word; i++)
            std::cout << word << '\n';
        
    for (size_t i = 0; i < 26; i++)
    {
        if(curr->next[i]){
            word.push_back((char) (i + 'a'));
            printRec(curr->next[i], word);
            word.pop_back();
        }
    }
    
}