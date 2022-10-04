#include <stdio.h>


void MP(int a[], int FI, int mid, int LI){
    int i = FI;
    int j = mid + 1;
    int k = FI - 1;
    int b[LI + 1];
    while(i <= mid && j <= LI){
        if(a[i] > a[j]){
            k++;
            b[k] = a[j];
            j++;
        }
        else{
            k++;
            b[k] = a[i];
            i++;
        }
    }
    if(i > mid){
        while(j <= LI){
            k++;
            b[k] = a[j];
            j++;
        }
    }
    else{
        while(i <= mid){
            k++;
            b[k] = a[i];
            i++;
        }
    }
    for( i = FI; i <= LI; i++){
        a[i] = b[i];
    }  
}
void MergeSort(int a[],int FI, int LI){
    if(FI < LI){
        int mid = (LI+FI)/2;
        MergeSort(a, FI, mid);
        MergeSort(a, mid + 1, LI);
        MP(a, FI, mid, LI);
    }
}


int main(){
    int n;
    printf("Enter Number of Elements:");
    scanf("%d", &n);
    int a[n];
    // int b[n];         // int *b = new int[size];
    printf("Enter Elements:");
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    MergeSort(a, 0, n - 1);
    printf("\nSorted Array:\n");
    for(int i = 0; i < n; i++){
        printf("%d,", a[i]);
    }
    return 0;
}