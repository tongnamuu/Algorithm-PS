#include <iostream>
using namespace std;
char a[51][51];
bool next_permutation(int a[], int n) {
	int index = n - 1;
	while (index >= 1 && a[index - 1] >= a[index]) --index;
	if (index == 0) return false;
	int ind = n - 1;
	while (a[index - 1] >= a[ind]) --ind;
	int temp = a[ind];
	a[ind] = a[index - 1];
	a[index - 1] = temp;
	ind = n - 1;
	while (index < ind) {
		temp = a[ind];
		a[ind] = a[index];
		a[index] = temp;
		--ind; ++index;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		int n, m; cin >> n >> m;
		for (int i = 0; i < n; ++i) cin >> a[i];
		int d[51] = { 0, };
		d[n - 2] = 1;
		d[n - 3] = 1;
		int ans = 2147483647;
		do {
			int cnt = 0;
			int first = -1, second = -1;
			for (int i = 1; i < n; ++i) {
				if (d[i - 1] && first == -1) first = i;
				else if (d[i - 1]) second = i;
			}
			for (int i = 0; i < first; ++i) {
				for (int j = 0; j < m; ++j) {
					if (a[i][j] != 'W') ++cnt;
				}
			}
			for (int i = first; i < second; ++i) {
				for (int j = 0; j < m; ++j) {
					if (a[i][j] != 'B') ++cnt;
				}
			}
			for (int i = second; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					if (a[i][j] != 'R') ++cnt;
				}
			}
			if (ans > cnt) ans = cnt;
		} while (next_permutation(d, n-1));
		cout << '#' << test_case << ' ' << ans << '\n';
	}
}