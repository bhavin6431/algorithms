#include <bits/stdc++.h>

using namespace std;

struct Edge {
	int from, to;
	long long w;
	bool operator<(const Edge &other) const {
		return w > other.w;
	}
};


int main () {
		int n, m, u, v;
		long long w;
		cin >> n >> m;
		vector<Edge> adj[n];
		vector<bool> visited(n);
		for(int i=0;i<m;i++) {
			cin >> u >> v >> w;
			adj[u-1].push_back({u-1, v-1, w});
			adj[v-1].push_back({v-1, u-1, w});
		}
		long long minCostSum = 0;
		priority_queue<Edge> pq;
		vector<int> minCostEdges;
		long long edgesCount = 0;
		pq.push({-1, 0, 0});
		while(!pq.empty() && edgesCount < n) {
			Edge currEdge = pq.top();
			pq.pop();
			if(visited[currEdge.to]) continue;
			visited[currEdge.to] = true;
			minCostEdges.push_back(currEdge.to);
			minCostSum+= currEdge.w;
			edgesCount++;
			for(Edge ne : adj[currEdge.to]) {
				if(!visited[ne.to]) {
					pq.push({ne.from, ne.to, ne.w});
				}
			}
		}
		//if(edgesCount != n) {
		//	cout << "Minimum Spanning Tree Doesn't exists";
		//} else {
			// for(int i=0;i<minCostEdges.size();i++) {
			// 	cout << minCostEdges[i] << " ";
			// }
			// cout << endl;
			cout << minCostSum;
		//}
} 