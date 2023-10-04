#include <stdio.h>

int main(){
	
	int a, numbers = 0;
	scanf("%d", &a);
	if(a==0){
		numbers++;
	}

	while(a>0){
		a = a/10;
		numbers++;
	}
	printf("%d", numbers);		

}
