#include <bits/stdc++.h>

using namespace std;

int MAX_ANGLE = 360;
map<int, string> hashAngleAndRequestServingNodeLabelAndIp;

int hashCode(string s) {
	long long hash = 0;
	int prime = 31;
	for(int i=0;i<s.length();i++) {
		hash += (pow(2, i) * s[i]);
	}
	return hash % MAX_ANGLE;
}

void printNodeLabel(string sourceIp) {
	cout << "From " << sourceIp << " Served by " <<hashAngleAndRequestServingNodeLabelAndIp.lower_bound(hashCode(sourceIp)) -> second << endl;
}

int main() {
	for(int i=0;i<360;i++) {
		if(i % 10 == 0) {
			hashAngleAndRequestServingNodeLabelAndIp.insert({i, "Node -> 10.34.25." + to_string(i)});
		}
	}

	string sourceIp = "10.12.32.124";
	printNodeLabel(sourceIp);

	hashAngleAndRequestServingNodeLabelAndIp.erase(220);
	cout << "Erase node with ip : " << "10.34.25." + to_string(220) << endl;
	printNodeLabel(sourceIp);

	hashAngleAndRequestServingNodeLabelAndIp.insert({220, "Node -> 10.34.25.220"});

	printNodeLabel(sourceIp);


	sourceIp = "10.12.32.125";
	printNodeLabel(sourceIp);
	
	sourceIp = "10.24.32.125";
	printNodeLabel(sourceIp);
	
	sourceIp = "100.24.32.125";
	printNodeLabel(sourceIp);


	sourceIp = "24.100.32.125";
	printNodeLabel(sourceIp);

	hashAngleAndRequestServingNodeLabelAndIp.erase(210);
	cout << "Erase node with ip : " << "10.34.25." + to_string(210) << endl;
	printNodeLabel(sourceIp);

	hashAngleAndRequestServingNodeLabelAndIp.insert({210, "Node -> 10.34.25.210"});
	printNodeLabel(sourceIp);
	
	return 0;
}