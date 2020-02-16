#include <iostream>
#include <cstring>
using namespace std;
int n, m;
int d[15 * 15][1 << 14];
int go(int num, int s) {
	if (num == n * m && s == 0) return 1;
	if (num >= n * m) return 0;
	int& ret = d[num][s];
	if (ret != -1) return ret;
	if (s & 1) ret = go(num + 1, s >> 1);
	else {
		ret = go(num + 1, (s >> 1) | (1 << (m - 1)));
		if (num%m != m - 1 && ((s & 2) == 0)) {
			ret += go(num + 2, s >> 2);
		}
	}
	ret %= 9901;
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	memset(d, -1, sizeof(d));
	cout << go(0, 0) << '\n';
}