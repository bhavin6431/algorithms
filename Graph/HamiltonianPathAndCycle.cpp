#include <bits/stdc++.h>

using namespace std;

void dfs(int at, int n, vector<int> adj[], set<int> visited, string psf, vector<string> &hamiltonianPaths) {
	if(visited.find(at) == visited.end()) {
		visited.insert(at);
		psf += psf.length() == 0 ? to_string(at) : "->" + to_string(at);
		if(visited.size() == n) {
			hamiltonianPaths.push_back(psf);
			return;
		}
		for(int ne : adj[at]) {
			if(visited.find(ne) == visited.end()) {
				dfs(ne, n, adj, visited, psf, hamiltonianPaths);
			}
		}
		visited.erase(at);
	}
}

int main() {
	int n, m, u, v;
	cin >> n >> m;

	vector<int> adj[n];
	for(int i=0;i<m;i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	set<int> visited;
	vector<string> hamiltonianPaths;
	string psf = "";
	dfs(0, n, adj, visited, psf, hamiltonianPaths);
	cout << hamiltonianPaths.size();
	cout << endl;
	for(int i=0;i<hamiltonianPaths.size();i++) {
		bool foundCycle = false;
		for(int ne : adj[hamiltonianPaths[i][hamiltonianPaths[i].length()-1] - '0']) {
			if(ne == 0) {
				foundCycle = true;
			}
		} 
		if(foundCycle) {
			cout << hamiltonianPaths[i] << "*";
		} else {
			cout << hamiltonianPaths[i] << ".";
		}
		cout << endl;
	}
	return 0;
}