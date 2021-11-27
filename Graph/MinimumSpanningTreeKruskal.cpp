#include <bits/stdc++.h>

using namespace std;

struct Edge {
	long long w;
	int from, to;
};

int find(int from, vector<int> &parent) {
	if(parent[from] != from) {
		parent[from] = find(parent[from], parent);
	}
	return parent[from];
}

bool unionJoin(int from, int to, vector<int> & parent) {
	int rootFrom = find(from ,parent);
	int rootTo = find(to, parent);

	if(rootTo != rootFrom) {
		parent[rootTo] = rootFrom;
		return true;
	}
	return false;
}

int main() {
	int n, m, u, v, w;
	cin >> n >> m;
	vector<int> parent(n+1);
	for(int i=0;i<n+1;i++) {
		parent[i] = i;
	}
	vector<vector<int>> edgeVec;

	for(int i=0;i<m;i++) {
		cin >> u >> v >> w;
		edgeVec.push_back({w, u, v});
	}
	sort(edgeVec.begin(), edgeVec.end());
	long long ans = 0;
	for(auto edge : edgeVec) {
		if(unionJoin(edge[1], edge[2], parent)) {
			ans += edge[0];
		}
	}
	cout << ans;

	return 0;
}
