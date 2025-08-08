#include<stdlib.h>
#include<stdio.h>
#define MAX 30
int h[MAX],n;
void read_CBT()
{
	int ele;
	printf("enter ele, -1 to stop\n");
	while(1)
	{
	  scanf("%d",&ele);
	  if(ele==-1)
	    break;
	  h[++n]=ele;	
	}
	heapify();
}
void heapify()
{
	int i,ele,child;
	for(i=n/2;i>=1;i--)
	{
		ele=h[i];
		child=2*i;
		while(child<=n)
		{
			if(child<n && h[child]<h[child+1])
			     child++;
			if(ele>=h[child])
			     break;
		    h[child/2]=h[child];
		    child=child*2;
		}
		h[child/2]=ele;
	}
}
void insert()
{
	int ele,cur;
	printf("enter ele\n");
	scanf("%d",&ele);
	cur=++n;
	while(cur!=1 && h[cur/2]<ele)
	{
		h[cur]=h[cur/2];
		cur=cur/2;
	}
	h[cur]=ele;
}
int del()
{
	int ele,last,cur,child;
	ele=h[1];
	last=h[n];
	n--;
	cur=1;
	child=2;
	while(child<=n)
	{
		if(child<n && h[child]<h[child+1])
		    child++;
		if(last>=h[child])
		    break;
		h[cur]=h[child];
		cur=child;
		child=child*2;
	}
	h[cur]=last;
	return ele;	
}
void heapsort()
{
    int i, x;
    int original_n = n;   // Save heap size

    for(i = n; i >= 1; i--) //here n-- i.e it is decreasing
    {
        x = del();        // Remove max (from root)
        h[i] = x;         // Place at end of array
    }

    n = original_n;       // Restore heap size if needed
}
void display()
{
	int i;
	if(n==1)
	{
		printf("heap is empty\n");
		return;
	}
	for(i=1;i<=n;i++)
	{
		printf("%d ",h[i]);
	}
}
int main()
{
    int op;
    do
    {
    	printf("Enter 1.Read elements 2.Insert 3.Delete 4.Display 5.Heapsort 6.Exit\n");
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
    		case 5:heapsort();
    		       break;
		}
	}while(op!=6);
}

