#include <bits/stdc++.h>

using namespace std;

vector<int> pii(string s) {
	vector<int> p(s.length(), 0);
	for(int i=1;i<s.length();i++) {
		int j = p[i - 1];
		while(j > 0 && s[i] != s[j]) {
			j = p[j - 1];
		}
		if(s[i] == s[j]) {
			j++;
		}
		p[i] = j;
	}
	return p;
}

int main() {
	string text, pattern;
	cin >> text >> pattern;
	vector<int> piiv = pii(pattern+"#" +text);
	if(piiv[(pattern+"#" +text).length() - 1] == pattern.size()){
		cout << "YES";
	} else {
		cout << "NO";
	}

	return 0;
}