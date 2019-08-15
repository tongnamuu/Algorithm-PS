#include <iostream>
using namespace std;
long long a[100001];
long long seg[400001];
const int MAX = 2000000000;
int min(int x, int y) { return x > y ? y : x; }
int init(int node, int start, int end) {
	if (start == end) return seg[node] = a[start];
	return seg[node] = min(init(2 * node, start, (start + end) / 2), init(2 * node + 1, (start + end)/2 + 1, end));
}
long long query(int node, int start, int end, int i, int j) {
	if (end < i || j < start) return MAX;
	else if (i <= start && end <= j) return seg[node];
	else return min(query(2 * node, start, (start + end) / 2, i, j), query(2 * node + 1, (start + end) / 2 + 1, end, i, j));
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	init(1, 1, n);
	for (int i = 0, a, b; i < m; ++i) {
		cin >> a >> b;
		cout << query(1, 1, n, a, b) << '\n';
	}
}