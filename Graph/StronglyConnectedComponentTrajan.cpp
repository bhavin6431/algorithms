#include <bits/stdc++.h>

using namespace std;

int id = 0;
int scc = 0;

void dfs(int at, vector<vector<int>> adj, vector<bool> &visited, vector<int> &low, vector<int> &ids, stack<int> &st, vector<int> &sccs) {
	st.push(at); 	
	low[at] = ids[at] = id++;
	visited[at] = true;
	for(int to : adj[at]) {
		if(ids[to] == -1) {
			dfs(to, adj, visited, low, ids, st, sccs);
		}
		if(visited[to]) {
			low[at] = min(low[at], low[to]);
		}
	}
	if(ids[at] == low[at]) {
		while(!st.empty()) {
			int p = st.top();
			st.pop();
			visited[p] = false;
			low[p] = ids[at];
			sccs[p] = scc;
			if(p == at) {
				break;
			}
		}
		scc++;
	}
}

int solve(int n, vector<vector<int>> adj) {
	vector<int> low(n+1, 0);
	//used to track if DFS is done for this node
	vector<int> ids(n+1, -1);
	//used for calling stack visited nodes only
	vector<bool> visited(n+1, false);

	vector<int> sccs(n);

	stack<int> st;
	for(int i=0; i<n;i++) {
		if(ids[i] == -1) {
			dfs(i, adj, visited, low, ids, st, sccs);
		}
	}

	vector<vector<int>> sccSubGraph(scc); 

	for(int i=0;i<n;i++) {
		sccSubGraph[sccs[i]].push_back(i);
	}
	int sumOdd = 0;
	int sumEven = 0;
	//cout << "Total SCC are : " << scc << endl;
	for(int i=0;i<sccSubGraph.size();i++) {
		//cout << "SCC Graph " << i + 1 << " : ";
		for(int j=0;j<sccSubGraph[i].size();j++) {
			//cout << sccSubGraph[i][j] << " ";
		}
		if(sccSubGraph[i].size() % 2 == 0) {
			sumEven += sccSubGraph[i].size();
		} else {
			sumOdd += sccSubGraph[i].size();
		}
		//cout << endl;
	}
	cout << (sumOdd - sumEven);

	return scc;
}

int main() {
	int n,m;
	cin >> n >> m;
	vector<vector<int>> adj(n+1);
	for(int i =0; i<m;i++) {
		int u, v;
		cin >> u >> v;
		adj[u-1].push_back(v-1);
	}
	

	solve(n, adj);
	return 0;
}