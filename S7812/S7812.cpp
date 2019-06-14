#include <iostream>
using namespace std;
int n, m;
int a[10001];
long long sum[10001];
int ans;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		ans = 0;
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			sum[i] = sum[i - 1] + a[i];
		}
		int i = 1, j = 0;
		while (i <= n&&j <= n && j<=i) {
			if (sum[i] - sum[j] == m) {
				++ans;
				++i;
			}
			else if (sum[i] - sum[j] > m) {
				++j;
			}
			else if (sum[i] - sum[j] < m) {
				++i;
			}
		}
		cout << '#' << test_case << ' ' << ans << '\n';
	}
}