#include <stdio.h>
#include <stdlib.h>

int c = 0;

struct node {
    int data;
    struct node *next;
} *first = NULL, *last = NULL;

void create() {
    struct node *nn;
    int num;
    while (1) {
        printf("Enter number to insert, -1 to EXIT: ");
        scanf("%d", &num);
        if (num == -1)
            break;
        nn = (struct node *)malloc(sizeof(struct node));
        nn->data = num;
        nn->next = NULL;
        c++;
        if (first == NULL)
            first = last = nn;
        else {
            last->next = nn;
            last = nn;
        }
    }
}

void display() {
    struct node *temp;
    if (first == NULL) {
        printf("List is Empty\n");
        return;
    }
    temp = first;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insert() {
    int num, op, ind;
    struct node *nn, *temp;
    
    nn = (struct node *)malloc(sizeof(struct node));
    if (!nn) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter number to insert: ");
    scanf("%d", &num);
    nn->data = num;
    nn->next = NULL;
    c++;

    printf("Enter place of insertion: 1.Beginning, 2.At Index, 3.End: ");
    scanf("%d", &op);
    
    switch (op) {
        case 1: // Insert at beginning
            nn->next = first;
            first = nn;
            if (last == NULL) // If the list was empty
                last = nn;
            break;
        
        case 2: // Insert at an index
            printf("Enter the index: ");
            scanf("%d", &ind);
            if (ind < 1 || ind > c) {
                printf("Invalid index!\n");
                free(nn);
                return;
            }
            
            if (ind == 1) { // Same as inserting at beginning
                nn->next = first;
                first = nn;
                break;
            }

            temp = first;
            for (int i = 1; i < ind - 1; i++) {
                if (temp->next == NULL) {
                    printf("Invalid index!\n");
                    free(nn);
                    return;
                }
                temp = temp->next;
            }
            nn->next = temp->next;
            temp->next = nn;

            if (nn->next == NULL) // If inserted at the last position
                last = nn;
            break;

        case 3: // Insert at end
            last->next = nn;
            last = nn;
            break;

        default:
            printf("Invalid choice!\n");
            free(nn);
    }
}

void deletion() {
    int ind, op;
    struct node *temp, *prev;

    if (first == NULL) {
        printf("List is Empty\n");
        return;
    }

    printf("Enter place of deletion: 1.Beginning, 2.At Index, 3.End: ");
    scanf("%d", &op);

    switch (op) {
        case 1: // Delete from beginning
            temp = first;
            first = first->next;
            free(temp);
            c--;
            if (first == NULL) // If list is now empty
                last = NULL;
            break;

        case 2: // Delete at index
            printf("Enter index to delete: ");
            scanf("%d", &ind);

            if (ind < 1 || ind > c) {
                printf("Invalid index!\n");
                return;
            }

            if (ind == 1) { // Same as deleting first node
                temp = first;
                first = first->next;
                free(temp);
                c--;
                return;
            }

            temp = first;
            for (int i = 1; i < ind - 1; i++) {
                if (temp->next == NULL) {
                    printf("Invalid index!\n");
                    return;
                }
                temp = temp->next;
            }
            prev = temp->next;
            temp->next = prev->next;
            if (temp->next == NULL) // If last node is deleted
                last = temp;
            free(prev);
            c--;
            break;

        case 3: // Delete from end
            temp = first;
            if (temp->next == NULL) { // Only one element in the list
                free(temp);
                first = last = NULL;
                c = 0;
                return;
            }
            
            while (temp->next->next != NULL)
                temp = temp->next;

            free(temp->next);
            temp->next = NULL;
            last = temp;
            c--;
            break;

        default:
            printf("Invalid choice!\n");
    }
}

void count() {
    printf("Count: %d\n", c);
}

int main() {
    int op;
    do {
        printf("MENU\n0.EXIT\n1.Create\n2.Display\n3.Insert\n4.Delete\n5.Count\n");
        scanf("%d", &op);
        switch (op) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert(); break;
            case 4: deletion(); break;
            case 5: count(); break;
        }
    } while (op != 0);
    
    return 0;
}

