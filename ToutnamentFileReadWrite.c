#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATA_SIZE 1000
#define DIR_SIZE 50

int CreateNewFile();
int CreateArray();
int AddToFile(char** array, int array_size);
int EditArray();

int main(){
	
	
	CreateArray();
	
	
	
	return 1;
}

int CreateNewFile(){
	
	char data[DATA_SIZE];
	
	FILE* fileptr;
	
	fileptr = fopen("data/filefortournament.txt", "w");
	
	if(fileptr == NULL){
		printf("Unable to create file \n");
		return 0;
	}
	
	printf("Enter content of File \n");
	fgets(data, DATA_SIZE, stdin);
	
	fputs(data, fileptr);
	fclose(fileptr);
	
	printf("File created and saved Succesfully \n");
}

int CreateArray(){
	char** competitors;
    int array_size, i;

    printf("Enter the number of competitors: ");
    scanf("%d", &array_size);

    // Allocate memory for an array of string pointers
    competitors = (char**)malloc(array_size * sizeof(char*));

    if (competitors == NULL) {
        printf("Memory not allocated\n");
        return 1;
    }

    printf("Memory allocated successfully with malloc()\n");

    // Read competitor names
    for (i = 0; i < array_size; i++) {
        
        printf("Enter the name for Competitor #%d: ", i + 1);
        
        char buffer[100];
        scanf("%s", buffer);
        
        competitors[i] = (char*)malloc(strlen(buffer) + 1); // Adjust the size as needed
        strcpy(competitors[i], buffer);
    }

    // Display competitor names
    for (i = 0; i < array_size; i++) {
        printf("Competitor #%d: %s\n", i + 1, competitors[i]);
    }
    
	AddToFile(competitors, array_size);

    // Free memory
    for (i = 0; i < array_size; i++) {
        free(competitors[i]);
    }
    free(competitors);
}

int AddToFile(char** array, int array_size){
	
	FILE* FileToAdd;
	FileToAdd = fopen("data/filefortournament.txt", "w");
	if(FileToAdd == NULL){
		printf("Unable to access to file \n");
		return 0;
	}
	int i;
	for(i = 0; i< array_size; i++){
		fprintf(FileToAdd, "%s \n", array[i]);
	}
	fclose(FileToAdd);
}

