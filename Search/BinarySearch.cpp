#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	bool found = false;
	vector<int> vec(n);
	for(int i=0;i<n;i++) {
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end());
	int itemToLook;
	cin >> itemToLook;
	int l = 0;
	int r = n-1;
	while(l <= r) {
		int mid = l + ((r - l) / 2);
		if(vec[mid] == itemToLook) {
			found = true;
			break;
		}
 		if(vec[mid] > itemToLook) {
 			r--;
		} else {
			l++;
		}
	}
	cout << (found ? "Found" : "Not Found");
	return 0;
}