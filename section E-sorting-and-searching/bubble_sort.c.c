#include <stdio.h>

// bubble sort function
void bubbleSort(int arr[], int n){
    int temp;
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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
    int arr[] = {5, 3, 8, 4, 2};
    int n = 5;

    printf("Before Sorting: ");
    display(arr, n);

    bubbleSort(arr, n);

    printf("After Bubble Sort: ");
    display(arr, n);

    return 0;
}
