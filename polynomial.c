#include<stdio.h>
#include<stdlib.h>
struct node
{
	int coeff;
	int power;
	struct node *next;
};
struct node *create()
{
   struct node *nn,*temp,*first=NULL;
   int op;
   while(1)
   {
     printf("enter 0/1 for creation of node in the polynomial\n");
     scanf("%d",&op);
     if(op==0)
       break;
     nn=(struct node*)malloc(sizeof(struct node));
     printf("enter coeff\n");
     scanf("%d",&nn->coeff);
     printf("enter power");
     scanf("%d",&nn->power);
     nn->next=NULL;
     if(first==NULL)
     {
   	  first=nn;
   	  first->next=NULL;
     }
     else
     {
   	  temp=first;
   	  while(temp->next!=NULL)
   	  {
   	    temp=temp->next;	
	  }
	  temp->next=nn;
     }
     
    }
    return first;
}
void display(struct node *first)
{   
    struct node *temp;
    temp=first;
	if(first==NULL)
	{
		printf("No polynomial\n");
	}
	else
	{
	   while(temp!=NULL)
	   {
	   	 printf("(%dx^%d)",temp->coeff,temp->power);
	   	 temp=temp->next;
	   	 if(temp!=NULL)
	   	   printf(" + ");
	   	 else
	   	   printf("\n");
	   }	
	}
}
struct node *add(struct node *r1,struct node *r2)
{
	struct node *r=NULL,*nn,*temp;
	while(r1!=NULL && r2!=NULL)
	{   
	    nn=(struct node*)malloc(sizeof(struct node));
	    nn->next=NULL;
		if(r1->power==r2->power)
		{
			nn->coeff=r1->coeff+r2->coeff;
			nn->power=r1->power;
			r1=r1->next;
			r2=r2->next;
		}
		else if(r1->power > r2->power)
		{
			nn->coeff=r1->coeff;
			nn->power=r1->power;
			r1=r1->next;
		}
		else if(r1->power < r2->power)
		{
			nn->coeff=r2->coeff;
			nn->power=r2->power;
			r2=r2->next;
		}
		if(r==NULL)
		{
			r=nn;
			temp=r;
		}
		else
		{
			temp->next=nn;
			temp=nn;
		}
	}
	while(r1!=NULL)
	{   
	    nn=(struct node*)malloc(sizeof(struct node));
	    nn->next=NULL;
		nn->coeff=r1->coeff;
		nn->power=r1->power;
		if(r==NULL)
		{
			r=nn;
			temp=r;
		}
		else
		{
			temp->next=nn;
			temp=nn;
		}
		r1=r1->next;
	}
	while(r2!=NULL)
	{
		nn=(struct node*)malloc(sizeof(struct node));
	    nn->next=NULL;
		nn->coeff=r2->coeff;
		nn->power=r2->power;
		if(r==NULL)
		{
			r=nn;
		}
		else
		{
			temp->next=nn;
			temp=nn;
		}
		r2=r2->next;
	}
	return r;
}
struct node *subt(struct node *r1,struct node *r2)
{
	struct node *r=NULL,*nn,*temp;
	while(r1!=NULL && r2!=NULL)
	{   
	    nn=(struct node*)malloc(sizeof(struct node));
	    nn->next=NULL;
		if(r1->power==r2->power)
		{
			nn->coeff=r1->coeff-r2->coeff;
			nn->power=r1->power;
			r1=r1->next;
			r2=r2->next;
		}
		else if(r1->power > r2->power)
		{
			nn->coeff=r1->coeff;
			nn->power=r1->power;
			r1=r1->next;
		}
		else if(r1->power < r2->power)
		{
			nn->coeff=r2->coeff;
			nn->power=r2->power;
			r2=r2->next;
		}
		if(r==NULL)
		{
			r=nn;
			temp=r;
		}
		else
		{
			temp->next=nn;
			temp=nn;
		}
	}
	while(r1!=NULL)
	{   
	    nn=(struct node*)malloc(sizeof(struct node));
	    nn->next=NULL;
		nn->coeff=r1->coeff;
		nn->power=r1->power;
		if(r==NULL)
		{
			r=nn;
			temp=r;
		}
		else
		{
			temp->next=nn;
			temp=nn;
		}
		r1=r1->next;
	}
	while(r2!=NULL)
	{
		nn=(struct node*)malloc(sizeof(struct node));
	    nn->next=NULL;
		nn->coeff=r2->coeff;
		nn->power=r2->power;
		if(r==NULL)
		{
			r=nn;
		}
		else
		{
			temp->next=nn;
			temp=nn;
		}
		r2=r2->next;
	}
	return r;
}
struct node *multi(struct node *r1,struct node *r2)
{
	struct node *r=NULL,*temp,*nn,*temp1,*temp2,*last=NULL;
	for(temp1=r1;temp1!=NULL;temp1=temp1->next)
	{
		for(temp2=r2;temp2!=NULL;temp2=temp2->next)
		{
			nn=(struct node*)malloc(sizeof(struct node));
			nn->coeff=temp1->coeff * temp2->coeff;
			nn->power=temp1->power + temp2->power;
			nn->next=NULL;
			if(r==NULL)
		    {
		    	r=nn;
			    last=nn;
		    }
	     	else
	     	{
			    last->next=nn;
			    last=nn;
		    }
		}
	}
	return r;
}
struct node *sort(struct node *r)
{
	struct node *t1,*t2,*temp;
	for(t1=r;t1!=NULL;t1=t1->next)
	{   temp=t1;
		for(t2=t1->next;t2!=NULL;)
		{   
			if(t1->power==t2->power)
			{
				t1->coeff = t1->coeff + t2->coeff;
				temp->next=t2->next;
				free(t2);
				t2=temp->next;
		    }
		    else
		    {
		    	temp=t2;
		    	t2=t2->next;
			}
		}
	}
	return r;
}
void main()
{   struct node *r1,*r2,*ra,*rs,*rm,*res;
	r1=create();
	display(r1);
	r2=create();
	display(r2);
	ra=add(r1,r2);
	printf("polynomial addition: ");
	display(ra);
	rs=subt(r1,r2);
	printf("polynomial subtraction: ");
	display(rs);
	rm=multi(r1,r2);
	printf("polynomial multiplication: ");
	res=sort(rm);
	display(res);
}
