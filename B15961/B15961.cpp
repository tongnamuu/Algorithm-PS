#include <iostream>
#include <set>
using namespace std;
int a[3000001];
int cnt[3001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, d, k, c; cin >> n >> d >> k >> c;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < k; ++i) {
		cnt[a[i]] += 1;
	}
	cnt[c] += 1;
	int temp = 0;
	int ans = 0;
	for (int i = 0; i <= 3000; ++i) if (cnt[i] > 0) ++temp;
	int i = 0;
	int j = k;
	while (i < n) {
		cnt[a[i]] -= 1;
		if (cnt[a[i]] == 0) temp--;
		if (cnt[a[k]] == 0) ++temp;
		cnt[a[k]] += 1;
		if (temp > ans) ans = temp;
		i += 1;
		k = (k + 1) % n;
	}
	cout << ans << '\n';
}