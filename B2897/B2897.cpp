#include <iostream>
using namespace std;
int a[1001];
int b[1001];
int n;
int sign(int x) {
	if (x > 0) return 1;
	else if (x < 0) return -1;
	return 0;
}
int abs(int x) { return x > 0 ? x : -x; }
int solve(int i, int j) {
	if (i == j) return 0;
	int index = i;
	for (int k = i; k < j; ++k) {
		if (abs(a[k]) < abs(a[index])) index = k;
	}
	int min = a[index];
	for (int k = i; k < j; ++k) a[k] -= min;
	return abs(min) + solve(i, index) + solve(index + 1, j);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i]; for (int i = 0; i < n; ++i) cin >> b[i]; for (int i = 0; i < n; ++i) a[i] -= b[i];
	int ans = 0;
	for (int i = 0, j; i < n; i=j) {
		for (j = i; j < n&&sign(a[i])*sign(a[j])>=0; ++j) { }
		ans += solve(i, j);
	}
	cout << ans << '\n';
}