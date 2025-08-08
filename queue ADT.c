#include<stdio.h>
#define MAX 5
int queue[MAX];
int f=-1,r=-1;
int isfull()
{
	if(r==MAX-1)
	  {
	   printf("queue overflow");
      }
	else 
	  return 0;
}
int isempty()
{
	if(r==-1 && f==-1)
	  {
	   printf("queue underflow");
      }
	else 
	  return 0;
}
void insert(int ele)
{
	if(isfull())
	  return;
	else if(f==-1 && r==-1)
	  {
	   f=0;
	   r=0;
	   queue[r]=ele;
      }
	else 
	  {
	   r++;
	   queue[r]=ele;
      }
}
int del()
{   int x;
	if(isempty())
	  return;
	else if(f==r)
	  {
	   x=queue[f];
	   f=-1;
	   r=-1;
      }
	else
	  {
	   x=queue[f];
	   f++;
      }
    return x;
}
void display()
{   int i;
	if(isempty())
	  return;
	else
	  for(i=f;i<=r;i++)
	  {
	  	printf("%d\n",queue[i]);
      }
}
int count()
{
	int c;
	if(r==-1 && f==-1)
	  c=0;
	else
	  c=(r-f)+1;
	return c;
}
void main()
{
	int opt,x;
	do
	{
		printf("enter 1.insert\n 2.delete\n 3.display\n 4.count\n 5.exit");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:printf("element to be inserted\n");
			       scanf("%d",&x);
			       insert(x);
			       break;
			case 2:printf("deleted element is %d\n",del());
			       break;
			case 3:display();
			       break;
		    case 4:printf("no of ele=%d\n",count());
		           break;
		}
		
	}while(opt!=5);
}
