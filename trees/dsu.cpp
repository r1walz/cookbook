/*
 * @author Samarth Agarwal
 *
 * Disjoint Set Union (DSU) is a data-structure that provides the 
 * following capabilities:
 * We are given several elements, each of which is a separate set. A DSU will
 * have an operation to combine any two sets, and it will be able to tell in 
 * which set a specific element is. The classical version also introduces a 
 * third operation, it can create a set from a new element.
 * 
 * This implementation uses path compression optimization and Union by size.
 * which gives the final amortized time complexity as O(α(n)), where α(n) is 
 * the inverse Ackermann function, which grows very slowly.
 */

#include <iostream>

using namespace std;

const int N = 100005;
int parent[N], sz[N];

void init(int n) {
	for (int i = 1; i <= n; ++i)
		parent[i] = i, sz[i] = 1;
}

int find(int node) {
	if (node == parent[node])
		return node;
	return parent[node] = find(parent[node]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) {
		if (sz[a] < sz[b]) 
			swap(a, b);

		parent[b] = a;
		sz[a] += sz[b];
	}
}

int main() {
	// This example finds number of connected components in a graph using dsu
	int n = 8;

	init(n);

	// let there be 4 edges 1--2, 2--3, 1--3, 4--5
	merge(1, 2);
	merge(2, 3);
	merge(1, 3);
	merge(4, 5);

	int components = 0;
	for (int i = 1; i <= n; ++i)
		if (i == parent[i])
			components++;

	cout << components << endl;
}