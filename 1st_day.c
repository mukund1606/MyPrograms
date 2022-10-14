#include<stdio.h>

//pre defined
//int char float double

//user defined
//structure enumeration(enum)

struct var{
    int a;
    char b;
    struct var *ptr;
    struct var *ptr2;
};

void main(){
    struct var a1, a2;
    a1.a = 5;
    a1.b = 'a';
    a1.ptr = &a2;
    a2.ptr2 = &a1;
    a2.a = 6;
    a2.b = 'b';
    a2.ptr = NULL;
    printf("%d %c", a2.ptr2->a, a2.ptr2->b);
}