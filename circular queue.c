#include<stdio.h>
#define MAX 5
int q[MAX];
int f=-1,r=-1;
int isfull()
{
	if((f==0 && r==MAX-1)||f==r+1||((r+1)%MAX==f))
	  {
	   printf("queue overflow");
	   return 1;
      }
	else
	  return 0;
}
int isempty()
{
	if(f==-1 && r==-1)
	  return 1;
	else 
	  return 0;
}
void insert(int x)
{
	if(isfull())
	  return;
	else if(f==-1 && r==-1)
	  {
	  	f=0,r=0;
	  	q[r]=x;
	  }
	else 
	{
		r=(r+1)%MAX;
		q[r]=x;
	}
}
int del()
{
	int x;
	if(isempty())
	  return;
	else if(f==r)
	 {  x=q[f];
	 	f=-1;
	 	r=-1;
	 }
	 else
	 {  x=q[f];
	 	f=(f+1)%MAX;
	 }
	return x;
}
void froele()
{
	if(isempty())
	  return;
	else
	{
		printf("front ele=%d",q[f]);
	}
}
void reaele()
{
	if(isempty())
	  return;
	else 
	  printf("rear ele=%d",q[r]);
}
void display()
{
	int i;
	if(isempty())
	{
	   printf("queue is empty");
	   return;
    }
	i=f;
	do
	{
		printf("%d\n",q[i]);
		i=(i+1)%MAX;
	}while(i!=r);
    printf("%d",q[r]);
}
int count()
{   int c;
	if(r==f)
	 c=1;
	else if(f<r)
	 c=(r-f)+1;
	else if(f>r)
	 c=(MAX-f+r)+1;
	return c;
}
void main()
{
	int opt,x;

	do
	{
		printf("enter 1.insert\n2.delete\n3.display\n4.froele\n5.reaele\n6.count\n7.exit");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:printf("ele to be inserted\n");
			       scanf("%d",&x);
			       insert(x);
			       break;
			case 2:printf("element to be deleted=%d",del());
			       break;
			case 3:display();
			       break;
			case 4:froele();
			       break;
			case 5:reaele();
			       break;
			case 6:printf("no of elements=%d",count());
			       break;
		}
	}while(opt!=7);
}
