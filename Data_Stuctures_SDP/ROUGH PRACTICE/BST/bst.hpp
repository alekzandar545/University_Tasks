#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

template <class DataType>
class BST{
private:
    struct Node{
        DataType data;
        Node *left, *right;

        Node(const DataType& data, const Node* left, const Node* right)
         : data(data), left(left), right(right){}
        Node(const DataType& data) : data(data), left(nullptr), right(nullptr){}
    } *root;
    unsigned size;

    Node* copy(Node* otherCurr){   //postfix traversal
        if(!otherCurr) 
            return nullptr;
        Node* result = new Node(otherCurr->data);
        try{
            result->left = copy(otherCurr->left);
            result->right = copy(otherCurr->right);
            return result;
        }
        catch (...){
            free(otherCurr->left); //point of this is that sometimes only one side gets created while
            free(otherCurr->right); //the other one throws an error so we clear both if we get an exception
            throw;
        }
    }
    void free(Node*& curr){ //prefix traversal
        if(curr){
            free(curr->left);
            free(curr->right);
            delete curr;
            curr = nullptr; //that is if we delete down the tree and we dont want broken adresses ;3
        }
    }

public:
    BST() : root(nullptr), size(0){}
    ~BST() noexcept {free(root);}
    BST(const BST& other){
        root = copy(other.root);
        size = other.size;
    }
    BST(BST&& other) noexcept {
        std::swap(root, other.root);
        std::swap(size, other.size);
    }
    BST& operator=(const BST& other){ //lets do some exception safety:
        if(this != &other)
            *this = BST(other); //here we use move semantics so if sth breaks it will be in the constructor of the temp object
        return *this;
    }
    BST& operator=(BST&& other) noexcept{
        if(this != &other){
            std::swap(root, other.root);
            std::swap(size, other.size);
        }
        return *this;
    }

    class Iterator;
    Iterator begin(){return Iterator(root);}
    Iterator end(){return Iterator(nullptr);}

    class LevelIterator;
    LevelIterator beginLevel(){return LevelIterator(root);}
    Iterator endLevel(){return LevelIterator(nullptr);}


    bool find(const DataType& val)const{return find(val, root);}
    bool findIterative(const DataType& val)const{return findIterative(val,root);}
    void insert(const DataType& val){
        insert(val,root);
        size++;
    }
    void insertIterative(const DataType& val){
        insertIterative(val, root);
        size++;
    }
    bool remove(const DataType& val){
        if(remove(val,root)){
            size--;
            return true;
        }
        return false;
    }
    unsigned getHeight() const{return height(root);}
    void printInOrder() const {
        print(root);
        std::cout << '\n';
    }
    bool isBalanced() const {return balanced(root);}
    bool isPerfectlyBalanced() const {return perfectlyBalanced(root);}
private:
    bool find(const DataType& val, const Node* curr) const{
        if(!curr)
            return false;
        if(curr->data == val)
            return true;
        return val < curr->data ?  find(val, curr->left) : find(val, curr->right);
    }
    bool findIterative(const DataType& val, const Node* root) const{
        const Node* curr = root; //I AM NOT CHANGING THE NODE AND THAT IS ALL THAT MATTERS
        while(curr){
            if(curr->data == val)
                return true;
            curr = val < curr->data ? curr->left : curr->right;
        }
        return false;
    }
    void insert(const DataType& val, Node*& curr){
        if(!curr)
            curr = new Node(val);
        else
            insert(val, val < curr->data ? curr->left : curr->right);
    }
    void insertIterative(const DataType& val, Node*& curr){
        if(!curr) curr = new Node(val);
        else{
            Node* parent = curr;
            Node* next = val < parent->data ? parent->left : parent->right;
            while(next){
                parent = next;
                next = val < parent->data ? parent->left : parent->right;
            }
            if(val < parent->data)
                parent->left = new Node(val);
            else
                parent->right = new Node(val);
                
            // next = new Node(val); //NEXT IS JUST A POINTER THAT WE STORE THAT ALSO HAPPENS TO BE
            //                       //THE SAME AS PARENT->LEFT/RIGHT. SO ALLOCATING MEMORY DOESNT CHANGE
            //                       //ACTUAL PARENT->LEFT/RIGHT
        }
    }
    bool remove(const DataType& val, Node*& curr){
        if(!curr)
            return false;
        if(curr->data == val){
            Node* toDelete = curr;
            if(!curr->left)
                curr = curr->right;
            else if(!curr->right)
                curr = curr->left;
            else{
                Node* replacement = extractMin(curr->right); //min of bigger side is closest to curr->data
                replacement->left = curr->left;
                replacement->right = curr->right;
                curr = replacement;
            }
            delete toDelete;
            return true;
        }
        else
            return remove(val, val < curr->data ? curr->left : curr->right);
    }

