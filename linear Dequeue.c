#include<stdio.h>
#define MAX 5
int f=-1,r=-1;
int DQ[MAX];
void finsert()
{   
    int ele;
    printf("enter element to be inserted");
    scanf("%d",&ele); 
	if(f==0)
	  {
       printf("DQ is full\n");
	   return;
      }
	else if(f==-1)
	  {
	   f=0;
	   r=0;
	   DQ[f]=ele;
      }
	else 
	  {
	   f--;
	   DQ[f]=ele;
      }
}
void rinsert()
{
	int ele;
    printf("enter element to be inserted");
    scanf("%d",&ele); 
    if(r==MAX-1)
      {
	   printf("DQ is full\n");
       return;
      }
    else if(r==-1)
      {
	   r=0;
       f=0;
       DQ[r]=ele;
      }
    else 
      {
	   r++;
       DQ[r]=ele;
      }
}
void fdel()
{   int ele;
	if(f==-1)
	  {
	   printf("DQ is empty\n");
	   return;
}
	ele=DQ[f];
	if(f==r)
	 {
	   f=-1;
	   r=-1;
     }
	else 
	  ++f;
	printf("deleted element from front is %d\n",ele);
}
void rdel()
{
	int ele;
	if(r==-1)
	  {
	   printf("DQ is empty\n");
	   return;
      }
	ele=DQ[r];
	if(f==r)
	 {
	  f=-1;
	  r=-1;
     }
	else 
	  --r;
	printf("deleted element from rear is %d\n",ele);
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
void rearele()
{
	if(r==-1 && f==-1)
	{
	  printf("empty\n");
	  return;
    }
	else
	  printf("%d\n",DQ[r]);
}
void frontele()
{
	if(r==-1 && f==-1)
	 {
	  printf("empty\n");
	  return;
     }
	else
	  printf("%d\n",DQ[f]);
}
void display()
{   int i;
	if(f==-1 && r==-1)
	{
	  printf("empty");
	  return;
    }
	else
	 {
	   for(i=f;i<=r;i++)
	    {
		  printf("%d\n",DQ[i]);
	    }
	 }
}
void main()
{
	int option;
	do
	{
	printf("enter option 1.finsert 2.rinsert 3.fdel 4.rdel 5.count 6.fele 7.rele 8.display 9.exit\n");
	scanf("%d",&option);
	switch(option)
	{
		case 1:finsert();
		       break;
		case 2:rinsert();
		       break;
		case 3:fdel();
		       break;
		case 4:rdel();
		       break;
		case 5:printf("count=%d",count());
		       break;
		case 6:frontele();
		       break;
		case 7:rearele();
		       break;
		case 8:display();
		       break;
	}
}while(option!=9);
	
}
