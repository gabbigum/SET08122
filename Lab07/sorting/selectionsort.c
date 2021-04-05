#include <stdio.h>

#define SIZE 10

int main(void) {
    int arr[SIZE] = {26 , 34543 , 17 , 31 , 13 , 543 , 456 , 1, 0, 2};

    // selection sort
    for(int i = 0; i < SIZE; i++) {
        int min = arr[i];
        for(int j = i+1; j < SIZE; j++) {
            if(min > arr[j]) {
                int temp = arr[j];
                arr[j] = min;
                min = temp;
            }
        }
        arr[i] = min;
    }

    for(int i = 0; i < SIZE; i++) {
        printf("%d\n", arr[i]);
    }
}