#include <stdio.h>

int primecheck(int number);

int main(){
	
	int i, prev, current, next = 0;	
	current = 1;
	
	while(next>=0){
		if(primecheck(current) == 1){
			printf("Prime \n");
		}
		else if(current%5 == 0){
			printf("Buzz \n");
		}
		else{
			printf("%d \n", current);
		}
		next = prev + current;
		prev = current;
		current = next;
	}
	

	
	
	return 0;
	
}

int primecheck(int number){
	int dividedtimes, i = 0;
	for(i = 1; i<number;i++){
		
		if(number%i == 0){
			dividedtimes++;
		}
	}
	
	if(dividedtimes > 1) return 0; return 1;
}
