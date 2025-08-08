#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int S[10],top=-1,V;
int graph[MAX][MAX],visited[MAX];
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
void push(int v)
{
	top++;
	S[top]=v;
}
int pop()
{
	int v;
	v=S[top];
	top--;
	return v;
}
void DFS()
{
	int s,i;
	init();
	printf("enter starting node\n");
	scanf("%d",&s);
	push(s);
	visited[s]=0;
	while(top!=-1)
	{
		s=pop();  //recently visited
		printf("%d ",s);
		visited[s]=1;
		for(i=0;i<V;i++)
		{
			if(graph[s][i]==1 && visited[i]==-1)
			{
				push(i);
				visited[i]=0;
			}
		}
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
		printf("enter 1.Insertedge 2.Deledge 3.DFS 4.Display 5.Exit\n");
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
			case 3:DFS();
			       break;
			case 4:display();
			       break;
		}
	}while(op!=5);
}

