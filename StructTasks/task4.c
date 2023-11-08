#include <stdio.h>
#include <string.h>

struct Manufacturer{
	char *name;
	char *location;
};

struct Product{
	char *name;
	int price;
	struct Manufacturer manufacturer;
};


int main(){
	
		struct Product Windows;
	
 		Windows.name = "Windows 11";
		Windows.price = 200;
		Windows.manufacturer.name = "Bill";
		Windows.manufacturer.location = "America";	
		
		printf("Product name %s \n", 	Windows.name);
		printf("Price %d \n", 	Windows.price);
		printf("Manufacturer %d \n", 	Windows.manufacturer.name);
		printf("Location  %s \n", 	Windows.manufacturer.location);
		
		printf("----------\n");	

	
	
	
	
	

	
	
	
	return 0;
}
