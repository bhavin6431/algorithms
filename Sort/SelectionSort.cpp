#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> vec(n);
	for(int i=0;i<n;i++) {
		cin >> vec[i];
	}
	for(int i=0;i<n-1;i++) {
		int minIndex = i;
		for(int j=i+1;j<n;j++) {
			if(vec[minIndex] > vec[j]) {
				minIndex = j;
			}
		}
		if(minIndex != i) {
			int tmp = vec[minIndex];
			vec[minIndex] = vec[i];
			vec[i] = tmp;
		}
	}
	for(int i=0;i<n;i++) {
		cout << vec[i] << " ";
	}
	return 0;
}