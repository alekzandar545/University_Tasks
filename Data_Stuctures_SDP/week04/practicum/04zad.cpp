#include <iostream>
#include <queue>
#include <stack>

/*Създайте текстов редактор, който поддържа следните операции:

write(char) - Записва символ в текста
read(char) - Прочита съдържанието на текста и го принтира
undo() - отменя последната операция извършена върху текста
redo() - връща последната отменена операция върху текста*/

class TextEditor{
    public:
    TextEditor() = default;
    TextEditor(const TextEditor& other) = default;
    void write(const char& ch){
        while(!history.empty())
            history.pop();
        text.push_back(ch);
    }
    void read() const{
        std::cout << text << '\n';
    }
    void undo(){
        char el = text.back();
        history.push(el);
        text.pop_back();
    }
    void redo(){
        if(!history.empty()){
            char el = history.top();
            text.push_back(el);
            history.pop();
        }
    }

    private:
    std::string text;
    std::stack<char> history; 
};

int main(){
    TextEditor editor;
    editor.write('a'); //a
    editor.write('b'); //ab
    editor.write('c'); //abc
    editor.write('d'); //abcd 
    editor.read(); // prints abcd
    editor.undo(); // abc
    editor.undo(); //ab
    editor.read(); //prints ab
    editor.redo(); //abc
    editor.read(); //prints abc
    editor.redo(); //abcd
    editor.read(); //prints abcd
}