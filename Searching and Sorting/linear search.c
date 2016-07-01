#include <stdio.h>
#include <stdlib.h>

int search(int arr[], int num, int size){
	for(int i=0; i<=size; i++){
		if(arr[i]==num){
			return i+1;
		}
	}
	return -1;
}

int main(){
	int arr[]={0,1,2,3,4,5,6};
	int num;
	scanf("%d",&num);
	int size=sizeof(arr)/sizeof(arr[0]);
	
	printf("%d is present at %d",num,search(arr, num, size));
	return 0;
}
