#include <bits/stdc++.h>

using namespace std;

long long computeHash(string s) {
	int hash = 0;
	int prime = 31;
	int m = 1e9 + 9;
	int prime_pow = 1; 
	for(int i=0;i<s.length();i++) {
		hash+= ((s[i] - 'a' + 1) * prime_pow) % m;
		prime_pow = (prime_pow * prime) % m;
	}
	return hash;
}

long long fastHash(string s, int i, int j) {
	int prime = 31;
	int m = 1e9 + 9;
	int prime_pow = 1; 
	vector<long long> h(s.length() + 1, 0);
	for(int i=0;i<s.length();i++) {
		h[i+1] = h[i] + ((s[i] - 'a' + 1) * prime_pow) % m;
		prime_pow = (prime_pow * prime) % m;
	}	
	return ((h[j] - h[i]) % m) / pow(prime, i);
}

int main() {
	string s = "hello";
	cout << computeHash(s) << endl;
	string s1 = "llo";
	cout << computeHash(s1) << endl;
	cout << fastHash(s, 2, s.length()) << endl;
	return 0;
}