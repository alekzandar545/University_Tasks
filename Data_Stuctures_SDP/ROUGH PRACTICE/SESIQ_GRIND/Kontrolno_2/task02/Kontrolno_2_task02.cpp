#include <iostream>
#include <queue>
#include <limits>
class Tree{
private:
    struct Node{
        int val;
        Node *left, *right;

        Node(int val) : val(val), left(nullptr), right(nullptr){}
        Node(int val, Node* left, Node* right) : val(val), left(left), right(right){}
    } *root;

    void clear(Node* curr){
        if(!curr)
            return;
        clear(curr->left);
        clear(curr->right);
        delete curr;
    }

    Node* copy(const Node* curr){
        if(!curr)
            return nullptr;
        try{
            return new Node(curr->val, copy(curr->left), copy(curr->right));
        }
        catch(...){
            free(curr->left);
            free(curr->right);
            throw;
        }
    }

public:

    Tree() : root(nullptr){}
    ~Tree() {clear(root);}
    Tree(const Tree& other){root = copy(other.root);}
    Tree(Tree&& other) noexcept {std::swap(root, other.root);}
    Tree& operator=(const Tree& other){
        if(this != &other){
            *this = Tree(other);
        }
        return *this;
    }
    Tree& operator=(Tree&& other){
        if(this != &other){
            std::swap(root, other.root);
        }
        return *this;
    }

    bool checkValid(const char* inputString){
        int bracketBalance;
        for (size_t i = 0; inputString[i] != '\0'; i++)
        {
            if(bracketBalance < 0)
                return false;
            if(inputString[i] == '(')
                bracketBalance++;
            else if(inputString[i] == ')')
                bracketBalance--;
        }
        return bracketBalance == 0;
    }

    static void skipWhitespace(const char*& data){
        while (*data == ' ' || *data == '\t' || *data == '\n') {
            ++data;
        }
    }
    static int parseNumber(const char*& data) {
        int sign = 1;

        if (*data == '-') {
            sign = -1;
            ++data;
        }
        int value = 0;

        while (std::isdigit(*data)) {
            value = value * 10 + (*data - '0');
            ++data;
        }

        return value * sign;
    }

    void deserialize(const char*& data){
        root = deserializeHelper(data);
    }

    static Node* deserializeHelper(const char*& data) {
        skipWhitespace(data);

        if (*data == 'x') {
            ++data;
            skipWhitespace(data);
            return nullptr;
        }

        if (*data == '(') {
            ++data;
            skipWhitespace(data);
            int value = parseNumber(data);
            Node* left = deserializeHelper(data);
            Node* right = deserializeHelper(data);

            if (*data == ')') {
                ++data; 
                skipWhitespace(data);
            }
            return new Node(value, left, right);
        }
        return nullptr;
    }

    void print(){
        printTree(root);
    }

    void printTree(Node* curr) {
        if (!curr) {
            std::cout << " x ";
            return;
        }
        std::cout << "(";
        std::cout << ' ' << curr->val << " ";
        printTree(curr->left);
        printTree(curr->right);
        std::cout << ")";
    }

    void serialize(std::ostream& stream){
        serializeHelper(stream,root);
    }

    void serializeHelper(std::ostream& stream, Node* curr){
        if (!curr) {
            stream << " x ";
            return;
        }
        stream << "(";
        stream << ' ' << curr->val << " ";
        serializeHelper(stream, curr->left);
        serializeHelper(stream, curr->right);
        stream << ")"; 
    }

    void trimToBST() { //that was too easy ;c
        if (!root) return;
        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            
            //check validity of children
            if(curr->left && curr->left->val > curr->val){//remove left
                removeElement(curr->left);
                q.push(curr);
                continue;
            }
            if(curr->right && curr->right->val < curr->val){//remove right
                removeElement(curr->right);
                q.push(curr);   //push back if the children of the children are invalid ;3
                continue;  
            }

            //everything is right
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }

    }

    Node* extractMax(Node* curr){
        if(!curr->right)
            return curr;
        return extractMax(curr->right);
    }

    void removeElement(Node*& curr) {
        if (!curr) return;

        Node* toDelete = curr;

        if (!curr->left) {
            curr = curr->right;
        } else if (!curr->right) {
            curr = curr->left;
        } else {
            Node* max = extractMax(curr->left);
            max->left = curr->left;
            max->right = curr->right;
            curr = max;
        }

        delete toDelete;
    }

};

int main(){
    const char* input = "(5 (6 (7 x x) x) x)";
    Tree t;
    t.deserialize(input);
    t.print();
    std::cout << '\n';
    t.trimToBST();
    t.print();



    return 0;
}