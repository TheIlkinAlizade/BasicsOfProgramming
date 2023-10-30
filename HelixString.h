#include <stdio.h>
#include <string.h>

int helixStrlen(char array[]);
void helixStrcpy(char crack[], char original[]);
void helixStrcat(char arr1[], char arr2[]);
int helixStrcmp(char arr1[], char arr2[]);
char* helixStrchr(char str[], char chr);
int helixStrstr(char text[], char substring[]);
int helixStrtok(char text[], char delimeter);
int helixStrncpy(char crack[], char original[], int limit);
void helixStrncat(char arr1[], char arr2[], int n);
int helixStrncmp(char arr1[], char arr2[], int n);
int main(){
	
	/*
	char arr[13]="Baris Akarsu ";
	int len = helixStrlen(arr);
	char arr2[50];
	
	helixStrcpy(arr2, "Mavi mavi gozlerinde hep sitemmi var? ");
	helixStrcat(arr, arr2);
	printf("%d \n", helixStrcmp("geek","geeksasa"));
	printf("%d \n", strcmp("geek","geeksasa"));
	char *ret = helixStrchr("Sherlock Holmes", 'H');
	printf("%s \n", ret);
	int k = helixStrstr("My name is Eminem", "name");
	printf("%d found in this index", k);
	helixStrtok("my name is - Jeff", '-');

	printf("%d \n", helixStrncmp("abcdF","abcd", 5));
	printf("%d \n", strncmp("abcdF","abcd", 5));
	return helixStrstr("My name is Eminem", "Eminem");
	*/
	
	return 0;



}

int helixStrlen(char array[]){
	
	int i,len=0;
	i=sizeof(array)/sizeof(array[0]);
	
	while(i!=0){
		if(array[len]!= '\0'){
			len++;
		}
		else i=0;
	}
	
	return len;	
}
void helixStrcpy(char crack[], char original[]){
	int len = helixStrlen(original);
	
	int i=0;
	for(i;i<len;i++){
		crack[i] = original[i];
	}
	crack[i+1]='\0';
}
void helixStrcat(char arr1[], char arr2[]){
	
	int len1 = helixStrlen(arr1);
	int len2 = helixStrlen(arr2);
	
	//realloc(arr1, len1+len2);
	int i;
	for(i = 0; i<len2;i++){
		arr1[i+len1] = arr2[i];
	}

}
int helixStrcmp(char arr1[], char arr2[]){
	int i,max;
	int len1 = helixStrlen(arr1);
	int len2 =helixStrlen(arr2);
	max = (len1 > len2) ? len2 : len1;
	for(i=0;i<max;i++){
		
		if(arr1[i]!=arr2[i]){
			return arr1[i]-arr2[i];
		}
	}
	if(len1>len2){return 1;} else return -1;
}
char* helixStrchr(char str[], char chr){
	
	int i = 0;
	int len=helixStrlen(str);

	static char tmp[30];	
	
	for(i;i<len;i++){
		if(str[i] == chr){
			int j;
			for(j=0; j<len-i;j++){
				tmp[j] = str[j+i];
			}
			tmp[j+1] = '\0';
			break;
		}
	}
	
	char *found = tmp;
		
	return tmp;
	
}
int helixStrstr(char text[], char substring[]){
	
	int len = helixStrlen(text);
	int sublen = helixStrlen(substring);
	
	int check=0;
	
	for(int i=0; i<len;i++){
		if(text[i] == substring[0]){
			check = 1;
			for(int j=0; j<sublen; j++){
				if(text[i+j] != substring[j]){
					check=0;
					break;
				}
			}
			if(check == 1){
				return i;
			}
		}
	}
	return -1;
}

int helixStrtok(char text[], char delimeter){
	
	int len = helixStrlen(text);
	for(int i = 0;i<len;i++){
		if(text[i] != delimeter){
			printf("%c", text[i]);
		}
		else printf("\n");
	}
	
	return 1;
}
int helixStrncpy(char crack[], char original[], int limit){
	for(int i = 0;i<limit;i++){
		crack[i] = original[i];
	}
}
void helixStrncat(char arr1[], char arr2[], int n){
	int len1 = helixStrlen(arr1);
	
	for(int i = 0; i<n;i++){
		arr1[i+len1] = arr2[i];
	}
}
int helixStrncmp(char arr1[], char arr2[], int n){
	int len1 = helixStrlen(arr1);
	int len2 = helixStrlen(arr2);
	for(int i=0;i<n;i++){
		if(i>len1) return arr2[i];
		if(i>len2) return arr1[i];
		if(arr1[i]!=arr2[i]){
			return arr1[i]-arr2[i];
		}
	}
	if(len1=len2) return 0;
}
