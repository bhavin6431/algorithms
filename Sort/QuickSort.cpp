#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &vec, int low, int high) {
	int pivot = vec[high];
	int i = low - 1;
	for(int j = low; j < high; j++) {
		if(vec[j] < pivot) {
			// to avoid -1 going to zero;
			i++;
			int tmp = vec[j];
			vec[j] = vec[i];
			vec[i] = tmp;
		}
	}
	//i + 1 next higher element after sorting all left side
	// that means pivot is less than that i + 1 element 
	int tmp = vec[i + 1];
	vec[i + 1] = vec[high];
	vec[high] = tmp;
	// next pivot is recently sorted element
	return i + 1;
}

void quickSort(vector<int> &vec, int low, int high) { 
    if (low < high) { 
		int pi = partition(vec, low, high);
		quickSort(vec, low, pi - 1);
		quickSort(vec, pi + 1, high);
	}
}
	


int main() {
	int n;
	cin >> n;
	vector<int> vec(n);
	for(int i=0;i<n;i++) {
		cin >> vec[i];
	}

	quickSort(vec, 0, n - 1); 

	for(int i=0;i<n;i++) {
		cout << vec[i] << " ";
	}
	return 0;
}