#include <stdio.h>
#include <stdlib.h>

// Stack ADT
struct Stack {
    int capacity;
    int top;
    char name;
    int* array;
};

struct Stack* createStack(int capacity,char name) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->name = name;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}

void moveDisk(char source, char destination, int disk) {
    printf("Move disk %d from %c to %c\n", disk, source, destination);
}

void towerOfHanoi(int numDisks, struct Stack* source, struct Stack* auxiliary, struct Stack* destination) {
    if (numDisks == 1) {
        int disk = pop(source);
        push(destination, disk);
        //moveDisk('A', 'C', disk);
        printf("Move disk 1 from %c to rod %c.\n",source->name,destination->name);
        return;
    }

    towerOfHanoi(numDisks - 1, source, destination, auxiliary);

    int disk = pop(source);
    push(destination, disk);
    //moveDisk('A', 'C', disk);
    printf("Move disk %d from %c to rod %c.\n",numDisks,source->name,destination->name);

    towerOfHanoi(numDisks - 1, auxiliary, source, destination);
}

int main() {
    int numDisks = 3;

    struct Stack* source = createStack(numDisks,'A');
    struct Stack* destination = createStack(numDisks,'C');
    struct Stack* auxiliary = createStack(numDisks,'B');

    for (int i = numDisks; i >= 1; i--)
        push(source, i);

    towerOfHanoi(numDisks, source, auxiliary, destination);

    return 0;
}
