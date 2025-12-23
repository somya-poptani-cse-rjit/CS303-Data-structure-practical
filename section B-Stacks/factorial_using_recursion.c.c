#include <stdio.h>

// recursive function
int fact(int n){
    if(n == 0)
        return 1;
    return n * fact(n - 1);
}

// main function
int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Factorial of %d is %d\n", n, fact(n));
    return 0;
}
