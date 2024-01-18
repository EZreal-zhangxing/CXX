#include "test.h"
#include <string>
#include <iostream>

class Student{
public:
    Student() = default;
    Student(const std::string name,const int age) : name(name),age(age) {};
    void print_out();
    ~Student() = default;
private:
    std::string name;
    int age;
};

void Student::print_out(){
    std::cout << this->name << " " << this->age << std::endl;
}

int main(){
    test t;
    t.test_method();
    Student* stu0 = new Student("zhangxing",18);
    stu0->print_out();
    return 0;
}