    Node* extractMin(Node*& curr){
        //OOH IM EXTRACTING SO I GOTTA MAKE SURE THE FUCK OFF THE CURR
        if(curr->left)
            return extractMin(curr->left);

        Node* extraction = curr;
        curr = curr->right;
        return extraction;
       
    }
    unsigned height(const Node* curr) const{
        if(!curr)
            return 0;
        return 1+ std::max(height(curr->left), height(curr->right));
    }
    bool balanced(const Node* curr) const{
        if(!curr)
            return true;
        return abs(height(curr->left) - height(curr->right)) < 2 &&
               balanced(curr->left) && balanced(curr->right);
    }
    long weight(const Node* curr) const{
        if(!curr)
            return 0;
        return 1 + weight(curr->left) + weight(curr->right);
    }
    bool perfectlyBalanced(const Node* curr) const{
        if(!curr)
            return true;
        return abs(weight(curr->left) - weight(curr->right)) < 2 &&
               perfectlyBalanced(curr->left) && perfectlyBalanced(curr->right);
    }
    void print(const Node* curr) const{ //prints on one line
        if(curr){
            print(curr->left);
            std::cout << curr->data << ' ';
            print(curr->right);
        }
    }
    void extractNodes(const Node* curr, std::vector<Node*>& nodes){
        if(curr){
            extractNodes(curr->left);
            nodes.push_back(curr);
            extractNodes(curr->right);
        }
    }
    Node* buildPBD(const std::vector<Node*>& nodes, unsigned left, unsigned right){//BINARY SEARCH
        if(left >= right) 
            return nullptr;
        unsigned middle = left + (right - left)/2; //any way we are not doing (right + left)/2?
        Node* curr = nodes[middle];
        curr->left = buildPBD(nodes, left,middle);//we dont want intersection with the middle
        curr->right = buildPBD(nodes, middle+1, right); //thats why we got middle+1
        return curr;
    }

//ITERATOR----------------------------------------------------------------------------
public:
    class Iterator{
    friend class BST;
    private:
        std::stack<Node*> front;
        Node* current = nullptr;

        Iterator(Node* root) {
            if(root){
                front.push(nullptr);//End
                pushLeft(root);
                ++(*this);
            }
        }
        void pushLeft(Node* curr){//THATS CUS WE ARE USING A STACK AND I NEED THE SMALLEST ELEMENT READY ALWAYS
            while(curr){
                front.push(curr);
                curr = curr->left;
            }
        }
    public:
        const DataType operator*() const{return current->data;}
        const DataType* operator->() const{return &current->data;}
        operator bool() const {return current;}
        bool operator==(const Iterator& other){return current == other.current;}
        bool operator!=(const Iterator& other){return !(*this==other);}
        Iterator& operator++(){//if nothing we just return nullptr ;c
            if(!front.empty()){
                current = front.top();
                front.pop();
            }
            if(current)
                pushLeft(current->right);
            return *this;//IF THE FRONT IS EMPTY CURRENT WILL ALWAYS BE NULLPTR BECAUSE NULLPTR IS AT THE BOTTOM OF THE STACK
        }
        Iterator operator++(int){
            Iterator res(*this);//copy constructor lol, took me a while...
            ++(*this);
            return res;
        }
    };
//BFS ITERATOR------------------------------------------------------------------------
public:
    class LevelIterator{
    friend class BST;
    private:
        std::queue<Node*> front;
        Node* current = nullptr;
        LevelIterator(Node* root){
            current = root;
            pushChildren(root);
        }
        void pushChildren(Node* root){
            if(root){
                if(root->left)front.push(root->left);
                if(root->right)front.push(root->right);
            }
        }
    public:
        const DataType operator*() const {return current->data;}
        const DataType* operator->()const{return &current->data;}
        operator bool() const{return current;}
        bool operator==(const Iterator& other)const{return current == other.current;}
        bool operator!=(const Iterator& other)const{return !(*this == other);}
        LevelIterator& operator++(){
            if(!front.empty()){
                current = front.front();
                front.pop();
                pushChildren(current);
            }
            else
                current = nullptr;
            return *this;
        }
        LevelIterator operator++(const){
            LevelIterator res(*this);
            ++(*this);
            return res;
        }
    };

};