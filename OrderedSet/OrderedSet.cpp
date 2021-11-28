#include <bits/stdc++.h>

using namespace std;

class Node {
	public:
	long long value;
	long long sizeOfLeftSubTree;
	Node(int val) {
		value = val;
	}
};

Node *root;

int insertNode(int val) {
	Node *currNode = root;
	
}

int deleteNode(int val) {

}

int find_by_order(int index) {

}

int order_of_key(int key) {

}

int main() {
	int n, val;
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> val;
		if(root == NULL) {
			root = new Node(val);
		} else {
			insertNode(val);
		}	
	}

	cout << find_by_order(6) << endl;
	cout << order_of_key(45) << endl;	




	return 0;
}