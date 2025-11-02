#pragma once
#include <iostream>
#include <queue>
#include <fstream>
#include <vector>

class BST{
private:
    struct Node
    {
        int val;
        Node *left, *right;

        Node(int val) : val(val), left(nullptr), right(nullptr){}
        Node(int val, Node* left, Node* right) : val(val), left(left), right(right){}
    } *root;
    
    Node* copy(const Node* curr){
        if(!curr)
            return nullptr;
        Node* res = new Node(curr->val);
        try{
            res->left = copy(curr->left);
            res->right = copy(curr->right);
        }
        catch(...){
            free(curr->left);
            free(curr->right);
            throw;
        }
        return res;
    }

    void free(const Node* curr){
        if(!curr)
            return;
        free(curr->left);
        free(curr->right);
        delete curr;
    }
public:
    BST() : root(nullptr) {}
    BST(Node* root) : root(root) {}
    ~BST() {free(root);}
    BST(const BST& other) {root = copy(other.root);}
    BST(BST&& other) noexcept{std::swap(root,other.root);}
    BST& operator=(const BST& other){
        if(this != &other){
            *this = BST(other);
        }
        return *this;
    }
    BST& operator=(BST&& other) noexcept{
        if(this!= &other){
            std::swap(root, other.root);
        }
        return *this;
    }

    void printBFS()const{
        if(!root){
            std::cout << "Empty tree!";
            return;
        }
        std::queue<Node*> q;
        q.push(root);
        q.push(nullptr);
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            if(!curr){
                std::cout << '\n';
                if(!q.empty())
                    q.push(nullptr);
            }
            else{
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                std::cout << curr->val << ' ';
            }
        }
    }

    void addElem(int val, Node*& curr){
        if(!curr)
            curr = new Node(val);
        else if(val > curr->val)
            addElem(val, curr->right);
        else
            addElem(val, curr->left);
    }

    void addElem(int val){
        addElem(val,root);
    }

    static void merge(std::vector<int>& values, int left, int mid, int right){
        int n1 = mid - left + 1; //+1 cus we counting the middle element as well
        int n2 = right - mid;

        std::vector<int> L(n1), R(n2);

        for (size_t i = 0; i < n1; i++)
            L[i] = values[i + left];
        for (size_t j = 0; j < n2; j++)
            R[j] = values[mid + 1 + j];

        int i = 0, j = 0;
        int curr = left;

        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                values[curr] = L[i];
                i++;
            }
            else {
                values[curr] = R[j];
                j++;
            }
            curr++;
        }
        while(i < n1){
            values[curr] = L[i];
            i++;
            curr++;
        }
        while(j < n2){
            values[curr] = R[j];
            j++;
            curr++;
        }
    }

    static void mergeSort(std::vector<int>& values, int left, int right){
        if(left >= right)
            return;
        int mid = (left + right) / 2;
        mergeSort(values,left,mid);
        mergeSort(values,mid+1,right);
        merge(values, left, mid, right);
    }

    void buildTree(std::vector<int> values, int start, int end){
        if(start > end)
            return;

        int mid = (start + end)/2;
        addElem(values[mid]);

        buildTree(values, start, mid-1);
        buildTree(values, mid+1, end);
    }

    void deserialize(std::ifstream& stream){
        free(root);
        std::vector<int> values;
        int curr;
        while(stream >> curr)
            values.push_back(curr);
        mergeSort(values,0,values.size()-1);
        buildTree(values, 0, values.size()-1);
    }

};