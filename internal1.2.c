#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *next;
};
struct node* create()
{
	struct node *last=NULL,*first=NULL,*nn;
	int d;
	while(1)
	{
		printf("enter data for creation.Enter -1 to stop\n");
		scanf("%d",&d);
		if(d==-1)
		  break;
		nn=(struct node*)malloc(sizeof(struct node));
		nn->data=d;
		nn->next=NULL;
		if(first==NULL)
		{
			first=nn;
			last=nn;
		}
		else
		{
			last->next=nn;
			last=nn;
		}
	}
	return(first);
}
void similar(struct node *t1,struct node *t2)
{
	struct node *temp1,*temp2;
	for(temp1=t1;temp1!=NULL;temp1=temp1->next)
	{
		for(temp2=t2;temp2!=NULL;temp2=temp2->next)
		{
			if(temp1->data==temp2->data)
			{
				printf("%d ",temp1->data);	
			}
		}
	}
}
void display(struct node *t)
{
	if(t==NULL)
	{
		printf("list is empty\n");
		return;
	}
	while(t!=NULL)
	{
		printf("%d ",t->data);
		t=t->next;
	}
	printf("\n");
}
void main()
{
	struct node *t1,*t2,*r;
	printf("enter list 1\n");
	t1=create();
	display(t1);
	printf("enter list 2\n");
	t2=create();
	display(t2);
	
	similar(t1,t2);
}
