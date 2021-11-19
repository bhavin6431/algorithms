#include <bits/stdc++.h>

using namespace std;

class Node {
	public:
	int data;
	Node* left = NULL;
	Node* right = NULL;
};

Node* root = NULL;

void insertNode(int data) {
	Node* newNode = new Node();
	newNode->data = data;
	if(root == NULL) {
		root = newNode;
	} else {
		queue<Node*> q;
		q.push(root);
		while(!q.empty()) {
			Node* node = q.front();
			q.pop();
			if(node -> left != NULL) {
				q.push(node -> left);
			} else {
				node -> left = newNode; 
				return;
			}


			if(node -> right != NULL) {
				q.push(node -> right);
			} else {
				node -> right = newNode;
				return;
			}
		}
	}
}

void deleteDeepestNode(Node* nodeToDelete) {
	queue<Node*> q;
	q.push(root);
	while(!q.empty()) {
		Node* tmp = q.front();
		q.pop();

		if(tmp == nodeToDelete) {
			tmp = NULL;
			delete(nodeToDelete);
			return;
		}

		if(tmp -> left == nodeToDelete) {
			tmp -> left = NULL;
			delete(tmp -> left);
			return;
		} else {
			q.push(tmp -> left);
		}

		if(tmp -> right == nodeToDelete) {
			tmp -> right = NULL;
			delete(tmp -> right);
			return;
		} else {
			q.push(tmp -> right);
		}


	}
}

void deleteNode(int data) {
	if(root -> data == data && root -> left == NULL && root -> right == NULL) {
		root == NULL;
	}
	queue<Node*> q;
	q.push(root);
	Node* nodeToDelete = NULL;
	Node* tmp = NULL;
	while(!q.empty()) {
		tmp = q.front();
		q.pop();
		if(tmp -> data == data) {
			nodeToDelete = tmp;
		}

		if(tmp -> left != NULL) {
			q.push(tmp -> left);
		}

		if(tmp -> right != NULL) {
			q.push(tmp -> right);
		}
	}
	if(nodeToDelete != NULL) {
		int dataToUpdate = tmp -> data;
		deleteDeepestNode(tmp);
		nodeToDelete -> data = dataToUpdate;
	}
}

void inOrder(Node* node) {
	if(node == NULL) {
		return;
	}
	inOrder(node -> left);
	cout << node -> data << " ";
	inOrder(node -> right);
}

void postOrder(Node* node) {
	if(node == NULL) {
		return;
	}
	postOrder(node -> left);	
	postOrder(node -> right);
	cout << node -> data << " ";
} 	

void preOrder(Node* node) {
	if(node == NULL) {
		return;
	}
	cout << node -> data << " ";
	postOrder(node -> left);	
	postOrder(node -> right);
}

int main() {
	int n;
	cin >> n;
	vector<int> vec(n);
	for(int i=0;i<n;i++) {
		cin >> vec[i];
		insertNode(vec[i]);	
	}

	inOrder(root);
	cout << endl;
	postOrder(root);
	cout << endl;
	preOrder(root);
	cout << endl;

	deleteNode(51);
	inOrder(root);
	cout << endl;

	deleteNode(100);
	inOrder(root);
	cout << endl;

	deleteNode(7);
	inOrder(root);
	cout << endl;

	deleteNode(87);
	inOrder(root);
	cout << endl;

	return 0;
}