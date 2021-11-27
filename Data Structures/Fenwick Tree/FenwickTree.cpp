#include <bits/stdc++.h>

using namespace std;

long long getSum(int index, long long n, long long *BIT) {
	long long sum = 0;
	index = index + 1;
	while(index > 0) {
		sum += BIT[index];
		index -= index & (-index);
	}
	return sum;
}

void update(int index, long long value, int n, long long *BIT) {
	index = index + 1;
	while(index <=n) {
		BIT[index] += value;
		index += index & (-index);
	}
}

long long getSum(int l, int r, int n, long long *BIT) {
	return getSum(r, n, BIT) - getSum(l - 1, n, BIT);
}
 
int main() {
	int n;
	cin >> n;
	vector<long long> vec(n);
	for(int i=0;i<n;i++) {
		cin >> vec[i];
	}
	long long BIT[n+1] = {0};		
	for(int i=0;i<n;i++) {
		update(i, vec[i], n, BIT);
	}
	cout << getSum(2, 5, n, BIT);
	return 0;
}
