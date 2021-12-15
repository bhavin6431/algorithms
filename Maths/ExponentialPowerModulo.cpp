#include <bits/stdc++.h>

using namespace std;

long long power(long long x, int y, int mod) {
	int res = 1;
	x = x % mod;

	if(x == 0) return 0;

	while(y > 0) {
		if(y & 1) {
			res = (res * x) % mod;
		}
		y = y >> 1;
		x = (x * x) % mod;
	}
	return res;
}

int main() {
	long long x;
	int y, mod;
	cin >> x >> y >> mod;

	cout << power(x, y, mod);

	return 0;
}