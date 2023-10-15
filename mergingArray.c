#include <stdio.h>


int* main(){

	int array1[] = {1,3,5,7,9};
	int array2[] = {2,4,6,8,10};
	
	
	int m = sizeof(array1)/sizeof(array1[0]);
	int n = sizeof(array2)/sizeof(array2[0]);
	
	int FatArr[m+n];
	
	int i,j,k,isSorted = 0;
	
	for(i=0; i<m; i++){
		FatArr[i] = array1[i];
	}
	for(j=0; j<n;j++){
		FatArr[j+m] = array2[j];
	}

	for(i = 0; i < m+n; i++){
        int temp;
        for(j = i + 1; j < m+n; j++) {
            if(FatArr[i] > FatArr[j]) {
                temp = FatArr[i];
                FatArr[i] = FatArr[j];
                FatArr[j] = temp;
            }
        }
    }   
	
	for(i = 0; i<(m+n); i++){
		printf("\n %d ", FatArr[i]);
	}
	
	return 0;
}
