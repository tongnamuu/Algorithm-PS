#include <iostream>
using namespace std;
int a[100001];
int maxtree[400004];
int mintree[400004];
int max(int x, int y) { return x > y ? x : y; }
int min(int x, int y) { return x < y ? x : y; }
void init(int node, int start, int end) {
	if (start == end) {
		maxtree[node] = a[start];
		mintree[node] = a[start];
		return;
	}
	int mid = (start + end) / 2;
	init(2 * node, start, mid);
	init(2 * node + 1, mid + 1, end);
	maxtree[node] = max(maxtree[node * 2], maxtree[node * 2 + 1]);
	mintree[node] = min(mintree[node * 2], mintree[node * 2 + 1]);
}
int maxquery(int node, int start, int end, int i, int j) {
	if (j < start || i > end) return -1;
	else if (i <= start && end <= j) return maxtree[node];
	else return max(maxquery(node * 2, start, (start + end) / 2, i, j), maxquery(node * 2 + 1, (start + end) / 2 + 1, end, i, j));
}
int minquery(int node, int start, int end, int i, int j) {
	if (j < start || i > end) return 1000000001;
	else if (i <= start && end <= j) return mintree[node];
	else return min(minquery(node * 2, start, (start + end) / 2, i, j), minquery(node * 2 + 1, (start + end) / 2 + 1, end, i, j));
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	init(1, 1, n);
	for (int i = 0, a, b; i < m; ++i) {
		cin >> a >> b;
		cout << minquery(1, 1, n, a, b) << ' ' << maxquery(1, 1, n, a, b) << '\n';
	}
}