#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*first,*last,*second;
int c=0;
void create()
{
	struct node *nn;
	int d;
	while(1)
	{
	printf("enter data for creation,Enter -1 to stop\n");
	scanf("%d",&d);
	if(d==-1)
	  break;
	nn=(struct node*)malloc(sizeof(struct node));
	nn->data=d;
	nn->next=NULL;
	c++;
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
}
struct node* reverse(struct node *t)
{
	struct node *t1,*t2,*sec;
	if(t==NULL)
	{
		printf("list is empty\n");
		return;
	}
    if(c==1)
    {
        t=last;
        last=t;
        return t;
    }
    if(c==2)
    {
       second = t->next;
       second->next = t;
       t->next = NULL;
       last = t;
       t = second;
       return t;
    }
    else{
	t1=t->next;
	t2=t1->next;
	t->next=NULL;
	last=t;
	while(t2!=NULL)
	{
		t1->next=t;
		t=t1;
		t1=t2;
		t2=t1->next;
	}
	t1->next=t;
	t=t1;
    }
    return t;
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
void main()
{
	int p,i=1;
	struct node *temp,*temp1,*x,*result;
	create();
	printf("enter position");
	scanf("%d",&p);
	temp=first;
	while(i<p-1)
	{
		printf("%d ",temp->data);
		temp=temp->next;
		i++;
	}
	printf("%d",temp->data);
	printf("\n");
	second=temp->next;
	printf("%d ",second->data);
	printf("\n");
	temp->next=NULL;	
	x=reverse(second);
	temp1=x;
	while(temp1!=NULL)
	{
		printf("%d ",temp1->data);
		temp1=temp1->next;
	}
	printf("\n");
	result=concat(x,first);
	while(result!=NULL)
	{
		printf("%d ",result->data);
		result=result->next;
	}
}
