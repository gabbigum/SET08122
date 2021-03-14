#include <stdio.h>
#include <stdbool.h>

#define SIZE 50

bool binarySearch(int arr[], int number) {
    if(number > SIZE) {
        return false;
    }
    int left = 0, right = SIZE;
    int mid = (right+left) / 2;

    while(left <= right) {
        if(number > arr[mid]) {
            left = mid;
            mid = (right+left) / 2;
        } else if(number < arr[mid]) {
            right = mid;
            mid = (right+left) /2;
        } else {
            return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int arr[SIZE];
    int number = 3;

    for(int i = 0; i < SIZE; i++) {
        arr[i] = i + 1;
    }

    bool numExist = binarySearch(arr, number);
    if(numExist == true) {
        printf("numExist");
    } else {
        printf("Num doesnt exist");
    }
    
    return 0;
}
