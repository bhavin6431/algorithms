#include <bits/stdc++.h>

using namespace std;
int c = 0;
void dfs(int u, vector<vector<int>> &adj, vector<bool> &visited) {
	c++;
	visited[u] = true;
	for(int ne : adj[u]) {
		if(!visited[ne]) {
			dfs(ne, adj, visited);
		}
	}
}

int main() {
	int n, m, u, v;
	cin >>  n >> m;
	vector<vector<int>> adj(n + 1);
	vector<bool> visited(n+1, false);
	for(int i=0;i<m;i++) {
		cin >> u;
		cin >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}	
	int x;
	cin >> x;
	dfs(x, adj, visited);
	cout << n - c;
	return 0;
}