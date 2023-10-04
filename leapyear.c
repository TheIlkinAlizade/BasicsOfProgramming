#include <stdio.h>

int main(){
	int year = 0;
	printf("Year : ");
	scanf("%d", &year);
	
	if(year <= 0){
		printf("Number must be natural \n");
		return 1;
	}

	if(year%400 == 0){
		printf("leap year");
	}
	else if(year%100 == 0 && year%400 !=0){
		printf("not leap year");
	}
	else if(year%4 == 0){
		printf("leap year");
	}
	else{
		printf("not leap year");
	}
	
	
	return 0;
}

