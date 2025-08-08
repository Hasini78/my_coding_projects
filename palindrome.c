#include<stdio.h>
#include<string.h>
#define MAX 30
int top=-1;
char STACK[MAX];
void push(char ele)
{
	top++;
	STACK[top]=ele;
}
char pop()
{
	return STACK[top--];
}
void main()
{
	char s1[30],s2[30];
	int i,len=0;
	printf("enter string 1\n");
	scanf("%s",s1);
	for(i=0;s1[i]!='\0';i++)
	{
		push(s1[i]);
		len++;
	}
	i=0;
	while(i<=len)
	{
		s2[i++]=pop();
	}
	if(strcmp(s1,s2)==0)
	  printf("yes");
	else 
	  printf("no");
	
}
