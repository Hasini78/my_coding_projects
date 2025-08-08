 #include<stdio.h>
#include<stdlib.h>
int m=11;
int *HT,c=0,cur;
float lf;
void init()
{
	int i=0;
	HT=(int*)malloc(sizeof(int)*m);
	for(i=0;i<m;i++)
	{
		HT[i]=-1;
	}
}
float loadfactor()
{
	return (float)c/m;
}
void rehash()
{
	int ns,j,i,flag,*nht,hb,nhb;
	ns=2*m;
	for( ; ;ns++)
	{
		for(j=2,flag=0;j<ns/2;j++)
		{
			if(ns%j==0)
			   flag=1;
		}
		if(flag==0)
		{
			break;
		}
	}
	nht=(int*)malloc(sizeof(int)*ns);
	for(j=0;j<ns;j++)
	{
		nht[j]=-1;
	}
	for(i=0;i<m;i++)
	{
		if (HT[i] == -1)
          continue;
		hb=HT[i]%ns;
		if(nht[hb]==-1)
		{
			nht[hb]=HT[i];
		}
		else
		{
		    for(j=0;j<ns;j++)
	     	{
		      nhb=(hb+j)%ns;
			  if(nht[nhb]==-1)
		      {
				nht[nhb]=HT[i];
				break;
			  }
		    }	
		}
	}
	free(HT);
	HT=nht;
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
	if(HT[hb]==-1)
	{
		HT[hb]=key;
		c++;
	}
	else{
		for(i=0;i<m;i++)
		{
			nhb=(hb+i)%m;
			if(HT[nhb]==-1)
			{
				HT[nhb]=key;
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
	if(HT[hb]!=key)
	{
		for(i=1;i<m;i++)
		{
			HB=(hb+i)%m;
			if(HT[HB]==-1)
              {
              	printf("element not found\n");
              	cur=-1;
				break;
			  }
			else if(HB==hb)
			   {
			   	 printf("element not found\n");
			   	 cur=-1;
			     break;
			   }
			else
			  {
				printf("element found\n");
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
	{
		return;
	}
	else
	{
		HT[cur]=-1;
		c--;
		i=(cur+1)%m;
		while(HT[i]!=-1)
		{
			temp=HT[i];
			HT[i]=-1;
			c--;
			hash=temp%m;
			for(j=0;j<m;j++)
			{
				k=(hash+j)%m;
				if(HT[k]==-1)
				{
					HT[k]=temp;
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
		printf("%d ",HT[i]);
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
