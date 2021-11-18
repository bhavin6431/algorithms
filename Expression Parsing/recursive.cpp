#include <bits/stdc++.h>

using namespace std;

//((3+4-1)*5+6*-7)/2

bool isOperator(char c) {
	return c == '+' || c == '-' || c == '/' || c == '*';
}


double result(char op, double op1, double op2 ) {
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


double eval(string exp, int l, int r) {
	//((a+b)+c)
	//will always have the bracket at the start
	if (exp[l] == '(') {
		int b1 = 1;
		int i = l + 1;
		while (b1 > 0) {
			if (exp[i] == '(') {
				b1++;
			} else if (exp[i] == ')') {
				b1--;
			}
			i++;
		}
		double a = eval(exp, l + 1, i - 2);
		//(a+b)
		//important
		if (i >= r) {
			return a;
		}
		//(a+b)+c
		char op = exp[i];

		double b = eval(exp, i + 1, r);
		return result(op, a, b);
	}
	//a+(b+c)
	//will always have digit at the start
	string as = "";
	double a;
	if (l <= r && isdigit(exp[l])) {

		while (l <= r && isdigit(exp[l]) || exp[l] == '.') {
			as += exp[l];
			l++;
		}
		a = stod(as);
		//important
		if (l > r) {
			return a;
		}
	} 
	double b = eval(exp, l + 1, r);
	return result(exp[l], a, b);
}


int main() {
	string s;
	cin >> s;
	cout << eval(s, 0, s.length() - 1);
	return 0;
}