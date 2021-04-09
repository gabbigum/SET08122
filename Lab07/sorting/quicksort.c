#include <stdio.h>

#define SIZE 10

int partition(int [], int, int);
int quickSort(int[], int, int);

int main(int argc, char const *argv[])
{
    /* code */
    int arr[SIZE] = {26 , 34543 , 17 , 31 , 13 , 543 , 456 , 1, 0, 2};

    printf("Before sort\n");

    for(int i = 0; i < SIZE; i++) {
        printf("%d\n", arr[i]);
    }

    printf("After sort\n");
    quickSort(arr, 0, SIZE-1);

    for(int i = 0; i < SIZE; i++) {
        printf("%d\n", arr[i]);
    }
    return 0;
}

int quickSort(int data[], int left, int right) {
    int pivot;
    if(left < right) {
        pivot = partition(data, left, right);
        quickSort(data, left, pivot - 1);
        quickSort(data, pivot + 1, right);
    }
}

int partition(int data[], int left, int right) {
    int pivot = data[right];
    int pIndex = left;
    int temp;

    for(int i = left; i < right; i++) {
        if(data[i] <= pivot) {
            // swap
            temp = data[pIndex];
            data[pIndex] = data[i];
            data[i] = temp; 
            pIndex++;
        }
    }

    temp = data[pIndex];
    data[pIndex] = data[right];
    data[right] = temp;

    return pIndex;
}
