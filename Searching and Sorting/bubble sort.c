#include <stdio.h>
#include <stdlib.h>

void swap(int *x,int *y){
	int temp=*x;
	*x=*y;
	*y=temp;
}

void bubbleSort(int arr[], int n){
	for(int i=0 ; i<=n-1 ; i++){
		for(int j=0 ; j<=n-1 ; j++){
			if(arr[j]>arr[j+1]){
				swap(&arr[j],&arr[1+j]);
			}
		}
	}
}

void printArr(int arr[], int n){
	for(int i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
}

int main(){
	int arr[]={64,25,12,22,11};
	bubbleSort(arr, sizeof(arr)/4);
	printArr(arr,sizeof(arr)/4);
	return 0;
}
