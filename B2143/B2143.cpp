#include <iostream>
#include <algorithm>
using namespace std; 
int a[1000001];
int sum1[1001];
int b[1000001];
int sum2[1001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum1[i] = sum1[i - 1] + a[i];
	}
	int m; cin >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> b[i];
		sum2[i] = sum2[i - 1] + b[i];
	}
	int k = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < i; ++j) {
			a[k++] = sum1[i] - sum1[j];
		}
	}
	sort(a, a + k);
	int l = 0;
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j < i; ++j) {
			b[l++] = sum2[i] - sum2[j];
		}
	}
	sort(b, b + l);
	long long ans = 0;
	int i = 0, j = l - 1;
	while (i < k && j >= 0) {
		if (a[i] + b[j] == T) {
			long long cnt1 = upper_bound(a, a + k, a[i]) - lower_bound(a, a + k, a[i]);
			long long cnt2 = upper_bound(b, b + l, b[j]) - lower_bound(b, b + l, b[j]);
			ans += (cnt1*cnt2);
			i += cnt1;
			j -= cnt2;
		}
		else if (a[i] + b[j] > T) {
			j--;
		}
		else if (a[i] + b[j] < T) {
			++i;
		}
	}
	cout << ans << '\n';
}