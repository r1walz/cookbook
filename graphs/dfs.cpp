/*
 * @author Tanmaya Khandelwal
 *
 * Algorithmm to print the depth first search of the given graph.
 
 * Time Complexity: O(nodes)
 * Space Complexity: O(edges)
 */
 
# include <bits/stdc++.h>
using namespace std;

const int N = 100005;
bool vis[N]; // keep track of all visited nodes


// Function to print depth first search of the given graph with a given root
void dfs(vector<int> graph[], int root){
	cout<<root<<endl;
	vis[root] = 1;
	
	for(int x = 0; x<graph[root].size();x++)
		if(!vis[graph[root][x]])
			dfs(graph,graph[root][x]);
}

int main(){
	int nodes,edges,root;
	cin>>nodes>>edges>>root;
	
	// Adjacency List to store the graph
	vector<int> graph[nodes+1];
	
	for(int i=0;i<edges;i++){
		int x,y;
		cin>>x>>y;
		
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	
	dfs(graph,root);  
	
}

