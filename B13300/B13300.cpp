#include <iostream>
using namespace std;
int a[7][2];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	int g, s;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		cin >> s >> g;
		++a[g][s];
	}
	for (int i = 0; i <= 1; ++i) {
		for (int j = 1; j <= 6; ++j) {
			ans += (a[j][i] + m - 1) / m;
		}
	}
	cout << ans << '\n';
} 