#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Stack {
    struct Node* tail;
};

void inStack(struct Stack* stack) {
    stack->tail = NULL;
}

int empty(struct Stack* stack) {
    return stack->tail == NULL;
}
void push(struct Stack* stack, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (empty(stack)) {
        stack->tail = newNode;
    } else {
        struct Node* temp = stack->tail;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Pushed %d onto the stack.\n", value);
}
void pop(struct Stack* stack) {
    if (empty(stack)) {
        printf("Stack is empty! Cannot pop.\n");
        return;
    }

    if (stack->tail->next == NULL) {
        free(stack->tail);
        stack->tail = NULL;
    } else {
        struct Node* temp = stack->tail;

        while (temp->next->next != NULL) {
            temp = temp->next;
        }

        free(temp->next);
        temp->next = NULL;
    }
    printf("Popped from the stack.\n");
}


void printStack(struct Stack* stack) {
    if (empty(stack)) {
        printf("Stack is empty.\n");
        return;
    }

    struct Node* temp = stack->tail;
    printf("Stack (from top to bottom): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    inStack(&stack);

    int choice, value;

    while (1) {
        printf("Choose operation:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display Stack\n");
        printf("4. Exit\n");
        printf("Enter your choice:\n ");
        scanf("%d", &choice);
          if(choice==4){
                printf("Exiting program.\n");
            break;

            }
else{
        switch (choice) {
                case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;

            case 2:
                pop(&stack);
                break;

            case 3:
                printStack(&stack);
                break;

            default:
                printf("Invalid choice, please try again.\n");
        }
    }}

    return 0;
}
