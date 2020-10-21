# include <stdio.h>
# include <stdlib.h>

# define Data int
# define dataDefaultValue 0

typedef struct stack {
    int top;
    unsigned int capacity;
    Data *array;
} Stack;

Stack *newStack(const unsigned int capacity) {
    Stack *pstack = (Stack *) calloc(1, sizeof(Stack));
    pstack->top = -1;
    pstack->capacity = capacity;
    pstack->array = (int *) calloc(capacity, sizeof(int));
    return pstack;
}

int isEmpty(Stack *pstack) {
    return pstack->top == -1;
}

int isFull(Stack *pstack) {
    return pstack->top == pstack->capacity - 1;
}

int push(Stack *pstack, Data data) {
    if (isFull(pstack)) {
        return -1;
    }
    pstack->array[++(pstack->top)] = data;
    return 0;
}

Data pop(Stack *pstack) {
    if (isEmpty(pstack)) {
        fprintf(stderr, "Stack Underflow!\n");
        return dataDefaultValue;
    }
    return pstack->array[(pstack->top)--];
}

Data peek(Stack *pstack) {
    if (isEmpty(pstack)) {
        fprintf(stderr, "Stack Underflow!\n");
        return dataDefaultValue;
    }
    return pstack->array[(pstack->top)];
}

int driver1() {
    int n = 7;
    scanf("%d", &n);
    printf("%d\n", n);
    fscanf(stdin, "%d", &n);
    fprintf(stderr, "Err: %d\n", n);
    fprintf(stdout, "Out: %d\n", n);
    return 0;
}

typedef struct queue {
    Stack *pstack1, *pstack2;
} Queue;

Queue *newQueue(int size) {
    Queue *pqueue = (Queue *) calloc(1, sizeof(Queue));
    pqueue->pstack1 = newStack(size);
    pqueue->pstack2 = newStack(size);
    return pqueue;
}

int isEmptyQueue(Queue *pqueue) {
    return isEmpty(pqueue->pstack1);
}

int isFullQueue(Queue *pqueue) {
    return isFull(pqueue->pstack1);
}

int enqueue(Queue *pqueue, Data data) {
    if (isFullQueue(pqueue)) {
        return -1;
    }
    while (!isEmpty(pqueue->pstack1)) {
        push(pqueue->pstack2, pop(pqueue->pstack1));
    }
    push(pqueue->pstack1, data);
    while (!isEmpty(pqueue->pstack2)) {
        push(pqueue->pstack1, pop(pqueue->pstack2));
    }
    return 0;
}

Data dequeue(Queue *pqueue) {
    if (isEmptyQueue(pqueue)) {
        fprintf(stderr, "Queue Underflow!\n");
        return dataDefaultValue;
    }
    return pop(pqueue->pstack1);
}

int driver2() {
    Stack *pstack = newStack(2);
    printf("isEmpty: %d\n", isEmpty(pstack));
    printf("isFull : %d\n", isFull (pstack));
    for (int i = 1; i < 4; i++) {
        printf("%d\n", push(pstack, i));
    }
    printf("isEmpty: %d\n", isEmpty(pstack));
    printf("isFull : %d\n", isFull (pstack));
    printf("peek: %d\n", peek(pstack));
    for (int i = 1; i < 4; i++) {
        printf("%d\n", pop(pstack));
    }
    printf("isEmpty: %d\n", isEmpty(pstack));
    printf("isFull : %d\n", isFull (pstack));
    return 0;
}

int main() {
    Queue *pqueue = newQueue(2);
    printf("isEmptyQueue: %d\n", isEmptyQueue(pqueue));
    printf("isFullQueue : %d\n", isFullQueue (pqueue));
    for (int i = 1; i < 4; i++) {
        printf("%d\n", enqueue(pqueue, i));
    }
    printf("isEmptyQueue: %d\n", isEmptyQueue(pqueue));
    printf("isFullQueue : %d\n", isFullQueue (pqueue));
    //printf("peek: %d\n", peek(pqueue));
    for (int i = 1; i < 4; i++) {
        printf("%d\n", dequeue(pqueue));
    }
    printf("isEmptyQueue: %d\n", isEmptyQueue(pqueue));
    printf("isFullQueue : %d\n", isFullQueue (pqueue));
}

