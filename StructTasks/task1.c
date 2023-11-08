#include <stdio.h>


struct Person{
	char *name;
	struct Date date;
};

struct Date{
	int Day;
	char *Month;
	int Year;
	//DDMMYYYY
};



int main(){
	
	struct Person person1;
	person1.name = "John";
	person1.date.Day = 20;
	person1.date.Month = "January";
	person1.date.Year = 2000;
	
	printf("%s", person1.name);
	
	return 0;
}
