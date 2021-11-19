#include <bits/stdc++.h>

using namespace std;

class Node {
	public:
	int key;
	int val;
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

void insert(int key, int val) {
	Node* newNode = new Node();
	newNode -> key = key;
	newNode -> val = val; 
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
int get(int key) {
	Node* exNode = table[getTableIndex(hashCode(key))];
	if(exNode -> next != NULL) {
		while(exNode != NULL && exNode -> key != key) {
			exNode = exNode -> next;
		}
		return exNode -> val;
	} else {
		return table[getTableIndex(hashCode(key))] -> val;
	}
}


int main() {
	insert(12, 23);
	insert(24, 34);
	insert(122, 122);
	insert(124, 124);
	cout << get(12) << endl;
	cout << get(24) << endl;
	cout << get(122) << endl;
	cout << get(124) << endl;
	cout << (containKey(12) ? "YES" : "NO") << endl;
	cout << (containKey(122) ? "YES" : "NO") << endl;
	Iterator* iterator = new Iterator(table, capacity);

	while(iterator->hasNext()) {
		int key = iterator->next();
		if(key != -1) {
			cout <<  key << " -> " << get(key) << endl;
		}
	}

}