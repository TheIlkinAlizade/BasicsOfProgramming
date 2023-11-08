#include <stdio.h>


struct Address{
	char *street;
	char *city;
	int postal_code;
};

struct Contact{
	char* name;
	struct Address address;
};


int main(){
	
	struct Contact Person1;
	Person1.name = "John";
	Person1.address.street = "Wolf Street";
	Person1.address.city = "New York";
	Person1.address.postal_code = 1001;
	
	printf("Street %s \n", 	Person1.address.street);
	printf("City %s \n", 	Person1.address.city);
	printf("Postal %d \n", 	Person1.address.postal_code);
	printf("Name %s \n", 	Person1.name);
	
	return 0;
}
