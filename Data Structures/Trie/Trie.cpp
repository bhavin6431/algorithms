#include <bits/stdc++.h>

using namespace std;

class Node {
public: 	
	Node* children[26];
}; 

Node* getNode() {
	Node *node = new Node();
	for (int i = 0; i < 26; i++)
		node->children[i] = NULL;
	return node;
}

void addWord(Node *root, string word) {	
	
	for(int i=0; i<word.length(); i++) {
		int index = word[i] - 'a';
		if(!root->children[index]) {
			root -> children[index] = getNode();
		}
		root = root->children[index];
	}
}

bool search(Node *root, string word) {
	for(int i=0; i<word.length(); i++) {
		int index = word[i] - 'a';
		if(root-> children[index] == NULL) {
			return false;
		}
		root = root->children[index];
	}
	return true;
}

int main() {
	int n, q;
	cin >> n >> q;
	Node *root = new Node();

	for(int i=0;i<n;i++) {
		string s;
		cin >> s;
		addWord(root, s);
	}

	for(int i=0;i<q;i++) {
		string qs;
		cin >> qs;
		if(search(root,qs)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	return 0;
}