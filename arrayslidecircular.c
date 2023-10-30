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
		arr[size] = arr[0];
		for(int k = 0; k<size;k++){
	    	arr[k] = arr[k+1];

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
		arr[-1] = arr[size-1];
		for(int k = size-1; k>=0;k--){
			arr[k] = arr[k-1];
		}	
		times--;
	}

	for(int j = 0; j<size;j++){
		printf("Element %d \n", arr[j]);
	}
	
	
	
}
