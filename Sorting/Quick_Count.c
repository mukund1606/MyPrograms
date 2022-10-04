#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int quick_part(int *arr, int Fi, int LI);

void QuickSort(int *arr, int FI, int LI);

void CountingSort(int *arr, int n);

int main()
{
    int n, i;
    int *count, *quick;
    printf("Enter Length of Array:");
    scanf("%d", &n);
    quick = (int *) malloc(n*sizeof(int));
    count = (int *) malloc(n*sizeof(int));
    printf("Enter Values:");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &quick[i]);
    }
    for(i = 0; i < n; i++)
    {
        count[i] = quick[i];
    }
    printf("Total Number of Elements: %d\n", n);
    printf("Entered Values Are:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d  ", count[i]);
    }
    printf("\n");
    QuickSort(quick, 0, n - 1);
    printf("After Quick Sort:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d  " , quick[i]);
    }
    CountingSort(count, n);
    printf("\nAfter Count Sort:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d  " , count[i]);
    }
    getch();
    return 0;
}

int quick_part(int *arr, int FI, int LI)
{
    int elem, i, j, temp;
    elem = arr[LI];
    i = FI;
    j = FI - 1;
    while(i < LI)
    {
        if(arr[i] > elem)
        {
            i++;
        }
        else
        {
            j++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }
    temp = arr[i];
    arr[i] = arr[j+1];
    arr[j+1] = temp;
    return (j+1);
}

void QuickSort(int *arr, int FI, int LI)
{
    int part;
    if (FI < LI)
    {
        part = quick_part(arr, FI, LI);
        QuickSort(arr, FI, part - 1);
        QuickSort(arr, part + 1, LI);
    }
}


void CountingSort(int *arr, int n)
{
    int max, i;
    int *temparr, *sortedarr;
    sortedarr = (int *) malloc (n*sizeof(int));
    max = arr[0];
    for(i = 1; i < n; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    temparr = (int *) malloc ((max)*sizeof(int));
    for(i = 0; i < max; i++)
    {
        temparr[i] = 0;
    }
    for(i = 0; i < n; i++)
    {
        temparr[arr[i]-1]++;
    }
    for(i = 1; i < max; i++)
    {
        temparr[i] += temparr[i-1];
    }
    for(i = n - 1; i >= 0; i--)
    {
        temparr[arr[i]-1]--;
        sortedarr[temparr[arr[i]-1]] = arr[i];
    }
    for(i = 0; i < n; i++)
    {
        arr[i] = sortedarr[i];
    }
}