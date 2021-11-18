#include <bits/stdc++.h>

using namespace std;
class Node {
	public:
	int data;
	Node* next;
};

Node *root = NULL;

void create(vector<int> &vec) {
	root = new Node();
	root->data = vec[0];
	Node *curr = root;
	for(int i = 1;i<vec.size();i++) {
		Node *newNode = new Node();
		newNode->data = vec[i];
		curr->next = newNode;
		curr = newNode;
	}	
	curr->next = NULL;
}

void addNode(int indx, int data) {
	Node *newNode = new Node();
	newNode -> data = data;

	if(indx == 0) {
		newNode->next = root;
		root = newNode;
	} else {
		int i=0;
		Node* currNode = root;
		while(root != NULL) {
			if(i == indx - 1) {
				Node* next = currNode->next;
				currNode -> next = newNode;
				newNode -> next = next;
				return;
			}
			currNode = currNode->next;
			i++;
		}
	}
}

void deleteNode(int data) {
	if(root->data == data) {
		root = root -> next;
	} else {
		Node* currNode = root;
		Node* prevNode = NULL;
		while(currNode->data != data) {
			prevNode = currNode;
			currNode = currNode->next;
		}
		if(currNode->next == NULL) {
			prevNode->next = NULL;
			currNode = NULL;
		} else {
			prevNode->next = currNode->next;
			currNode = NULL;
		}
	}
}

void display() {
	Node* currNode = root;
	while(currNode != NULL) {
		cout << currNode->data << " ";
		currNode = currNode->next;
	}
	cout << endl;
}

int main() {
	int n;
	cin >> n;
	vector<int> vec(n);
	for(int i=0;i<n;i++) {
		cin >> vec[i];
	}
	
	create(vec);
	addNode(5, 45);
	display();
	deleteNode(5);
	display();
	deleteNode(1);
	display();
	addNode(0,1);
	display();

	return 0;
}