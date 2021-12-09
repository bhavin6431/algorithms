#include <bits/stdc++.h>

using namespace std;

bool isSafe(int n, vector<int> adj[], vector<int> &color, int curr, int currColor) {
	for(int ne : adj[curr]) {
		if(color[ne] == currColor) {
			return false;
		}
	}
	return true;
}


bool canColorGraph(vector<int> adj[], int n, int m, vector<int> &color, int curr) {
	if(curr == n) {
		return true;
	}
	for(int i=1;i<=m;i++) {
		if(isSafe(n, adj, color, curr, i)) {
			color[curr] = i;
			if(canColorGraph(adj, n, m, color, curr+1)) {
				return true;
			}
			color[curr] = 0;
		}
	}
	return false;
}

bool graphColoring(bool graph[101][101], int m, int V) {
	vector<int> adj[V];
	vector<int> color(V, 0);
	for(int i=0;i<V;i++) {
		for(int j=0;j<V;j++) {
			if(graph[i][j]) {
				adj[i].push_back(j);
			}
		}
	}

	return canColorGraph(adj , V, m, color, 0);
}

int main() {
	int n, m, u, v, e;
	cin >> n >> m >> e;

	vector<int> adj[n];
	vector<int> color(n, 0);
	
	for(int i=0;i<e;i++) {
		cin >> u >> v;
		adj[u - 1].push_back(v - 1);
		adj[v - 1].push_back(u - 1);
	}

	cout << canColorGraph(adj, n, m, color, 0);

	return 0;
}