#include<stdio.h>
#include<stdlib.h>
#define V 10
int Q[10],f=-1,r=-1;
int graph[V][V]={0},visited[V];
void init()
{
	int i;
	for(i=0;i<V;i++)
	{
		visited[i]=-1;
	}
}
void insertedge(int i,int j)
{
	graph[i][j]=1;
	graph[j][i]=1;
}
void deledge(int i,int j)
{
	graph[i][j]=0;
	graph[j][i]=0;
}
void insert(int v)
{
	if(f==-1)
	{
		f=0;
		r=0;
	}
	else
	{
		r++;
	}
	Q[r]=v;
}
int del()
{
	int v;
	v=Q[f];
	if(f==r)
	{
		f=-1;
		r=-1;
	}
	else
	{
		f++;
	}
	return v;
}
void BFS()
{
	int s,i;
	init();
	printf("enter starting node\n");
	scanf("%d",&s);
	insert(s);
	visited[s]=0;
	while(f!=-1)
	{
		s=del();  //recently visited
		printf("%d ",s);
		visited[s]=1;
		for(i=0;i<V;i++)
		{
			if(graph[s][i]==1 && visited[i]==-1)
			{
				insert(i);
				visited[i]=0;
			}
		}
		
	}
}
void display()
{
	int i,j;
	for(i=0;i<V;i++)
	{
		for(j=0;j<V;j++)
		{
			printf("%d ",graph[i][j]);
		}
		printf("\n");
	}
}
void main()
{
	int i,op,u,v;
	init();
	printf("enter V");
	scanf("%d",&V);
	do
	{
		printf("enter 1.Insertedge 2.Deledge 3.BFS 4.Display 5.Exit\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:printf("enter 2 vertices\n");
			       scanf("%d %d",&u,&v);
			       insertedge(u,v);
			       break;
			case 2:printf("enter 2 vertices\n");
			       scanf("%d %d",&u,&v);
			       deledge(u,v);
			       break;
			case 3:BFS();
			       break;
			case 4:display();
			       break;
		}
	}while(op!=5);

}

