#include <stdio.h>
#include <stdlib.h>


int main(){
	
	//left
	
	printf("Size of Array: ");
	int size, *arr;
	scanf("%d", &size);
	
	arr = malloc(sizeof(int)*size);
	if(arr==NULL) exit(0);
	
	for(int i = 0; i<size;i++){
		scanf("%d", &arr[i]);
	}
	printf("Slide to left for : ");
	int times;
	scanf("%d", &times);
	
	while(times>0){	
		int tmp;
		for(int k = 0; k<size;k++){
			if(k==0) tmp = arr[0]; 
			if(k != size - 1)arr[k] = arr[k+1];
			else arr[k] = tmp;
		}	
		times--;
	}

	for(int j = 0; j<size;j++){
		printf("Element %d \n", arr[j]);
	}
	
	//right
	
	printf("Slide to right for : ");
	times=0;
	scanf("%d", &times);
	
	while(times>0){	
		int tmpr;
		for(int k = size-1; k>0;k--){
			if(k==size-1) tmpr = arr[size-1]; 
			arr[k] = arr[k-1];
			if(k==1) arr[0] = tmpr;
		}	
		times--;
	}

	for(int j = 0; j<size;j++){
		printf("Element %d \n", arr[j]);
	}
}
