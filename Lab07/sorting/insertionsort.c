#include <stdio.h>

#define SIZE 10

int main(int argc, char const *argv[])
{
    int arr[SIZE] = {26 , 34543 , 17 , 31 , 13 , 543 , 456 , 1, 0, 2};

    // insertion sort
    int i, j;

    for(i = 1; i < SIZE; i++) {
        j = i;
        while(j > 0 && arr[j-1] > arr[j]) {
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }

    for(int i = 0; i < SIZE; i++) {
        printf("%d\n", arr[i]);
    }
    return 0;
}
