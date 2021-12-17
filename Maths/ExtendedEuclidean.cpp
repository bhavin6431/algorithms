#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
	if(b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int gcdCo(int a, int b, int& x, int& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int x1, y1;
	int d = gcdCo(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return d;
}

int moduleInverse(int a, int m, int x, int y) {
	int g = gcdCo(a, m, x, y);
	if(g != 1) {
		cout << "NO Solution !";
		return -1;
	} else{
		return (x % m + m) % m;
	}
} 

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcdCo(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

int main() {
	int x, y;
	//15x + 17y = 79
	int g = gcd(15, 17);
	if(find_any_solution(15, 17, 79, x, y, g)) {
		cout << x  << " <-> " << y << endl;
	} else {
		cout << "No Solution !";
	}

	cout << moduleInverse(20, 1e9 + 7, 1, 1);

	return 0;
}