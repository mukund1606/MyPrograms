#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *a;
    int n;
    scanf("%d", &n);
    a = (int *) malloc (n* sizeof(int));
    if (a == NULL)
    {
        printf("Not Allocated \n");
        exit (0);
    }
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; i++)
    {
        printf("%d  ", a[i]);
    }
    return 0;
}