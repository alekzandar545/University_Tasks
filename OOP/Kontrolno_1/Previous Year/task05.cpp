#include <iostream>
#include <cstring>

class Task{
public:
    char* name;
    unsigned hours;
public:
    Task();
    Task(const char* task, unsigned hours);
    Task(const Task& task);
    Task& operator=(const Task& other);
    ~Task();

    unsigned getHours() const;

    void copy(const Task& other);
    void print() const;
    int compareName(const Task& other) const;
};

class TaskList{
public:
    Task* list;
    size_t size;
    size_t capacity;
public:
    TaskList();
    TaskList(const Task* tasks, const size_t size);
    TaskList(const TaskList& other);
    TaskList& operator=(const TaskList& other);
    ~TaskList();

    void printTasks() const;
    void addTask(const Task& task);
    void removeTask(const Task& task);
};
//big 4
Task::Task(){
    name = nullptr;
    hours = 0;
}
Task::Task(const char* task, unsigned hours){
    name = new(std::nothrow) char[strlen(task) + 1];
    if(!name){
        std::cout << "Memory error!";
        return;
    }
    strcpy(name,task);
    this->hours = hours;
}
Task::Task(const Task& task){
    copy(task);
}
Task& Task::operator=(const Task& other){
    if(&other == this)
        return *this;
    copy(other);
    return *this;
}
Task::~Task(){
    delete[] name;
}
//functionality
void Task::copy(const Task& other){
    if(name)
        delete[] name;
    name = new(std::nothrow) char[strlen(other.name)+1];
    if(!name){
        std::cout << "Memory error!";
        return;
    }
    strcpy(this->name, other.name);
    hours = other.hours;
}
void Task::print() const{
    std::cout << name;
}
int Task::compareName(const Task& other) const{
    return strcmp(name, other.name);
}   

unsigned Task::getHours() const{
    return this->hours;
}

//bug4
TaskList::TaskList(){
    list = nullptr;
    capacity = 0;
    size = 0;
}
TaskList::TaskList(const Task* tasks, const size_t size){
    this->size = size;
    capacity = size + 10;
    list = new Task[capacity];
    for (size_t i = 0; i < size; i++)
    {
        list[i] = tasks[i];
    }
}
TaskList::TaskList(const TaskList& other){
    this->size = other.size;
    this->capacity = other.capacity;
    this->list = new Task[capacity];
    for (size_t i = 0; i < size; i++)
    {
        list[i] = other.list[i];
    }
}
TaskList& TaskList::operator=(const TaskList& other){
    if(this == &other){
        return *this;
    }
    if(this->list)
        delete[] list;
    this->size = other.size;
    this->capacity = other.capacity;
    this->list = new Task[capacity];
    for (size_t i = 0; i < size; i++)
    {
        list[i] = other.list[i];
    }
    return *this;
}
TaskList::~TaskList(){
    delete[] list;
}


//functtionality
void TaskList::printTasks() const{
    for (size_t i = 0; i < size; i++)
    {
        list[i].print();
        std::cout << ' ';
    }
}
void TaskList::addTask(const Task& task){
    if(size == capacity){
        std::cout << "full";
        return;
    }
    list[size++] = task;
}
void TaskList::removeTask(const Task& task){
    for (size_t i = 0; i < size; i++)
    {
        if(!list[i].compareName(task) && list[i].getHours() == task.getHours()){
            Task temp;
            temp = list[i];
            //std::cout << temp.name;
            //std::cout << temp.name;
            list[i].copy(list[size-1]);
            list[size-1].copy(temp);
            size--;
            i--;
        }
    }
}
int main(){
    char cock[] = "cock";
    Task task1(cock, 4);
    char balls[] = "balls";
    Task task2(balls, 5);
    Task tasks[2];
    tasks[0] = task1;
    tasks[1] = task2;
    TaskList taskList(tasks, 2);
    taskList.addTask(task1);
    taskList.removeTask(task1);
    taskList.addTask(task1);
    taskList.printTasks();
}