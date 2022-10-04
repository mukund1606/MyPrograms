#include <stdio.h>
#include <stdlib.h>
#include"C1.h"

int i = 0;

void radixSort(int *a, int n);

int main()
{
    int *a, n;
    printf("Enter Number of Elements:");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    printf("Enter Elemenets:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\nNumber of Elements: %d\n", n);
    printf("\nElements Before Sorting:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    radixSort(a, n);
    printf("\n\nAfter Radix Sort:\n");
    for(i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}

void radixSort(int *a, int n){
    int max = a[0];
    for(i = 1; i < n; i++)
        if(max < a[i])
            max = a[i];
    for(int R = 1; max/R > 0; R *= 10){
        countSort(a, n, R);
    }
}