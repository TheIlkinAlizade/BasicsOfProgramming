#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Employee;

struct Employee{
	char *name;
	int ID;
	struct Employee *employees;
	//int *a;
};


int main(){
	
	struct Employee employee;
	
 	employee.name = "John";
	employee.ID = 1;
	
	printf("II am working \n");
	
	for(int i=0; i<5;i++){
		printf("I am working \n");
		employee.employees[i].name = "Doe";
		employee.employees[i].ID = 100+i;
		printf("I am working \n");
	}
	printf("II am working \n");
		
	printf("Main Employee name %s \n", 	employee.name);
	printf("Employee 0 %s \n", 	employee.employees[0].name);
	printf("----------\n");	

	
	//codeblox
	return 0;
}
