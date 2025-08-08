#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *next;
};
struct node* create()
{
	int d;
	struct node *first=NULL,*last=NULL,*nn;
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
	return first;
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
struct node* merge(struct node *t1,struct node *t2)
{   
    struct node *t,*temp;
	if(t1==NULL)
	  return t2;
    else if(t2==NULL)
      return t1;
    else
    {   temp=t1;
    	while(t1->next!=NULL && t2->next!=NULL)
         { 
    	   t=t2;
    	   t2=t2->next;
    	   t->next=t1->next;
    	   t1->next=t;
    	   t1=t1->next->next; //moving by two nodes
	     }
	     if(t1->next==NULL)
	       t1->next=t2;
	     else if(t2->next==NULL)
	     {
		   t2->next=t1->next;
	       t1->next=t2;
	     }
	}
	return temp;
}
void main()
{
	struct node *t1,*t2,*r;
	printf("enter list1\n");
	t1=create();
	display(t1);
	
	printf("enter list2\n");
	t2=create();
	display(t2);
	r=merge(t1,t2);
	printf("merged list is\n");
	display(r);
}
