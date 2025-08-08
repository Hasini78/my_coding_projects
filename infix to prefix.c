#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 10
int top=-1;
char STACK[MAX];
void push(char op)
{
	top++;
	STACK[top]=op;
}
char pop()
{
	return(STACK[top--]);
}
int prec(char op)
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
void intopre(char Q[])
{
	char p[30];
	int i,j=0;
	push(')');
	strrev(Q);
	strcat(Q,"(");
	for(i=0;Q[i]!='\0';i++)
	{
	    if(isalpha(Q[i]))
	      p[j++]=Q[i];
		else if(Q[i]==')')
		  push(Q[i]); 
	    else if(Q[i]=='(')
	      { while(STACK[top]!=')')
		      p[j++]=pop();
	        pop();
	      }
	    else 
		  { while(prec(STACK[top])>prec(Q[i]))
	          p[j++]=pop();
	        push(Q[i]);
	      }
    }
	p[j]='\0';
	strrev(p);
	printf("prefix statement=%s",p);
}
void main()
{
	char infix[199];
	printf("enter infix stat");
	scanf("%s",infix);
	intopre(infix);
}
