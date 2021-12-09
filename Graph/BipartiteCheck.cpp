#include <bits/stdc++.h>

using namespace std;

bool isBipartite(int n, vector<int> adj[]){
	bool isBipartite = true;
	vector<int> side(n, -1);
	queue<int> q;
	for(int from=0;from<n;from++) {
		if(side[from] == -1) {
			q.push(from);
			side[from] = 0;
			while(!q.empty()) {
				int front = q.front();
				q.pop();
				for(int ne : adj[front]) {
					if(side[ne] == -1)  {	
						side[ne] = side[front] ^ 1;
						q.push(ne);
					} else {
						isBipartite &= side[front] != side[ne];
					}
				}
			}
		}
	}
	return isBipartite;
}

int main() {
	int n, m, u, v;
	cin >> n;
	cin >> m;
	vector<int> adj[n];
	for(int i=0;i<m;i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cout << isBipartite(n, adj);
	return 0;
}