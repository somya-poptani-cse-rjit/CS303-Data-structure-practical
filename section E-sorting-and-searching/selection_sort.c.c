#include <stdio.h>

// selection sort function
void selectionSort(int arr[], int n){
    int min, temp;
    for(int i = 0; i < n - 1; i++){
        min = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[min])
                min = j;
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
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
    int arr[] = {64, 25, 12, 22, 11};
    int n = 5;

    printf("Before Sorting: ");
    display(arr, n);

    selectionSort(arr, n);

    printf("After Selection Sort: ");
    display(arr, n);

    return 0;
}
