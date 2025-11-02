#include <iostream>
#include "data_structures/DynamicArray/DynArray.hpp"
#include "data_structures/Queue/staticQueue.hpp"
#include "data_structures/Queue/priorityQueue.hpp"
#include "data_structures/Stack/staticStack.hpp"
#include "data_structures/Stack/sortedStack.hpp"
#include <stdexcept>
#include <fstream>

using namespace fmi::sdp; //using modified data structures from the lectures

//Constants
constexpr unsigned MAX_ROOM_SIZE = 50;
constexpr unsigned START_TIME = 8;
constexpr char OCCUPIED_SEAT = 'O';
constexpr char BROKEN_SEAT = 'B';
constexpr char FREE_SEAT = 'F';

//Structs
struct Student{
    uint8_t id;
    unsigned entryTime, length, priority;

    Student(uint8_t id = 0, unsigned entryTime = 0, unsigned length = 0, unsigned priority = 0) 
        : id(id), entryTime(entryTime), length(length), priority(priority) {}
};

struct Event{
    enum EventType {
        STUDENT_START, 
        STUDENT_FINISH, 
        LECTURER_START, 
        LECTURER_FINISH
    };
    unsigned priority;
    unsigned time;
    unsigned length;
    EventType type;
    uint8_t id;
    
    Event(unsigned time = 0, unsigned length = 0, EventType type = Event::EventType::STUDENT_START, uint8_t id = 0, uint8_t priority = 0)
        : time(time), length(length), type(type), id(id), priority(priority) {}

    //factory functions bc of long constructor
    static Event createStudentStartEvent(unsigned time, unsigned length, uint8_t id, uint8_t priority) {
        return Event(time, length, STUDENT_START, id, priority);
    }

    static Event createStudentFinishEvent(unsigned time, uint8_t id) {
        return Event(time, 0, STUDENT_FINISH, id);
    }

    static Event createLecturerStartEvent(unsigned time, unsigned length) {
        return Event(time, length, LECTURER_START);
    }

    static Event createLecturerFinishEvent(unsigned time, uint8_t id) {
        return Event(time, 0, LECTURER_FINISH, id);
    }

    bool operator>(const Event& other) const { //need to sort neatly with sortedStack
        return time > other.time;
    }
    
    bool operator>= (const Event& other) const {
        return time >= other.time; 
    }
};

//Printing
void printMatrix(const DynArray<DynArray<char>>& matrix){
    unsigned N = matrix.getSize();
    unsigned M = matrix[0].getSize();
    std::cout << "----------------------------\n";
    for (size_t i = 0; i < N; i++){
        for (size_t j = 0; j < M; j++)
            std::cout << matrix[i][j];
        std::cout << '\n';
    }
    std::cout << '\n';
}

