#include <stdio.h>

int PrimeCheck(int number);
int makeNumber(int x);

int main(){
	//printf("%d", PrimeCheck(makeNumber(1)));
	int times=0;
	
	int a, b;
	scanf("%d %d", &a, &b);
	
	
	
	if((a>=1 && a<=10000) && (b>=1 && b<=10000));
	else return -1;
	
	if(a<b){
	for(int i = a; i<=b;i++){
		if(PrimeCheck(makeNumber(i)) == 1 && PrimeCheck(i)){
			times++;
		}
	}
	}
	else{
	for(int i = b; i<=a;i++){
		if(PrimeCheck(makeNumber(i)) == 1 && PrimeCheck(i)){
			times++;
		}
	}
	}
	

	
	printf("%d", times);
	
	return 0;
}

int PrimeCheck(int number){
	if(number <= 1) return 0;

	for(int i = 2; i<=number/2; i++){
		if(number%i == 0){
			return 0;
		}
	}
	return 1;
}

int makeNumber(int x){
	int y=0;
	while(x!=0){
		y = x%10 + y*10;
		x=x/10;
	}
	return y;
}
