#include<stdio.h>
#include<stdlib.h>
#define max 30
int h[max];
int n;
void read_CBT()
{
	int ele;
	printf("enter element,-1 to stop\n");
	while(1)
	{
		scanf("%d",&ele);
		if(ele==-1)
		  break;
		h[++n]=ele;
	}
	heapify();
}
void heapify() //bottom to top
{
	int i,ele,child;
	for(i=n/2;i>=1;i--)
	{
		ele=h[i];
		child=2*i;
		while(child<=n)
		{
			if(child<n && h[child]<h[child+1]) //checking whether it has right child or not
			//and if exists then checking which child is greater
			   child++;
			if(ele>=h[child])
			    break;
			h[child/2]=h[child];//swapping parent ele with child
			child=child*2; //updating child to child's child
		}
		h[child/2]=ele; //new child's parent
	}
}
void insert() //bottom to top
{
	int ele,curr;
	printf("enter ele to be inserted\n");
	scanf("%d",&ele);
	curr=++n;
	while(curr!=1 && h[curr/2]<ele)
	{
		h[curr]=h[curr/2]; //child is replaced with parent
		curr=curr/2; //parent ele
	}
	h[curr]=ele;
}
void del() //top to bottom
{
	int ele,last,curr,child;
	ele=h[1];
	last=h[n];
	n--;
	curr=1;
	child=2;
	while(child<=n)
	{
		if(child<n && h[child]<h[child+1])
		     child++;
		if(last>=h[child])
		     break;
		h[curr]=h[child]; //top to bottom
		curr=child;
		child=child*2;
	}
	h[curr]=last;
}
void display()
{ 
    int i;
    if (n == 1)
    {
        printf("Heap is empty!\n");
        return;
    }
    printf("Heap elements:\n");
    for (i = 1; i<=n; i++) //first we set the ele and then incre n
        printf("%d ", h[i]); //so here normally n=heap+1
    printf("\n");
}

int main()
{
    int op;
    do
    {
    	printf("Enter 1.Read elements 2.Insert 3.Delete 4.Display 5.Exit\n");
    	scanf("%d",&op);
    	switch(op)
    	{
    		case 1:read_CBT();
    		       break;
    		case 2:insert();
    		       break;
    		case 3:del();
    		       break;
    		case 4:display();
    		       break;
		}
	}while(op!=5);
}

