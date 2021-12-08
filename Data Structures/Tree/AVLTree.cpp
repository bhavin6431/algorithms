#include <bits/stdc++.h>

using namespace std;

class Node {
public:
	int data;
	Node* left = NULL;
	Node* right = NULL;
	int height;

};

Node* root = NULL;

int height(Node *node) {
	return node == NULL ? 0 : node -> height;
}

int getBalance(Node *node) {
	return node == NULL ? 0 : height(node -> left) - height(node -> right); 	
}

Node* rotateLeft(Node* x) {
	Node* y = x -> right;
	Node* T2 = y -> left;

	y -> left = x;
	x -> right = T2;

	x -> height = max(height(x -> left), height(x -> right)) + 1;
	y -> height = max(height(y -> left), height(y -> right)) + 1;

	//return new root
	return y;
}


Node* rotateRight(Node *x) {
	Node* y = x -> left;
	Node* T2 = y -> right;

	y -> right = x;
	x -> left = T2;

	x -> height = max(height(x -> left), height(x -> right)) + 1;
	y -> height = max(height(y -> left), height(y -> right)) + 1;

	//return new root
	return y;
}

Node* insertNode(Node *node, int data) {
	if(node == NULL) {
		Node *newNode = new Node();
		newNode -> data = data;
		newNode -> height = 1;
		return newNode;
	}

	if( data < node -> data ) {
		node -> left = insertNode(node -> left, data);
	} else {
		node -> right = insertNode(node -> right, data);
	}

	node -> height = 1 + max(height(node -> left), height(node -> right));

	int balance = getBalance(node);

	//LL
	if(balance > 1 && data < node -> left -> data)
		return rotateRight(node);

	//RR
	if(balance < -1 && data > node -> right -> data) 
		return rotateLeft(node);

	//LR
	if(balance > 1 && data > node -> left -> data) {
		node -> left = rotateLeft(node -> left);
		return rotateRight(node);
	}

	//RL
	if(balance < -1 && data < node -> right -> data) {
		node -> right = rotateRight(node -> right);
		return rotateLeft(node);
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

	if(node == NULL) {
		return node;
	}


	node -> height = 1 + max(height(node -> left), height(node -> right));

	int balance = getBalance(node);

	//LL
	if(balance > 1 && data < node -> left -> data)
		return rotateRight(node);

	//RR
	if(balance < -1 && data > node -> right -> data) 
		return rotateLeft(node);

	//LR
	if(balance > 1 && data > node -> left -> data) {
		node -> left = rotateLeft(node -> left);
		return rotateRight(node);
	}

	//RL
	if(balance < -1 && data < node -> right -> data) {
		node -> right = rotateRight(node -> right);
		return rotateLeft(node);
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

void prettyPrint(const string& prefix, Node* node, bool isLeft) {
	if(node != NULL ) {
		cout << prefix;

		cout << (isLeft ? "├──" : "└──" );

		cout << node -> data << endl;

		prettyPrint( prefix + (isLeft ? "│   " : "    "), node -> left, true);
		prettyPrint( prefix + (isLeft ? "│   " : "    "), node -> right, false);
	}
}


// 1 Insert
// 2 delete
// 3 search 

int main() {
	int n, q, type, val;
	cin >> n;
	vector<int> vec(n);
	for(int i=0;i<n;i++) {
		cin >> vec[i];
		root = insertNode(root, vec[i]);	
	}
	prettyPrint("", root, false); 
	cout << endl;
	cin >> q;
	while(q--) {
		cin >> type >> val;
		if(type == 1) {
			cout << "Inserting : " << val << endl;
			root = insertNode(root, val);
		} else if(type == 2) {
			cout << "Deleting : " << val << endl;
			root = deleteNode(root, val);
		} else if(type == 3) {
			bool found = contains(val);
			cout << (found ? "Found : " + val : "Not found : " + val) << endl;
		}
		prettyPrint("", root, false); 		
	}

	return 0;
}