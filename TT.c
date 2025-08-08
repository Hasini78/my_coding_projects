#include <stdio.h>
#include <stdlib.h>
typedef struct node{
int expo;
char vari;
float coeff;
struct node*next;
}node;
typedef struct polynomial{
struct node* head;
}polynomial;
void insert_term(struct polynomial*poly,float co,int ex,char va)
{
    struct node* nn= (struct node*)malloc(sizeof(struct node));
    if (nn == NULL) {
        printf("Memory allocation error!\n");
        exit(1);
    }
    nn->coeff=co;
    nn->expo=ex;
    nn->vari=va;
    nn->next=NULL;
    if(poly->head == NULL)
    {
        poly->head=nn;
    }
    else
    {
        struct node* temp = poly->head;
        while(temp->next != NULL)
        {
            temp=temp->next;
        }
        temp->next = nn;;
    }
}
void display(struct polynomial* poly,int n)
{
    int i;
    printf("polynomial:\n");
    for(i=0;i<n;i++)
    {
        printf("polynomial %d:  ",i+1);
        struct node* temp=poly[i].head;
        if(temp == NULL)
        {
            printf("0");
        }
        while(temp!= NULL)
        {
            printf("%.1f%c^%d",temp->coeff,temp->vari,temp->expo);
            temp=temp->next;
            if(temp!=NULL)
                printf(" + ");
        }
        printf("\n");
    }
}
int main()
{
    int n;
    printf("enter no.of polynomials:");
    scanf("%d",&n);
      int i,terms,expo,j;
    float coeff;
    char vari;
    struct polynomial* poly= (struct polynomial*)malloc(n * sizeof(struct polynomial));
    for(i=0;i<n;i++)
    {
        poly[i].head=NULL;
        printf("enter no.of terms in the polynomial %d:",i+1);
        scanf("%d",&terms);
        for(j=0;j<terms;j++)
        {
            printf("enter the coefficient,variable,and exponent for term %d:",j+1);
            scanf("%f %c %d",&coeff,&vari,&expo);
            insert_term(&poly[i],coeff,expo,vari);
        }
    }
    display(poly,n);
     for (i = 0; i < n; i++) {
        node *temp = poly[i].head;
        while (temp != NULL) {
            node *next = temp->next;
           /* free(temp);*/
            temp = next;
        }
    }
    free(poly);
    return 0;
}
