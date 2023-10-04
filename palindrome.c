#include <stdio.h>
#include <string.h>

int main(){
	char text[2];
	scanf("%s", &text);
	
	int len = strlen(text);
	
	int i = 0;
	
	for(i; i<len;i++){
		if(text[i] != text[len-1]){
			printf("Not a palindrome \n");
			return 0;
		}
		len--;
	}
	
	printf("Palindrome");
	
	
	return 1;
	
}
