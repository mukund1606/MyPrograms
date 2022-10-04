#include <stdio.h>
int main()
{
    int n;
    printf("ENTER THE SIZE OF ARRAY:");
    scanf("%d", &n);
    int a[n], b, i, mid = 0, flag = 0, LI = 0, UI = n - 1;
    printf("ENTER THE ELEMENTS OF ARRAY:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("ENTER THE ELEMENT YOU WANT TO FOUND: ");
    scanf("%d", &b);
    while (LI != UI && UI > LI)
    {
        mid = (LI + UI+1) / 2;
        if (a[mid] == b)
        {
            printf("ELEMENT IS FOUND");
            flag = 1;
            break;
        }
        else
        {
            if (a[mid] > b)
            {
                UI = mid - 1;
            }
            else
            {
                LI = mid + 1;
            }
        }
    }
    if (flag == 0)
    {
        if (a[UI] == b)
        {
            printf("ELEMENT FOUND");
        }
        else
        {
            printf("ELEMENT NOT FOUND");
        }
    }
    return 0;
}