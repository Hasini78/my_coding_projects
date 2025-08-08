#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *llink;
	struct node *rlink;
}*first,*last;
int c=0;
void create()
{
	struct node *nn;
	int d;
	while(1)
	{
		printf("enter data for creation.Enter -1 to stop\n");
		scanf("%d",&d);
		if(d==-1)
		  break;
		else
		{
			nn=(struct node*)malloc(sizeof(struct node));
			nn->data=d;
			nn->rlink=NULL;
			nn->llink=NULL;
			c++;
			if(first==NULL)
			{
				first=nn;
				last=nn;
			}
			else
			{
				last->rlink=nn;
				nn->llink=last;
				last=nn;
			}
			first->llink=last;
			last->rlink=first;
		}
	}
}
void count()
{
	printf("%d\n",c);
}
void display()
{
	int option;
	struct node *temp;
	printf("enter 1.forward 2.backward\n");
	scanf("%d",&option);
	if(option==1)
	{
		temp=first;
		do
		{
			printf("%d ",temp->data);
			temp=temp->rlink;
		}while(temp!=first);
    }
    else if(option==2)
    {
    	temp=last;
    	do
    	{
    		printf("%d ",temp->data);
    		temp=temp->llink;
		}while(temp!=last);
	}
}
void insert()
{
	struct node *temp,*nn;
	int op,p,d,i=1;
	printf("enter 1.begin 2.middle 3.end\n");
	scanf("%d",&op);
	nn=(struct node*)malloc(sizeof(struct node));
	printf("enter data to be inserted");
	scanf("%d",&d);
	nn->data=d;
	nn->rlink=NULL;
	nn->llink=NULL;
	c++;
	switch(op)
	{
		case 1:nn->rlink=first;
		       first->llink=nn;
		       first=nn;
		       break;
		case 2:temp=first;
		       printf("enter position");
		       scanf("%d",&p);
		       while(i<p-1)
		       {
		       	temp=temp->rlink;
		       	i++;
			   }
			   nn->rlink=temp->rlink;
			   nn->llink=temp;
			   temp->rlink=nn;
			   temp->rlink->llink=nn;
			   break;
		case 3:last->rlink=nn;
		       nn->llink=last;
		       last=nn;
		       break;
	}
	first->llink=last;
	last->rlink=first;
}
void del()
{
	struct node *t,*temp;
	int op,p,i=1;
	temp=first;
	if(first==NULL)
	{
		printf("list is empty\n");
		return;
	}
	printf("enter 1.begin 2.middle 3.end\n");
	scanf("%d",&op);
	switch(op)
	{
		case 1:t=first;
		       first=first->rlink;
		       first->llink=NULL;
		       break;
		case 2:printf("enter position\n");
		       scanf("%d",&p);
		       if(p>c)
		       {
		       	printf("invalid pos");
		       	return;
			   }
		       temp=first;
		       while(i<p-1)
		       {
		       	temp=temp->rlink;
		       	i++;
			   }
			   t=temp->rlink;
			   temp->rlink=temp->rlink->rlink;
			   temp->rlink->llink=temp;
			   break;
		case 3:t=last;
		       last=last->llink;
		       last->rlink=NULL;
		       break;
	}
	printf("%d\n",t->data);
	free(t);
	c--;
	first->llink=last;
	last->rlink=first;
	
}
void main()
{
	int op;
	do
	{
		printf("enter 1.create 2.display 3.insert 4.del 5.count 6.exit\n");
		scanf("%d",&op);
		switch(op)
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
			
		}
	}while(op!=6);
}
