#include <iostream>
using namespace std;
int max(const int a, const int b) { return a > b ? a : b; }
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int a[201] = { 0, };
	int d[201] = { 0, };
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) {
		d[i] = 1;
		for (int j = i-1; j >= 1; --j) {
			if (a[i] > a[j]) {
				d[i] = max(d[i], d[j] + 1);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (ans < d[i]) ans = d[i];
	}
	cout << n - ans << '\n';
}