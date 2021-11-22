#include <bits/stdc++.h>

using namespace std;

int id = 0;
int outEdgesCount = 0;

void dfs(int root, int at, int parent, vector<vector<int>> adj, vector<int> &visited, vector<int> &low, vector<int> &ids, vector<pair<int,int>> &bridges, vector<bool> &isArt) { 
	if(parent == root) outEdgesCount++;
	visited[at] = true;
	id = id + 1;
	low[at] = ids[at] = id;
	for(int to : adj[at]) {
		if(to == parent) {
			continue;
		}
		if(!visited[to]) {
			dfs(root, to, at, adj, visited, low, ids, bridges, isArt);
			low[at] = min(low[at], low[to]);
			if(ids[at] <= low[to]) {
				if(ids[at] != low[to]) {
					bridges.push_back({at, to});
				}
				isArt[at] = true;
			} 
		} else {
			low[at] = min(low[at], ids[to]); 
		}

	}
}

int main() {
	int n,m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	for(int i=0;i<m;i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> low(n+1, 0);
	vector<int> ids(n+1, 0);
	vector<int> visited(n+1, 0);
	vector<pair<int,int>> bridges;
	vector<bool> isArt(n+1);

	for(int i=0;i<n;i++) {
		if(!visited[i]) {
			outEdgesCount = 0;
			dfs(i, i, -1, adj, visited, low, ids, bridges, isArt);
			if(outEdgesCount > 1) {	
				isArt[i] = true;
			}  else {
				isArt[i] = false;
			}
		}
	}
	sort(bridges.begin(), bridges.end());
	int c =0;
	string anss = "";
	for(int i=0;i<n;i++) {
		if(isArt[i]) {
			c++;
			if(anss.length() == 0) {
				anss += to_string(i);
			} else {
				anss += " " + to_string(i);
			}
		}
	}
	cout << c << endl;
	cout << anss << endl;
	cout << bridges.size() << endl;
	for(int i=0;i<bridges.size();i++) {
		cout << bridges[i].first << " " << bridges[i].second <<endl;
	}
	return 0;
}