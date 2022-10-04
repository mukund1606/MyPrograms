#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void insertionSort(int *a, int n);
void bucketSort(int *a, int n, int bucketSize);

void main()
{
    int *a, n, b, i;
    printf("Enter Number of Elements:");
    scanf("%d", &n);
    a = (int *)calloc(n, sizeof(int));
    printf("Enter Bucket Size:");
    scanf("%d", &b);
    printf("Enter Elements:");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    bucketSort(a, n, b);
    printf("\n\nAfter Bucket Sort:");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    getch();
    // clrscr();
}

void insertionSort(int *a, int n)
{
    int b, i, j;
    int *temp;
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
            while (j >= 0 && temp[j] > b)
            {
                temp[j + 1] = temp[j];
                j--;
            }
            temp[j + 1] = b;
        }
    }
    for (i = 0; i < n; i++)
    {
        a[i] = temp[i];
        // printf("%d ", a[i]);
    }
}

void bucketSort(int *a, int n, int bucketSize)
{
    int max, b, size, i, k, j;
    int *sa;
    int **temp;
    max = a[0];
    for (i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    b = max / bucketSize;
    sa = (int *)calloc(b + 1, sizeof(int));
    temp = (int **)calloc(b + 1, sizeof(int));
    for (i = 0; i <= b; i++)
    {
        sa[i] = 1;
        temp[i] = (int *)calloc(1, sizeof(int));
    }
    for (i = 0; i <= b; i++)
    {
        k = 0;
        // printf("bucket %d\n", i);
        for (j = 0; j < n; j++)
        {
            if ((i * bucketSize <= a[j]) && (a[j] < (i + 1) * bucketSize))
            {
                temp[i] = realloc(temp[i], sa[i] * sizeof(int));
                // printf("Final Loop %d\n", sa[i]);
                temp[i][k] = a[j];
                k++;
                sa[i]++;
            }
        }
    }
    // for (i = 0; i <= b; i++)
    // {
    //     for (j = 0; j < n; j++)
    //     {
    //         printf("%d ", temp[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\nwork\n");
    k = 0;
    for (i = 0; i <= b; i++)
    {
        size = sa[i] - 1;
        insertionSort(temp[i], size);
        // printf("Size %d", size);
        for (j = 0; j < size; j++)
        {
            a[k] = temp[i][j];
            k++;
        }
    }
}