#include <bits/stdc++.h>

using namespace std;

class Node {
	public:
	int key;
	Node* next;
};

class Iterator {
	public:

	Node** table;
	int currIndex = 0;	
	int size;
	Node* currNode = NULL;
	
	Iterator(Node** tableP, int sizeP) {
		table = tableP;
		size = sizeP;
	}

	bool hasNext() {
		return currIndex < size;
	}
	int next() {
		if(table[currIndex] != NULL) {
			if(currNode == NULL) {
				currNode = table[currIndex];
			} else {
				if(currNode -> next != NULL) {
					int val = currNode -> next -> key;
					currNode = currNode -> next;
					return val;
				} 
			}
			return table[currIndex++] -> key;				
		} else {
			currIndex++;
			return next();
		}
	}
};

int capacity = 16;
int init = 0;
Node* table[16];


int hashCode(int val) {
	return val * 31;
}

int getTableIndex(int hash) {
	return hash & (capacity - 1);
}

void insert(int key) {
	Node* newNode = new Node();
	newNode -> key = key;
	Node* exNode = table[getTableIndex(hashCode(key))];
	if(exNode != NULL) {
		exNode -> next = newNode;
	} else {
		table[getTableIndex(hashCode(key))] =  newNode;
	}
}
bool containKey(int key) {
	return table[getTableIndex(hashCode(key))] != NULL;
}

int main() {
	insert(12);
	insert(24);
	insert(122);
	insert(124);
	insert(124);
	cout << (containKey(12) ? "YES" : "NO") << endl;
	cout << (containKey(128) ? "YES" : "NO") << endl;
	Iterator* iterator = new Iterator(table, capacity);

	while(iterator->hasNext()) {
		cout <<  iterator->next() << endl;
	}

}