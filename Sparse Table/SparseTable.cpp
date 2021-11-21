#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	vector<int> vec(n);
	for(int i=0;i<n;i++) {
		cin >> vec[i];
	}

	int LOG = ceil(log2(n)) - 1;
	int sz = pow(2, LOG);

	int sTable[sz][LOG + 1] = {0};	

	for(int i=0;i<n;i++) {
		sTable[i][0] = vec[i];
	}

	for(int j = 1; j <= LOG; j++) {
		for(int i=0; i + (1 << j) <= n;i++) {
			sTable[i][j] = max(sTable[i][j - 1], sTable[i + (1 << (j - 1))][j - 1]);	
		}
	} 
	for(int i=0;i < q;i++) {
		int l, r;
		cin >> l >> r;	
		l--;
		r--;
		int j = ceil(log2(r - l + 1)) - 1;
		cout << max(sTable[l][j],sTable[r - (1 << j) + 1][j]) << endl;
	}

	return 0;
}