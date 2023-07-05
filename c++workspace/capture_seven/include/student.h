#ifndef STUDENT
#define STUDENT
#include<string>
#include<iostream>

class Student;
/**
 * 定义友元内部函数必须遵循如下顺序
 * 1.在类(teacher)中先声明要访问友元的方法
 * 2.在类(student)声明友元方法
 * 3.定义1中声明的方法
 * 同时确保在同一个头文件中，多个文件因为无法确定编译顺序也无法通过编译器
*/
class teacher{
public:
    Student & update_age(Student &s); //函数声明
};

class Student{
friend Student & teacher::update_age(Student &); //类内部函数的友元声明
friend class age_manager;//友元类声明
friend void set_student_name(const Student &stud,std::string std_name); // 友元外部方法声明
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
    /**
     * 当stud对象为常量对象/常量引用/常量指针时，无法改变对象的内容 page258
     * 除非将其写成mutable 
    */
    stud.student_name = std_name; 
}

/**
 * 类内部函数定义
*/
Student & teacher::update_age(Student &s){
    s.age += 2;
    return s;
}

#endif