#include <bits/stdc++.h>

using namespace std;


class Node {
	public:
	int data;
	Node* next = NULL;
};

Node *head;
Node *tail;

class Iterator {
	public:
	Node* currNode = NULL;
	
	Iterator(Node* head) {
		currNode = head;
	}

	bool hasNext() {
		return currNode != NULL;
	}
	int next() {
		int retVal = currNode -> data;
		currNode = currNode -> next;
		return retVal;
	}
};


void push(int data) {
	Node* newNode = new Node();
	newNode -> data = data;
	if(head == NULL) {
		head = newNode;
		tail = newNode;
	} else {
		tail -> next = newNode;
		tail = newNode;
	}
}

int front() {
	return head -> data;
}

int poll() {
	if(head != NULL) {
		head = head -> next;
	}
}

bool empty() {
	return head == NULL;
}

void display() {
	Iterator* iterator = new Iterator(head);
	while(iterator -> hasNext()) {
		cout << iterator -> next() << " "; 
	}	
	cout << endl;
}


int main() {
	push(10);
	cout << front() << endl;
	push(20);
	cout << front() << endl;
	push(30);
	cout << front() << endl;
	push(40);
	display();
	poll();
	display();
	cout << "Popping .." << endl;
	while(!empty()) {
		cout << front() << endl;
		poll();
	}
	push(200);
	cout << front() << endl;
	push(300);
	cout << front() << endl;
	push(400);
	cout << front() << endl;
	display();
	return 0;
}