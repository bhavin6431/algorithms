#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> vec(n);
	for(int i=0;i<n;i++) {
		cin >> vec[i];
	}
	for(int i = 1; i<n;i++) {
		int j = i - 1;
		int key = vec[i];
		while(j >=0 && vec[j] > key) {
			vec[j + 1] = vec[j];
			j = j - 1;
		}
		vec[j + 1] = key;
	}

	for(int i=0;i<n;i++) {
		cout << vec[i] << " ";
	}
	return 0;
}