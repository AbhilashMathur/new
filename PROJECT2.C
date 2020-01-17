
#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<time.h>
#define INFINITY 9999
#define MAX 20

void dijkstra(int G[MAX][MAX],int n,int startnode);
int a,b,u,v,n,i,j,ne=1;
int visited[10]={0},min,mincost=0,cost[10][10];
void main()
{
	clock_t starting_time,finishing_time;
	int i,j,total_cost;
	int G[MAX][MAX],n,u;
	int ch;
	starting_time=clock();
	finishing_time=clock();
	clrscr();
	printf("\nStarting time:\t%ld",starting_time);
	printf("________________________________________________________________________________");
	printf("\n\tPROGRAM FOR COMPUTING SHORTEST PATH AND MINIMUM SPANNING TREE IN A GRAPH");
	printf("________________________________________________________________________________");
	printf("\n\n1.Dijkstra algorithm for computing shortest path in a graph");
	printf("\n2.Prim's algorithm for minimum spanning tree of a graph");
	printf("\n3.Exit");
	do
	{
	printf("\n\nEnter your choice(1-3):");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: //FOR DIJKSTRA
			printf("\n\nEnter no. of vertices:");
			scanf("%d",&n);
			printf("\nEnter the adjacency matrix:\n");
			for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&G[i][j]);

			printf("\nEnter the starting node:");
			scanf("%d",&u);
			dijkstra(G,n,u);
			break;

		case 2: //FOR PRIM'S
			printf("\nEnter the number of nodes:");
			scanf("%d",&n);
			printf("\nEnter the adjacency matrix:\n");
			for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
			{
				scanf("%d",&cost[i][j]);
				if(cost[i][j]==0)
				cost[i][j]=999;
			}
			visited[1]=1;
			printf("\n");
			while(ne < n)
			{
				for(i=1,min=999;i<=n;i++)
				for(j=1;j<=n;j++)
				if(cost[i][j]< min)
				if(visited[i]!=0)
				{
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
				if(visited[u]==0 || visited[v]==0)
				{
					printf("\n Edge %d:(%d %d) cost:%d",ne++,a,b,min);
					mincost+=min;
					visited[b]=1;
				}
				cost[a][b]=cost[b][a]=999;
			}
			printf("\n Minimun cost=%d",mincost);
			break;

		case 3: exit(0);
			break;

		default: printf("\nWrong choice!!");
			 break;
	}
	}while(ch!=0);
	printf("\nEnding time:\t%ld",finishing_time);
	printf("\nExecution time:\t%ld\n",finishing_time-starting_time);
	getch();
}

void dijkstra(int G[MAX][MAX],int n,int startnode)
{

	int cost[MAX][MAX],distance[MAX],pred[MAX];
	int visited[MAX],count,mindistance,nextnode,i,j;

	//pred[] stores the predecessor of each node
	//count gives the number of nodes seen so far
	//create the cost matrix
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(G[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=G[i][j];

	//initialize pred[],distance[] and visited[]
	for(i=0;i<n;i++)
	{
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}

	distance[startnode]=0;
	visited[startnode]=1;
	count=1;

	while(count<n-1)
	{
		mindistance=INFINITY;

		//nextnode gives the node at minimum distance
		for(i=0;i<n;i++)
			if(distance[i]<mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}

			//check if a better path exists through nextnode
			visited[nextnode]=1;
			for(i=0;i<n;i++)
				if(!visited[i])
					if(mindistance+cost[nextnode][i]<distance[i])
					{
						distance[i]=mindistance+cost[nextnode][i];
						pred[i]=nextnode;
					}
		count++;
	}

	//print the path and distance of each node
	for(i=0;i<n;i++)
		if(i!=startnode)
		{
			printf("\nDistance of node%d=%d",i,distance[i]);
			printf("\nPath=%d",i);

			j=i;
			do
			{
				j=pred[j];
				printf("<-%d",j);
			}while(j!=startnode);
	}
}
