#include <stdio.h>

#define SIZE 10
// insert
// search
// delete

struct DataItem {
    int key;
    int data;
};

struct DataItem* hashArray[SIZE];
struct DataItem* tempItem;
struct DataItem* item;

void display(void);
int hashCode(int);
void insert(int, int);
struct DataItem* search(int key);
struct DataItem* delete(struct DataItem* item);

struct DataItem* delete(struct DataItem* item) {
    int key = item->key;
    int hashIndex = hashCode(key);

    while(hashArray[hashIndex] != NULL) {
        if(hashArray[hashIndex]->key == key) {
            struct DataItem *temp = hashArray[hashIndex];
            hashArray[hashIndex] = NULL;
            return temp;
        }

        hashIndex++;
        hashIndex %= SIZE;
    }
    return NULL;
}

struct DataItem* search(int key) {
    int hashIndex = hashCode(key);
    
    while(hashArray[hashIndex] != NULL) {
        if(hashArray[hashIndex]->key == key) {
            return hashArray[hashIndex];
        }
        hashIndex++;
        hashIndex %= SIZE;
    }

    return NULL;
}

void insert(int key, int data) {
    struct DataItem *item = (struct DataItem*) malloc (sizeof(struct DataItem));
    item->key = key;
    item->data = data;

    int hashIndex = hashCode(key);
    while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
        hashIndex++;
        hashIndex %= SIZE;
    }
    hashArray[hashIndex] = item;
}


void display(void) {
    for(int i = 0; i < SIZE; i++) {
        
        if(hashArray[i] != NULL) {
            printf("%d,%d\n", hashArray[i]->key, hashArray[i]->data);
        } else {
            printf(" ~,~ \n");
        }
        printf("\n");
    }
}

int hashCode(int key) {
    return key % SIZE;
}

int main(int argc, char const *argv[])
{
    tempItem = (struct DataItem*) malloc(sizeof(struct DataItem));
    tempItem->data = -1;
    tempItem->key = -1;

    insert(1, 20);
    insert(2, 70);
    insert(42, 80);
    insert(4, 25);
    insert(3, 44);
    insert(10, 10);

    display();
    return 0;
}
