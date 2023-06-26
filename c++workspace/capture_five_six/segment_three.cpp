#include<iostream>

using namespace std;

/**
 * 常量表达式函数
*/
constexpr int char_bias(){ return 42;}
// 如果x也是常量 那么返回的也是常量表达式，否则不是
constexpr int expend_twice(int x){ return x*2; }

void method_2(int z,void p(const int x,int y)){
    cout << z << endl;
    p(2,4);
}

void method(const int x, int y){
    cout << x << " " << y << endl;
}
int main(){

    cout << expend_twice(2) << endl;

    int y = 4;
    cout << expend_twice(y) << endl;
    cout << __FILE__ << endl;
    cout << __func__ << endl;
    cout << __LINE__ << endl;
    cout << __TIME__ << endl;
    cout << __DATE__ << endl;

    void (*m_p)(const int a,int b); // 函数指针
    m_p = method;

    m_p(2,4);
    method_2(6,m_p);
    return 0;
}