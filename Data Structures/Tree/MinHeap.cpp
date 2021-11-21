#include <bits/stdc++.h>

using namespace std;

int sizeOfHeap = 0;
int initalHeight = 4;
int capacity = pow(2, initalHeight) - 1; 
int *heap;

void swap(int i, int j) {
	int tmp = heap[i];
	heap[i] = heap[j];
	heap[j] = tmp;
}

int getParent(int i) {
	return (i - 1) / 2;
}

bool hasParent(int i) {
	return getParent(i) >= 0;
}

int getLeftChild(int i) {
	return (i * 2) + 1;
}

bool hasLeftChild(int i) {
	return getLeftChild(i) < sizeOfHeap;
}

int getRightChild(int i) { 
	return (i * 2) + 2;
}

bool hasRightChild(int i) {
	return getRightChild(i) < sizeOfHeap;
}

void heapifyUp() {
	int index = sizeOfHeap - 1;
	while(hasParent(index) && heap[getParent(index)] > heap[index]) {
		swap(getParent(index), index);
		index = getParent(index);	
	}
}

void display() {
	for(int i=0;i<sizeOfHeap;i++) {
		cout << heap[i] << " ";
	}
	cout << endl;
}	

void heapifyDown() {
	int index = 0;
	while(hasLeftChild(index)) {
		int small = getLeftChild(index);
		if(hasRightChild(index) && heap[getRightChild(index)] < heap[getLeftChild(index)]) {
			small = getRightChild(index);
		}

		if(heap[index] < heap[small]) {
			break;
		} else {
			swap(index, small);
			index = small;
		}
	}
}

void push(int val) {
	heap[sizeOfHeap++] = val;
	heapifyUp();
}


int top() {
	if(sizeOfHeap > 0) {
		return heap[0];
	}
	throw "Heap is empty";
}


int pop() {
	int retVal = top();
	heap[0] = heap[sizeOfHeap - 1];
	sizeOfHeap--;
	heapifyDown();	
	return retVal;
}


int main() {
	heap = new int[capacity];
	int n;
	cin >> n;
	vector<int> vec(n);
	for(int i=0;i<n;i++) {
		cin >> vec[i];
		push(vec[i]);
		display();
	}
	cout << endl;
	for(int i=0;i<10;i++) {
		cout << top() << endl;
		pop();
		display();
	}

	for(int i=0;i<n;i++) {
		push(vec[i]);
		display();
	}
}