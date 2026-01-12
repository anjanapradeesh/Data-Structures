#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;
struct node *head=NULL;

void insertAtBeginning(Node** head, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = *head;

    if (*head != NULL)
        (*head)->prev = newNode;

    *head = newNode;
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtPosition(Node** head, int data, int position) {
    if (position <= 1) {
        insertAtBeginning(head, data);
        return;
    }

    Node* newNode = (Node*) malloc(sizeof(Node));
    Node* temp = *head;
    int i = 1;

    while (i < position - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        insertAtEnd(head, data);
        return;
    }

    newNode->data = data;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

void deleteAtBeginning(Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = *head;
    *head = (*head)->next;

    if (*head != NULL)
        (*head)->prev = NULL;

    free(temp);
}

void deleteAtEnd(Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = *head;

    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);
}

void deleteAtPosition(Node** head, int position) {
    if (*head == NULL || position < 1) {
        printf("Invalid position or empty list.\n");
        return;
    }

    if (position == 1) {
        deleteAtBeginning(head);
        return;
    }

    Node* temp = *head;
    int i = 1;

    while (i < position && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

void displayList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("List: ");
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void searchList(Node* head, int key) {
    int pos = 1;
    while (head != NULL) {
        if (head->data == key) {
            printf("Value %d found at position %d.\n", key, pos);
            return;
        }
        head = head->next;
        pos++;
    }
    printf("Value %d not found in the list.\n", key);
}

void mergeLists(Node** head1, Node** head2) {
    if (*head1 == NULL) {
        *head1 = *head2;
        *head2 = NULL;
        return;
    }

    Node* temp = *head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = *head2;
    if (*head2 != NULL)
        (*head2)->prev = temp;

    *head2 = NULL;
}


int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;
    int choice, data, position, listNum;

    while (1) {
        printf("\n--- DOUBLY LINKED LIST MENU ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete at position\n");
        printf("7. Display list\n");
        printf("8. Search\n");
        printf("9. Merge two lists\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 10) break;

        if (choice >= 1 && choice <= 8) {
            printf("Select list (1 or 2): ");
            scanf("%d", &listNum);
        }

        Node** selectedList = (listNum == 2) ? &head2 : &head1;

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(selectedList, data);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(selectedList, data);
                break;

            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(selectedList, data, position);
                break;

            case 4:
                deleteAtBeginning(selectedList);
                break;

            case 5:
                deleteAtEnd(selectedList);
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteAtPosition(selectedList, position);
                break;

            case 7:
                displayList(*selectedList);
                break;

            case 8:
                printf("Enter value to search: ");
                scanf("%d", &data);
                searchList(*selectedList, data);
                break;

            case 9:
                mergeLists(&head1, &head2);
                printf("Lists merged into List 1.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
