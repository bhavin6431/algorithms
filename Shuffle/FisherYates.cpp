#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> vec(n);
	for(int i=0;i<n;i++) {
		cin >> vec[i];
	}
	
	srand (time(NULL));

	for(int i= n - 1; i > 0; i--) {
		int j = rand() % (i + 1);
		int tmp = vec[j];
		vec[j] = vec[i];
		vec[i] = tmp;
	}

	for(int i=0;i<n;i++) {
		cout << vec[i] << " ";
	}


	return 0;
}