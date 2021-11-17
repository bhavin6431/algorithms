#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> vec(n);
	vector<int> vecans(n, 0);

	int minelement = INT_MAX;
	int maxelement = 0;	
	for(int i=0;i<n;i++) {
		cin >> vec[i];
		minelement = min(minelement, vec[i]);
		maxelement = max(maxelement, vec[i]);	
	}
	int range = maxelement - minelement + 1;
	vector<int> count(range, 0);
	for(int i=0;i<n;i++) {
		count[vec[i] - minelement]++;
	}

	for(int i=1;i<count.size();i++) {
		count[i] += count[i - 1];
	}
	for(int i=0;i<n;i++) {
		vecans[count[vec[i] - minelement] - 1] = vec[i];
		count[vec[i] - minelement]--;
		vecans[count[vec[i] - minelement] - 1] = vec[i];
		count[vec[i] - minelement]--;
	}	
	for(int i=0;i<n;i++) {
		cout << vecans[i] << " ";
	}
	return 0;
}