//Logic
bool isValid(const DynArray<DynArray<char>>& matrix, unsigned x, unsigned y) {
    unsigned N = matrix.getSize();
    unsigned M = matrix[0].getSize();

    if (matrix[x][y] == BROKEN_SEAT) return false;

    //directions
    const int directionsX[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    const int directionsY[] = {0, 0, -1, 1, -1, 1, -1, 1};

    for (int i = 0; i < 8; ++i) {
        int newX = x + directionsX[i];
        int newY = y + directionsY[i];
        if (newX >= 0 && newX < N && newY >= 0 && newY < M && matrix[newX][newY] == OCCUPIED_SEAT) 
            return false;
    }

    return true; //if nothing is occupied/broken
}

void generateSeats(DynArray<DynArray<char>>& matrix, unsigned count, const unsigned desiredCapacity, unsigned& max, DynArray<DynArray<char>>& resultMatrix, unsigned x, unsigned y) {
    unsigned N = matrix.getSize();
    unsigned M = matrix[0].getSize();

    if(count > max){
        max = count;
        resultMatrix = matrix;
    }

    if (count == desiredCapacity)
        return; //best case is when desired capacity reached

    for (unsigned i = x; i < N; ++i) {
        for (unsigned j = (i == x ? y : 0); j < M; ++j) { //important to reset to 0 when working on other rows!
            if (matrix[i][j] == FREE_SEAT && isValid(matrix, i, j)) {
                matrix[i][j] = OCCUPIED_SEAT; //placing student
                generateSeats(matrix, count + 1, desiredCapacity, max, resultMatrix, i, j + 1);
                matrix[i][j] = FREE_SEAT; //backtrack
            }
        }
    }
}

unsigned findMaxCapacity(unsigned N, unsigned M) {
    unsigned maxRow = (M % 2 == 0) ? M / 2 : M / 2 + 1;
    unsigned maxCol = (N % 2 == 0) ? N / 2 : N / 2 + 1;
    return maxCol * maxRow;
}

void InitializeEvents(SortedStack<Event>& events, std::ifstream& file, unsigned lecturerLate, unsigned lecturerTime){
    std::string curr;
    file >> curr;
    Event lecturerComes(lecturerLate, lecturerTime, Event::EventType::LECTURER_START);
    events.push(lecturerComes);
    while(curr != "end"){
        unsigned entryTime, id, length, priority, tempID;
        file >> entryTime >> tempID >> length >> priority >> curr;
        id = static_cast<uint8_t>(tempID);
        priority = priority != 2; //adjust 
        Event studentEnters(entryTime, length, Event::EventType::STUDENT_START, id, priority);
        events.push(studentEnters);
    }
}

void InitializeMatrix(std::ifstream& file, DynArray<DynArray<char>>& matrix, unsigned &hallCapacity, unsigned &lecturerLate, unsigned& lecturerTime){
   unsigned N, M, B;
   //IF THE INPUT FORMAT WASN'T LIKE THIS I WOULD'T HAVE TO KEEP THE LECTURER INFO IN THE PARAMETERS
    file >> N >> M >> lecturerLate >> lecturerTime >> B;
    if(N * M > 50)
        throw std::invalid_argument("No more than 50 seats allowed!");
    DynArray<char> row;
    for (size_t i = 0; i < M; i++)
        row.append(FREE_SEAT);
    for (size_t i = 0; i < N; i++)
        matrix.append(row);
    
    for (size_t i = 0; i < B; i++){
        unsigned brokenNum;
        file >> brokenNum;
        unsigned brokenX = brokenNum / M;
        unsigned brokenY = brokenNum % M;
        if(brokenX > N || brokenY > M)
            throw std::out_of_range("Invalid placement");
        matrix[brokenX][brokenY] = BROKEN_SEAT;
    }
    DynArray<DynArray<char>> resultMatrix;
    generateSeats(matrix, 0, findMaxCapacity(N,M), hallCapacity, resultMatrix, 0, 0);
    printMatrix(resultMatrix);
}

void runSimulation(SortedStack<Event>& events, unsigned hallCapacity, unsigned lecturerTime) {
    unsigned peopleInHall = 0;
    unsigned finalTime = 0;
    PriorityQueue<Student> waitingLine;
    StaticStack<uint8_t> papers(events.getSize()); //have to template this
    StaticStack<uint8_t> result(events.getSize());

    while(events.getSize() > 0) {
        Event currEvent = events.pop();
        switch (currEvent.type) {
            case Event::EventType::STUDENT_START: {
                Student student(currEvent.id, currEvent.time, currEvent.length, currEvent.priority);
                if (peopleInHall < hallCapacity) {
                    peopleInHall++;
                    events.push(Event::createStudentFinishEvent(currEvent.time + currEvent.length, currEvent.id));
                } else {
                    waitingLine.enqueue(student, student.priority);
                }
                break;
            }

            case Event::EventType::STUDENT_FINISH: {
                papers.push(currEvent.id);
                peopleInHall--;
                if (!waitingLine.isEmpty()) {
                    peopleInHall++;
                    Student newStudent = waitingLine.dequeue();
                    events.push(Event::createStudentFinishEvent(currEvent.time + newStudent.length, newStudent.id));
                }
                break;
            }

            case Event::EventType::LECTURER_START: {
                if (papers.isEmpty()) {
                    if (events.isEmpty()) { // nothing more to check
                        finalTime = currEvent.time;
                        break;
                    }
                    events.push(Event::createLecturerStartEvent(events.top().time, lecturerTime));
                } else {
                    events.push(Event::createLecturerFinishEvent(currEvent.time + lecturerTime, papers.pop()));
                }
                break;
            }

            case Event::EventType::LECTURER_FINISH: {
                result.push(currEvent.id);
                events.push(Event::createLecturerStartEvent(currEvent.time, lecturerTime));
                break;
            }
        }
    }

    while (!result.isEmpty())
        std::cout << (int)result.pop() << '\n';
    std::cout << "Finish time: " << (START_TIME + finalTime / 60) % 24 << ':' << finalTime % 60;
}

int main(){
    std::ifstream file("input.txt");
    if (!file.is_open())
		throw std::runtime_error("Couldn't open the file!");

    unsigned hallCapacity = 0, lecturerLate, lecturerTime;
    DynArray<DynArray<char>> matrix;
    SortedStack<Event> events;

    InitializeMatrix(file, matrix, hallCapacity, lecturerLate, lecturerTime);
    InitializeEvents(events, file, lecturerLate, lecturerTime );

    file.close();

    runSimulation(events, hallCapacity, lecturerTime);

    return 0;
}