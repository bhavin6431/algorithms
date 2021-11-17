#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &vec, int left, int mid, int right) {
	vector<int> one = {vec.begin() + left, vec.begin() + mid + 1};
	vector<int> two = {vec.begin() + mid + 1, vec.begin() + right + 1};
	int i1 = 0;
	int i2 = 0;
	while(i1 < one.size() && i2 < two.size()) {
		if(one[i1] <= two[i2]) {
			vec[left++] = one[i1++];
		} else {
			vec[left++] = two[i2++];
		}
	}
	while(i1 < one.size()) {
		vec[left++] = one[i1++];
	}

	while(i2 < two.size()) {
		vec[left++] = two[i2++];
	}
}

void mergeSort(vector<int> &vec, int begin, int end) {
	if(begin >= end) {
		return;
	}
	int mid = begin + ((end - begin)/2);
	mergeSort(vec, begin, mid);
	mergeSort(vec, mid+1, end);
	merge(vec, begin, mid, end);
}



int main() {
	int n;
	cin >> n;
	vector<int> vec(n);
	for(int i=0;i<n;i++) {
		cin >> vec[i];
	}

	mergeSort(vec, 0, n-1);
	
	for(int i=0;i<n;i++) {
		cout << vec[i] << " ";
	}
	return 0;
}