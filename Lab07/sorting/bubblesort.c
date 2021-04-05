#include <stdio.h>

#define SIZE 10

int main(void) {
    int arr[SIZE] = {26 , 34543 , 17 , 31 , 13 , 543 , 456 , 1, 0, 2};

    // bubble sort
    for(int i = 0; i < SIZE - 1; i++) {
        for(int j = 0; j < SIZE - i - 1 ; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for(int i = 0; i < SIZE; i++) {
        printf("%d\n", arr[i]);
    }
}