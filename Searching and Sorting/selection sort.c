#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y){
	int temp = *x;
	*x=*y;
	*y=temp;
}

void selSort(int arr[], int n){
	for(int i=0;i<n;i++){
		int min_id = i;
		for(int j=i+1;j<n;j++){
			if(arr[j]<arr[min_id]){
				min_id = j;
			}
		}
		swap(&arr[min_id], &arr[i]);
	}
}

void printArr(int arr[], int n){
	for(int i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
}

int main(){
	int arr[]={64, 25, 12, 22, 11};
	selSort(arr, sizeof(arr)/4);
	printArr(arr, sizeof(arr)/4);
	return 0;
}
