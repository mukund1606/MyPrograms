#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void main()
{
    int n;
    printf("ENTER THE TOTAL NUMBER OF ELEMENTS IN AN ARRAY:");
    scanf("%d", &n);
    int *a, max, i;
    a = (int *) malloc(n*sizeof(int));
    printf("ENTER THE ELEMENTS OF ARRAY:");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");


    max = a[0];

    for (i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }

    int *c;

    c = (int *) malloc((max+1)*sizeof(int));

    for (i = 0; i < max; i++)
    {
        c[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        c[a[i]-1] = c[a[i]-1] + 1;
    } 

    for (i = 1; i <= max; i++)
    {
        c[i] = c[i - 1] + c[i];
    }
    // for(int i = 0; i < max; i++){
    //     printf("%d ", c[i]);
    // }
    int *b;
    b = (int *) malloc((n)*sizeof(int));
    for (i = n - 1; i >= 0; i--)
    {

        c[a[i]-1] = c[a[i]-1] - 1;
        b[c[a[i]-1]] = a[i];
    }

    for (i = 0; i < n; i++)
    {
        a[i] = b[i];
    }

    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}