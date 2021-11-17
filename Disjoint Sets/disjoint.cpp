#include <bits/stdc++.h>

using namespace std;

/**
 * https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-flood-1/ 
 * */
int find(vector<int> &parent, int x) {
	if(parent[x] != x) {
		parent[x] =  find(parent, parent[x]);
	}
	return parent[x];
}

void unionJoin(vector<int> &parent, int x, int y) {
	int xroot = find(parent, x);
	int yroot = find(parent, y);	
	if(xroot != yroot) {
		parent[xroot] = yroot;
	}
}

int main() {
	int n, m, x, y;
	cin >> n;
	cin >> m;
	vector<int> parent(n + 1);
	for(int i=1;i<=n;i++) {
		parent[i] = i;
	}
	for(int i = 0;i < m; i++) {
		cin >> x;
		cin >> y;
		unionJoin(parent, x, y);
	}
	set<int> countDSU;
	for(int i=1;i<=n;i++) {
		countDSU.insert(find(parent, parent[i]));
	}
	cout << countDSU.size() << endl;

	return 0;
}