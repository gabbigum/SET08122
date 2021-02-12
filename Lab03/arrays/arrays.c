#include <stdio.h>

#define MAX 5
#define RESIZE_MULTIPLIER 2

void display(int*);
void init(int*);
void insert(int*, int, int);
void update(int*, int, int);
void delete(int*, int);
void reverse(int*);
void search(int*, int);
int* resize(int*);

int main(int argc, char const *argv[])
{
    int array[MAX];
    
    init(array);
    
    insert(array, 1, 11);
    insert(array, 2, 12);
    insert(array, 3, 13);
    insert(array, 4, 14);
    insert(array, 5, 15);
    
    printf("Printing array contents \n");
    //display(array);

    insert(array, 5, 25);
    display(array);
    
    printf("Deleting...\n");
    delete(array, 2);
    display(array);

    printf("Reversing...\n");
    reverse(array);
    display(array);

    search(array, 15);
    
    int* resizedArray = resize(array);
    printf("Size of non resized array %d\n", sizeof(array));
    printf("Size of resized array: %d\n" ,sizeof(resizedArray));

    for(int i = 0; i < MAX*RESIZE_MULTIPLIER; i++) {
        printf("Resized array idx %d value %d\n", i, resizedArray[i]);
    }
    
    return 0;
}

int* resize(int* array) {
    int* newArray[MAX*RESIZE_MULTIPLIER];
    int i;
    
    for(i = 0; i < MAX; i++) {
        newArray[i] = array[i];
        printf("new array: %d\n", newArray[i]);
    }

    for(; i < MAX*RESIZE_MULTIPLIER; i++) {
        newArray[i] = 0;
        printf("new array: %d\n", newArray[i]);
    }
    return newArray;
}

void search(int* array, int value) {
    for(int i = 0; i < MAX; i++) {
        if(array[i] == value) {
            printf("Value %d found at position %d.\n", value, i);
            return;
        }
    }
    printf("Value %d not found in the array.\n", value);
}

//O(n) memory and runtime
void reverse(int* array) {
    for(int i = 0; i < MAX/2; i++) {
        int temp = array[i];
        array[i] = array[MAX-i-1];
        array[MAX-i-1] = temp;
    }
}

void delete(int* array, int pos) {
    // [1,2,3,4,5] if pos is 3 == (index==2)
    // [1,2,4,5,0];
    int i;
    for(i = pos; i < MAX; i++) {
        array[i-1] = array[i];
    }
    array[i-1] = 0;
}

void update(int * array, int pos, int number) {
    for(int i = 0; i < MAX; i++) {
        if(i == (pos-1)) {
            array[i] = number;
            break;
        }
    }
}

void insert(int* array, int pos, int number) {
    for(int i = MAX-1; i >= pos; i--) {
        array[i] = array[i-1];
    }
    array[pos-1] = number; 
}

void display(int* array) {
    
    for(int i = 0; i < MAX; i++) {
        printf("index=%d value=%d\n",i ,array[i]);
    }
}

void init(int* array) {
    for(int i = 0; i < MAX; i++) {
        array[i] = i;
    }
}



