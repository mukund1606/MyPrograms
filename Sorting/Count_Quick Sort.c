#include <stdio.h>
#include <stdlib.h>

int quick_part(int *a, int FI, int LI)
{
    int l, i ,j ,temp;
    l = a[LI];
    i = FI;
    j = FI - 1;

    while ( i < LI)
    {
        if (a[i] > l)
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
    a[i] = a[j+1];
    a[j+1] = temp;
    return j + 1;
}

void QuickSort(int *a, int FI, int LI)
{
    int Q;
    if (FI < LI)
    {
        Q = quick_part(a, FI, LI);
        QuickSort(a, FI, Q - 1);
        QuickSort(a, Q + 1, LI);
    }
}


void CountSort(int *a, int n)
{
    int max, i;
    int *c, *b;
    b = (int *) malloc (n*sizeof(int));
    max = a[0];
    for(i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    c = (int *) malloc (max*sizeof(int));
    for(i = 0; i < max; i++)
    {
        c[i] = 0;
    }
    for(i = 0; i < n; i++)
    {
        c[a[i]-1] = c[a[i]-1] + 1;
    }
    for(i = 1; i <= max; i++)
    {
        c[i] = c[i-1] + c[i];
    }
    for(i = n - 1; i >= 0; i--)
    {
        c[a[i]-1] = c[a[i]-1] - 1;
        b[c[a[i]-1]] = a[i];
    }
    for(i = 0; i < n; i++)
    {
        a[i] = b[i];
    }
}


int main()
{
    int n;
    int *quick, *count;
    printf("Enter Length of Array:");
    scanf("%d", &n);
    quick = (int *) malloc(n*sizeof(int));
    count = (int *) malloc(n*sizeof(int));
    // int quick[n];
    printf("Enter Values:");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &quick[i]);
    }
    for(int i = 0; i < n; i++)
    {
        count[i] = quick[i];
    }
    printf("Total Number of Elements: %d\n", n);
    printf("Entered Values Are:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d  ", count[i]);
    }
    printf("\n");
    QuickSort(quick, 0, n - 1);
    printf("After Quick Sort:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d  " , quick[i]);
    }
    CountSort(count, n);
    printf("\nAfter Count Sort:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d  " , count[i]);
    }
}