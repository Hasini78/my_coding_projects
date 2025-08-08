#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define MAX 10
int top=-1;
int STACK[MAX];
void push(int ele)
{
	top++;
	STACK[top]=ele;
}
int pop()
{
	return(STACK[top--]);
}
void eval(char p[])
{
	int i,some,a,b;
	for(i=0;p[i]!='\0';i++)
	{
		if(isalpha(p[i]))
		  {
		   printf("enter value of char");
		   scanf("%d",&some);
		   push(some);
	      }
		else 
		  {
		    a=pop();
		  	b=pop();
		  	switch(p[i])
		  	{
		  	  case'+':push(a+b);
				      break;
		      case'-':push(a-b);
			          break;
			  case'*':push(a*b);
			          break;
			  case'/':push(a/b);
			          break;
			  case'%':push(a%b);
			          break;
			  case'^':push(pow(a,b));
			          break;		   	
			}
		  }
	}
	printf("evaluated value=%d",STACK[top]);
}
void main()
{
	char prefix[30];
	printf("enter prefix char");
	scanf("%s",prefix);
	strrev(prefix);
	eval(prefix);
}


