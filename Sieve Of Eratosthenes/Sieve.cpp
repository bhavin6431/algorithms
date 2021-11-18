#include <bits/stdc++.h>

using namespace std;
int MAX_PRIME = 100000000 + 1;
vector<bool> prime(MAX_PRIME, true);
int main() {
	int i = 2;
	while(i * i < MAX_PRIME) {
		if(prime[i]) {
			int k = 2;
			while( i * k < MAX_PRIME) {
				prime[i * k] = false;
				k++;
			}
		}
		i++;
	}
	for(int i=0;i<100;i++) {
		cout << (prime[i] ? i : 0) << " ";	
	}

	return 0;
}