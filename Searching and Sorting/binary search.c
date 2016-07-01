#include <stdio.h>
#include <stdlib.h>

int binSearch(int arr[],int num, int l,int r){
	
	int mid = l+(r-l)/2;
	
	if(num==arr[mid]){
		return mid+1;
	}
	
	else if(num<arr[mid]){
		return binSearch(arr,num, l, mid-1);
	}
	else if(num>arr[mid]){
		return binSearch(arr, num, mid+1, r);
	}
	else return -1;
}
	

int main(){
	int arr[] ={1,4,7,2,5,8,100,156};
	int num = 7;
	printf("%d is available at %d", num, binSearch(arr,num, 0, (sizeof(arr)/sizeof(arr[0]))-1));
	return 0;
}
