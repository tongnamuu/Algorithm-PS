#include <iostream>
using namespace std;
int a[100001];
int seg[400004];
int max(int x, int y) { return x > y ? x : y; }
void init(int node, int start, int end) {
	if (start == end) seg[node] = start;
	else {
		init(node * 2, start, (start + end) / 2);
		init(node * 2 + 1, (start + end) / 2 + 1, end);
		if (a[seg[node * 2]] <= a[seg[node * 2 + 1]]) {
			seg[node] = seg[node * 2 + 1];
		}
		else seg[node] = seg[node * 2];
	}
}
void update(int node, int start, int end, int index, int val) {
	if (index<start || index>end) return;
	if (start == end) return;
	else {
		update(node * 2, start, (start + end) / 2, index, val);
		update(node * 2 + 1, (start + end) / 2 + 1, end, index, val);
		if (a[seg[node * 2]] <= a[seg[node * 2 + 1]]) {
			seg[node] = seg[node * 2 + 1];
		}
		else seg[node] = seg[node * 2];
	}
}
int query(int node, int start, int end, int i, int j) {
	if (start > j || end < i) return 0;
	if (i <= start && end <= j) return seg[node];
	else {
		int temp1 = query(node * 2, start, (start + end) / 2, i, j);
		int temp2 = query(node * 2 + 1, (start + end) / 2 + 1, end, i, j);
		if (temp1 == 0 && temp2 == 0) return 0;
		else if (temp1 == 0) return temp2;
		else if (temp2 == 0) return temp1;
		else if (a[temp1] <= a[temp2]) return temp2;
		else return temp1;
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	init(1, 1, n);
	int m; cin >> m;
	for (int i = 0, cmd, x, y; i < m; ++i) {
		cin >> cmd >> x >> y;
		if (cmd == 1) {
			a[x] = y;
			update(1, 1, n, x, y);
		}
		else if (cmd == 2) {
			int pos = query(1, 1, n, x, y);
			int left = query(1, 1, n, x, pos - 1);
			int right = query(1, 1, n, pos + 1, y);
			if(a[left]<a[right]) cout << a[right] + a[pos] << '\n';
			else cout << a[left] + a[pos] << '\n';
		}
	}
}