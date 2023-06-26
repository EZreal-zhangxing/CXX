#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// #include<iostream>
// using namespace std;
/**
 * 拷贝传值
 * 通过指针对原来的变量进行值得替换
*/
void swap(int * a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int * p_g = 0;
/**
 * 开辟内存空间，但是形参p只保留在整个函数运行期间
*/
void create(int * p){
    p = (int *)malloc(sizeof(int) * 10);
    p_g = (int *)malloc(sizeof(int) * 10);
    memset(p,0,sizeof(int) * 10);
    memset(p_g,0,sizeof(int) * 10);
    p[0] = 1;
    printf("%d \n",p[0]);
    printf("%p \n",p);
}

/**
 * 引用操作原来（主函数）得变量地址
*/
void test_ref(int *& p){
    p = (int *)malloc(sizeof(int) * 10);
    memset(p,0,sizeof(int) * 10);
    p[0] = 2;
}

int main(){
    int a = 5,b=6;
    printf("%d %d \n",a,b);
    // cout << a << " " << b << endl;
    swap(&a,&b);
    // cout << a << " " << b << endl;
    printf("%d %d \n",a,b);

    int *p = 0;
    create(p);// 在方法调用完毕后，内存被释放，指针传值原理上还是拷贝传值,但是作为return后 该块内存区域和指针会返回本函数
    printf("%p \n",p); // nil 空指针
    // cout << p[0] << endl;
    printf("%p \n",p_g); // 全局变量的操作在整个程序结束后才会销毁

    test_ref(p);
    printf("test_ref return %p %d\n",p,p[0]); // 使用引用则会对原变量进行操作
    return 0;
}