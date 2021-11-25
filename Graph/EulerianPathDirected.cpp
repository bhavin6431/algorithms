#include <bits/stdc++.h>

using namespace std;

int edgeCount = 0;
void setupInOut(int n, vector<int> *adj, vector<int> &in, vector<int> &out) {
	for(int from=0;from < n; from++) {
		for(int to : adj[from]){
			out[from]++;
			in[to]++;
			edgeCount++;	
		}
	}
}

bool hasEdulerianPath(int n, vector<int> &in, vector<int> &out) {
	if(edgeCount == 0) {
		return false;
	}
	int startNode = 0, endNode = 0;
	for(int i=0;i<n;i++) {
		if(out[i] - in[i] > 1 || in[i] - out[i] > 1) {
			return false;
		}
		if(in[i] - out[i] == 1) endNode++;
		if(out[i] - in[i] == 1) startNode++;
	} 
	return (startNode == 0 && endNode == 0) || (endNode == 1 && startNode == 1);
}

int findStartNode(int n, vector<int> &in, vector<int> &out) {
	int start = 0;
	for(int i=0;i<n;i++) {
		if(out[i] - in[i] == 1){
			return i;
		}
		if(out[i] > 0) start = i;
	}	
	return start;
}

void dfs(int at, vector<int> &out, vector<int> *adj, vector<int> &path) {
	while(out[at]) {
		--out[at];
		dfs(adj[at][out[at]], out, adj, path);
	}
	path.push_back(at);
}

void getEulerianPath(int n, vector<int> *adj, vector<int> &in, vector<int> &out, vector<int> &path) {
	if(!hasEdulerianPath) return;

	dfs(findStartNode(n, in, out), out, adj, path);
}
int main() {
	int n, m, u, v;
	cin >> n >> m;
	vector<int> adj[n+1];
	for(int i=0;i<m;i++) {
		cin >> u >> v;
		adj[u].push_back(v);
	}
	vector<int> in(n+1, 0);
	vector<int> out(n+1, 0);
	vector<int> path;
	setupInOut(n, adj, in, out);
	hasEdulerianPath(n, in, out);

	getEulerianPath(n, adj, in, out, path);
	 if (path.size() != edgeCount + 1) {
	 	cout << "No Path exists";
	 }
	 if(path[0] == path[path.size() - 1]) {
	 	cout << "There is cycle" << endl;
	 }
	for(int i=0;i<path.size();i++) {
		cout << path[i] << " ";
	}
	
	return 0;
}