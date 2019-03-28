#include <iostream>
using namespace std;
int min(const int& a, const int& b) { return a > b ? b : a; }
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		int a[4], b[13] = { 0, };
		int d[13] = { 0, };
		for (int i = 0; i < 4; ++i) cin >> a[i];
		for (int i = 1; i <= 12; ++i) cin >> b[i];
		for (int i = 1; i <= 12; ++i) {
			if (i >= 3) {
				if (b[i] * a[0] >= a[1])d[i] = min(d[i - 1] + a[1], d[i - 3] + a[2]);
				else d[i] = min(d[i - 1] + b[i] * a[0], d[i - 3] + a[2]);
			}
			else d[i] = min(d[i - 1] + a[1], d[i - 1] + b[i] * a[0]);
		}
		int ans = min(d[12], a[3]);
		cout << '#' << test_case << ' ' << ans << '\n';
	}
}