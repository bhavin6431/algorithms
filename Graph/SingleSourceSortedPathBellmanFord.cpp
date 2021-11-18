#include <bits/stdc++.h>

using namespace std;

struct Edge {
	int from, to, w;
};

struct Node {
	int v;
	long long int wsf;
};

int main() {
	int n, m, u, v, w;
	cin >>  n >> m;
	vector<Edge> edges(m);
	vector<double> distance(n + 1, numeric_limits<double>::infinity());
	distance[1] = 0;
	for(int i=0;i<m;i++) {
		cin >> u;
		cin >> v;
		cin >> w;
		edges.push_back({u, v, w});
	}	

	for(int i=0;i<n - 1;i++) {
		for(Edge edge : edges) {
			distance[edge.to] = min(distance[edge.to] , distance[edge.from] + edge.w);
		}
	}


	//Negative cycle
	for(int i=0;i<n - 1;i++) {
		for(Edge edge : edges) {
			if(distance[edge.from] + edge.w < distance[edge.to]) {
				distance[edge.to] =  -1 * numeric_limits<double>::infinity();
			}
		}
	}

	for(int i=2;i<=n;i++) {
		cout << distance[i] << " ";
	}

	return 0;
}