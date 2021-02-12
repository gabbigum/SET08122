#include <stdio.h>

#define MAX 5

struct stack;

void init(struct stack*);
void push(struct stack*, int);
int pop(struct stack*);

struct stack {
    int array[MAX];
    int top;
};

int main(int argc, char const *argv[])
{
    struct stack s;
    init(&s);
    printf("top of the stack %d\n", s.top);

    push(&s, 5);
    push(&s, 10);
    push(&s, 15);
    push(&s, 7);
    push(&s, 8);
    push(&s, 95);

    pop(&s);
    pop(&s);
    pop(&s);
    pop(&s);
    pop(&s);
    pop(&s);
    pop(&s);
    
    return 0;
}

void push(struct stack *s, int item) {
    if(s->top == MAX-1) {
        printf("Stack is full couldn't push the item.\n");
        return;
    }
    s->top++;
    s->array[s->top] = item;
    printf("Item pushed to the stack %d\n", s->array[s->top]);
}

int pop(struct stack *s) {
    if(s->top == -1) {
        printf("Stack is empty.\n");
        return -1;
    }
    int data = s->array[s->top];
    s->array[s->top] = 0;
    s->top--;
    printf("Item popped from the stack.\n", data);
    return data;
}

void init(struct stack* s) {
    s->top = -1;
}
