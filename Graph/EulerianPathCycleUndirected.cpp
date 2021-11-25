#include <bits/stdc++.h>

using namespace std;

void dfs(int at, vector<int> *adj, vector<bool> &visited) {
	visited[at] = true;
	for(int to : adj[at]) {
		if(!visited[to]) {
			dfs(to, adj, visited);
		}
	}
}

bool isConnected(int n, vector<int> *adj, vector<bool> &visited) {

    int i;
    for (i = 0; i < n; i++)
        visited[i] = false;
 
    for (i = 0; i < n; i++)
        if (adj[i].size() != 0)
            break;

    if (i == n)
        return true;
 
    dfs(i, adj, visited);
 
    for (i = 0; i <n; i++)
       if (!visited[i] && adj[i].size() > 0)
            return false;
 
    return true;
}
int getNumberOfOddEdges(int n, vector<int> *adj) {
	int oddEdges = 0;
	for(int i=0;i<n;i++) {
		if(adj[i].size() % 2 != 0) {
			oddEdges++;
		}
	}
	return oddEdges;
}

int isEularCircuit(int n, vector<int> *adj) {
	
	vector<bool> visited(n+1);	
	if(!isConnected(n, adj, visited)) {
		return 0;
	} 

	if(getNumberOfOddEdges(n, adj) > 2) {
		return 0;
	}

	return getNumberOfOddEdges(n, adj) ? 1 : 2;
}

int main() {
	int n, m, u, v;
	cin >> n >> m;
	vector<int> adj[n+1];
	vector<bool> visited(n+1);
	for(int i=0;i<m;i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);	
	}

	// 2 - Eulerian Cycle
	// 1 - Eulerian Path
	// 0 - Neither
	cout << isEularCircuit(n, adj);

	return 0;
}