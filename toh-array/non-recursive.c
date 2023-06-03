 /*
 Tower of hanoi by Stack as ADT using Array without recursion
 */

    #include <stdio.h>
    #include <stdlib.h>
    #include<math.h>

    struct Stack {
        int capacity;
        int top;
        int *array;
    };

    struct Stack *createStack(int capacity) {
        struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
        stack->capacity = capacity;
        stack->top = -1;
        stack->array = (int *)malloc(capacity * sizeof(int));
        return stack;
    }

    int isEmpty(struct Stack *stack) {
        if (stack->top == -1)
            return 1;
    }

    void push(struct Stack *stack, int item) {
        stack->array[++stack->top] = item;
    }

    void pop(struct Stack *stack) {
        if (!isEmpty(stack)) 
         stack->array[stack->top--];
 
    }

    void moveDisk(char source, char destination) {
        printf("Move disk from %c to %c\n", source, destination);
    }

    void towerOfHanoi(int num_disks, struct Stack *source, struct Stack *auxiliary, struct Stack *destination) {
        int total_moves = pow(2,num_disks) - 1;
        char source_peg = 'A';
        char auxiliary_peg = 'B';
        char destination_peg = 'C';

        for (int i = num_disks; i >= 1; i--) {
            push(source, i);
        }

        for (int move = 1; move <= total_moves; move++) {
            if (move % 3 == 1) {
                pop(source);
                if((move % 2) == ((move % 3)% 2))
                moveDisk(source_peg, destination_peg);
                else
                moveDisk(destination_peg, source_peg);

            } else if (move % 3 == 2) {
                pop(source);
                if((move % 2) == ((move % 3)% 2))
                moveDisk(source_peg, auxiliary_peg);
                else
                moveDisk(auxiliary_peg, source_peg);

            } else if (move % 3 == 0) {
                pop(auxiliary);
                if((move % 2) == ((move % 3)% 2))
                moveDisk(auxiliary_peg, destination_peg);
                else
                moveDisk(destination_peg, auxiliary_peg);


            }
        }
    }



    int main() {
        int num_disks = 3;
        struct Stack *source = createStack(num_disks);
        struct Stack *auxiliary = createStack(num_disks);
        struct Stack *destination = createStack(num_disks);

        towerOfHanoi(num_disks, source, auxiliary, destination);

        return 0;
    }