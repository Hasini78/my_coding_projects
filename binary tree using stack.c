#include<stdlib.h>
#include<stdio.h>
struct node
{
	int data;
	struct node *lc;
	struct node *rc;
}*root,*stack[20];
int top=-1;
void push(struct node *t)
{
	top++;
	stack[top]=t;
}
struct node* pop()
{
	struct node *t;
	t=stack[top];
	top--;
	return t;
}
void create()
{
	struct node *temp,*nn;
	if(root==NULL)
	{
		root=(struct node*)malloc(sizeof(struct node));
		printf("enter value of root node\n");
		scanf("%d",&root->data);
		root->lc=NULL;
		root->rc=NULL;
	}
	temp=root;
	while(1)
	{   
	    int op;
		printf("do u have a rc for %d.Enter 0/1\n",temp->data);
		scanf("%d",&op);
		if(op==1)
		{
		    nn=(struct node*)malloc(sizeof(struct node));
		    printf("enter rc value\n");
		    scanf("%d",&nn->data);
		    nn->lc=NULL;
		    nn->rc=NULL;
		    temp->rc=nn;
		    push(nn);
		    
	    }
	    printf("do u have lc for %d.Enter 0/1\n",temp->data);
	    scanf("%d",&op);
	    if(op==1)
		{
	    	nn=(struct node*)malloc(sizeof(struct node));
		    printf("enter lc value\n");
		    scanf("%d",&nn->data);
		    nn->lc=NULL;
		    nn->rc=NULL;
		    temp->lc=nn;
		    temp=temp->lc;
	    }
	    else
	    {   
		    if(top!=-1)
		    {
		    	temp=pop();
			}
			else
			    return;
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
