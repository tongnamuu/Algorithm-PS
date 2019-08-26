#include <iostream>
using namespace std;
int seg[400004];
void init(int node, int start, int end) {
	if (start == end) {
		seg[node] = 1;
		return;
	}
	init(node * 2, start, (start+end)/2);
	init(node * 2 + 1, (start + end) / 2 + 1, end);
	seg[node] = seg[node * 2] + seg[node * 2 + 1];
}
void update(int node, int start, int end, int index, int val) {
	if (index<start || index>end) return;
	if (start == end) {
		seg[node] += val;
		return;
	}
	else {
		update(node * 2, start, (start + end) / 2, index, val);
		update(node * 2 + 1, (start + end) / 2 + 1, end, index, val);
		seg[node] = seg[node * 2] + seg[node * 2 + 1];
	}
}
int sumquery(int node, int start, int end, int i, int j) {
	if (end < i || j < start) return 0;
	else if (i <= start && end <= j) return seg[node];
	return sumquery(node * 2, start, (start + end) / 2, i, j) + sumquery(node * 2 + 1, (start + end) / 2 + 1, end, i, j);
}
int query(int node, int start, int end, int k) {
	if (start == end) return start;
	if (seg[node * 2] >= k) return query(node * 2, start, (start + end) / 2, k);
	else return query(node * 2 + 1, (start + end) / 2 + 1, end, k - seg[node * 2]);
}
int main() {
	int n, k; cin >> n >> k;
	init(1, 1, n);
	cout << '<';
	int prev = 0;
	for (int i = n; i >= 1 ; --i) {
		int prevcnt = 0;
		if (prev != 0) prevcnt = sumquery(1, 1, n, 1, prev);
		int index = (prevcnt + k) % i;
		if (index == 0) index = i;
		prev = query(1, 1, n, index);
		update(1, 1, n, prev, -1);
		if(i!=1)cout << prev << ", ";
		else cout << prev << '>';
	}
}