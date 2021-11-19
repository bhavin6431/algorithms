#include <bits/stdc++.h>

using namespace std;

class Node {
	public:
	int data;
	Node* next;
};

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

Node* head;

void push(int data) {
	Node* newNode = new Node();
	newNode -> data = data;
	if(head == NULL) {
		head = newNode;
	} else {
		newNode -> next = head;
		head = newNode;
	}
}

int pop() {
	int retVal = head -> data;
	Node* tmp = head;
	head = head -> next;
	return retVal;
}

int top() {
	return head == NULL ? -1 : head -> data;
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

int main () {
	for(int i=100;i<=1000;i+=100) {
		push(i);
	}
	cout << top() << endl;
	display();
	pop();
	display();
	cout << top() << endl;
	while(!empty()) {
		pop();
		cout << top() << endl;
	}

	for(int i=1;i<=10;i++) {
		push(i);
	}
	display();

	return 0;
}