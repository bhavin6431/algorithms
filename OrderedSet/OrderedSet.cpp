#include <bits/stdc++.h>

using namespace std;

class Node {
public:
	long long data;
	long long sizeOfLeftSubTree = 0;
	long long sizeOfRightSubTree = 0;
	
	Node* left = NULL;
	Node* right = NULL;
	Node(int dataP) {
		data = dataP;
	}
};

Node *root = NULL;

Node* minValueNode(Node* node)
{
	Node* current = node;

	while (current && current -> left != NULL)
		current = current -> left;

	return current;
}

Node* insertNode(Node *node, int data) {
	if(node == NULL) {
		Node *newNode = new Node(data);
		return newNode;
	}

	if( data < node -> data ) {
		node -> sizeOfLeftSubTree = node -> sizeOfLeftSubTree + 1;
		node -> left = insertNode(node -> left, data);
	} else {
		node -> sizeOfRightSubTree = node -> sizeOfRightSubTree + 1;
		node -> right = insertNode(node -> right, data);
	}
	return node;
}

Node* deleteNode(Node *node, int data) {
	if(node == NULL) {
		return node;
	}

	if(data < node -> data) {
		node -> sizeOfLeftSubTree -= 1;
		node -> left = deleteNode(node -> left, data);
	} else if(data > node -> data) {
		node -> sizeOfRightSubTree -= 1;
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

		Node *tmp = minValueNode(node -> right);
		node -> data = tmp -> data; 
		node -> sizeOfRightSubTree -= 1;
		node -> right = deleteNode(node -> right, tmp -> data);
	}
}

int find_by_order(int index) {
	int currIndex = root -> sizeOfLeftSubTree;
	Node *currNode = root;
	while(currNode != NULL && currIndex != index) {
		if(index > currIndex) {
			if(currNode -> right == NULL) {
				break;
			}
			currIndex += (1 + currNode -> right -> sizeOfLeftSubTree);
			currNode = currNode -> right;
		} else {
			if(currNode -> left == NULL) {
				break;
			}
			currIndex -= (1 + currNode -> left -> sizeOfRightSubTree);
			currNode = currNode -> left;
		}
	}
	return currNode -> data;
}

int order_of_key(int key) {
	int ans = root -> sizeOfLeftSubTree;
	Node* currNode = root;
	while(currNode != NULL && currNode -> data != key) {
		if(key > currNode -> data) {
			if(currNode -> right == NULL) {
				break;
			}
			ans += (1 + currNode -> right -> sizeOfLeftSubTree);
			currNode = currNode -> right;
		} else {
			if(currNode -> left == NULL) {
				break;
			}
			ans -= (1 + currNode -> left -> sizeOfRightSubTree);
			currNode = currNode -> left;
		}
	}
	return ans;
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

void inOrder(Node* node) {
	if(node == NULL) {
		return;
	}
	inOrder(node -> left);
	cout << node -> data << " " << "(L - " << node -> sizeOfLeftSubTree << ")" << "(R - " << node -> sizeOfRightSubTree << ")" << endl;
	inOrder(node -> right);
}

int main() {
	int n, data;
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> data;
		root = insertNode(root, data);
	}

	inOrder(root);
	cout << endl;

	cout << find_by_order(20) << endl;
	cout << order_of_key(30) << endl;	

	root = deleteNode(root, 4);
	inOrder(root);	
	root = deleteNode(root, 42);
	inOrder(root);
	return 0;
}