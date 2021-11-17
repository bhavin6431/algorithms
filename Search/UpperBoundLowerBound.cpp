#include <bits/stdc++.h>

using namespace std;

int lower_bound(vector<int> &vec, int val) {
	int l = 0;
	int r = vec.size() - 1;
	while(l <= r) {
		int mid = l + ((r - l) / 2);
		if(vec[mid] > val) {
			r--;
		} else {
			l++;
		}
	}
	return vec[r];
}

int upper_bound(vector<int> &vec, int val) {
	int l = 0;
	int r = vec.size() - 1;
	while(l < r) {
		int mid = l + ((r - l) / 2);
		if(vec[mid] <= val) {
			l++;
		} else {
			r--;
		}
	}
	return vec[r];
}

int main() {
	int n;
	cin >> n;
	vector<int> vec(n);
	for(int i=0;i<n;i++) {
		cin >> vec[i];
	}
	
	sort(vec.begin(), vec.end());
	
	int val;
	cin >> val;
	
	cout << "Lower Bound : " << lower_bound(vec, val) << endl;
	cout << "Upper Bound : " << upper_bound(vec, val);
	
	return 0;
}