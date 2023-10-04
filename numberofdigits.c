#include <stdio.h>

int numberofdigits(int number, int digits);

int main(){
	int a, digits = 0;
	printf("Please enter number: ");
	scanf("%d", &a);
	if(a==0){
		digits++;
		printf("%d", digits);
		return 0;
	}
	
	
	digits = numberofdigits(a, digits);
	printf("%d", digits);
	
	return 1;
	
}

int numberofdigits(int number, int digits){
	++digits;
	if(number/10 > 0){
		numberofdigits(number/10, digits);
	}
	else{
		return digits;
	}
	
}
