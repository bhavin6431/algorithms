#include <bits/stdc++.h>

using namespace std;

vector<int> z(string s) {
	vector<int> zv(s.length(), 0);
	int l = 0;
	int r = 0;
	for(int i=1;i<s.length();i++) {
		//if within the z box
		if(i <= r) {
			// don't go beyond the z box
			zv[i] = min(r - i + 1, zv[i - 1]);
		}
		//find new z box
		while(i + zv[i] < s.length() && s[zv[i]] == s[i + zv[i]]) {
			++zv[i];
		}

		//reset l & r
		if(i + zv[i] - 1 > r) {
			l = i;
			r = i + zv[i] - 1;
		}
	}
	return zv;
}

int main() {
	string text, pattern;
	cin >> text >> pattern;
	vector<int> zv = z(pattern+"#"+text);
	int count = 0;
	for(int i=0;i<zv.size();i++) {
		if(pattern.size() == zv[i]) {
			count++;
		}
	}
	if(count > 0) {
		cout << "YES";
	} else {
		cout << "NO";
	}
}
