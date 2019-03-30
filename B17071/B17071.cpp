#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
int d[500001][2];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, k; cin >> n >> k;
	queue<pair<int, int>>q;
	memset(d, -1, sizeof(d));
	q.push({ n,0 });
	d[n][0] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int t = q.front().second; q.pop();
		for (int next : {x + 1, x - 1, 2 * x}) {
			if (0 <= next && next <= 500000) {
				if (d[next][1 - t] == -1) {
					d[next][1 - t] = d[x][t] + 1;
					q.push({ next,1 - t });
				}
			}
		}
	}
	int ans = -1;
	for (int t = 0;; ++t) {
		k += t;
		if (k > 500000) break;
		if (d[k][t % 2] <= t) {
			ans = t;
			break;
		}
	}
	cout << ans << '\n';
}