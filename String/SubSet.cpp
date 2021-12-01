#include <bits/stdc++.h>

using namespace std;

vector<string> subset(string s) {
	int n = (1 << s.length());
	vector<string> ans;
	for(int masks=0;masks<n;masks++) {
		string subset;
		for(int bits = 0; bits < s.length(); bits++) {
			if(masks & (1 << bits)) subset.push_back(s[bits]);
		}
		if(subset.size()) ans.push_back(subset);
	}
	return ans;
}

int main() {
	string s;
	cin >> s;
	vector<string> vec = subset(s);
	for(string str : vec) {
		cout << str << endl;
	}
	return 0;
}