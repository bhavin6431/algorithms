#include <bits/stdc++.h>

using namespace std;

int heapify(vector<int> &vec, int n, int i) {
	int largest = i;
	int l = 2 * i + 1;
	int r = l + 1;
	
	if(l < n && vec[l] > vec[largest]) {
		largest = l;
	}

	if(r < n && vec[r] > vec[largest]) {
		largest = r;
	}

	if(largest != i) {
		int tmp = vec[largest];
		vec[largest] = vec[i];
		vec[i] = tmp;
	}

	return largest;

}

void heapSort(vector<int> &vec, int n) {
	for(int i=n/2 - 1;i>=0;i--) {
		heapify(vec, n, i);
	}

	for(int i = n - 1; i > 0;i--) {
		int tmp = vec[0];
		vec[0] = vec[i];
		vec[i] = tmp;

		// call heapify on i only which is reduced set
		heapify(vec, i, 0);
	}
}



int main() {
	int n;
	cin >> n;
	vector<int> vec(n);
	for(int i=0;i<n;i++) {
		cin >> vec[i];
	}

	heapSort(vec, n);

	for(int i=0;i<n;i++) {
		cout << vec[i] << " ";
	}
	return 0;
}