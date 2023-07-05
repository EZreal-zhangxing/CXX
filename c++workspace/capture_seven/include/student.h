#ifndef STUDENT
#define STUDENT
#include<string>
#include<iostream>

class Student{
friend void set_student_name(const Student &stud,std::string std_name);
private:
    mutable std::string student_name;
    unsigned int age;
public:
    Student() = default;
    Student(std::istream &in); // 外部构造器
    Student(std::string std_name):student_name(std_name),age(0){/*内部构造器*/};
    Student(std::string std_name,unsigned int a):student_name(std_name),age(a){};
    void print_info() const; // 常量成员函数
    void print_info_unconst();
};

Student::Student(std::istream &in){
    // 外部构造器
    in >> this->student_name >> age;
}

inline void Student::print_info() const{
    std::cout << "student name: [" << this->student_name;
    std::cout << "] age : [" << this->age << "]" << std::endl;
}

inline void Student::print_info_unconst(){
    std::cout << "student name: [" << this->student_name;
    std::cout << "] age : [" << this->age << "]" << std::endl;
}

/**
 * 如果不将该函数声明称友元 则会报错，无法方位私有成员
*/
void set_student_name(const Student &stud,std::string std_name){
    stud.student_name = std_name; //当stud对象为常量对象时，无法改变对象的内容 page258
}
#endif