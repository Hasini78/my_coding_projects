#include<stdio.h>
#include<stdlib.h>
#define max 100
int a[max];
void mergesort(int low,int high)
{
	int mid;
	if(low<high)
	{
	  	mid=(low+high)/2;
		mergesort(low,mid);
		mergesort(mid+1,high);
		merge(low,mid,high);	
	}
}
void merge(int low,int mid,int high)
{
	int i,j,h,k,B[max];
	i=low;
	h=low;
	j=mid+1;
	while(h<=mid && j<=high)
	{
		if(a[h]>a[j])
		{
			B[i]=a[j];
			j++;
		}
		else{
			B[i]=a[h];
			h++;
		}
		i++;
	}
	if(h>mid)
	{
		for(k=j;k<=high;k++)
		{
			B[i++]=a[k];
		}
	}
	else
	{
		for(k=h;k<=mid;k++)
		{
			B[i++]=a[k];
		}
	}
	for(k=low;k<=high;k++)
	{
		a[k]=B[k];
	}
}
void main()
{
	int n,i;
	printf("enter n\n");
	scanf("%d",&n);
	printf("enter array elements to sort\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	mergesort(0,n-1);
	printf("after sort\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
