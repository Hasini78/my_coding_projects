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
}
void display()
{
	struct node *temp;
	if(first==NULL)
	{
		printf("list is empty\n");
		return;
	}
	temp=first;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
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
		       break;
	}
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
		case 3:while(temp->next->next!=NULL)
		        {
				 temp=temp->next;
			    }
		       temp->next=NULL;
		       printf("%d",last->data);
		       free(last);
		       last=temp;
		       break;
	}
	c--;
}
void reverse() //without using stack
{
	struct node *t1,*t2;
	if(first==NULL)
	{
		printf("list is empty\n");
		return;
	}
	t1=first->next;
	t2=t1->next;
	first->next=NULL;
	last=first;
	while(t2!=NULL)
	{
		t1->next=first;
		first=t1;
		t1=t2;
		t2=t1->next;
	}
	t1->next=first;
	first=t1;
}
void lisearch()
{   
    int d,flag=0;
    struct node *temp;
	temp=first;
	if(temp==NULL)
	{
		printf("list is empty");
		return;
	}
	printf("enter data to be searched\n");
	scanf("%d",&d);
	while(temp!=NULL)
	{
		if(temp->data==d)
		{
			flag=1;
			break;
		}
		else
		{
			temp=temp->next;
		}
	}
	if(flag==0)
	{
		printf("data is not found\n");
	}
	else
	{
		printf("data found\n");
	}
	
}
void sort() //sorting using nested loop
{
	struct node *t1,*t2;
	int t;
	for(t1=first;t1!=NULL;t1=t1->next)
	{
		for(t2=t1->next;t2!=NULL;t2=t2->next)
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
void sorts() //sorting using single loop
{
	struct node *temp,*t1;
	temp=first;
	while(temp->next!=NULL)
	{
		if(temp->data>temp->next->data)
		{
			t1=temp->data;
			temp->data=temp->next->data;
			temp->next->data=t1;
			
			temp=first; //restart from first after each swap
		}
		else
		{
			temp=temp->next;
		}
	}
}
int main()
{
	int op;
	do
	{
		printf("enter op 1.creation 2.display 3.count 4.insert 5.delete 6.reverse 7.sort 8.lisearch 9.sorts 10.exit\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:create();
			       break;
			case 2:display();
			       break;
			case 3:count();
			       break;
			case 4:insert();
			       break;
			case 5:del();
			       break;
			case 6:reverse();
			       break; 
		    case 7:sort();
			       break;  
			case 8:lisearch();
			       break;
			case 9:sorts();
			       break;     
		}
		
	}while(op!=10);
}
