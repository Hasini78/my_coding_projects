#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node {
    int cof;
    int pow;
    struct node *link;
};
typedef struct node NODE;
NODE *p1 = NULL, *p2 = NULL, *p3 = NULL;

NODE *create() {
    NODE *first = NULL, *last, *nn;
    char ch;
    do {
        nn = (NODE*)malloc(sizeof(NODE));
        printf("\n Enter the term coefficient and power: ");
        scanf("%d%d", &nn->cof, &nn->pow);
        nn->link = NULL;
        if (first == NULL)
            first = nn;
        else
            last->link = nn;
        last = nn;
        printf("\n Do you want to continue...y/n? ");
        fflush(stdin);
        ch = getchar();
    } while (ch != 'n');
    return first;
}

void display(NODE *t) {
    if (t == NULL) {
        printf("\n No Polynomial to Display!\n");
        return;
    }
    while (t != NULL) {
        if (t->cof < 0)
            printf(" - ");
        else
            printf(" + ");
        printf("%d X ^ %d", abs(t->cof), t->pow);
        t = t->link;
    }
    printf("\n");
}

void add(NODE *t1, NODE *t2) {
    p3 = NULL;
    NODE *nn, *t;
    while (t1 != NULL && t2 != NULL) {
        nn = (NODE*)malloc(sizeof(NODE));
        nn->link = NULL;
        if (t1->pow > t2->pow) {
            nn->cof = t1->cof;
            nn->pow = t1->pow;
            t1 = t1->link;
        } else if (t2->pow > t1->pow) {
            nn->cof = t2->cof;
            nn->pow = t2->pow;
            t2 = t2->link;
        } else {
            nn->cof = t1->cof + t2->cof;
            nn->pow = t1->pow;
            t1 = t1->link;
            t2 = t2->link;
        }
        if (p3 == NULL)
            p3 = nn;
        else
            t->link = nn;
        t = nn;
    }
}

void subtract(NODE *t1, NODE *t2) {
    NODE *temp = t2, *copy = NULL, *newNode, *last = NULL;
    while (temp != NULL) {
        newNode = (NODE*)malloc(sizeof(NODE));
        newNode->cof = -temp->cof;
        newNode->pow = temp->pow;
        newNode->link = NULL;
        if (copy == NULL)
            copy = newNode;
        else
            last->link = newNode;
        last = newNode;
        temp = temp->link;
    }
    p3 = NULL;
    add(t1, copy);
}

void multiply(NODE *t1, NODE *t2) {
    p3 = NULL;
    NODE *temp, *nn, *t2_start = t2;
    while (t1 != NULL) {
        t2 = t2_start;
        while (t2 != NULL) {
            nn = (NODE*)malloc(sizeof(NODE));
            nn->cof = t1->cof * t2->cof;
            nn->pow = t1->pow + t2->pow;
            nn->link = NULL;
            if (p3 == NULL) {
                p3 = nn;
            } else {
                temp = p3;
                NODE *prev = NULL;
                while (temp != NULL && temp->pow > nn->pow) {
                    prev = temp;
                    temp = temp->link;
                }
                if (temp != NULL && temp->pow == nn->pow) {
                    temp->cof += nn->cof;
                    free(nn);
                } else {
                    nn->link = temp;
                    if (prev == NULL)
                        p3 = nn;
                    else
                        prev->link = nn;
                }
            }
            t2 = t2->link;
        }
        t1 = t1->link;
    }
}

int main() {
    int choice;
    do {
        printf("\n MENU:\n");
        printf("1. Enter Polynomial 1\n");
        printf("2. Enter Polynomial 2\n");
        printf("3. Display Polynomial 1\n");
        printf("4. Display Polynomial 2\n");
        printf("5. Add Polynomials\n");
        printf("6. Subtract Polynomials\n");
        printf("7. Multiply Polynomials\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\n Enter Polynomial 1:\n");
                p1 = create();
                break;
            case 2:
                printf("\n Enter Polynomial 2:\n");
                p2 = create();
                break;
            case 3:
                printf("\n Polynomial 1: ");
                display(p1);
                break;
            case 4:
                printf("\n Polynomial 2: ");
                display(p2);
                break;
            case 5:
                add(p1, p2);
                printf("\n Sum of Polynomials: ");
                display(p3);
                break;
            case 6:
                subtract(p1, p2);
                printf("\n Subtraction of Polynomials: ");
                display(p3);
                break;
            case 7:
                multiply(p1, p2);
                printf("\n Product of Polynomials: ");
                display(p3);
                break;
            case 8:
                printf("\n Exiting program...\n");
                break;
            default:
                printf("\n Invalid choice! Please try again.\n");
        }
    } while (choice != 8);
    return 0;
}
