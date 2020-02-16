#include <iostream>
#include <memory.h>
using namespace std;
long long d[12 * 12][1 << 12];
int n, m;
long long go(int num, int s) {
	if (num == n * m && s == 0) return 1;
	if (num >= n * m) return 0;
	long long &ret = d[num][s];
	if (ret != -1) return ret;
	if (s & 1) ret = go(num + 1, (s >> 1));
	else {
		ret = go(num + 1, (s >> 1) | (1 << (m - 1)));
		if ((num%m != (m - 1)) && ((s & 2) == 0)) {
			ret += go(num + 2, (s >> 2));
		}
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		if (n*m & 1) {
			cout << 0 << '\n';
			continue;
		}
		memset(d, -1, sizeof(d));
		cout << go(0, 0) << '\n';
	}
}