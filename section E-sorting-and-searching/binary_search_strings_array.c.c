#include <stdio.h>
#include <string.h>

// binary search function for strings
int binarySearch(char arr[][20], int n, char key[]){
    int low = 0, high = n - 1, mid;
    while(low <= high){
        mid = (low + high) / 2;
        if(strcmp(arr[mid], key) == 0)
            return mid;
        else if(strcmp(arr[mid], key) < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// main function
int main(){
    char arr[][20] = {"apple", "banana", "grapes", "mango", "orange"};
    int n = 5;
    char key[20];
    int pos;

    printf("String Array:\n");
    for(int i = 0; i < n; i++)
        printf("%s ", arr[i]);

    printf("\nEnter string to search: ");
    scanf("%s", key);

    pos = binarySearch(arr, n, key);

    if(pos != -1)
        printf("String found at position %d\n", pos + 1);
    else
        printf("String not found\n");

    return 0;
}
