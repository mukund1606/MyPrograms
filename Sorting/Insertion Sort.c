#include<stdio.h>

void insertionSort(int *a, int n)
{
    int *temp, b, i, j;
    temp = (int *)calloc(n, sizeof(int));
    for (i = 0; i < n; i++)
        temp[i] = 0;
    for (i = 0; i < n; i++)
    {
        b = a[i];
        if (i == 0)
            temp[i] = b;
        else
        {
            j = i - 1;
            while(j >= 0 && temp[j] > b){
                temp[j+1] = temp[j];
                j--;
            }
            temp[j + 1] = b;
        }
    }
    for (i = 0; i < n; i++)
    {
        a[i] = temp[i];
    }
}

void main(){
    int n, b, i, j;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++){
        a[i] = 0;
    }

    
    for(i = 0; i < n; i++){
        scanf("%d", &b);
        if(i == 0){
            a[i] = b;
        }
        else{
            for(j = i - 1; j >= 0 && a[j] > b; j--){
                a[j+1] = a[j];
            }
            a[j+1] = b;
        }
    }
    printf("\n \n \n \n");
    for(i = 0; i < n; i++){
        printf("%d, ", a[i]);
    }
}