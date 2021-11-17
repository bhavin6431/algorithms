#include <bits/stdc++.h>

using namespace std;
void dfs(int u, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &path) {
	visited[u] = true;
	for(int ne : adj[u]) {
		if(!visited[ne]) {
			dfs(ne, adj, visited, path);
		}
	}
	path.push_back(u);

}

int main() {
	int n, m, u, v;
	cin >>  n >> m;
	vector<vector<int>> adj(n + 1);
	vector<bool> visited(n+1, false);
	vector<int> path;
	for(int i=0;i<m;i++) {
		cin >> u;
		cin >> v;
		adj[u].push_back(v);
	}	
	for(int i=1;i<=n;i++) {
		if(!visited[i]) {
			dfs(i, adj, visited, path);
		}
	}
	for(int i=path.size() - 1;i >= 0; i--) {
		cout << path[i] << " ";
	}
	return 0;
}