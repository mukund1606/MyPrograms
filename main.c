#include <stdio.h>
#include <stdlib.h>

//getch();
//clrscr();

void takestr(char a[]);

void main(){
    char a[6]; 
    char b[6] = "Hello";        //Pointer
    // b = (int *)malloc(5*sizeof(int)); //Space de raha hu
    // b = (float *)malloc(400); //Space de raha hu
    // free(b);
    gets(a);
    printf("%d", strcomp(b, a));
    puts(a);
}