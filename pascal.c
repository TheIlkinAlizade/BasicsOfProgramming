#include <stdio.h>

void pascalline(int line);

int main(){
	int line;
	scanf("%d", &line);
	
	pascalline(line);
	
	return 0;
	
}


void pascalline(int line){
	int column;
	for(column = 1; column<=line;column++){
		int C =1;
		int row;
		for(row=1;row<=column;row++){
			printf("%d ", C);
			C = C*(column-row)/row;
		}
		printf("\n");
	}
	
}
