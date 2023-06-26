/**
 * C 风格的结构体定义
 * 
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/**
 * method one
*/
struct student{
    char name[20];
    int age;
} *std1;

typedef struct student STUDENT;

struct node{
    int value;
    struct node *left;
    struct node *right;
};

int main(){
    std1 = (struct student *)malloc(sizeof(student));
    std1->age = 10;
    strncpy(std1->name,"zhangxing",sizeof("zhangxing") + 1);

    STUDENT * std2 = (STUDENT *) malloc(sizeof(STUDENT));
    std2->age = 20;
    strcpy(std2->name,"hhhhhh");

    printf("student info : \n");
    printf(" student age : %d\n",std1->age);
    printf(" student name: %s\n",std1->name);
    printf("student info : \n");
    printf(" student age : %d\n",std2->age);
    printf(" student name: %s\n",std2->name);

    return 0;
}