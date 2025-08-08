#include<stdio.h>
#include<ctype.h>
#include<math.h>
#define MAX 10
int top=-1;
char STACK[MAX];
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
		    printf("enter the value of char");
		    scanf("%d",&some);
		    push(some);
		  }
		else 
		{
		   a=pop();
		   b=pop();
		   switch(p[i])
		   {
		   	 case '+':push(b+a);
		   	          break;
		   	 case '-':push(b-a);
		   	          break;
		   	 case '*':push(b*a);
		   	          break;
		   	 case '/':push(b/a);
		   	          break;
		   	 case '%':push(b%a);
		   	          break;
		   	 case '^':push(pow(b,a));
		   	          break;
		   }	
		}
	}
	printf("postfix evaluated value= %d",STACK[top]);
}
void main()
{
	char post[30];
	printf("enter postfix statement");
	scanf("%s",post);
	eval(post);
}
