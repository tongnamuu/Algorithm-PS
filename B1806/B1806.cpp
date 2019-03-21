#include <iostream>
using namespace std;
int a[100001];
int sum[100001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, s; cin >> n >> s;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	int len = 2147483647;
	int j = 0, i = 0;
	while (j <= n&&i <= n) {
		if (sum[j] - sum[i] >= s) {
			if (j - i < len) {
				len = j - i;
			}
			++i;
		}
		else if (sum[j] - sum[i] < s) {
			++j;
		}
	}
	if (len == 2147483647) len = 0;
	cout << len << '\n';
}