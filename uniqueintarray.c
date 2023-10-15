#include <stdio.h>


int* main(){
	
	int array[] = {1,2,2,9,3,4,5,5,6,7,8,9,6,9};
	
	int len = sizeof(array)/sizeof(array[0]);
	int i, j, k, isUnique, foundSame = 0;
	
	
	while(isUnique!=1){
		
		for(i=0; i<len; i++){
			for(j=0; j<i;j++){
				if(array[j] == array[i]){
					printf("%d and %d are duplicate items\n", array[j], array[i]);
					
					//delete that item
					
					for(k=j; k<len; k++){
						array[k] = array[k+1];
					}
					len--;
					
					foundSame=1;
					isUnique = 0;
					break;
				}
				else{
					foundSame = 0;
				}
			}
			if(foundSame == 0){
				isUnique = 1;
			}
		}
		
		
	}
	
	
	for(j=0; j<len; j++){
		printf("%d ", array[j]);	
	}

	
	
	return 0;
}

