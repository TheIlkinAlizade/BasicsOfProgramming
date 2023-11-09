#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATA_SIZE 1000
#define DIR_SIZE 50

struct Student{
	char name[50];
	int id;
};
struct StudentInfo{
	int id;
	int age;
	int score;
};

int CreateStudentsFile();
int CreateStudents();
int AddToFile(struct Student* array, int array_size);
int EditFile(); //undone
int GetFile(); 
int GetStudentInfo(); 

#define selected 20
char tmpSelected[selected];

char* Selector(char* word, char lastelement, char* full);

int main(){	

	printf("Welcome To Student Application version 1.0 \n");
	
	int key=1;
	while(key==1){
		printf("What Function Would you like to use? \n");
		printf("Create new Student File(1) \nGet Student File(2) \nEdit Student File(3) \nGetStudent Info(4) \nQuit Application(5) \n");
		int operation;
		scanf("%d", &operation);
		
		switch(operation){
			case 1:
				CreateStudents();
				break;
			case 2:
				GetFile();
				break;
			case 3:
				EditFile();
				break;
			case 4:
				GetStudentInfo();
				break;
			default:
				key = 0;
				break;
		}
	}
	
	printf("\n Application Quit \n");
		
	return 1;
}

int CreateStudentsFile(){
	
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

int CreateStudents(){
	struct Student* Students;
    int array_size;

    printf("Enter the number of Students: ");
    scanf("%d", &array_size);

    // Allocate memory for an array of string pointers
    Students = (struct Student*)malloc(array_size * sizeof(struct Student));

    if (Students == NULL) {
        printf("Memory not allocated\n");
        return 1;
    }

    printf("Memory allocated successfully with malloc()\n");

    // Read Student names
    char buffer[100];
    for (int i = 0; i < array_size; i++) {
        printf("Enter the name for Student #%d: ", i + 1);
        scanf("%s", buffer);
        strcpy(Students[i].name, buffer);

        printf("Enter the id for Student #%d: ", i + 1);
        scanf("%d", &Students[i].id);
    }

    // Display Student names
    for (int i = 0; i < array_size; i++) {
        printf("Student #%d: Name = %s, id = %d\n", i + 1, Students[i].name, Students[i].id);
    }
    
    AddToFile(Students, array_size);

    // Free memory
    free(Students);
}

int AddToFile(struct Student* array, int array_size){
	
	FILE* FileToAdd;
	
	char filepath[DIR_SIZE];
	printf("Please, Enter Filepath : ");
	scanf("%s", filepath);
	
	FileToAdd = fopen(filepath, "a");
	if(FileToAdd == NULL){
		printf("Unable to access to file \n");
		return 0;
	}
	for(int i = 0; i< array_size; i++){
		fprintf(FileToAdd, "Student : %s, ID : %d \n", array[i].name, array[i].id);
	}
	fclose(FileToAdd);
}
int GetFile(){
	char filepath[DIR_SIZE];
	printf("Please, Enter Filepath : ");
	scanf("%s", filepath);

	FILE* File;
	File = fopen(filepath, "r");

	if(File == NULL){
		printf("Unable to access to file \n");
		return 0;
	}
	
	char buffer[100];
	//fread(buffer, 5, File);
	while(fgets(buffer, 100, File)) {
 		printf("%s \n", buffer);
	}
	
	fclose(File);
	
	return 1;
}

char* Selector(char* word, char lastelement, char* full){
	int len = strlen(full);
	int indexofLCOW = 0;
	int len_word = strlen(word);
	

	
	for(int i = 0; i < len; i++){
		if(full[i]==word[0] && indexofLCOW == 0){
			for(int j = 0; j < len_word; j++){
				if(full[j+i] != word[j]){
					indexofLCOW=0;	
					if(j != len_word-1) break;	
				}
				else indexofLCOW=i+j+1;
			}
		}
	}

	for(int i = indexofLCOW; i < len; i++){
		if(full[i] != lastelement){
			tmpSelected[i-indexofLCOW] = full[i];	
		}
		else break;
	}
	return tmpSelected;
}
int GetStudentInfo(){
	
	char filepath[DIR_SIZE];
	printf("Please, Enter Filepath : ");
	scanf("%s", filepath);
	
	char name[DIR_SIZE];
	printf("Please, Enter Student name : ");
	scanf("%s", name);
	
	int id;
	printf("Please, Enter ID : ");
	scanf("%d", &id);
	
	FILE* File;
	File = fopen(filepath, "r");
	
	if(File == NULL){
		printf("Unable to access to file \n");
		return 0;
	}
	
	char buffer[100];
	while(fgets(buffer, 100, File) != NULL) {
		if(atoi(Selector("ID : ", '\0', buffer)) == id && strncmp(Selector("Student : ", ',', buffer), name, strlen(name)) == 0){
			printf("STUDENT FOUND! \n");
			printf("%s \n", buffer);
			return 1;
		}
	}
	
	printf("STUDENT NOT FOUND, PLEASE GIVE VALID ID OR NAME \n");
	
	fclose(File);
	return -1;
}

int EditFile(){
	
	char filepath[DIR_SIZE];
	printf("Please, Enter Filepath of File You want to Edit : ");
	scanf("%s", filepath);
	
	char name[DIR_SIZE];
	printf("Please, Enter Student name : ");
	scanf("%s", name);
	
	int id;
	printf("Please, Enter ID : ");
	scanf("%d", &id);
	
	FILE* File;
	File = fopen(filepath, "r");
	FILE* FileTMP = fopen("replace.txt", "w");
	
	if(File == NULL || FileTMP == NULL){
		printf("Unable to access to file \n");
		return 0;
	}
	
	int done=0;
	char buffer[100];
	while(fgets(buffer, 100, File) != NULL) {
		if(atoi(Selector("ID : ", '\0', buffer)) == id && strncmp(Selector("Student : ", ',', buffer), name, strlen(name)) == 0){
			printf("Name : %s, ID : %d \n", Selector("Student : ", ',', buffer), id);
			printf("---Please Enter new Info---\n");
			struct Student student;
			char tmpName[50];
			printf("Enter Name : ");
			scanf("%s", tmpName);
			strcpy(student.name, tmpName);
			printf("Enter ID : ");
			scanf("%d", &student.id);
			
			char TMPnewline[] = "Student : %s, ID : %d \n";
			char newline[100];
			sprintf(newline, TMPnewline, student.name, student.id);
			printf("New Info, %s \n", newline);
			fputs(newline, FileTMP);
			done = 1;
			break;
		}
		else{
			fputs(buffer, FileTMP);
		}
	}
	fclose(File);
	fclose(FileTMP);	
	if(done==1){
		remove(filepath);
		rename("replace.txt", filepath);
		printf("\n---Successfully replaced Info---\n \n");	
	}else 		printf("\n---Something went wrong. Please Enter Valid Informations---\n \n");	
	
	return 1;	
}
