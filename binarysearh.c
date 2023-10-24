// Online C compiler to run C program online
#include <stdio.h>


int binarySearch(int arr[], int S, int E, int x);

int main() {

    int arr[7] = {1,2,3,6,7,8,19};
    int len = sizeof(arr)/sizeof(arr[0]);
    int x;
    printf("Search: ");
    scanf("%d", &x);
    
    if(binarySearch(arr, 0, len-1, x) == -1){
        printf("Not Found \n");
    }

    return 0;
}

//S start E end, check between this range 
int binarySearch(int arr[], int S, int E, int x){
    if(S>E) return -1;
    
    int mid = S+(E-S)/2;
    if(x==arr[mid]){
        printf("Found \n");
        return 1;
    }
    else if(x>mid) binarySearch(arr, mid+1, E,x);
    else binarySearch(arr, S, mid-1,x);
    
}
