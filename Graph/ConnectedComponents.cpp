#include <bits/stdc++.h>

using namespace std;

void dfs(int i, vector<vector<int>> adj, vector<int> &visited) {
	visited[i] = true;
	for(int to : adj[i]) {
		if(!visited[to]) {
			dfs(to, adj, visited);
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n+1);
	for(int i=0;i<m;i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> visited(n+1);

	int c = 0;
	for(int i=1;i<=n;i++) {
		if(!visited[i]) {
			dfs(i, adj, visited);
			c++;
		}
	}

	cout << c;
	return 0;
}