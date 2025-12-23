#include <stdio.h>
#include <string.h>

// linear search function for strings
int linearSearch(char arr[][20], int n, char key[]){
    for(int i = 0; i < n; i++){
        if(strcmp(arr[i], key) == 0)
            return i;
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

    pos = linearSearch(arr, n, key);

    if(pos != -1)
        printf("String found at position %d\n", pos + 1);
    else
        printf("String not found\n");

    return 0;
}
