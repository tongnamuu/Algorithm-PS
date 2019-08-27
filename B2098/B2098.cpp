#include <iostream>
#include <memory.h>
using namespace std;
int w[17][17];
int d[17][1 << 17];
int n;
int min(int x, int y) { return x > y ? y : x; }
const int INF = 1000000000;
int go(int lastvisit, int visit) {
	if (visit == (1 << n) - 1) {
		if (w[lastvisit][0]) return w[lastvisit][0];
		else return INF;
	}
	int& ret = d[lastvisit][visit];
	if (ret != -1) return ret;
	ret = INF;
	for (int i = 0; i < n; ++i) {
		if (i == lastvisit) continue;
		if (visit&(1 << i)) continue;
		if (w[lastvisit][i]) ret = min(ret, go(i, visit | (1 << i)) + w[lastvisit][i]);
	}
	return ret;
}
int main() {
	memset(d, -1, sizeof(d));
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> w[i][j];
		}
	}
	cout << go(0, 1 << 0) << '\n';
}