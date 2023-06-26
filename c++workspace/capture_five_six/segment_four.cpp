#include<iostream>

/**
 * 返回函数指针的样例，本样例和返回一个指向数组的指针样例类似
 * 结合primer C++ 223 和 205一起理解
 * 样例文件参考 segment_two.cpp
 * 
*/
using namespace std;

/**
 * 定义一个返回函数指针的函数
*/
// 使用typedef声明一个指向函数的指针,用func作为别名
typedef void (* func)(const int x,int y);

// void(* func1(void))(const int x,int y);

void method(const int x,int y){
    cout << x << " " << y << endl;
}

func test_method(){
    return method;
}
/**
 * 申明一个返回类型 内层func1(void)函数的形参，
 * (*func1(void)) 这是一个指针
 * 指针指向外层两个形参的函数指针
*/
void(* func1(void))(const int x,int y){
    return method;
}

/**
 * 方式三：使用后置返回类型
 * 后置返回类型不需要方法名，只需要申明成指针
*/
auto func2() -> void (*)(const int x,int y){
    return method;
}

/**
 * 方式四：使用decltype
 * 这里推测出来的是函数类型 并不是函数指针 因此需要加上*
*/

decltype(method) *func3(){
    return method;
}


int main(){
    func f = test_method();
    f(2,4);
    void (*ff)(const int x,int y) = func1();// 定义一个指向两个参数的函数指针
    ff(4,6);
    auto fff = func2();
    fff(6,8);
    decltype(method) *ffff = func3();
    ffff(8,10);
    return 0;
}