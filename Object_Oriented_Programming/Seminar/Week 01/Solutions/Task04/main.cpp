#include <iostream>

struct Student
{
    enum Year{
    first = 1,
    second = 2,
    third = 3,
    fourth = 4
    };

    unsigned studentID;
    Year year;
    float grade;
};

Student InitStudent(unsigned studentID, int year, float grade){
    Student student;
    switch (year)
    {
    case Student::first:
        student.year = Student::first;
        break;
    case Student::second:
        student.year = Student::second;
        break;
    case Student::third:
        student.year = Student::third;
        break;
    case Student::fourth:
        student.year = Student::fourth;
        break;
    default:
        std::cout << "Invalid year!";
        student.year = Student::first;
        break;
    }
    student.grade = grade;
    student.studentID = studentID;
    return student;
}

void PrintStudent(const Student& student){
    std::cout << "ID: " << student.studentID << '\n';
    std::cout << "Grade: " << student.grade << '\n';
    std::cout << "Year: ";
    switch (student.year)
    {
    case Student::first:
        std::cout << "first\n";
        break;
    case Student::second:
        std::cout << "second\n";
        break;
    case Student::third:
        std::cout << "third\n";
        break;
    case Student::fourth:
        std::cout << "fourth\n";
        break;        
    }    
}

struct Group
{
    unsigned size;
    Student* students;
    float averageGrade;
};

Group InitGroup(unsigned size, Student* students){
    Group group;
    group.size = size;
    group.students = students;
    
    group.averageGrade = 0;
    for (size_t i = 0; i < group.size; i++)
    {   
        group.averageGrade += group.students[i].grade;
    }
    group.averageGrade /= group.size;
    return group;
}

unsigned ScolarshipCount(const Group& group, float minGrade){
    unsigned counter = 0;
    for (size_t i = 0; i < group.size; i++)
    {
        if(group.students[i].grade >= minGrade)
            counter++;
    }
    return counter;
    
}


int main(){
    unsigned size;
    std::cin >> size;
    Student* students = new(std::nothrow) Student[size];
    if(!students){
        std::cout << "Memory error!";
        return 0;
    }
    for (size_t i = 0; i < size; i++)
    {
        unsigned id;
        int year;
        float grade;
        std::cin >> id >> year >> grade;
        //validation
        if(!(id <= 100000 && id >=10000)){
            std::cout << "Invalid ID!";
            return -1;
        }
        if(grade < 2 || grade > 6){
            std::cout << "Invalid grade!";
            return -1;
        }
        Student currstudent = InitStudent(id, year, grade);
        students[i] = currstudent;
    }
    
    Group group = InitGroup(size, students);
    float minGrade;
    std::cin >> minGrade;

    std::cout << group.averageGrade << ' ' << ScolarshipCount(group, minGrade);

    delete[] group.students;
    return 0;
}