#include <stdio.h>

// binary search function
int binarySearch(int arr[], int n, int key){
    int low = 0, high = n - 1, mid;
    while(low <= high){
        mid = (low + high) / 2;
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// main function
int main(){
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5, key, pos;

    printf("Array elements: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nEnter element to search: ");
    scanf("%d", &key);

    pos = binarySearch(arr, n, key);

    if(pos != -1)
        printf("Element found at position %d\n", pos + 1);
    else
        printf("Element not found\n");

    return 0;
}
