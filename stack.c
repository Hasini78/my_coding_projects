#include<stdio.h>
#define MAX 5
int STACK[MAX],top=-1;
enum bool{false,true};
enum bool isempty()
{
	if(top==-1)
	 return true;
	else 
	 return false;
}
enum bool isfull()
{
	if(top==MAX-1)
	 return true;
	else 
	 return false;
}
void push(int item)
{
	if(isfull())
	{
		printf("stack overflow\n");
		return ;
	}
	top++;
	STACK[top]=item;
}
int pop()
{   int temp;
	if(isempty())
	 {
	  printf("stack underflow");
	  return -1;
}
temp=STACK[top];
top--;
return temp;	 
}
int peek()
{
	if(isempty())
	{
		printf("stack underflow\n");
		return -1;
	}
	return(STACK[top]);
}
void display()
{
	int i;
	if(isempty())
	{
		printf("underflow");
		return;
	}
	for(i=top;i>=0;i--)
	{
		printf("%d",STACK[i]);
	}
}
int count()
{
	return top+1;
}
void main()
{
	int item,option;
	do{
		printf("enter 1.push 2.pop 3.display 4.count 5.peek 6.exit\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:printf("enter item");
			       scanf("%d",&item);
			       push(item);
			       break;
			case 2:item=pop();
			       if(item!=-1)
			        printf("deleted element is %d",item);
			    break;
			case 3:display();
			       break;
			case 4:item=count();
			       printf("no of elements is%d",item);
			       break;
			case 5:item=peek();
			        if(item!=-1)
			         printf("top element is%d",item);
			        break;
		}
	}while(option!=6);
}
