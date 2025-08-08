#include<stdio.h>
#include<stdlib.h>
#define SIZE 11
struct node
{
	int data;
	struct node *next;
}*HT[SIZE];
int c=0,key;
struct node *cur,*pre;
void init()
{
	int i;
	for(i=0;i<SIZE;i++)
	{
		HT[i]=NULL;
	}
}
void insert(int key)
{
	int hb;
	struct node *nn,*temp;
	hb=key%SIZE;
	nn=(struct node*)malloc(sizeof(struct node));
	nn->data=key;
	nn->next=NULL;
	if(HT[hb]==NULL)
	{
		HT[hb]=nn;
	}
	else
	{
		temp=HT[hb];
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=nn;
	}
	c++;
}
void search(int key)
{
	int hb;
	struct node *temp;
	cur=NULL;
	pre=NULL;
	hb=key%SIZE;
	if(HT[hb]==NULL)
	{
		printf("element not found\n");
	}
	else
	{
		temp=HT[hb];
		while(temp!=NULL)
		{
			if(temp->data==key)
			{
				printf("element found\n");
				break;
			} 
			pre=temp;
			temp=temp->next;
		}
		cur=temp;
		if(temp==NULL)
		{
			printf("element not found\n");
		}
	}
}
void del(int key)
{
	int hb;
	hb=key%SIZE;
	struct node *temp;
	search(key);
	if(cur==NULL)
	{
		return;
	}
	else
	{
		if(cur==HT[hb]) //front deletion
		{
			temp=cur;
			HT[hb]=cur->next;
		}
		else if(cur->next==NULL) //end deletion
		{
			temp=cur;
			pre->next=NULL;
		}
		else //middle del
		{
			temp=cur;
			pre->next=temp->next;
		}
	}
	free(temp);
	c--;
}
void display()
{
	int i;
	struct node *temp;
	for(i=0;i<SIZE;i++)
	{
		printf("[%d]",i);
		temp=HT[i];
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}
void main()
{
	int op;
	do
	{
		printf("Enter 1.Insertion 2.Display 3.Search 4.Count 5.Deletion\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:printf("enter key\n");
			       scanf("%d",&key);
			       insert(key);
			       break;
			case 2:display();
			       break;
			case 3:printf("enter key\n");
			       scanf("%d",&key);
			       search(key);
			       break;
			case 4:printf("No.of elements=%d\n",c);
		           break;
		    case 5:printf("enter key\n");
			       scanf("%d",&key);
			       del(key);
		           break;
		}
	}while(op!=6);
}
