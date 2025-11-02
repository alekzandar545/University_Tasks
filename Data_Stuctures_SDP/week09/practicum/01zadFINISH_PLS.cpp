#include <iostream>
#include <vector>

constexpr unsigned BOARD_SIZE = 3;

void LoadInputs(std::vector<std::vector<int>>& matrix){
    //validate later
    for (size_t i = 0; i < BOARD_SIZE; i++){
        for (size_t j = 0; j < BOARD_SIZE; j++){
            char input;
            std::cin >> input;
            if(input != 'X' || input != 'O' || input != '-')
                continue;
            std::cin >> matrix[i][j];  
        }
    }

            
}


struct State{
    int x, y;
    unsigned depth;

    State* child;
    State* sibling;

    bool player;

    State(unsigned x, unsigned y, bool player = 0, unsigned depth = 0, State* child = nullptr, State* sibling = nullptr)
    : x(x)
    , y(x)
    , depth(depth)
    , child(child)
    , sibling(sibling)
    , player(player)
    {}
    
};

bool isWinner(State* board){
    bool diagonals = 0;
    bool leftRight = 0;
    bool rightLeft = 0;
}

bool isFull(const std::vector<std::vector<int>>& matrix){
    for (size_t i = 0; i < BOARD_SIZE; i++)
        for (size_t j = 0; j < BOARD_SIZE; j++)
            if(matrix[i][j] == '-')
                return false;  
    return true;
    
}

class Tree{
    private:
    State* root;
    std::vector<std::vector<int>> matrix;

    void clear(State* root){
        if(root){
            clear(root->child);
            clear(root->sibling);
            delete root;
        }
    }

    bool find(const State* root, const unsigned x, const unsigned y, bool player, const unsigned depth) const
    {
        if (!root) return false;
        if (root->x == x && root->y == y && root->player == player && root->depth == depth) return true;
        return find(root->sibling, x,y,player,depth) || find(root->child, x,y,player,depth);
    }
  

    bool insert(State*& root, const unsigned x, const unsigned y, bool player, const unsigned depth, const int* path)
    {
        //A sibling to the root
        if (path[0] < 0) {
            root = new State(x,y,player, depth, nullptr, root);
            return true;
        }
        //No such child? Wrong path!
        if (!root) return false;
        // Attach element in the roots children list
        if (path[0] == 0) {
            return insert(root->child, x,y,player, depth, path + 1);
        }
        // Find the right child in the list
        State* it = root;
        int pos = path[0];
        while (it->sibling && pos > 0) {
            it = it->sibling;
            --pos;
        }
        return it->sibling ? insert(it->sibling->child, x,y,player, depth, path + 1) : false;
    }

    public:
    Tree(State* root, std::vector<std::vector<int>>) : root(root), matrix(matrix){}
    ~Tree(){clear(root);}


    bool insert(const unsigned x, const unsigned y, bool player, const unsigned depth, int path[])
    {
        if (insert(root, x, y, player, depth, path))
            return true;
        return false;
    }
    bool find(const unsigned x, const unsigned y, bool player, const unsigned depth) const { return find(root, x, y, player, depth); }
    
    void insertState(State* parentNode, int x, int y, bool player, unsigned depth){
        State* newState = new State(x,y,player,depth+1);
        if(!parentNode->child)
            parentNode->child = newState;
        else{
            State* curr = parentNode->child;
            while(curr->sibling){
                curr = curr->sibling;
            }
            curr->sibling = newState;
        }
    }

    void GenerateMovesHelper(State* node, std::vector<std::vector<int>>& matrix, int x, int y, bool player, unsigned depth){//finish
        if(isFull(matrix))
            return;
        for (size_t i = 0; i < BOARD_SIZE; i++)
        {
            for (size_t j = 0; j < BOARD_SIZE; j++)
            {
                if(matrix[i][j] == '-'){
                    if(!node->child){
                        
                    }
                    else{
                        node->child->sibling ;
                    }
                }

            }
            
        }
        
    }

    void GenerateMoves(){

    }
};



int main(){
    std::vector<std::vector<int>> matrix;
    LoadInputs(matrix);  

    bool turn;
    std::cin >> turn; //0 for O and 1 for X
    Tree tree(new State(-1,-1,turn), matrix);
    tree.GenerateMoves();



}