#include <bits/stdc++.h>

using namespace std;
int main() {
	int n, m, u, v;
	cin >>  n >> m;
	vector<vector<double>> dp(n, vector<double> (n, INT_MAX));
	vector<bool> visited(n+1, false);
	for(int i=0;i<m;i++) {
		cin >> u;
		cin >> v;
		cin >> dp[u- 1][v -1];
		dp[i][i] = 0;
	}	

	for(int k=0;k<n;k++) {
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}		
	}

	//Negative cycle detection
	for(int k=0;k<n;k++) {
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if(dp[i][k] + dp[k][j] < dp[i][j]) {
					cout << "Negative cycle detected";
				}				
			}
		}		
	}

	for(int i=1;i<n;i++) {
		cout << dp[0][i] << " ";
	}

	return 0;
}