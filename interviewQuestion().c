#include <stdio.h>

int CheckExist(char array[], char x);

int main() {
    char array[20];
    scanf("%s", &array);
    int len = strlen(array);
    int balance,M,same = 0;
    char starters[] = {'[','{','('};
    char enders[] = {']','}',')'};

    
    for(int i = 0; i<len; i++){
        if(CheckExist(starters, array[i])==1) balance++;
        if(CheckExist(enders, array[i])==1) balance--;
        if(CheckExist(starters, array[i])==1 && CheckExist(enders, array[i+1])==1){
            //printf("Melting Point %d  \n", i);
            for(int j=0; j<=i;j++){
                if(array[(M-j)]-array[(M+j+1)] == -2 || array[(M-j)]-array[(M+j+1)] ==-1){
                    same=1;
                    //printf("same %d M %d \n", same, M);
                    break;
                }else same = 0;
            }
            
        }
        M++;
    }
    if(same==1 && balance==0) printf("ORDER has been established succesfully \n");
    else printf("ORDER has not been established succesfully \n");

    return 0;
}

int CheckExist(char arr[], char x){
    
    for(int i = 0; i < 3; i++){
        if(arr[i]==x){
            return 1;
        }
    }
    return 0;
}

//todo
/*
take array
use starters and enders
scan and check array
use balance variable to check your alghorithm
Stay strong
*/
