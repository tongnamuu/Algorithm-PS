#include <iostream>
using namespace std;
long long d[201][201];
void go(int n, int m, int k) {
	if (n == 0) return;
	if (n == 1 && m == 1) {
		cout << 'a';
		return;
	}
	if (m == 0) {
		cout << 'z';
		go(n - 1, m, k);
	}
	else if (d[n - 1][m - 1] >= k) {
		cout << 'a';
		go(n - 1, m - 1, k);
	}
	else {
		k -= d[n - 1][m - 1];
		cout << 'z';
		go(n - 1, m, k);
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m, k; cin >> n >> m >> k;
	for (int i = 1; i <= n + m; ++i) {
		d[i][0] = 1;
		d[i][1] = i;
	}
	for (int i = 2; i <= n + m; ++i) {
		for (int j = 1; j <= i; ++j) {
			d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
			if (d[i][j] > 1000000000) d[i][j] = 1000000001;
		}
	}
	if (d[n + m][n] < k) {
		cout << -1 << '\n';
		return 0;
	}
	go(n + m, n, k);
}