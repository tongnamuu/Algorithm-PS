#include <iostream>
using namespace std;
int n, x;
int pat[21];
bool up[21];
bool down[21];
bool check() {
	for (int i = 0; i< n - 1; ) {
		if (pat[i] - pat[i + 1] >= 2 || pat[i] - pat[i + 1] <= -2) return false;
		if (pat[i] - pat[i + 1] == 1) {
			int temp = pat[i + 1];
			for (int k = 0; k < x; ++k) {
				if (k + i + 1 >= n) return false;
				if (pat[k + i + 1] != temp) return false;
				down[k + i + 1] = true;
			}
			i = i + x;
		}
		else ++i;
	}
	for (int i = n - 1; i >= 1;) {
		if (pat[i] - pat[i - 1] >= 2 || pat[i] - pat[i - 1] <= -2) return false;
		if (pat[i] - pat[i - 1] == 1) {
			int temp = pat[i - 1];
			for (int k = 0; k < x; ++k) {
				if (i - 1 - k < 0) return false;
				if (pat[i - 1 - k] != temp) return false;
				up[i - 1 - k] = true;
			}
			i = i - x;
		}
		else --i;
	}
	for (int i = 0; i < n; ++i) if (up[i] && down[i]) return false;
	return true;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		cin >> n >> x;
		int a[21][21];
		int ans = 0;
		for (int i = 0; i < n; ++i)for (int j = 0; j < n; ++j) cin >> a[i][j];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				pat[j] = a[i][j];
				up[j] = false;
				down[j] = false;
			}
			if (check()) ++ans;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				pat[j] = a[j][i];
				up[j] = false;
				down[j] = false;
			}
			if (check()) ++ans;
		}
		cout << '#' << test_case << ' ' << ans << '\n';
	}
}