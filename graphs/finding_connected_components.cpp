/*
 * @author Tanmaya Khandelwal
 *
 * Algorithm to find all the connected components of the given graph.
 
 * Time Complexity: O(nodes)
 * Space Complexity: O(edges)
 */
 
# include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int component[N]; // keep track of all visited nodes and the component number of each node
				
// Function to find the connected components of the given graph
void find_connected_component(vector<int> graph[], int root, int count){
	
	component[root] = count;
	for(int x = 0; x<graph[root].size();x++)
		if(!component[graph[root][x]])
			find_connected_component(graph,graph[root][x],count);
}

int main(){
	int nodes,edges;
	cin>>nodes>>edges;
	
	// Adjacency List to store the graph
	vector<int> graph[nodes+1];
	
	for(int i=0;i<edges;i++){
		int x,y;
		cin>>x>>y;
		
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	
	int count=1; // present component number
	for(int i=1;i<=nodes;i++){
		
		if(!component[i]){
			find_connected_component(graph,i,count);
			count++;
		}
	}
	
	for(int i=1;i<=nodes;i++)
		cout<<"node "<<i<<" is in "<<component[i]<<" component"<<endl;
	
}

