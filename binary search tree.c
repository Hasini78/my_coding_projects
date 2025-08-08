#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *lc,*rc;
}*root,*par,*loc;
void insert(int d)
{
	struct node *nn,*temp,*p;
	nn=(struct node*)malloc(sizeof(struct node));
	nn->data=d;
	nn->rc=NULL;
	nn->lc=NULL;
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
			if(d>temp->data)
			{
				temp=temp->rc;
			}
			else
			    temp=temp->lc;
		}
		if(d>p->data)
		{
			p->rc=nn;
		}
		else
		{
			p->lc=nn;
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
void search(int key)
{
	struct node *temp,*p;
	temp=root;
	if(temp==NULL)
	{
		printf("empty tree\n");
		return;
	}
	while(temp!=NULL)
	{
		p=temp;
		if(temp->data<key)
		   temp=temp->rc;
		else if(temp->data>key)
		   temp=temp->lc;
		else if(temp->data==key)
		   break;
	}
	par=p;
	loc=temp;
}
void del(int key)
{
	search(key);
	if(loc==NULL)
	{
		printf("element not found\n");
		return;
	}
	else if(loc==root&& loc->lc==NULL&& loc->rc==NULL)
	{
		root=NULL;
	}
	else if(loc->rc!=NULL && loc->lc!=NULL)//two children
	{
		del_two_bst();
	}
	else //one child
	{
		del_one_bst();
	}
}
void del_one_bst()
{
	struct node *child;
	if(loc->lc==NULL && loc->rc==NULL)//leaf node
	{
		child=NULL;
	}
	else if(loc->lc!=NULL)//having lc
	{
		child=loc->lc;
	}
	else  //having rc
	{
		child=loc->rc;
	}
	if(par->lc==loc)//checking whether deleting ele is lc or rc of parent
	    par->lc=child;
	else
	    par->rc=child;
}
void del_two_bst()  //inorder successor
{
   struct node *temp,*ip;
   temp=loc->rc;
   ip=loc;
   while(temp->lc!=NULL)
   {
      	ip=temp;
      	temp=temp->lc;
   }
   loc->data=temp->data;
   loc=temp;
   par=ip;
   del_one_bst();	
}
int height(struct node *t)
{   int lh,rh,x;
	if(t==NULL)
	   return -1;
	lh=height(t->lc);
	rh=height(t->rc);
	x=((lh>rh)?lh:rh);
	return x+1;
}
void main()
{
	int op,d,de;
	do
	{
		printf("enter 1.create 2.display 3.getmax 4.getmin 5.height 6.del 7.exit\n");
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
        	case 6:printf("enter the ele u want to del\n");
        	       scanf("%d",&de);
        	       del(de);
        	       break;
        	       
		}
	}while(op!=7);
}
