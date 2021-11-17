#include <bits/stdc++.h>

using namespace std;
int main() {
	int n, m, u, v, x = 0, c = 0;
	cin >>  n;
	m = n - 1;
	vector<vector<int>> adj(n + 1);
	vector<bool> visited(n+1, false);
	for(int i=0;i<m;i++) {
		cin >> u;
		cin >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cin >> x;	
	queue<pair<int,int>> q;
	q.push({1, 1});
	while(!q.empty()) {
		pair<int,int> u = q.front();
		q.pop();
		visited[u.first] = true;
		for(int ne : adj[u.first]) {
			if(!visited[ne]) {
				if(u.second == x - 1) {
					c++;
				}
				q.push({ne, u.second + 1});
			}
		}
	}
	cout << c;
	return 0;
}
