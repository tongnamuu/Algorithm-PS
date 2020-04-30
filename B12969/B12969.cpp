#include <iostream>
#include <cstring>
using namespace std;
int d[31][31][31][31 * 15];
char ans[31];
int n, k;
int go(int idx, int a, int b, int pn) {
	if (idx == n) {
		return pn == k;
	}
	int& ret = d[idx ][a][b][pn];
	if (ret != -1) return ret;
	ans[idx] = 'A';
	if (go(idx + 1, a + 1, b, pn)) return ret = 1;
	ans[idx] = 'B';
	if (go(idx + 1, a, b + 1, pn + a)) return ret = 1;
	ans[idx] = 'C';
	if (go(idx + 1, a, b, pn + a + b)) return ret = 1;
	return ret = 0;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	cin >> n >> k;
	memset(d, -1, sizeof(d));
	if (go(0, 0, 0, 0) == 1) ans[n] = '\0', cout << ans;
	else cout << -1;
}