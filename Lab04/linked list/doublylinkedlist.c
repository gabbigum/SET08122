#include <stdio.h>

int count(struct Node* list);
void display(struct Node* list);
void append(struct Node** list, int num);
void prepend(struct Node** list, int num);
void insertAfter(struct Node* list, int location, int num);
void delete(struct Node** list, int num);

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// there is a bug rewrite the whole thang
void delete(struct Node ** list, int num) {
    struct Node *iterator;
    iterator = *list;

    // if the head is to be removed
    if(iterator != NULL && iterator->data == num) {
        *list = iterator->next;
        (*list)->prev = NULL;
        free(iterator);
        return;
    }

    while(iterator != NULL) {
        if(iterator->data == num) {
            iterator->prev->next = iterator->next;
            if(iterator->prev->next != NULL) {
                iterator->next->prev = iterator->prev;
            }
            free(iterator);
            break;
        }
        iterator = iterator->next;
    }
    
}


void insertAfter(struct Node* list, int location, int num) {
    struct Node *iterator, *newNode, *temp;
    newNode = (struct Node *) malloc (sizeof(struct Node));
    
    newNode->data = num;
    newNode->next = NULL;
    newNode->prev = NULL;

    iterator = list;
    for(int i = 0; i < location; i++) {
        iterator = iterator->next;
        if(iterator == NULL) {
            printf("Location is out of bounds for that linked list.");
            return;
        }
    }

    temp = iterator->next;
    iterator->next = newNode;
    newNode->prev = iterator;
    newNode->next = temp;
}

void prepend(struct Node** list, int num) {
    struct Node *newNode, *oldHead;
    newNode = (struct Node*) malloc (sizeof(struct Node));
    newNode->data = num;
    newNode->prev = NULL;
    newNode->next = *list;

    (*list)->prev = newNode;
    *list = newNode;
}
void append(struct Node** list, int num) {
    struct Node *iterator, *newNode, *currentPrev;
    
    newNode = (struct Node *) malloc (sizeof(struct Node));
    newNode->data = num;
    newNode->next = NULL;
    newNode->prev = NULL; // for now

    if(*list == NULL) {
        *list = newNode;
    } else {
        iterator = *list;
        currentPrev = iterator;

        while(iterator->next != NULL) {
            currentPrev = iterator;
            iterator = iterator->next;
        }
        
        iterator->next = newNode;
        newNode->prev = currentPrev;
        iterator->prev = currentPrev;
    }

}

int count(struct Node* list) {
    int count = 0;
    while(list != NULL) {
        list = list->next;
        count++;
    }
    return count;
}

void display(struct Node* list) {
    while(list != NULL) {
        printf("%d\n", list->data);
        list = list->next;
    }
}


int main(int argc, char const *argv[])
{   
    struct Node *head;
    
    
    append(&head, 10);
    append(&head, 20);
    prepend(&head, 5);
    insertAfter(head, 1, 15);
    delete(&head, 20);
    display(head);
    return 0;
}
