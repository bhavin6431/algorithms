#include <bits/stdc++.h>

using namespace std;

class Node {
public:
	int data;
	Node* next = NULL;
	Node* prev = NULL;
};

Node* front = NULL;
Node* tail = NULL;


void addNode(int indx, int data) {
	Node* newNode = new Node();
	newNode -> data = data;
	if(indx == 0) {
		front -> prev = newNode;
		newNode -> next = front;
		front = newNode;
	} else {
		int i = 1;
		Node* prev = front;
		Node* curr = front -> next;
		while(i != indx) {
			prev = curr;
			curr = curr->next;
			i++;
		}
		newNode -> next = curr;
		prev -> next = newNode;
		newNode -> prev = prev;
		curr -> prev = newNode;
	}
}

void deleteNode(int data) {
	if(front -> data == data) {
		Node* tmp = front;
		front = front -> next;
		front -> prev = NULL;
		tmp = NULL;
	} else if(tail -> data == data) {
		tail -> prev -> next = NULL;
		tail = tail -> prev;
	} else {
		Node* prev = front;
		Node* curr = front -> next;
		while(curr -> data != data) {
			prev = curr;
			curr = curr -> next;
		}
	}
}

void create(vector<int> &vec) {
	front = new Node();
	front->data = vec[0];
	Node* prev = front;
	for(int i=1;i<vec.size();i++) {
		Node* newNode = new Node();
		newNode->data = vec[i];
		prev -> next = newNode;
		newNode->prev = prev;
		prev = newNode;
	}	
	tail = prev;
}

void display(bool forward) {
	if(forward) {
		Node* curr = front;
		while(curr != NULL) {
			cout << curr->data << " ";
			curr = curr->next;
		}
	} else {
		Node* curr = tail;
		while(curr != NULL) {
			cout << curr->data << " ";
			curr = curr -> prev;
		}
	}	
	cout << endl << endl;
}

int main() {
	int n;
	cin >> n;
	vector<int> vec(n);
	for(int i=0;i<n;i++) {
		cin >> vec[i];
	}
	
	create(vec);
	display(1);
	display(0);
	addNode(3, 45);
	display(1);
	display(0);
	addNode(5, 50);
	display(1);
	display(0);
	deleteNode(1);
	display(1);
	display(0);
	deleteNode(5);
	display(1);
	display(0);

	return 0;
}