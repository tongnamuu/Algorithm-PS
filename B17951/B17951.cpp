#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int a[100001];
int sum[100001];
bool solve(int n, int k, int val) {
	int i = 1, j = 1;
	int cnt = 0;
	while (i <= n && j <= n) {
		if (sum[j] - sum[i - 1] >= val) {
			i = j + 1;
			j++;
			cnt++;
		}
		else {
			j++;
		}
	}
	return cnt >= k;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	int s = 0, e = sum[n];
	while (s <= e) {
		int m = s + e >> 1;
		if (solve(n, k, m)) s = m + 1;
		else e = m - 1;
	}
	cout << e;
}