#include <stdio.h>

#define SIZE 10

void mergeSort(int [], int, int);
void merge(int [], int, int, int);

int main(int argc, char const *argv[])
{
    int arr[SIZE] = {26 , 34543 , 17 , 31 , 13 , 543 , 456 , 1, 0, 2};

    printf("Before sort\n");

    for(int i = 0; i < SIZE; i++) {
        printf("%d\n", arr[i]);
    }

    printf("After sort\n");
    mergeSort(arr, 0, SIZE-1);

    for(int i = 0; i < SIZE; i++) {
        printf("%d\n", arr[i]);
    }
    return 0;
}

void mergeSort(int data[], int left, int right) {
    if(left < right) {
        int mid = left + (right-left) / 2;
        mergeSort(data, left, mid);
        mergeSort(data, mid+1, right);
        merge(data, left, mid, right);
    }
}

void merge(int data[], int left, int mid, int right) {
    int i, j, k = 0;
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    int *leftArr = (int*) calloc(leftSize, sizeof(int));
    int *rightArr = (int*) calloc(rightSize, sizeof(int));

    for(i = 0; i < leftSize; i++) {
        leftArr[i] = data[left + i];        
    }
    for(j = 0; j < rightSize; j++) {
        rightArr[j] = data[mid + 1 + j];
    }

    i, j = 0; // left arr right arr indecies
    k = left; // merged arr

    while(i < leftSize && right < rightSize) {
        if(leftArr[i] <= rightArr[j]) {
            data[k] = leftArr[i];
            i++;
        } else {
            data[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while(i < leftSize) {
        data[k] = leftArr[i];
        i++;
        k++;
    }
    while(j < rightSize) {
        data[k] = rightArr[j];
        j++;
        k++; 
    }

    free(leftArr);
    free(rightArr);
}
