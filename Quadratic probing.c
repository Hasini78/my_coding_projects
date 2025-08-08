#include<stdio.h>
#include<stdlib.h>
int m=10;
int *ht,c=0,cur;
float lf;
void init()
{
	int i;
	ht=(int*)malloc(sizeof(int)*m);
	for(i=0;i<m;i++)
	{
		ht[i]=-1;
	}
}
float loadfactor()
{
	return c/m;
}
void rehash()
{
	int ns,hb,nhb,flag,j,*nht,i;
	ns=2*m;
	for( ; ;ns++)
	{
		for(j=2,flag=0;j<ns/2;j++)
		{
			if(ns%j==0)
			  flag=1;
		}
		if(flag==0)
		   break;
	}
	nht=(int*)malloc(sizeof(int)*ns);
	for(j=0;j<ns;j++)
	{
		nht[j]=-1;
	}
	for(i=0;i<m;i++)
	{
		if(ht[i]==-1)
		   continue;
		hb=ht[i]%ns;
		if(nht[hb]==-1)
		{
			nht[hb]=ht[i];
		}
		else
		{
			for(j=0;j<ns;j++)
			{
				nhb=(hb+j)%ns;
				if(nht[nhb]==-1)
				{
				   nht[nhb]=ht[i];
				   break;
		     	}
			}
		}
	}
	free(ht);
	ht=nht;
	m=ns;
}
void insert(int key)
{
	int hb,i,nhb;
	lf=loadfactor();
	if(lf>0.7F)
	{
		rehash();
	}
	hb=key%m;
	if(ht[hb]==-1)
	{
		ht[hb]=key;
		c++;
	}
	else
	{
		for(i=0;i<m;i++)
		{
			nhb=(hb+i*i)%m;
			if(ht[nhb]==-1)
			{
				ht[nhb]=key;
				c++;
				return;
			}
		}
	}
}
void search(int key)
{
	int i,hb,HB;
	hb=key%m;
	if(ht[hb]!=key)
	{
		for(i=1;i<m;i++)
		{
			HB=(hb+i*i)%m;
			if(ht[HB]==-1)
			{
				printf("not found\n");
				cur=-1;
				break;
			}
			else if(hb==HB)
			{
				printf("not found\n");
				cur=-1;
				break;
			}
			else
			{
				printf("found\n");
				cur=HB;
				break;
			}
		}
	}
	else
	{
		printf("found\n");
		cur=hb;
	}
}
void del(int key)
{
	int i,j,hash,k,temp;
	search(key);
	if(cur==-1)
	  return;
	else
	{
		ht[cur]==-1;
		c--;
		i=(cur+1)%m;
		while(ht[i]!=-1)
		{
			temp=ht[i];
			ht[i]=-1;
			c--;
			hash=temp%m;
			for(j=0;j<m;j++)
			{
				k=(hash+j)%m;
				if(ht[k]==-1)
				{
					ht[k]=temp;
					c++;
					break;
				}
			}
			i=(i+1)%m;
		}
	}
}
void display()
{
	int i;
	for(i=0;i<m;i++)
	{
		printf("[%d]",i);
		printf("%d ",ht[i]);
	}	
}
int main()
{
	int op,key;
	init();
	do
	{
		printf("Enter 1.Insert 2.Display 3.Count 4.Search 5.Delete 6.Exit\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:printf("Enter key\n");
			       scanf("%d",&key);
			       insert(key);
                   break;
            case 2:display();
                   break;
            case 3:printf("no.of elements is %d\n",c);
                   break;
            case 4:printf("Enter key\n");
			       scanf("%d",&key);
			       search(key);
                   break;
			case 5:printf("Enter key\n");
			       scanf("%d",&key);
			       del(key);
			       break;
			        
		}
	}while(op!=6);
	return 0;
}

