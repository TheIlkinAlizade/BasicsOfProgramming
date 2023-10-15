#include <stdio.h>


int* main(){

	int arrayOfScores[] = {100,100,100,90,100};
	
	int len = sizeof(arrayOfScores)/sizeof(arrayOfScores[0]);
	int i;
	float avarage;
	
	for(i = 0; i<len; i++){
		printf("%d ",  arrayOfScores[i]);
		avarage += arrayOfScores[i];
	}
	
	avarage = avarage/len;
	
	printf("\nYour avarage score is %.2f ", avarage);



	return 0;
}
