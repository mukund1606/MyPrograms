#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void countSort(int *a, int n , int R){
    int i;
    int *b = (int *)calloc(n, sizeof(int));
    int c[10] = { 0 };
    //Frequency
    for(i = 0; i < n; i++){
        c[(a[i]/R)%10]++;
    }
    //Cumilative Frequency
    for(i = 1 ; i < 10; i++){
        c[i] += c[i-1];
    }
    //Storing Values in b
    for(i = n - 1; i >= 0; i--){
        b[c[(a[i]/R)%10]-1] = a[i];
        c[(a[i]/R)%10]--;
    }
    //Replacing Values of a from b
    for(i = 0; i < n; i++){
        a[i] = b[i];
    }
}