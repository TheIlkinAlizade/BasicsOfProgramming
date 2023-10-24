// Online C compiler to run C program online
#include <stdio.h>


int bubblesort(int arr[], int len);
int binarySearch(int arr[], int S, int E, int x);

int main() {

    int arr[7] = {1,22,3,116,199,18,29};
    int len = sizeof(arr)/sizeof(arr[0]);
    int x;
    printf("Search: ");
    scanf("%d", &x);
    
    bubblesort(arr, len);
    binarySearch(arr, 0, len-1, x);

    return 0;
}

int bubblesort(int arr[], int len){
    int i,j,temp;
    for(i = 0; i<len; i++){
        for(j = 0; j<len; j++){
            if(arr[i] < arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


//S start E end, check between this range 
int binarySearch(int arr[], int S, int E, int x){
    if(S>E) {
        printf("Not Found");
        return -1;
    }
    
    int mid = S+(E-S)/2;
    if(x==arr[mid]){
        printf("Found \n");
        return 1;
    }
    else if(x>mid) binarySearch(arr, mid+1, E,x);
    else binarySearch(arr, S, mid-1,x);
    
}
