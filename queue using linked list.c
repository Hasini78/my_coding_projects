#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*f=NULL,*r=NULL;
int c=0;
void insert()
{
	struct node *nn;
	int d;
	nn=(struct node*)malloc(sizeof(struct node));
	printf("enter data value\n");
	scanf("%d",&d);
	nn->data=d;
	nn->next=NULL;
	c++;
	if(f==NULL&& r==NULL)
	{
		f=nn;
		r=nn;
	}
	else
	{  
	    r->next=nn;
		r=nn;
	}

}
void del()
{
	struct node *t;
	if(f==NULL)
	{
		printf("queue underflow\n");
		return;
	}
	t=f;
	printf("deleted element from queue is %d",t->data);
	f=f->next;
	free(t);
	c--;
}
void display()
{   
    struct node *temp;
	int i;
	if(f==NULL)
	{
		printf("queue underflow\n");
		return;
	}
	temp=f;
	while(temp!=NULL)
	{
		printf("%d",temp->data);
		temp=temp->next;
	}
}
void count()
{
	printf("no.of elements=%d",c);
}
void main()
{
	int opt;
	do
	{
		printf("enter 1.insert 2.delete 3.display 4.count 5.exit\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:insert();
			       break;
			case 2:del();
			       break;
			case 3:display();
			       break;
			case 4:count();
			       break;
		}
	}while(opt!=5);
}
