#include <stdio.h>
#include <stdlib.h>

#define SIZE 4

struct stack {
    int top;
    int array[SIZE];
};

void initStack(struct stack *st) {
    st->top = 0;

    for (int i = 0; i < SIZE; i++) {
        st->array[i] = 0;
    }
}

int isEmpty(struct stack *st) {
    if (st->top == 0) {
        return 1;
    } else {
        return 0;
    }
}

int isFull(struct stack *st) {
    if (st->top > SIZE) {
        return 1;
    } else {
        return 0;
    }
}

void push(struct stack *st, int *number) {
    if (!isFull(st)) {
        if (!isEmpty(st)) {
            for (int k = st->top; k >= 0; k--) {
                st->array[k+1] = st->array[k];
            }
        }

        st->array[0] = number;
        st->top++;
        system("cls");
        print(st);
    } else {
        system("cls");
        printf("Impossible to add value! The stack is full\n\n");
    }
}

void print(struct stack *st) {
    printf("Stack elements:\n");
    for (int j = 0; j <= SIZE; j++) {
        printf("Index - %d - Value - %d\n", j, st->array[j]);
    }
    printf("\n");
}

void pop(struct stack *st) {
    system("cls");
    if (!isEmpty(st)) {
        printf("%d", st->array[0]);
    } else {
        printf("Firstly, add at least one element\n\n");
    }
}

void delete(struct stack *st) {
    system("cls");
    if (!isEmpty(st)) {
        for (int y = 0; y < st->top; y++) {
            st->array[y] = st->array[y+1];
        }

        st->array[st->top] = 0;
        st->top--;
        print(st);
    } else {
        printf("The stack is empty! Add at least one element\n\n");
    }
}

int main()
{
    int option;
    struct stack st;
    int is_digit = 1;
    int push_numb;

    initStack(&st);

        while (is_digit) {
            printf("Enter the number of the following functions:\n 1. Push the value to the stack\n 2. Get the values of the stack\n 3. Pop to output the first stack element\n 4. Delete element\n 5. Exit\n Function: ");

            if (scanf("%d", &option)) {
                switch (option) {
                case 1:
                    printf("Enter the value to push:\n");
                    scanf("%d", &push_numb);
                    push(&st, push_numb);
                    break;
                case 2:
                    system("cls");
                    print(&st);
                    break;
                case 3:
                    pop(&st);
                    break;
                case 4:
                    delete(&st);
                    break;
                case 5:
                    exit(1);
                default:
                    system("cls");
                    printf("Incorrect action! Enter 4 for help\n");
                    break;
                }
            } else {
                is_digit = 0;
            }

        }

    return 0;
}
