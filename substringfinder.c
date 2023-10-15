#include <stdio.h>

int main(){
	
	char text[] = "with great powers, comes great responsibility";
	char substring[5] = "great";
	
	printf("%s is text \n", text);
	printf("%s is substring to find \n", substring);
	
	int len = sizeof(text)/sizeof(text[0]);
	int sublen = sizeof(substring)/sizeof(substring[0]);
	
	int i,j;
	int check=0;
	
	for(i=0; i<len;i++){
		if(text[i] == substring[0]){
			check = 1;
			for(j=0; j<sublen; j++){
				if(text[i+j] != substring[j]){
					check=0;
					break;
				}
			}
			if(check == 1){
				printf("SubString found in %i \n", i);
				check =0;
			}
		}
		
	}
	

	
	
	return 0;
}
