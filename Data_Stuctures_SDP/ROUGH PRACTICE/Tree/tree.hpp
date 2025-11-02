#pragma once
#include <iostream>
#include <vector>
#include <queue>

template <class DataType>
class Tree{
public:
    struct Node{
        DataType data;
        Node *child, *sibling;

        Node(DataType data, Node *child = nullptr, Node *sibling = nullptr) :
        data(data), child(child), sibling(sibling){}
    } *root;
    unsigned size;

    Node* copy(Node* otherCurr){
        return otherCurr ? new Node(otherCurr.data,copy(otherCurr->child),copy(otherCurr->sibling)) : otherCurr;
    }

    void free(Node* root){
        if(root){
            free(root->sibling);
            free(root->child);
            delete root;
        }
    }

    bool find(const DataType& key, const Node* curr) const{
        if(!curr)
            return false;
        if(curr->data == key)
            return true;
        else
            return find(key,curr->child) || find(key,curr->sibling);
    }

    unsigned height(const Node* curr) const{
        if(!curr)
            return 0;
        return std::max(1+height(curr->child), height(curr->sibling));
    }
    template <class Function>
    void map(const Function& func, Node* curr){
        if(!curr)
            return;
        func(curr->data);
        map(func,curr->sibling);
        map(func,curr->child);
    }
    bool insert(const DataType& val,const int* path, Node*& curr){
        if(path[0] < 0){ //at the right place
            curr = new Node(val,nullptr,curr);
            return true;
        } //OOOH I GET IT WHY ITS HERE ITS CUS OF THE ROOT
        if(!curr)
            return false;

        int pos = path[0];
        Node* it = curr;
        while(pos > 0 && it){
            it = it->sibling;
            pos--;
        }
        //why use it->child and not it? ANSWER -> NO REASON ;3
        return it ? insert(val, path+1, it->child) : false;
    }
    bool remove(const DataType& val,Node*& curr){
        if(!curr)
            return false;
        if(curr->data == val){
            Node* toDelete = curr;
            if(!curr->child){curr = curr->sibling;}
            else if(curr->sibling){
                Node* it = curr->child;
                while(it->sibling)
                    it = it->sibling;
                it->sibling = curr->sibling->child;
                curr->sibling->child = curr->child;
                curr = curr->sibling;
            }
            else{curr = curr->child;}
            delete toDelete;
            return true;
        }
        else{
            return remove(val, curr->sibling) || remove(val, curr->child);
        }
    }
    // A BFS search with sentinel in the queue
    void printByLevels(const Node* root) const{
        if(!root)
            return;
        std::queue<const Node*> queue;
        queue.push(root);
        queue.push(nullptr);
        for(;;){
            const Node* curr = queue.front();
            queue.pop();
            if(!curr){
                std::cout << '\n';
                if(queue.empty())
                    return;
                queue.push(nullptr);
            }
            else{
                std::cout << curr->data << ' ';
                for(const Node* it = curr->child; it; it = it->sibling){
                    queue.push(it);
                }
            }
        }
    }


public:
    Tree() : root(nullptr), size(0){}
    ~Tree() noexcept{free(root);}
    Tree(const Tree& other){
        root = copy(other.root);
        size = other.size;
    }
    Tree(Tree&& other) noexcept{
        std::swap(root, other.root);
        std::swap(size, other.size);
    }
    Tree& operator=(const Tree& other){
        if(this != &other){
            free(root);
            root = copy(other.root);
            size = other.size;
        }   
        return *this;
    }
    Tree& operator=(Tree&& other) noexcept{ //we dont want exceptions here do we
        if(this != &other){
            std::swap(root,other.root);
            std::swap(size,other.size);
        }
        return *this;
    }

    bool find(const DataType& key) const{
        return find(key, root);
    }
    bool insert(const DataType& val, int* path){
        if(insert(val,path,root)){
            ++size;
            return true;
        }
        return false;
    }
    bool remove(const DataType& val){
        if(remove(val, root)){
            size--;
            return true;
        }
        return false;
    }
    unsigned getSize() const{return size;}
    unsigned getHeight() const{return height(root);}
    template <class Function>
    void map(const Function& func){map(func, root);}
    void print(){
        map([](const DataType& x) {std::cout << x << ' ';});
        std::cout << '\n';
    }
    void printByLevels() const{printByLevels(root);}
};