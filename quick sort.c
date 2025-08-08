#include<stdio.h>
#include<stdlib.h>
void quicksort(int a[],int lb,int up)
{
	int temp,mid,p,i,j;
	if(lb<up)
	{
		p=a[lb];
		i=lb+1;
		j=up;
		while(i<=j)
		{
			while(a[i]<p)
			{
				i++;
			}
			while(a[j]>p)
			{ 
			    j--;
			}
			if(i<j)
			{
				temp=a[i];
			    a[i]=a[j];
			    a[j]=temp;
			}
		}
	    temp=a[lb];
     	a[lb]=a[j];
    	a[j]=temp;
    	quicksort(a,lb,j-1);
	    quicksort(a,j+1,up);
    }
}
void main()
{
	int a[100],n,i;
	printf("enter n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	quicksort(a,0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
