#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define SIZE 100

bool jumpSearch(int arr[], int number) {
    int jump = floor(sqrt(number));
    int index = 0;

    while(index < SIZE) {
        if(arr[index] == number) {
            return true;
        }
        if(arr[index] > number) {
            index -= jump;
            for(int i = index; i < SIZE /* for now*/; i++) {
                if(arr[i] == number) {
                    return true;
                }
            }
        } else {
            index += jump;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int arr[SIZE];
    int number = 15;

    for(int i = 0; i < SIZE; i++) {
        arr[i] = i + 1;
    }

    bool numExist = jumpSearch(arr, number);
    if(numExist == true) {
        printf("numExist");
    } else {
        printf("Num doesnt exist");
    }
    
    return 0;
}
