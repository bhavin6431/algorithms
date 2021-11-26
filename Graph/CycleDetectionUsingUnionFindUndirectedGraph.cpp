#include <bits/stdc++.h>

using namespace std;

int find(int a, vector<int> &parent) {
	if(parent[a] != a) {
		parent[a] = find(parent[a], parent);
	}
	return parent[a];
}

bool unionJoin(int x, int y, vector<int> &parent) {
	int rootx = find(x, parent);
	int rooty = find(y, parent);
	if(rootx != rooty) {
		parent[rootx] = rooty;
		return true;
	}
	return false;
}	

bool isCycle(int n, vector<int> adj[]) {
	vector<int> parent(n + 1);
	for(int i=0;i<n;i++) {
		parent[i] = i;
	}

	for(int i=0;i<n; i++) {
		for(int j : adj[i]) {
			if(!unionJoin(i, j, parent)) {
				return true;
			}
		}
	}      
	return false;
}

int main() {	
	int n, m, u, v;
	cin >> n >> m;
	vector<int> adj[n];

	for(int i=0;i<m;i++) {
		cin >> u >> v;
		adj[u].push_back(v);
	}

	cout << isCycle(n, adj);
	return 0;
}