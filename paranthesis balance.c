#include<stdio.h>
#define MAX 100
int top=-1;
char STACK[MAX];
void push(char op)
{
	top++;
	STACK[top]=op;
}
char pop()
{
	return STACK[top--];
}
void main()
{
	char q[100];
	int i,flag=0;
	printf("enter expression to check");
	scanf("%s",q);
	for(i=0;q[i]!='\0';i++)
	{
		if(q[i]=='('||q[i]=='['||q[i]=='{')
		  push(q[i]);
		else if(q[i]==')'||q[i]==']'||q[i]=='}')
		  if(top==-1||(STACK[top]=='(' && q[i]!=')')||(STACK[top]=='['&&q[i]!=']')||(STACK[top]=='{'&&q[i]!='}'))
	        { printf("invalid");
	          flag=1;
	        }
	      else
	        pop();
	}
	if(top==-1 && flag==0)
	  printf("valid");
	
}
