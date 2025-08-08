#include<stdio.h>
int c=0;
struct node
{
	int data;
	struct node* next;
}*first,*last,*temp;
void create()
{
	struct node *nn;
	int data;
	while(1)
	{
		printf("enter data to insert, enter -1 to stop\n");
		scanf("%d",&data);
		if(data==-1)
		  break;
		nn=(struct node*)malloc(sizeof(struct node));
		nn->data=data;
		nn->next=0;
		c++;
		if(first==0)
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
void display()
{
	if(first==0)
	  printf("list is empty\n");
	temp=first;
	while(temp!=0)
	{
		printf("%d ",temp->data);
		printf("%p\n",temp->next);
		temp=temp->next;
	}
}
void count()
{
	printf("%d",c);
}
void insertb()
{
	struct node *nn;
	nn=(struct node*)malloc(sizeof(struct node));
	c++;
	printf("enter data to be inserted");
	scanf("%d",&nn->data);
	nn->next=first;
	first=nn;
}
void inserte()
{   int ele;
	struct node *nn;
	while(1)
	{
		printf("enter data to insert, enter -1 to stop\n");
		scanf("%d",&ele);
		if(ele==-1)
		  break;
		nn=(struct node*)malloc(sizeof(struct node));
		c++;
	    nn->data=ele;
	    nn->next=0;
	    last->next=nn;
	    last=nn;
	}
}
void insertp()
{
	int i=1,pos;
	struct node *nn,*temp;
	printf("enter position");
	scanf("%d",&pos);
	if(pos>count)
	{
		printf("invalid position");
	}
	else
	{
		temp=first;
		while(i<pos)
		{
			temp=temp->next;
			i++;
		}
		nn=(struct node*)malloc(sizeof(struct node));
		c++;
		printf("enter data to be inserted");
		scanf("%d",&nn->data);
		nn->next=temp->next;
		temp->next=nn;
	}
	
}
void delb()
{
	struct node *temp;
	temp=first;
	if(first==0)
	{
		printf("linked list is empty");
	}
	else
	{   printf("deleted data is %d",first->data);
		first=first->next;
	    free(temp);
	}
	c--;
}
void dele()
{  
	struct node *temp;
	printf("deleted data is %d",last->data);
	temp=first;
	while(temp->next!=last)
	{
		temp=temp->next;
	}
	free(last);
	last=temp;
	last->next=0;
	c--;
}
void delp()
{
	struct node *nextn,*temp;
	int pos,i=1;
	temp=first;
	printf("enter position");
	scanf("%d",&pos);
	while(i<pos-1)
	{
		temp=temp->next;
		i++;
	}
	nextn=temp->next;
	temp->next=nextn->next;
	free(nextn);
}
void main()
{
	int op;
	do
	{
		printf("enter op 1.creation 2.display 3.count 4.insertb 5.inserte 6.insertp 7.delb 8.dele 9.delp 10.exit\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:create();
			       break;
			case 2:display();
			       break;
			case 3:count();
			       break;
			case 4:insertb();
			       break;
			case 5:inserte();
			       break;
			case 6:insertp();
			       break;
			case 7:delb();
			       break;
			case 8:dele();
			       break;
			case 9:delp();
			       break;        
		}
		
	}while(op!=10);
}
