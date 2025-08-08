#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *lc;
	struct node *rc;
}*root,*q[20];
int f=-1,r=-1;
void insert(struct node *t)
{
	if(r==-1)
	{
		f=0;
		r=0;
	}
	else
	{
		r++;
	}
	q[r]=t;
}
struct node *del()
{
	struct node *t;
	t=q[f];
	if(f==r)
	{
		f=-1;
	    r=-1;
    }
	else
	    f++;
	return t;
}
void create()
{
	struct node *temp,*nn;
	int op;
	if(root==NULL)
	{
		root=(struct node*)malloc(sizeof(struct node));
	    printf("enter value of root node\n");
	    scanf("%d",&root->data);
	    root->lc=NULL;
	    root->rc=NULL;
	    insert(root);
	}
	while(f!=-1)
	{
	    temp=del();
	    printf("do u have lc for %d.Enter 0/1\n",temp->data);
	    scanf("%d",&op);
	    if(op==0)
	        temp->lc=NULL;
	    else
	    {
		    nn=(struct node*)malloc(sizeof(struct node));
	        printf("enter lc value\n");
	        scanf("%d",&nn->data);
	        temp->lc=nn;
	        insert(nn);
	    }
	    printf("do u have rc for %d.Enter 0/1\n",temp->data);
	    scanf("%d",&op);
	    if(op==0)
	        temp->rc=NULL;
	    else
	    {
			nn=(struct node*)malloc(sizeof(struct node));
	        printf("enter rc value\n");
	        scanf("%d",&nn->data);
	        temp->rc=nn;
	        insert(nn);
	    }
    }
}
void inorder(struct node *t)
{
	if(t==NULL)
	    return;
	inorder(t->lc);
	printf("%d ",t->data);
	inorder(t->rc);
}
void preorder(struct node *t)
{
	if(t==NULL)
	    return;
	printf("%d ",t->data);
	preorder(t->lc);
	preorder(t->rc);
}
void postorder(struct node *t)
{
	if(t==NULL)
	    return;
	postorder(t->lc);
	postorder(t->rc);
	printf("%d ",t->data);
}
void main()
{
	int option;
	do
	{
		printf("enter 1.creation 2,inorder 3.preorder 4.postorder 5.exit\n");
	    scanf("%d",&option);
		switch(option)
		{
		  case 1:create();
		         break;
		  case 2:printf("inorder traversal\n");
		         inorder(root);
				 break;
		  case 3:printf("preorder traversal\n");
		         preorder(root);
				 break;
		  case 4:printf("postorder traversal\n");
		         postorder(root);
				 break;	
		}	
	}while(option!=5);
	
}
