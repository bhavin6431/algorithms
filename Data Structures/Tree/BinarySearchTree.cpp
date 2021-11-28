#include <bits/stdc++.h>

using namespace std;

class Node {
	public:
	int data;
	Node* left = NULL;
	Node* right = NULL;
};

Node* root = NULL;

Node* insertNode(Node *node, int data) {
	if(node == NULL) {
		Node *newNode = new Node();
		newNode -> data = data;
		return newNode;
	}

	if( data < node -> data ) {
		node -> left = insertNode(node -> left, data);
	} else {
		node -> right = insertNode(node -> right, data);
	}
	return node;
}

Node* minValueNode(Node* node)
{
    Node* current = node;
 
    while (current && current -> left != NULL)
        current = current -> left;
 
    return current;
}

bool contains(int key) {
	Node *  currNode = root;
	while(currNode != NULL && currNode -> data != key) {
		if(key > currNode -> data) {
			currNode = currNode -> right;
		} else {
			currNode = currNode -> left;
		}
	}
	return currNode != NULL && currNode -> data == key;
}

Node* deleteNode(Node* node, int data) {
	if(node == NULL) {
		return node;
	}
	if (data < node -> data) {
        node -> left = deleteNode(node -> left, data);
    } else if(data > node -> data) {
		node -> right = deleteNode(node -> right, data);
	} else {
		if(node -> left == NULL && node -> right == NULL) {
			return NULL;
		} else if(node -> left == NULL) {
			Node *tmp = node -> right;
			free(node);
			return tmp;
		} else if(node -> right == NULL) {
			Node *tmp = node -> left;
			free(node);
			return tmp;
		}

		Node* temp = minValueNode(node -> right);
		node -> data = temp -> data;
		node -> right = deleteNode(node -> right, temp -> data);

	}
	return node;
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
		root = insertNode(root, vec[i]);	
	}
	inOrder(root);
	cout << endl;
	postOrder(root);
	cout << endl;
	preOrder(root);
	cout << endl;
	root = deleteNode(root, 51);
	inOrder(root);
	cout << endl;

	root = deleteNode(root, 100);
	inOrder(root);
	cout << endl;
	root = deleteNode(root, 7);
	inOrder(root);
	cout << endl;
	root = deleteNode(root, 87);
	inOrder(root);
	cout << endl;

	cout << "Contains : " << contains(11);

	return 0;
}