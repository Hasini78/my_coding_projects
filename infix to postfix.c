#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 10
char STACK[MAX];
int top=-1;
void push(char op)
{
	top++;
	STACK[top]=op;
}
char pop()
{   char item;
    item=STACK[top];
    top--;
	return(item);
}
int pre(char op)
{
	if(op=='^')
	 return 3;
	else if(op=='*'||op=='/'||op=='%')
	 return 2;
	else if(op=='+'||op=='-')
	 return 1;
	else 
	 return 0;
}
void intopost(char Q[])
{
	char post[30];
	int i,j=0;
	push('(');
	strcat(	Q,")");
	for(i=0;Q[i]!='\0';i++)
	{
		if(isalpha(Q[i]))
		 post[j++]=Q[i];
		else if(Q[i]=='(')
		 push(Q[i]);
		else if(Q[i]==')')
		 {
		 	while(STACK[top]!='(')
		 	{
		 		post[j++]=pop();
			 }
			 pop();
		 }
		else
		{
			while(pre(STACK[top])>=pre(Q[i]))
			{
				post[j++]=pop();
			}
			push(Q[i]);
		}
	}
post[j]='\0';
printf("the equation after postfix=%s",post);
}
void main()
{
	char infix[30];
	printf("enter infix statement");
	scanf("%s",infix);
	intopost(infix);
}
