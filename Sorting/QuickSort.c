// QUICK SORTING//
#include <stdio.h>
#include <stdlib.h>
void quick_sort(int a[], int FI, int LI);
int part(int a[], int, int);
void main()
{
    int n;
    printf("ENTER THE TOTAL NUMBER OF ELEMENTS IN N ARRAY:");
    scanf("%d", &n);
    int a[n], FI = 0, LI = n - 1, i;
    printf("ENTER THE ELEMENTS OF ARRAY:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    quick_sort(a, FI, LI);
    for (i = 0; i < n; i++)
    {
        printf("%d", a[i]);
    }
}
void quick_sort(int a[], int FI, int LI)
{
    int Q;
    if (FI < LI)
    {

        Q = part(a, FI, LI);
        quick_sort(a, FI, Q - 1);
        quick_sort(a, Q + 1, LI);
    }
}

int part(int a[], int FI, int LI)
{
    int p, i, j, temp;
    p = a[LI];
    i = FI;
    j = FI - 1;

    while (i < LI)
    {
        if (a[i] > p)
        {
            i++;
        }

        else
        {
            j++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
        }
    }
    temp = a[i];
    a[i] = a[j + 1];
    a[j + 1] = temp;

    return j + 1;
}
