#include<stdio.h>
void towers(int n,char a,char b,char c)
{
	if(n==1)
	  {
	   printf("move %d disk %c to %c\n",n,a,c);
      }
	else 
	  {
	   towers(n-1,a,c,b);
	   printf("move %d disk %c to %c\n",n,a,c);
	   towers(n-1,b,a,c);
      }
}
void main()
{
	int n;
	printf("enter n");
	scanf("%d",&n);
	towers(n,'a','b','c');
}
