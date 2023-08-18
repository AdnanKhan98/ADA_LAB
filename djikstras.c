#include <limits.h>
#include <stdbool.h>
#include <stdio.h>


int minDistance(int dist[], bool sptSet[],int V)
{
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

void printSolution(int dist[], int V)
{
	printf("Vertex \t\t Distance from Source\n");
	for (int i = 0; i < V; i++)
		printf("%d \t\t\t\t %d\n", i, dist[i]);
}


void dijkstra(int V,int graph[V][V], int src)
{
	int dist[V];

	bool sptSet[V];


	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;


	dist[src] = 0;


	for (int count = 0; count < V - 1; count++) {

		int u = minDistance(dist, sptSet,V);


		sptSet[u] = true;


		for (int v = 0; v < V; v++)


			if (!sptSet[v] && graph[u][v]
				&& dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}


	printSolution(dist,V);
}


int main()
{

	int n;
	printf("Enter the number of vertices:\n");
	scanf("%d",&n);
	int graph[n][n];
	printf("Enter the cost matrix of the graph:\n");
	for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }


	dijkstra(n,graph, 0);

	return 0;
}
