#include <stdio.h>

int main(){
	int i, j, temp, ch, b, n;
	printf("Sorting\nEnter 1 For Bubble Sort\nEnter 2 For Insertion Sort\nEnter Your Choice:");
	scanf("%d" ,&ch);
	printf("Enter Number of Elements:");
	scanf("%d", &n);
	int a[n];
	printf("Enter Elements:");
	if(ch == 1){
		for(i = 0; i < n; i++){
			scanf("%d:", &a[i]);
		}
		printf("\nArray Before Sorting:\n");
		for(i = 0; i < n; i++){
			printf("%d,", a[i]);
		}
		for(i = 0; i < n;i++){
			for(j = 0; j < n - i - 1; j++){
				if(a[j] > a[j+1]){
					temp = a[j+1];
					a[j+1] = a[j];
					a[j] = temp;
				}
			}
		}

		printf("\nBubble Sort\n");
	}
	if(ch == 2){
		for(i = 0; i < n; i++){
			scanf("%d", &b);
			if(i == 0){
				a[i] = b;
			}
			else{
				j = i - 1;
				while (j >= 0 && a[j] > b){
					a[j+1] = a[j];
					j--;
				}
				a[j+1] = b;
			}
		}
		printf("\nInsertion Sort\n");
	}
	for(i = 0; i<n; i++){
		printf("%d," , a[i]);
	}
	return 0;
}