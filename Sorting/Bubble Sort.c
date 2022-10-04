// bubble sorting//
#include <stdio.h>
int main()
{
    int n;
    printf("ENTER THE NUMBER OF ELEMENTS IN AN ARRAY:");
    scanf("%d", &n);
    int a[n], i, j, temp;
    printf("ENTER THE ELEMENTS OF ARRAY:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        int flag = 0;

        for (j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }

    printf("AFTER BUBBLE SORING THE ARRAY IS:");

    for (i = 0; i < n; i++)
    {
        printf(" %d", a[i]);
    }

    return 0;
}
