#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATA_SIZE 1000
#define DIR_SIZE 50

struct Competitor{
	char name[50];
	int score;
};

int CreateNewFile();
int CreateArray();
int AddToFile(struct Competitor* array, int array_size);
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
	struct Competitor* competitors;
    int array_size, i;

    printf("Enter the number of competitors: ");
    scanf("%d", &array_size);

    // Allocate memory for an array of string pointers
    competitors = (struct Competitor*)malloc(array_size * sizeof(struct Competitor));

    if (competitors == NULL) {
        printf("Memory not allocated\n");
        return 1;
    }

    printf("Memory allocated successfully with malloc()\n");

    // Read competitor names
    char buffer[100];
    for (i = 0; i < array_size; i++) {
        printf("Enter the name for Competitor #%d: ", i + 1);
        scanf("%s", buffer);
        strcpy(competitors[i].name, buffer);

        printf("Enter the score for Competitor #%d: ", i + 1);
        scanf("%d", &competitors[i].score);
    }

    // Display competitor names
    for (i = 0; i < array_size; i++) {
        printf("Competitor #%d: Name = %s, Score = %d\n", i + 1, competitors[i].name, competitors[i].score);
    }
    
    AddToFile(competitors, array_size);
    
    

    // Free memory
    free(competitors);
}

int AddToFile(struct Competitor* array, int array_size){
	
	FILE* FileToAdd;
	FileToAdd = fopen("data/filefortournament2.txt", "a");
	if(FileToAdd == NULL){
		printf("Unable to access to file \n");
		return 0;
	}
	int i;
	for(i = 0; i< array_size; i++){
		fprintf(FileToAdd, "Competitor %s : %d score \n", array[i].name, array[i].score);
	}
	fclose(FileToAdd);
}

