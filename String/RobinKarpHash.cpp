#include <bits/stdc++.h>

using namespace std;

vector<long long> primePower(int size) {
	int m = 1e9 + 9;
	int p = 31;
	vector<long long> p_pow(size); 
	p_pow[0] = 1; 
	for (int i = 1; i < (int) p_pow.size(); i++) 
		p_pow[i] = (p_pow[i-1] * p) % m;

	return p_pow;
}

vector<long long> prefixHashes(vector<long long> prime_power, string text) {
	int m = 1e9 + 9;
	vector<long long> h(text.length() + 1, 0);
	for(int i=0;i<text.length();i++) {
		h[i+1] = (h[i] +  ((text[i] - 'a' + 1) * prime_power[i])) % m; 
	}
	return h;
}

long long hashPatter(vector<long long> prime_power, string pattern) {
	int m = 1e9 + 9;
	int hash = 0;
	for(int i=0;i<pattern.length();i++) {
		hash += ((pattern[i] - 'a' + 1) * prime_power[i]) % m ;
	}
	return hash;
}

int main() {
	string text, pattern;
	int m = 1e9 + 9;
	cin >> text;	
	cin >> pattern;

	vector<long long> prime_power = primePower(max(text.length(), pattern.length()));
	vector<long long> hashTextPrefixes = prefixHashes(prime_power, text); 	
	long long hashPattern = hashPatter(prime_power, pattern);
	cout << hashPattern << endl;
	vector<int> occurrences;
	for(int i=0;i + pattern.length()  - 1 < text.length();i++) {
		long long cur_h = (hashTextPrefixes[i+pattern.length()] - hashTextPrefixes[i]) % m;
		if(cur_h == (hashPattern * prime_power[i]) % m) {
			occurrences.push_back(i);
		}
	}
	cout << "Total Occurances : " << occurrences.size() << endl;
	return 0;
}