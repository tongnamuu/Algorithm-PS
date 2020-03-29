#include <iostream>
#include <algorithm>
using namespace std;
int a[2][10001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	if (n == 1) {
		cout << 2 << '\n';
		cout << 1 << ' ' << 2;
		return 0;
	}
	int s = 2 * n;
	int start = s - 4;
	a[1][n] = s;
	a[1][1] = s - 1;
	a[0][n] = s - 2;
	a[0][1] = s - 3;
	long long sum = (1 + s)*s / 2;
	long long T = 0;
	long long ans = 0;
	for (int i = 2; i < n; ++i) {
		a[0][i] = start--;
	}
	for (int i = 2; i < n; ++i) {
		a[1][i] = start--;
	}
	for (int i = 1; i <= n; ++i) {
		ans += sum * T;
		sum -= a[0][i];
		T++;
	}
	for (int i = 1; i <= n; ++i) {
		ans += sum * T;
		sum -= a[1][i];
		T++;
	}
	cout << ans << '\n';
	for (int j = 0; j < 2; ++j) {
		for (int i = 1; i <= n; ++i) {
			cout << a[j][i] << ' ';
		}
		cout << '\n';
	}
}