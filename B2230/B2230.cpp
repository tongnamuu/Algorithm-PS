#include <iostream>
#include <algorithm>
using namespace std;
int a[100001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	int i = 1, j = 1;
	int ans = 2147483647;
	while (i <= n && j <= n) {
		if (a[j] - a[i] >= m) {
			ans = min(a[j] - a[i], ans);
			i++;
		}
		else {
			j++;
		}
	}
	cout << ans << '\n';
}