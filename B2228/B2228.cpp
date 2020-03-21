#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define IMPOSSIBLE -2147483647
int a[101];
int sum[101];
int n, m;
int d[101][101];
bool c[101][101];
int go(int index, int cnt) {
	if (cnt == m) return 0;
	if (index > n) return IMPOSSIBLE;
	int& ret = d[index][cnt];
	if (c[index][cnt]) return ret;
	c[index][cnt] = true;
	ret = go(index + 1, cnt);
	for (int i = index; i <= n; ++i) {
		int temp = go(i + 2, cnt + 1);
		if (temp != IMPOSSIBLE)
			temp += sum[i] - sum[index - 1];
		if (ret < temp) ret = temp;
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		for (int j = 1; j <= m; ++j) {
			d[i][j] = IMPOSSIBLE;
		}
	}
	for (int i = 1; i <= n; ++i) {
		sum[i] = sum[i - 1] + a[i];
	}
	cout << go(1, 0);
}