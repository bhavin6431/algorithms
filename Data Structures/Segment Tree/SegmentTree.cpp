#include <bits/stdc++.h>

using namespace std;

int getMid(int l, int r) {
	return l + ((r - l) / 2);
}

int query(int *st, int ss, int se, int qs, int qe, int si) {
	if(qs <= ss && qe >= se) {
		return st[si];
	}
	if(qe < ss || qs > se) {
		return INT_MAX;
	}
	int mid = getMid(ss, se);
	return min(query(st, ss, mid, qs, qe, si * 2 + 1),
		query(st, mid + 1, se, qs, qe, si * 2 + 2));
}

void update(int *st, int* vec, int ss, int se,
	int index, int value, int si) {
	if (ss == se) {  
		vec[index] = value;
		st[si] = value;
	}
	else {
		int mid = getMid(ss, se);
		if (index >= ss && index <= mid) {
			update(st, vec,	ss, mid, index, value, 2 * si + 1);
		}
		else {
			update(st, vec, mid + 1, se, index,value, 2 * si + 2);
		}
		st[si] = min(st[2 * si + 1], st[2 * si + 2]);
	}
	return;
}

int construct(int *st, int *vec, int ss, int se, int si) {
	if(ss == se) {
		st[si] = vec[ss];
		return vec[ss];
	}

	int mid = getMid(ss ,se);
	st[si] = min(construct(st, vec, ss, mid, si * 2 + 1) 
		, construct(st, vec, mid + 1, se, si * 2 + 2));
	return st[si];
}

int main() {
	int n, m, x, v;
	cin >> n >> m;
	int vec[n];
	for(int i=0;i<n;i++) {
		cin >> vec[i];
	}
	

	int height = (int) ceil(log2(n));

	int size = 2 * (int) pow(2, height) - 1;
	int st[size] = {0};
	construct(st, vec, 0, n - 1, 0);
	for(int i = 0; i < m; i++){
		char type;
		cin >> type;
		if(type == 'q') {
			int l, r;
			cin >> l >> r;
			cout << query(st, 0, n - 1, l - 1, r - 1, 0) << endl;
		} else {
			int x, y;
			cin >> x >> y;
			update(st, vec, 0, n - 1, x-1, y, 0);
		}
	}


	return 0;
}