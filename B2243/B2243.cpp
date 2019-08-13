#include <iostream>
using namespace std;
int seg[1000000 * 3 + 1];
void update(int node, int start, int end, int index, int value) {
	if (index<start || index>end) return;
	seg[node] += value;
	if (start != end) {
		int mid = (start + end) / 2;
		update(node * 2, start, mid, index, value);
		update(node * 2 + 1, mid + 1, end, index, value);
	}
}
int query(int node, int start, int end, int k) {
	if (start == end) return start;
	else {
		int mid = (start + end) / 2;
		if (k <= seg[2 * node]) return query(node * 2, start, mid, k);
		else return query(node * 2 + 1, mid + 1, end, k - seg[2 * node]);
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0, a, b, c; i < n; ++i) {
		cin >> a;
		if (a == 2) {
			cin >> b >> c;
			update(1, 1, 1000000, b, c);
		}
		else if (a == 1) {
			cin >> b;
			int index = query(1, 1, 1000000, b);
			cout << index << '\n';
			update(1, 1, 1000000, index, -1);
		}
	}
}