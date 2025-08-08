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
struct node* concat(struct node *t1,struct node *t2)
{
	struct node *r,*temp;
	if(t1==NULL)
	{
		r=t2;
	}
	else if(t2==NULL)
	{
		r=t1;
	}
	else
	{
		temp=t1;
		while(temp->next!=NULL)
		{
		  temp=temp->next;	
		}
		temp->next=t2;
		r=t1;
	}
	return r;
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
int main()
{
	struct node *t1,*t2,*r;
	printf("enter list 1\n");
	t1=create();
	display(t1);
	printf("enter list 2\n");
	t2=create();
	display(t2);
	
	r=concat(t1,t2);
	printf("the concatenated list is \n");
	display(r);
	return 0;
}
