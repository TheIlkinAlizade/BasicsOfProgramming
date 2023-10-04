#include <stdio.h>

int main(){
	int number, i, dividedtimes = 0;
	scanf("%d", &number);
	
	if(number <= 1){
		printf("Number must be positive and greater than 1 \n");
		return 1;
	}

	
	for(i = 1; i<number;i++){
		
		if(number%i == 0){
			dividedtimes++;
		}
	}
	
	(dividedtimes > 1) ? printf("Not Prime"): printf("Prime");
	
	
	return 0;
	
}
