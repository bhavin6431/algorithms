#include <bits/stdc++.h>

using namespace std;
int main() {
	int n, m, u, v, x = 0, c = 0;
	cin >>  n;
	m = n - 1;
	vector<vector<int>> adj(n + 1);
	vector<bool> visited(n+1, false);
	vector<int> d(n + 1);
	vector<int> p(n + 1, -1);
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
				d[ne] = d[u.first] + 1;
				p[ne] = u.first;
			}
		}
	}
	cout << c << endl;

	for(int j = 1; j <= n;j++) {
		x = j;
		vector<int> path;
		path.push_back(x);
		while(p[x] != - 1) {
			path.push_back(p[x]);
			x = p[x];
		}
		for(int i=0;i<path.size();i++) {
			cout << path[i] <<(i != path.size() - 1 ? " -> " : " ");
		}
		cout << endl;
	}
	return 0;
}
