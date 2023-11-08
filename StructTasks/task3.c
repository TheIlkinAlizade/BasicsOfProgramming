#include <stdio.h>
#include <string.h>

struct Course{
	char *course_name;
	int course_code;
};

struct Student{
	char* name;
	int ID;
	struct Course course;
};


int main(){
	
	struct Student Students[5];
	
	for(int i = 0; i < 5; i++){
 		Students[i].name = "John";
		Students[i].ID = i + 1;
		Students[i].course.course_name = "Business";
		Students[i].course.course_code = 1011;	
		
		printf("Name %s \n", 	Students[i].name);
		printf("ID %d \n", 	Students[i].ID);
		printf("C code %d \n", 	Students[i].course.course_code);
		printf("C name %s \n", 	Students[i].course.course_name);
		
		printf("----------\n");	
	}

	
	
	
	
	

	
	
	
	return 0;
}
