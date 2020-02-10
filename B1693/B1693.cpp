#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;
#define SIZE 100001
int color_cnt;
vector<int>adj[SIZE];
int d[SIZE][19];
int colortree(int now, int color, int prev) {
	int& ret = d[now][color];
	if (ret != -1) return ret;
	int val = 0;
	for (int next : adj[now]) {
		if (next == prev) continue;
		int temp = 2147483647;
		for (int i = 1; i <= color_cnt; ++i) {
			if (color == i) continue;
			temp = min(temp, colortree(next, i, now));
		}
		val += temp;
	}
	return ret = val + color;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	color_cnt = int(ceil(log2(n))) + 1;
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int ans = 2147483647;
	memset(d, -1, sizeof(d));
	for (int i = 1; i <= color_cnt; ++i) {
		ans = min(ans, colortree(1, i, -1));
	}
	cout << ans << '\n';
}