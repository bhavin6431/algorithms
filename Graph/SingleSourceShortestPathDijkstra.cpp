#include <bits/stdc++.h>

using namespace std;

struct Edge {
	int from, to, w;
};

struct Node {
	int v;
	long long int wsf;
};

struct CompareWeight {
	bool operator()(Node const& p1, Node const& p2)
	{
		return p1.wsf > p2.wsf;
	}
};

int main() {
	int n, m, u, v, w;
	cin >>  n >> m;
	vector<vector<Edge>> adj(n + 1);
	for(int i=0;i<m;i++) {
		cin >> u;
		cin >> v;
		cin >> w;
		adj[u].push_back({u, v, w});
		adj[v].push_back({v, u, w});
	}	

	vector<bool> visited(n+1, false);
	priority_queue<Node, vector<Node>, CompareWeight> q;
	q.push({1, 0});
	vector<long long int> distance(n + 1, 0);
	while(!q.empty()) {
		Node node = q.top();
		q.pop();

		if(!visited[node.v]) {
			distance[node.v] = node.wsf;
			visited[node.v] = true;
			for(Edge ne : adj[node.v]) {
				if(!visited[ne.to]) {
					q.push({ne.to, ne.w + node.wsf});
				}
			}
		}
		
	}	
	for(int i=2;i<=n;i++) {
		cout << distance[i] << " ";
	}

	return 0;
}
