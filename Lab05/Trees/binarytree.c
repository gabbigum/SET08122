#include <stdio.h>

struct Node* insert(struct Node*, int);
void inorder(struct Node*);
void search(struct Node*, int);
struct Node* minValueNode(struct Node*);
struct Node* delete(struct Node*, int);
struct Node* newNode(int);
struct Node* minValueNode(struct Node*);

struct Node {
    struct Node *leftChild;
    struct Node *rightChild;
    int data;
};

struct Node* newNode(int item){
    struct Node* temp = (struct Node*) malloc (sizeof(struct Node));
    temp->leftChild = NULL;
    temp->rightChild = NULL;
    temp->data = item;
    return temp;
}

struct Node* minValueNode(struct Node* root) {
    struct Node* temp = root;

    while(temp && temp->leftChild != NULL) {
        temp = temp->leftChild;
    }
    return temp;
}

struct Node* delete(struct Node* root, int num) {
    if(root == NULL) {
        return root;
    }

    if(num < root->data) {
        root->leftChild = delete(root->leftChild, num);
    } else if(num > root->data) {
        root->rightChild = delete(root->rightChild, num);
    } else {
        if(root->leftChild == NULL) {
            struct Node* temp = root->rightChild;
            free(root);
            return temp;
        } else if(root->rightChild == NULL) {
            struct Node* temp = root->leftChild;
            free(root);
            return temp;
        }
        struct Node* temp = minValueNode(root->rightChild);

        root->data = temp->data;
        root->rightChild = delete(root->rightChild, root->data);
    }
    return root;
}

void search(struct Node* root, int num) {
    if(root == NULL) {
        printf("Value not found.\n");
    } else {
        if(root->data < num) {
            search(root->leftChild, num);
        } else {
            search(root->rightChild, num);
        }
    }
}

struct Node* insert(struct Node* root, int num) {
    if(root == NULL) {
        return newNode(num);
    } 

    if(root->data > num) {
        root->leftChild = insert(root->leftChild, num);
    } else {
        root->rightChild = insert(root->rightChild, num);
    }
    return root;
}

void inorder(struct Node* root) {
    if(root == NULL) {
        return;
    } 
    inorder(root->rightChild);
    printf("%d\n", root->data);
    inorder(root->leftChild);
}

int main(int argc, char const *argv[]){
    struct Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
 
    printf("Inorder traversal of the given tree \n");
    inorder(root);
 
    printf("\nDelete 20\n");
    root = delete(root, 20);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
 
    printf("\nDelete 30\n");
    root = delete(root, 30);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
 
    printf("\nDelete 50\n");
    root = delete(root, 50);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
 
    return 0;
}
