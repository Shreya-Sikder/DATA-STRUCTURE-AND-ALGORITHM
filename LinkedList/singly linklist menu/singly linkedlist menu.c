#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node
{
    int data;
    struct Node* next;
};

// Function to insert at the head of the linked list
struct Node* insertAtHead(struct Node* head, int newData)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return head;
    }

    newNode->data = newData;
    newNode->next = head;
    head = newNode;

    return head;
}

// Function to insert at the tail of the linked list
struct Node* insertAtTail(struct Node* head, int newData)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return head;
    }

    newNode->data = newData;
    newNode->next = NULL;

    if (head == NULL)
    {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;

    return head;
}

// Function to insert after a specific value
struct Node* insertAfterValue(struct Node* head, int value, int newData)
{
    struct Node* temp = head;

    while (temp != NULL && temp->data != value)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Value %d not found in the list.\n", value);
        return head;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return head;
    }

    newNode->data = newData;
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// Function to delete the head of the linked list
struct Node* deleteHead(struct Node* head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return head;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);

    return head;
}

// Function to delete the tail of the linked list
struct Node* deleteTail(struct Node* head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return head;
    }

    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }

    struct Node* temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;

    return head;
}

// Function to delete after a specific value
struct Node* deleteAfterValue(struct Node* head, int value)
{
    struct Node* temp = head;

    while (temp != NULL && temp->data != value)
    {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)
    {
        printf("Value %d not found or no node exists after it.\n", value);
        return head;
    }

    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);

    return head;
}

// Function to print the linked list
void printList(struct Node* head)
{
    struct Node* temp = head;

    if (temp == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Linked list: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main()
{
    struct Node* head = NULL;
    int choice, value, newValue;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert at Head\n");
        printf("2. Insert at Tail\n");
        printf("3. Insert After Value\n");
        printf("4. Delete Head\n");
        printf("5. Delete Tail\n");
        printf("6. Delete After Value\n");
        printf("7. Print List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice==8)
        {
            printf("Exiting...\n");
            break;
            return 0;
        }
        else
        {
            switch (choice)
            {
            case 1:
                printf("Enter value to insert at head: ");
                scanf("%d", &value);
                head = insertAtHead(head, value);
                break;

            case 2:
                printf("Enter value to insert at tail: ");
                scanf("%d", &value);
                head = insertAtTail(head, value);
                break;

            case 3:
                printf("Enter value after which to insert: ");
                scanf("%d", &value);
                printf("Enter new value to insert: ");
                scanf("%d", &newValue);
                head = insertAfterValue(head, value, newValue);
                break;

            case 4:
                head = deleteHead(head);
                printf("Head deleted.\n");
                break;

            case 5:
                head = deleteTail(head);
                printf("Tail deleted.\n");
                break;

            case 6:
                printf("Enter value after which to delete: ");
                scanf("%d", &value);
                head = deleteAfterValue(head, value);
                break;

            case 7:
                printList(head);
                break;


            default:
                printf("Invalid choice! Try again.\n");
            }
        }
    }
    return 0;
}
