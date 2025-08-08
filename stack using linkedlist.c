#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*top=NULL;
int c=0;
void push()
{
	struct node *nn;
	int d;
	nn=(struct node*)malloc(sizeof(struct node));
	printf("enter data value\n");
	scanf("%d",&d);
	nn->data=d;
	nn->next=NULL;
	if(top==NULL)
	{
		top=nn;
	}
	else
	{
		nn->next=top;
		top=nn;
	}
	c++;
}
void pop()
{
	struct node *t;
	if(top==NULL)
	{
		printf("stack underflow\n");
		return;
	}
	t=top;
	top=top->next;
	printf("deleted element from stack is %d",t->data);
	free(t);
	c--;
}
void display()
{
	struct node *temp;
	temp=top;
	if(top==NULL)
	{
		printf("stack is empty\n");
		return;
	}
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
void count()
{
	printf("no.of elements=%d",c);
}
void main()
{
	int option;
	do{
		printf("Enter 1.push 2.pop 3.display 4.count 5.exit\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:push();
			       break;
			case 2:pop();
			       break;
			case 3:display();
			       break;
			case 4:count();
			       break;
		}
	}while(option!=5);
}
