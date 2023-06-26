#include<iostream>
#include<string.h>

using namespace std;

struct User{
    string user_name;
    int age;    
};

/**
 * 变长参数传递
*/
void print(initializer_list<string> input){
    for(initializer_list<string>::value_type temp : input){
        cout << temp << endl;
    }
}

User* create_user(){
    User *user = (User *)malloc(sizeof(User));
    user->user_name = "zhangxing";
    user->age = 10;
    return user;
}

/**
 * 创建一块区域后，return
 * 上层函数会收到该块申请的内存区域
*/
int * create_array(){
    int * p = (int *)malloc(sizeof(int)*10);
    memset(p,0,sizeof(int) * 10);
    p[0] = 100;
    return p;
}

void test(int a,...){
    cout << a << endl;
}



// int (* create_arr())[10];
/**
 * create_array无法指明数组是多大的长度
 * 返回指向数组的指针 要想指明长度需要通过如下的方式
 * 1.通过别名的方式
*/
typedef int arr[10];
using arr_t = int[10];
arr* create_arr_1_1(){
    return NULL;
}

arr_t* create_arr_1(){
    return NULL;
}
/**
 * 2.声明返回指向数组的指针
*/
int (* create_arr_2())[10]{
    int (*p)[10] = (int (*)[10])malloc(sizeof(int) * 10);
    (*p)[0] = 5;
    return p;
}
/**
 * 3.尾置返回类型
 * 原返回类型的地方必须加上auto
*/
auto create_arr() -> int (*)[10]{
    return NULL;
}

auto function() -> int{
    return 1;
}

/**
 * 4.使用decltype 自动推测返回类型
 * 这里推测出来的书数组 并不是数组指针 因此需要加上*
*/
int temp[10];
decltype(temp) *func(){
    int (*p)[10] = (int (*)[10])malloc(sizeof(int) * 10);
    (*p)[0] = 111;
    return p;
}

int main(int argc,char *argv[]){
    initializer_list<string> il = {"zhangxing","age","names"};
    print(il);

    test(11,22,33,44,55);

    User* user = create_user();
    cout << user << endl;
    cout << user->user_name << endl;
    cout << user->age << endl;

    int * p = create_array();
    cout << p << endl;
    cout << p[0] << endl;

    int (*pp)[10] = create_arr_2();
    cout << pp << endl;
    cout << (*pp)[0] << endl;

    int (*ppp)[10] = func();
    cout << ppp << endl;
    cout << (*ppp)[0] << endl;
    return 0;
}