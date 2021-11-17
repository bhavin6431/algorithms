#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> vec(n);
	for(int i=0;i<n;i++) {
		cin >> vec[i];
	}
	bool swap = true;
	while(swap) {
		swap = false;	
		for(int i=0;i<n -1;i++) {
			for(int j=i+1;j<n;j++) {
				if(vec[i] > vec[j]) {
					int tmp = vec[j];
					vec[j] = vec[i];
					vec[i] = tmp;
					swap = true;
				}
			}
		}
	}
	for(int i=0;i<n;i++) {
		cout << vec[i] << " ";
	}
	return 0;
}