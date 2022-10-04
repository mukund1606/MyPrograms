#include <stdio.h>
#include <string.h>


struct stru{
    int x, y, z;
};

int main(){
    //Structures with pointer
    struct stru s = {1, 5, 2};

    //Stroing Address of s in s2
    struct stru *s2 = &s;

    //Accessing Data of s1 using s2
    printf("\n%d %d %d\n", s2->x, s2->y, s2->z);

    return 0;
}