#include <iostream>

constexpr size_t MAX_STRING_SIZE = 256;

template <class DataType>
class Stack{
private:
    unsigned tos;
    DataType* data;
    unsigned capacity;
    void resize(){
        unsigned new_capacity = capacity * 2;
        DataType* new_data = new DataType[new_capacity];
        for (unsigned i = 0; i < tos; i++)
            new_data[i] = data[i];

        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

    void copyData(const Stack& other) {
        while(other.tos >= capacity)
            resize();
        for (unsigned i = 0; i <= other.tos; i++) {
            data[i] = other.data[i];
        }
    }   

public:
    Stack() : tos(0), data(new DataType[16]), capacity(16){}
    Stack(unsigned size) : tos(0), data(new DataType[size]), capacity(size){}
    ~Stack(){delete data;}
    Stack(const Stack& other) : data(new DataType[other.capacity]), tos(other.tos), capacity(other.capacity){
        copyData(other);
    }
    Stack(Stack&& other) noexcept 
        : tos(other.tos), capacity(other.capacity), data(other.data) {
        other.data = nullptr;
        other.tos = 0;
        other.capacity = 0;
    }
    Stack& operator=(const Stack& other){
        if(this != &other){
            delete[] data; 
            capacity = other.capacity;
            data = new DataType[capacity];  
            tos = other.tos;
            copyData(other);
        }
        return *this;
    }
    Stack& operator=(Stack&& other){
        if(this != &other){
            delete[] data;
            tos = other.tos;
            capacity = other.capacity;
            data = other.data;
            
            other.data = nullptr;
            other.tos = 0;
            other.capacity = 0;
        }
        return *this;
    }
    //functionality
    bool empty() const{return tos == 0;}

    DataType pop(){
        if(empty())
            throw std::underflow_error("Stack is empty!");
        DataType res = data[tos-1];
        tos--;
        return res;
    }
    DataType top() const{
        if(empty())
            throw std::underflow_error("Stack is empty!");
        return data[tos-1];
    }

    bool full() const{return tos == capacity;}

    void push(const DataType& element){
        if(full())
            resize();
        data[tos++] = element;
    }

    void print()const{
        for (size_t i = 0; i < tos; i++)
            std::cout << data[i] << ' ';
        std::cout << '\n';
    }
};

bool isPriorityOperator(char op){
    bool res = op == '*' || op == '/';
    return res;
}

int processCalculation(char op, int num1, int num2){
switch(op){
    case '+':
        return num1 + num2;
        break;
    case '-':
        return num2 - num1;
        break;
    case '*':
        return num1 * num2;
        break;
    case '/':
        return num2 / num1;
        break;
    default:
        throw std::invalid_argument("Invalid operator!");
        break;
}

}

int processExpression(Stack<char>& operators, Stack<int>& operands, const char* inputString){
    bool firstOperator = true;
    for (size_t i = 0; inputString[i] != '\0'; i++){
        char c = inputString[i];
        if(c == ' ') //space
            continue;
        else if(std::isalnum(c)){ //num -> empty operators
            firstOperator = true;
            while(!operators.empty()){
                int num1 = operands.pop();
                int num2 = operands.pop();
                char op = operators.pop();
                operands.push(processCalculation(op, num1, num2));
            }
            operands.push(inputString[i] - '0');
        }
        else if(isPriorityOperator(c) || firstOperator){ //yes operator -> push stars on top
            operators.push(c);
            firstOperator = false;
        }
        else{ //have to jugala bugala 
            Stack<char> temp;
            while(!operators.empty() && isPriorityOperator(operators.top()))//pop from original and and to temp
                temp.push(operators.pop());
            operators.push(c);
            while(!temp.empty())// push back to original
                operators.push(temp.pop());
        }
    }
    while(!operators.empty()){//last bit of operators to process
        int num1 = operands.pop();
        int num2 = operands.pop();
        char op = operators.pop();
        operands.push(processCalculation(op, num1, num2));
    }
    return operands.top();
}

int main(){
    char input[MAX_STRING_SIZE];
    std::cin.get(input, MAX_STRING_SIZE);

    Stack<int> operands;
    Stack<char> operators;

    operands.print();
    operators.print();

    std:: cout << processExpression(operators, operands, input);
    //push operands into stack
    //push operators into stack
    //write stack ffs

}