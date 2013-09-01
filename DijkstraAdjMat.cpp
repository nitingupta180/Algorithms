#include <iostream>

using namespace std;

// Function to find vertex with minimum distance value
int minDistance(int dist[], bool visited[], int V) {
	int min = INT_MAX, minIndex;

	for(int v = 0; v < V; v++) {
		if(visited[v] == false && dist[v] <= min) {
			min = dist[v];
			minIndex = v;
		}
	}
	return minIndex;
}

// Function to print solution
void printSolution(int dist[], int V) {
	cout << "Vertex distance from source" << endl;
	for(int v = 0; v < V; v++) {
		cout << v << " - " << dist[v] << endl;
	}
}

// Function to implement dijkstra using adjacency matrix
void dijkstra(int graph[][9], int src, int V) {
	int* dist = (int*) malloc(sizeof(int) * V);
	bool* visited = (bool*) malloc(sizeof(bool) * V);
	for(int i = 0; i < V; i++) {
		dist[i] = INT_MAX;
		visited[i] = false;
	}

	dist[src] = 0;

	for(int count = 0; count < V - 1; count++) {
		int u = minDistance(dist, visited, V);
		visited[u] = true;
		for(int v = 0; v < V; v++) {
			if(!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
				dist[v] = dist[u] + graph[u][v];
			}
		}
	}
	printSolution(dist, V);
}

// Function to allocate memory to 2D array
int** my2Dalloc(int R, int C) {
	int i;
	int header = R * sizeof(int*);
	int data = R * C * sizeof(int);
	int** rowPtr = (int**) malloc(header + data);
	if(rowPtr == NULL) {
		return NULL;
	}

	int* buf = (int*) (rowPtr + R);
	for(int i = 0; i < R; i++) {
		rowPtr[i] = buf + i * C;
	}
	return rowPtr;
}

int main() {
	int V, E, i, j, k;
	cin >> V >> E;
	/*int** graph = my2Dalloc(V, V);
	while(E--) {
		cin >> i >> j >> k;
		graph[i-1][j-1] = k;
		graph[j-1][i-1] = k;
	}*/
	int graph[9][9] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 0, 10, 0, 2, 0, 0},
                      {0, 0, 0, 14, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
	dijkstra(graph, 0, V);
	free(graph);
}

/*
9 14
1 2 4
1 8 9
2 8 11
8 7 1
8 9 7
2 3 8
3 9 2
9 7 6
7 6 2
3 6 4
3 4 7
4 6 14
6 5 10
4 5 9

*/
