#ifndef FRIEND_TEST
#define FRIEND_TEST

class A;
class B{
public:
    void modify_a(A &);
    /**
     * 如果在类内部进行定义会报错，必须在编译器预编译ClassA 后才能知道，
     * 该函数是作为A的友元函数从而进行访问
     * 如果要引入类A作为参数，所以需要先声明A是一个类
    */
    // void modify_a(A &a){
    //     a.x = 1;
    //     a.y = 3;
    // };
};

class A{
friend void B::modify_a(A &); //友元内部函数申明
private:
    int x,y;
};

void B::modify_a(A &a){
    a.x = 1;
    a.y = 3;
}

#endif