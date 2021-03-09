#include <stdio.h>

int count(struct node* list);
void display(struct node* list);
void append(struct node** list, int num);
void prepend(struct node** list, int num);
void insertAfter(struct node* list, int location, int num);
void delete(struct node** list, int num);

struct node {
    int data;
    struct node *next;
};

void delete(struct node ** list, int num) {
    struct node *temp, *prev;
    temp = *list;

    printf("Head of list %d\n", temp->data);

    if(temp != NULL && temp->data == num) {
        *list = temp->next;
        free(temp);
        return;
    }
    
    while(temp != NULL && temp->data != num) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        return;
    }
    printf("Element to be deleted %d\n", temp->data);
    prev->next = temp->next;
    free(temp);
}

void insertAfter(struct node * list, int location, int num) {
    struct node *iterator, *r;
    int i;
    iterator = list;
    for(int i = 0; i < location; i++) {
        iterator = iterator->next;
        if(iterator == NULL) {
            printf("Location = %d is out of bounds for the list = %d.\n", location, i);
            return;
        }
    }
    r = (struct node *) malloc (sizeof(struct node));
    r->data = num;
    r->next = iterator->next;
    iterator->next = r;
}

void prepend(struct node** list, int num) {
    struct node *iterator;
    iterator = (struct node*) malloc(sizeof(struct node));
    iterator->data = num;
    iterator->next = *list;
    *list = iterator;
}

void append(struct node** list, int num) {
    struct node *iterator, *newNode;
    
    if(*list == NULL) {
        iterator = (struct node *) malloc (sizeof(struct node));
        iterator->data = num;
        iterator->next = NULL;
        *list = iterator;
    } else {
        iterator = *list;
        while(iterator->next != NULL) {
            iterator = iterator->next;
        }
        newNode = (struct node *) malloc(sizeof(struct node));
        newNode->data = num;
        newNode->next = NULL;
        iterator->next = newNode;
    }
}

void display(struct node* list) {
    while(list != NULL) {
        printf("%d\n", list->data);
        list = list->next;
    }
}

int count(struct node* list) {
    int count = 0;
    while(list != NULL) {
        list = list->next;
        count++;
    }
    return count;
}

int main(int argc, char const *argv[])
{
    struct node * list ;
    list = NULL;

    append(&list, 14);
    append(&list, 13);
    append(&list, 15);
    prepend(&list, 10);
    insertAfter(list, 2, 20);
    delete(&list, 15);
    display(list);

    return 0;
}
