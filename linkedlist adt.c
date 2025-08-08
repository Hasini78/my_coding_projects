#include <stdio.h>
#include<stdlib.h>

int c = 0;

struct node{
	int data;
	struct node *next;
} *first = NULL ,*last = NULL;

void create(){
	struct node * nn;
	int num;
	while(1){
		printf("Enter number to insert , -1 to EXIT : ");
		scanf("%d",&num);
		if(num == -1)
		break;
		nn = (struct node*)malloc(sizeof(struct node));
		nn -> data = num;
		nn -> next = NULL;
		c++;
		if(first == NULL)
			first = last = nn;
		else{
			last -> next = nn;
			last = nn;
		}
	}
}

void display(){
	struct node * temp;
	if(first == NULL){
		printf("List is Empty\n");
		return ;
	}
	temp = first;
	while(temp != NULL){
		printf("%d ",temp -> data);
		temp = temp -> next;
	}
	printf("\n");
}

void insert(){
	int num , op , ind;
	struct node * nn , *temp;
	nn = (struct node *)malloc(sizeof(struct node));
	printf("Enter number to insert : ");
	scanf("%d",&num);
	nn -> data = num;
	nn -> next = NULL;
	c++;
	printf("Enter place of insertion : 1.Beginning , 2.At Index , 3.End : ");
	scanf("%d",&op);
	switch(op){
		case 1 :
			nn -> next = first;
			first = nn;
			break;
		case 2 :
			printf("Enter the index : ");
			scanf("%d",&ind);
			temp = first;
			ind -= 2;
			while(ind--)
			temp = temp -> next;
			nn -> next = temp -> next;
			temp -> next = nn;
			break;
		case 3 :
			last -> next = nn;
			last = nn;
			break;
	}	
}

void deletion(){
	int ind , op;
	struct node *temp;
	if(first == NULL){
		printf("List is Empty\n");
		return;
	}
	c--;
	temp = first;
	printf("Enter place of deletion : 1.Beginning , 2.At Index , 3.End : ");
	scanf("%d",&op);
	switch(op){
		case 1 :
			first = first -> next;
			break;
		case 2 :
			printf("Enter index to Delete : ");
			scanf("%d",&ind);
			ind -= 2;
			while(ind--)
			temp = temp -> next;
			temp -> next = ( temp -> next ) -> next;
			break;
		case 3 :
			do{
				temp = temp -> next;
			}while(( temp -> next ) -> next != NULL);
			temp -> next = NULL;
			break;
	}	
}

void count(){
	printf("Count : %d\n",c);
}

int main(){
	int op;
	do{
		printf("MENU\n0.EXIT\n1.Create\n2.Display\n3.Insert\n4.Delete\n5.Count\n");
		scanf("%d",&op);
		switch(op){
			case 1 : create(); break;
			case 2 : display(); break;
			case 3 : insert(); break;
			case 4 : deletion(); break;
			case 5 : count(); break;
		}
	}while(op != 0);
	return 0;
}
