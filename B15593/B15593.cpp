#include <iostream>
using namespace std;
int d[1001];
pair<int, int> t[101];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0, a, b; i < n; ++i) {
		cin >> a >> b;
		t[i].first = a, t[i].second = b;
		for (int k = a; k < b; ++k) {
			d[k]++;
		}
	}
	int cnt = 0, ans = 0;
	for (int i = 0; i < n; ++i) {
		cnt = 0;
		int x = t[i].first;
		int y = t[i].second;
		for (int k = x; k < y; ++k) {
			d[k]--;
		}
		for (int k = 0; k <= 1000; ++k) {
			if (d[k]) ++cnt;
		}
		if (cnt > ans) ans = cnt;
		for (int k = x; k < y; ++k) {
			d[k]++;
		}
	}
	cout << ans << '\n';
}