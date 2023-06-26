#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    auto b(a); // 初始化一个指针b指向a数组
    decltype(a) c = {10,11,12,13,14,15,16,17,18,19}; // decltype 不会隐式的将数组名转换成数组指针
    cout << b[0] << endl;
    int *p[10] = {0};// 指针数组

    for(int i=0;i<10;i++){
        int *temp = (int *)malloc(sizeof(int) * 10);
        for(int j=0;j<10;j++){
            temp[j] = i*10+j;
        }
        p[i] = temp;
    }

    int (*p_a)[10] = &a;
    cout << (*p_a)[6] << endl;

    int* &ref_a = p[1]; // 创建一个指针得引用
    cout << ref_a[3] << endl;

    for(int x=0;x<10;x++){
        for(int y=0;y<10;y++){
            printf("%2d ",p[x][y]);
        }
        printf("\n");
    }


    return 0;
}