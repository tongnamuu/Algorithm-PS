#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
vector<pair<int,int>>a[50001];
int d[3][50001];
pair<int,int> go(int turn, int now, int prev) {
	pair<int, int> temp = { now,0 };
	for (auto& p : a[now]) {
		int next = p.first;//정점
		if (next == prev) continue;
		int len = p.second;//거리
		d[turn][next] = d[turn][now] + len;
		auto x = go(turn, next, now);
		if (temp.second < x.second + len) {
			temp.first = x.first;
			temp.second = x.second + len;
		}
	}
	return temp;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0, u, v, w; i < n - 1; ++i) {
		cin >> u >> v >> w;
		a[u].push_back({ v,w });
		a[v].push_back({ u,w });
	}
	auto x = go(0, 1, -1);
	x = go(1, x.first, -1);
	x = go(2, x.first, -1);
	for (int i = 1; i <= n; ++i) {
		cout << max(d[1][i], d[2][i]) << '\n';
	}
}