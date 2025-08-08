#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *lc,*rc;
}*root=NULL;
void insert(int key)
{
	struct node *temp,*p,*nn;
	nn=(struct node*)malloc(sizeof(struct node));
	nn->lc=NULL;
	nn->rc=NULL;
	nn->data=key;
	if(root==NULL)
	{
		root=nn;
	}
	else
	{
		temp=root;
		while(temp!=NULL)
		{
			p=temp;
			if(temp->data>key)
			  temp=temp->lc;
			else
			  temp=temp->rc;
		}
		if(p->data>key)
		  p->lc=nn;
		else
		  p->rc=nn;
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
int getmax(struct node *t)
{
	while(t->rc!=NULL)
	  t=t->rc;
	return(t->data);
}
int getmin(struct node *t)
{
	while(t->lc!=NULL)
	  t=t->lc;
	return(t->data);
}
int height(struct node *t)
{   int lh,rh,x;
	if(t==NULL)
	   return -1;
	lh=height(t->lc);
	rh=height(t->rc);
	x=((lh>rh)?lh:rh);
	return x;
}
void main()
{
	int op,d;
	do
	{
		printf("enter 1.create 2.display 3.getmax 4.getmin 5.height 6.exit\n");
        scanf("%d",&op);
        switch(op)
        {
        	case 1:printf("enter data u want to insert\n");
        	       scanf("%d",&d);
        	       insert(d);
        	       break;
        	case 2:inorder(root);
        	       break;
        	case 3:printf("max element of tree=%d\n",getmax(root));
        	       break;
        	case 4:printf("min element of tree=%d\n",getmin(root));
        	       break;
        	case 5:printf("height of tree=%d",height(root));
        	       break;
        	       
		}
	}while(op!=6);
}

