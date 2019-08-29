#include <iostream>
#include <memory.h>
#include <string>
using namespace std;
const int N = 100000;
int seg[4 * N + 4];
void update(int node, int start, int end, int index, int val) {
	if (index<start || index>end) return;
	if (start == end) {
		seg[node] = val; return;
	}
	update(node * 2, start, (start + end) / 2, index, val);
	update(node * 2 + 1, (start + end) / 2 + 1, end, index, val);
	seg[node] = seg[node * 2] * seg[node * 2 + 1];
}
int query(int node, int start, int end, int i, int j) {
	if (start > j || end < i) return 1;
	if (i <= start && end <= j) return seg[node];
	return query(node * 2, start, (start + end) / 2, i, j)*query(node * 2 + 1, (start + end) / 2 + 1, end, i, j);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	while (cin >> n >> m) {
		memset(seg, 0, sizeof(seg));
		string ans;
		for (int i = 1, num; i <= n; ++i) {
			cin >> num;
			if (num > 1) num = 1;
			else if (num < 0) num = -1;
			update(1, 1, n, i, num);
		}
		char cmd;
		for (int i = 0, u, v; i < m; ++i) {
			cin >> cmd >> u >> v;
			if (cmd == 'C') {
				if (v > 0) v = 1;
				else if (v < 0) v = -1;
				update(1, 1, n, u, v);
			}
			else if (cmd == 'P') {
				int temp = query(1, 1, n, u, v);
				if (temp == 1) ans += '+';
				else if (temp == -1) ans += '-';
				else if (temp == 0)ans += '0';
			}
		}
		cout << ans << '\n';
	}
}