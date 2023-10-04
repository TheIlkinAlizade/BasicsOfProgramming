#include <stdio.h>
#include <string.h>

//You can either use library or dont use library

void checkletter(char letter, char vowels[]);

int main(){
	char letter;
	printf("Please enter one character \n");
	scanf("%c", &letter);

	char vowels[] = {'A', 'E', 'I', 'O', 'U'};
	char consonants[] = {'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L','M', 'N', 'P', 'Q', 'R', 'S','T', 'V', 'W', 'X', 'Y', 'Z'};

	int i = 0;
	for(i; i < sizeof(vowels - 1); i++){
		if((letter - vowels[i] == 0) || ((letter - 32) - vowels[i]) == 0 ){
			printf("Vowel \n");
		}
	}
	i = 0;
	for(i; i < sizeof(consonants - 1); i++){
		if((letter - consonants[i] == 0) || ((letter - 32) - consonants[i]) == 0 ){
			printf("Consonant \n");
		}
	}
	
	checkletter(letter, vowels);

	return 1;
	
}

void checkletter(char letter, char vowels[]){
	

	if((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z') ){		
		if(strchr(vowels, letter) != NULL || strchr(vowels, letter-32) != NULL){
			printf("Vowel \n");
		}
		else{
			printf("Consonant \n");
		}
	}
	else{
		printf("Wrong Input \n");
	}
}
