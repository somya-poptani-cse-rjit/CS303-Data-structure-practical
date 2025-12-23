#include <stdio.h>

// insertion sort function
void insertionSort(int arr[], int n){
    int key, j;
    for(int i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// display array
void display(int arr[], int n){
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// main function
int main(){
    int arr[] = {9, 5, 1, 4, 3};
    int n = 5;

    printf("Before Sorting: ");
    display(arr, n);

    insertionSort(arr, n);

    printf("After Insertion Sort: ");
    display(arr, n);

    return 0;
}
