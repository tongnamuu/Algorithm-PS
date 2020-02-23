#include <iostream>
using namespace std;
#define SIZE 1025
int a[SIZE][SIZE];
long long tree[SIZE][SIZE];
void update(int n, int x, int y, int val) {
	for (int i = x; i <= n; i += i & -i) {
		for (int j = y; j <= n; j += j & -j) {
			tree[i][j] += val;
		}
	}
}
long long sum(int x, int y) {
	long long sum = 0LL;
	for (int i = x; i > 0; i -= i & -i) {
		for (int j = y; j > 0; j -= j & -j) {
			sum += tree[i][j];
		}
	}
	return sum;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) {
		cin >> a[i][j];
		update(n, i, j, a[i][j]);
	}
	while (m--) {
		int w, x1, y1, x2, y2, c; cin >> w;
		if (w) {
			cin >> x1 >> y1 >> x2 >> y2;
			cout << sum(x2, y2) - sum(x2, y1 - 1) - sum(x1 - 1, y2) + sum(x1 - 1, y1 - 1) << '\n';
		}
		else {
			cin >> x1 >> y1 >> c;
			update(n, x1, y1, c - a[x1][y1]);
			a[x1][y1] = c;
		}
	}
}