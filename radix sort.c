#include<stdio.h>
#include<stdlib.h>
void radixsort(int a[],int n)
{
	int i,j,k,large,dig=0,pass,bucket_unit[10],bucket[10][n],rem,div=1;
	large=a[0];
	for(i=0;i<n;i++)
	{
		if(a[i]>large)
		{
			large=a[i];
		}
	}
	while(large>0)
	{
		dig++;
		large/=10;
	}
	for(pass=0;pass<dig;pass++)
	{
		for(j=0;j<10;j++)
		{
			bucket_unit[j]=0;
	    }
			for(i=0;i<n;i++)
			{
				rem=(a[i]/div)%10;
				bucket[rem][bucket_unit[rem]]=a[i];
				bucket_unit[rem]++;
			}
			i=0;
			for(k=0;k<10;k++)
			{
				for(j=0;j<bucket_unit[k];j++)
				{
					a[i]=bucket[k][j];
					i++;
				}
			}
			div=div*10;
		}
}
void main()
{
	int a[10],n,i;
	printf("enter n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	radixsort(a,n);
	printf("after sorting\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
