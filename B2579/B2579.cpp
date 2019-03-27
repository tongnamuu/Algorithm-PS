#include <iostream>
using namespace std;
int max(const int &a, const int &b) { return a > b ? a : b; }
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int a[301] = { 0, };
	int d[301][3] = { 0, };
	for (int i = 1; i <= n; ++i) cin >> a[i];
	d[1][1] = a[1];
	for (int i = 2; i <= n; ++i) {
		d[i][2] = d[i - 1][1] + a[i];
		d[i][1] = max(d[i - 2][1] + a[i], d[i - 2][2] + a[i]);
	}
	cout << max(d[n][1], d[n][2]) << '\n';
}