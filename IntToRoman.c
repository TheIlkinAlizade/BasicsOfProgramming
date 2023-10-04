#include <stdio.h>

void NumberToRoman(int number, char romanletters[]);

int main(){
	int number;
	scanf("%d", &number);
	
	char romanletters[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

	NumberToRoman(number, romanletters);

	
	
	return 0;
}

void NumberToRoman(int number, char romanletters[]){
	while(number!=0){
		if(number>=1000){
			printf("%c", romanletters[6]);
			number-=1000;
		}
		else if(number >= 900){
			printf("%c%c", romanletters[4], romanletters[6]);
			number-=900;
		}
		else if(number >= 500){
			printf("%c", romanletters[5]);
			number-=500;
		}
		else if(number >= 400){
			printf("%c%c", romanletters[4], romanletters[5]);
			number-=400;			
		}
		else if(number >= 100){
			printf("%c", romanletters[4]);
			number-=100;
		}
		else if(number >= 90){
			printf("%c%c", romanletters[2], romanletters[4]);
			number-=90;			
		}
		else if(number >= 50){
			printf("%c", romanletters[3]);
			number-=50;
		}
		else if(number >= 40){
			printf("%c%c", romanletters[2], romanletters[3]);
			number-=40;		
		}
		else if(number >= 10){
			printf("%c", romanletters[2]);
			number-=10;
		}
		else if(number >= 9){
			printf("%c%c", romanletters[0], romanletters[2]);
			number-=9;			
		}
		else if(number >= 5){
			printf("%c", romanletters[1]);
			number-=5;
		}
		else if(number >= 4){
			printf("%c%c", romanletters[0], romanletters[1]);
			number-=4;			
		}
		else if(number >=1){
			printf("%c", romanletters[0]);
			number-=1;
		}
		
	}
}
