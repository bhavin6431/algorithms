#include <bits/stdc++.h>

using namespace std;

int MAXN = 1000;

void generatePascalTriangle(vector<vector<int>> &C) {
	C[0][0] = 1;	
	for(int n=1;n<MAXN;n++) {
		C[n][0] = C[n][n] = 1;
		for(int k=1;k<MAXN;k++) {
			C[n][k] = C[n-1][k-1] + C[n-1][k];
		}
	}
}

int main() {
	int t, n, k;
	cin >> t;
	vector<vector<int>> C(MAXN, vector<int> (MAXN, 0));
	generatePascalTriangle(C);

	while(t--) {
		cin >> n;
		cin >> k;

		cout << C[n][k] << endl;

	}
	return 0;
}