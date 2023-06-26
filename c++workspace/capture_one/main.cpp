#include<iostream>
#include<string>

using namespace std;

const int data = 100;
constexpr int data3 = 300; // 无法修改
int data2 = 200;

/**
 * 等价写法 
 * 在指针/引用中：无论在什么位置，constexpr 用来修饰指针是个常量指针
 **/
int constexpr * p = &data2; 
constexpr int* p2 = &data2;

const int constexpr *c_p = &data;
constexpr const int * c_p2 = &data;

constexpr int &r = data2;
constexpr const int &c_r = data;

typedef double name,*name2;
using I = int;
int main(){
    // string c = u8"test";

    name dd = 3;
    name2 dd_p = &dd;
    I age = 20;
    // cout << c << endl;
    cout << *p << " " << *p2 << endl;
    cout << *c_p << " " << *c_p2 << endl;

    cout << r << " " << c_r << endl;

    cout << "d type is " << typeid(dd).name() << endl;
    cout << "d_p type is " << typeid(dd_p).name() << endl;

    cout << "age type is " << typeid(age).name() << endl;

    int a = 10,&b = a;
    decltype(a) c = 20; // 这里c是一个int型
    cout << c << " " << typeid(c).name() << endl;
    decltype(b) d = c; // 这里d是一个int型的引用
    decltype((a)) f = c ; // 同样f也是一个int型的引用，decltype((x)) 永远返回的是x类型的引用
    cout << typeid(d).name() << " " << typeid(f).name() << endl;
    int * p_a = &a;
    decltype(*p_a) g = a; // 对于指针解引用后 返回的也是该类型的引用类型
    g = 11;
    cout << a << endl;
    cout << typeid(g).name() << endl;
    return 0;
}
