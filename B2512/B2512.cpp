#include <iostream>
using namespace std;
int a[10001];
int n, m;
int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }
bool cal(int M) {
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += min(a[i], M);
	}
	return sum <= m;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	cin >> m;
	int start = 1;
	int end = 1000000000;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (cal(mid)) start = mid + 1;
		else end = mid - 1;
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = max(ans, min(a[i], end));
	}
	cout << ans << '\n';
}