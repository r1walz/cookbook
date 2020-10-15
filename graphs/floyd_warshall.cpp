/*
 * @author Samarth Agarwal
 *
 * Floyd-Warshall is an algorithm that finds the shortest distance
 * between each pair of nodes in a graph. It uses dynamic programming
 * to accomplish this task.
 *
 * Time Complexity: O(n^3)
 * Space Complexity: O(n^2)
 */

#include <iostream>

using namespace std;

const int N = 505;
const int INF = 1000000007;

int graph[N][N], dist[N][N];

void floyd_warshall(int n) {
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			dist[i][j] = graph[i][j];

	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				if (dist[i][k] + dist[k][j] < dist[i][j])  
                    dist[i][j] = dist[i][k] + dist[k][j];
}

int main() {
	int n;
	cin >> n;

	// First we initialize the graph with some arbitirarily high value
	// and 0 for case when i == j
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			graph[i][j] = (i == j) ? 0 : INF;

	int edges;
	cin >> edges;

	for (int i = 1; i <= edges; ++i) {
		int u, v, weight;
		cin >> u >> v >> weight;

		graph[u][v] = graph[v][u] = weight;
	}

	floyd_warshall(n);

	int start, end;
	cin >> start >> end;

	cout << dist[start][end] << endl;
}