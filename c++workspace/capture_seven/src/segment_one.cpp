#include "student.h"
#include<vector>
#include<list>
using namespace std;

vector<Student> read_student(){
    vector<Student> l;
    // list<Student> l;
    int count = 1;
    while(cin){
        Student input = Student(cin);
        l.push_back(input);
    }
    for(auto s = l.cbegin(),e = l.cend();s!=e;s++){
        cout << count++ << " ";
        s->print_info(); //常量成员函数 page258
        /**
         * 由于我这里申明的是常量迭代器，返回的对象都是常量类型，不能修改
         * 如果调用非常量的方法，方法的this默认是指向非常量对象，
         * 所以将会是一个将一个常量对象传入指向非常量的指针，会导致编译错误
         * 因此对于常量对象/常量引用/常量指针只能调用常量成员函数，也就是将函数内部this申明成常量的函数 page258
         * 同时 非常量对象/非常量引用/非常量指针则可以调用常量成员函数
        */
        // s->print_info_unconst(); //非常量成员函数
    }
    return l;
}

int main(){
    vector<Student> ll = read_student();
    const Student c_s = ll[0];
    set_student_name(c_s,"zhangxing");

    c_s.print_info();
    return 0;
}