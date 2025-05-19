#include <stdio.h>

int main() {
    int arr[3] = {1, 2, 3};
    
    arr[3] = 10;
    printf("arr[0] = %d\n", arr[0]);
    
    return 0;
}