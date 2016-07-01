#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n){
	for(int i=1;i<n;i++){
		int key = arr[i];
		int j = i-1;
		
		while(j>=0 && arr[j]> key){
			arr[j+1] = arr[j];
			j=j-1;
		}
		arr[j+1]=key;
	}
}

void printArr(int arr[], int n){
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}

int main(){
	int arr[]={12,11,13,5,6};
	int n = sizeof(arr)/4;
	insertionSort(arr, n);
	printArr(arr,n);
	return 0;
}
