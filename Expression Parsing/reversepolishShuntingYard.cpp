#include <bits/stdc++.h>

using namespace std;

bool isOperator(char c) {
	return c == '+' || c == '-' || c == '/' || c == '*';
}

int precedence(char op){
	if(op == '+'||op == '-')
		return 1;
	if(op == '*'||op == '/')
		return 2;
	return 0;
}

double result(char op, double op1, double op2) {
	if(op == '+') {
		return op1 + op2;
	} else if(op == '-') {
		return op1 - op2;
	} else if(op == '*') {
		return op1 * op2;
	} else if(op == '/') {
		return op1 / op2;
	}
}

void performOperation(stack<char> &opStack, stack<double> &oprndStack) {
	double op2 = oprndStack.top();				
	oprndStack.pop();

	double op1 = oprndStack.top();
	oprndStack.pop();

	char op = opStack.top();
	opStack.pop();

	oprndStack.push(result(op, op1, op2));
}

double eval(string exp) {
	stack<char> opStack;
	stack<double> oprndStack;

	for(int i=0;i<exp.length();i++) {
		if(exp[i] == '(') {
			opStack.push(exp[i]);
		} else if(isdigit(exp[i])) {
			double val = 0;
			while(i < exp.length() && isdigit(exp[i])) {
				val = (val * 10) + (exp[i] - '0');
				i++;
			}
			oprndStack.push(val);
			i--;
		} else if(exp[i] == ')') {
			while(!opStack.empty() && opStack.top() != '(') {
				performOperation(opStack, oprndStack);
			}
			opStack.pop();
		} else {
			while(!opStack.empty() && precedence(opStack.top()) >= precedence(exp[i])) {
				performOperation(opStack, oprndStack);
			}
			opStack.push(exp[i]);
		}
	}
	while(!opStack.empty()) {
		performOperation(opStack, oprndStack);
	}
	return oprndStack.top();
}

int main() {
	string exp;
	cin >> exp;
	cout << eval(exp);
	return 0;
}