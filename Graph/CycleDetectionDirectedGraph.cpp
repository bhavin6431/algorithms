#include <bits/stdc++.h>

using namespace std;

bool isCycle(int i, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &onstack) {
	if(onstack[i]) {
		return true;
	}

	if(visited[i]) {
		return false;
	}

	visited[i] = true;
	onstack[i] = true;
	for(int ne : adj[i]) {
		if(isCycle(ne, adj, visited, onstack)) {
			return true;
		}
	}

	// take it off the stack
	onstack[i] =false;

	return false;
}

int main() {
	int n, m, u, v;
	cin >>  n >> m;
	vector<vector<int>> adj(n + 1);
	vector<bool> visited(n+1, false);
	vector<bool> onstack(n+1, false);

	for(int i=0;i<m;i++) {
		cin >> u;
		cin >> v;
		adj[u].push_back(v);
	}	
	bool cycleExists = false;
	for(int i=1;i<=n;i++) {
		if(isCycle(i, adj, visited, onstack)) {
			cycleExists = true;
			break;
		}
	}
	if(cycleExists) {
		cout << "Graph contains cycle";		
	} else {
		cout << "Graph does not contain cycle";		
	}


	return 0;
}