#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *next;
}*first,*last;
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
    last->next=first;
}
void count()
{
	printf("No.of elements=%d\n",c);
}
void insert()
{
	struct node *nn,*temp;
	int p,i=1,d,opt;
	temp=first;
	printf("enter 1.begin 2.pos 3.end\n");
	scanf("%d",&opt);
	nn=(struct node *)malloc(sizeof(struct node));
	printf("enter data for insertion\n");
	scanf("%d",&d);
	nn->data=d;
	nn->next=NULL;
	c++;
	switch(opt)
	{
		case 1:nn->next=first;
		       first=nn;
		       last->next=first;
		       break;
		case 2:printf("enter the position\n");
		       scanf("%d",&p);
		       while(i<p-1)
		       {
		       	temp=temp->next;
		       	i++;
			   }
			   nn->next=temp->next;
			   temp->next=nn;
			   break;
		case 3:last->next=nn;
		       last=nn;
		       last->next=first;
		       break;
	}
}

void display()
{
	struct node *temp;
	temp=first;
	do
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}while(temp!=first);
}
void del()
{
	struct node *temp,*t;
	int p,i=1,opt;
	temp=first;
	if(first==NULL)
	{
		printf("list is empty\n");
		return;
	}
	printf("enter 1.begin 2.middle 3.end\n");
	scanf("%d",&opt);
	switch(opt)
	{
		case 1:t=first;
		       first=first->next;
		       last->next=first;
		       printf("%d",t->data);
		       free(t);
		       break;
		case 2:printf("enter the pos\n");
		       scanf("%d",&p);
		       while(i<p-1)
		       {
		       	temp=temp->next;
		       	i++;
			   }
			   t=temp->next;
			   temp->next=temp->next->next;
			   printf("%d",t->data);
			   free(t);
		       break;
		case 3:while(temp->next!=last)
		        {
				 temp=temp->next;
			    }
		       temp->next=first;
		       printf("%d",last->data);
		       free(last);
		       last=temp;
		       break;
	}
	c--;
}
void sort()
{
	struct node *t1,*t2;
	int t;
	for(t1=first;t1!=last;t1=t1->next)
	{
		for(t2=t1->next;t2!=first;t2=t2->next)
		{
			if(t1->data > t2->data)
			{
			  t=t1->data;
			  t1->data=t2->data;
			  t2->data=t;	
		    }
		}
	}
}
void main()
{   int option;
    do
    {
	printf("enter 1.create 2.display 3.insert 4.del 5.count 6.sort 7.exit\n");
	scanf("%d",&option);
	switch(option)
	 {
		case 1:create();
		       break;
		case 2:display();
		       break;
		case 3:insert();
		       break;
		case 4:del();
		       break;
		case 5:count();
		       break;
		case 6:sort();
		       break;
	 }
    }while(option!=7);
}
