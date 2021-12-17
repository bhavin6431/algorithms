#include <bits/stdc++.h>

using namespace std;

int MAXN = 10;
int MOD = 1e9 + 7;

long long calculateFactorial(vector<long long> &factorial) {
	factorial[0] = 1;
	for (int i = 1; i < MAXN; i++) {
		factorial[i] = factorial[i - 1] * i % MOD;
	}
}

long long binomial_coefficient(vector<long long> &factorial, vector<long long> &inverse_factorial, int n, int k) {
	return factorial[n] * inverse_factorial[k] % MOD * inverse_factorial[n - k] % MOD;
}

void moduleInverse(vector<long long> &inv) {
	inv[1] = 1;
	for(int i = 2; i < MAXN; ++i)
		inv[i] = MOD - (MOD/i) * inv[MOD%i] % MOD;

}

int main() {
	int n, t, k;
	vector<long long> inv(MAXN, 1);
	vector<long long> factorial(MAXN, 1);
	calculateFactorial(factorial);
	moduleInverse(inv);
	cout << factorial[5] << endl;
	cout << inv[2] << endl;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		cout << binomial_coefficient(factorial, inv, n , k) << endl;
	}
	return 0;
}